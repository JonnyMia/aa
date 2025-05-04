#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
int xc, yc, r;
void plotCirclePoints(int x, int y) {
glBegin(GL_POINTS);
glVertex2i(xc + x, yc + y);
glVertex2i(xc - x, yc + y);
glVertex2i(xc + x, yc - y);
glVertex2i(xc - x, yc - y);glVertex2i(xc + y, yc + x);
glVertex2i(xc - y, yc + x);
glVertex2i(xc + y, yc - x);
glVertex2i(xc - y, yc - x);
glEnd();
}
void MidpointCircle() {
int x = 0, y = r;
int p = 1 - r; // Initial decision parameter
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
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
MidpointCircle();
glFlush();
glutSwapBuffers();
}
void myinit() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char **argv) {
xc = 200, yc = 200, r = 80;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutCreateWindow("Midpoint Circle Drawing Algorithm");
myinit();
glutDisplayFunc(display);
glutMainLoop();
}
