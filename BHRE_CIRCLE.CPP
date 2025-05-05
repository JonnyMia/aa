#include <GL/glut.h>
#include <iostream>
using namespace std;

// Center coordinates and radius
int xc, yc, r;

// Function to plot all 8 symmetric points of the circle
void plotCirclePoints(int x, int y) {
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        glEnd();
}

// Bresenham's circle drawing function
void bresenhamCircle() {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    glClear(GL_COLOR_BUFFER_BIT);
    
    while (x <= y) {
        plotCirclePoints(x, y);
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    glFlush();
}

// Initialization function
void Init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);   // Set background to white
    glColor3f(1.0, 0.0, 0.0);          // Set drawing color to red
    gluOrtho2D(0, 640, 0, 480);        // Set the 2D orthographic viewing region
}

// Main function
int main(int argc, char** argv) {
    cout << "Enter center coordinates (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter radius of circle: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing");
    Init();
    glutDisplayFunc(bresenhamCircle);
    glutMainLoop();
    return 0;
}
