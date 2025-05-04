#include <GL/glut.h>
#include <math.h>  // For fabs (absolute value)

int triangle[3][2] = {
    {200, 100},  // Bottom
    {100, 300},  // Left
    {300, 300}   // Right
};

bool fill = false;  // Flag to fill the triangle after clicking inside

// Function to calculate area of triangle
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// Check if (x, y) point is inside the triangle
bool isInside(int x, int y) {
    float A  = area(triangle[0][0], triangle[0][1],
                    triangle[1][0], triangle[1][1],
                    triangle[2][0], triangle[2][1]);

    float A1 = area(x, y, triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1]);
    float A2 = area(triangle[0][0], triangle[0][1], x, y, triangle[2][0], triangle[2][1]);
    float A3 = area(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1], x, y);

    return (A == A1 + A2 + A3);
}

// Draw triangle (filled or just outline)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (fill)
        glColor3f(0.3, 0.7, 1.0); // Fill with blue
    else
        glColor3f(0, 0, 0);       // Outline in black

    glBegin(fill ? GL_TRIANGLES : GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
        glVertex2i(triangle[i][0], triangle[i][1]);
    glEnd();

    glFlush();
}

// Mouse click function
void mouse(int button, int state, int mx, int my) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        my = 480 - my; // Convert Y from window to OpenGL
        if (isInside(mx, my)) {
            fill = true;
            glutPostRedisplay(); // Redraw the screen
        }
    }
}

// Setup OpenGL
void init() {
    glClearColor(1, 1, 1, 1);    // White background
    gluOrtho2D(0, 640, 0, 480);  // 2D view
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Click Inside Triangle to Fill");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

