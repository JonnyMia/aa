#include <GL/glut.h>
#include <iostream>

using namespace std;

int x_start, y_start, x_end, y_end;

void drawLine() {
    float dx, dy, x, y, p;
    dx = x_end - x_start;
    dy = y_end - y_start;
    p = (2 * dy) - dx;
    x = x_start;
    y = y_start;

    glClear(GL_COLOR_BUFFER_BIT); // Clear screen
    glBegin(GL_POINTS); // Begin drawing points

    glVertex2i(x, y); // Plot the initial point

    while (x < x_end) {
        if (p < 0) {
            p = p + (2 * dy);  // Move horizontally
            x++;
        } else {
            p = p + (2 * (dy - dx)); // Move diagonally
            x++;
            y++;
        }
        glVertex2i(x, y); // Plot the next point
    }

    glEnd(); // End drawing
    glFlush(); // Force render
}

void init() {
    glClearColor(1, 1, 1, 1); // White background
    glColor3f(0, 0, 0);       // Black line
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1: ";
    cin >> x_start >> y_start;
    cout << "Enter x2 y2: ";
    cin >> x_end >> y_end;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single buffer
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line");

    init();
    glutDisplayFunc(drawLine);
    glutMainLoop();

    return 0;
}

