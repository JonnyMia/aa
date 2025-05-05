#include <GL/glut.h>

bool reflectX = true;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply reflection
    glScalef(reflectX ? 1 : -1, reflectX ? -1 : 1, 1);

    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.5f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int, int) {
    reflectX = (key == 'x' || key == 'X'); // 'x' reflects over X-axis, 'y' over Y-axis
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Reflection");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
