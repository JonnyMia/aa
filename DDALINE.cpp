#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

float x_start, y_start, x_end, y_end;

int roundFloat(float value) {
    return int(value + 0.5);
}

void drawLine() {
    float dx = x_end - x_start;
    float dy = y_end - y_start;

    float steps = max(abs(dx), abs(dy)); 
    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x_start;  //starting point of line 
    float y = y_start;

    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glBegin(GL_POINTS);       // Start drawing pixels

    for (int i = 0; i <= steps; i++) {
        glVertex2i(roundFloat(x), roundFloat(y));
        x += xInc;
        y += yInc;
    }

    glEnd();  // End drawing
    glFlush(); // Force OpenGL to draw immediately
}

void init() {
    glClearColor(1, 1, 1, 1);  // Set background color to white
    glColor3f(0, 0, 0);    // Set draw color to black
    gluOrtho2D(0, 640, 0, 480);
}

int main() {
    cout << "Enter x1 y1: ";
    cin >> x_start >> y_start;
    cout << "Enter x_end y_end: ";
    cin >> x_end >> y_end;

    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple DDA Line");

    init();
    glutDisplayFunc(drawLine);
    glutMainLoop();

    return 0;
}

