#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;
int x_start, y_start, x_end, y_end; // Renamed variables to avoid conflicts

void display() {
    float dx, dy, x, y, p;
    dx = x_end - x_start;
    dy = y_end - y_start;
    p = (2 * dy) - dx;
    x = x_start;
    y = y_start;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2i(x, y); // Plot the initial point
    glEnd();

    // Bresenham's Line Algorithm
    while (x < x_end) {
        if (p < 0) {
            p = p + (2 * dy);  // Move horizontally
            x++;
        } else {
            p = p + (2 * (dy - dx)); // Move diagonally
            x++;
            y++;
        }

        // Plot the point at (x, y)
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
    glutSwapBuffers();
}

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set the coordinate system
}

int main(int argc, char** argv) {
  
    cout << "Enter x1";
    cin>>x_start;
    cout << "Enter x2";
    cin>>x_end;
    
    cout << "Enter y1";
    cin>>y_start;
    cout << "Enter y2";
    cin>>y_end;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use double buffering and RGB color mode
    glutInitWindowSize(640, 480); // Set window size
    glutCreateWindow("Bresenham's Line Algorithm"); // Create the window

    myinit();
    glutDisplayFunc(display); // Register the display function
    glutMainLoop(); // Start the main loop

    return 0;
}

