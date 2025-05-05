#include <GL/glut.h>
#include <iostream>
using namespace std;

float triangle[3][2] = {
    {100, 100},
    {150, 200},
    {200, 100}
};

void drawTriangle(float points[3][2]) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}

void reflectTriangle(float output[3][2]) {
    for (int i = 0; i < 3; i++) {
        output[i][0] = triangle[i][0];           // X remains same
        output[i][1] = -triangle[i][1] + 300;    // Reflect across y = 150
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);       // Red original triangle
    drawTriangle(triangle);

    float reflected[3][2];
    reflectTriangle(reflected);

    glColor3f(0.0, 1.0, 1.0);       // Cyan reflected triangle
    drawTriangle(reflected);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    gluOrtho2D(0, 640, 0, 480);       // 2D orthographic projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Reflection");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

