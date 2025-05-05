#include <GL/glut.h>

// Scaling variables
float scale = 1.0f;
bool growing = true;

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(scale, scale, 1.0f);

    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.6f, 1.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glutSwapBuffers();
}

// Timer function for animation
void timer(int) {
    scale += (growing ? 0.01f : -0.01f);

    if (scale >= 1.5f || scale <= 0.5f)
        growing = !growing;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Scaling Animation");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
