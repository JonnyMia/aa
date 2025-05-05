#include <GL/glut.h>
#include <iostream>
using namespace std;

int xc, yc, r;

void plotCirclePoints(int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void drawCircle() {
    int x = 0, y = r;
    int p = 1 - r;

    glClear(GL_COLOR_BUFFER_BIT); // Clear screen
    glBegin(GL_POINTS); // Start drawing

    plotCirclePoints(x, y);

    while (x < y) {
        if (p < 0) {
            x++;
            p += 2 * x + 1;
        } else {
            x++;
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(x, y);
    }
    
    glEnd(); // Finish drawing
    glFlush(); // Force render
}

void init() {
    glClearColor(1, 1, 1, 1); // White background
    glColor3f(0, 0, 0);       // Black points
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set coordinate system
}

int main(int argc, char **argv) {
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single buffer
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");

    init();
    glutDisplayFunc(drawCircle);
    glutMainLoop();

    return 0;
}

