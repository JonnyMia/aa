#include <GL/gl.h>
#include <GL/glut.h>
float flagY = -0.8f;
void drawPole(){
glColor3f(0.0f,0.0f,0.0f);
glBegin(GL_QUADS);
glVertex2f(-0.05f,-0.8f);
glVertex2f(0.05f,-0.8f);
glVertex2f(0.05f,0.8f);
glVertex2f(-0.05f,0.8f);
glEnd();
}void drawFlag(float y){
glColor3f(1.0f,0.0f,0.0f);
glBegin(GL_QUADS);
glVertex2f(0.05f,y);
glVertex2f(0.5f,y);
glVertex2f(0.5f,y + 0.3f);
glVertex2f(0.05f,y + 0.3f);
glEnd();
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
drawPole();
drawFlag(flagY);
glutSwapBuffers();
}
void timer(int value){
if(flagY < 0.4f){
flagY += 0.01f;
glutPostRedisplay();
glutTimerFunc(16,timer,0);
}
}
int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("Flag Hosting Animation");
glClearColor(1.0,1.0,1.0,1.0);
glutDisplayFunc(display);
glutTimerFunc(0,timer,0);
glutMainLoop();
}
