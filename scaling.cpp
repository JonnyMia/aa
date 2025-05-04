#include <GL/gl.h>
#include <GL/glut.h>
float triangle[3][2] = {
{100,100},
{150,200},
{200,100}
};
float sx = 1.5, sy = 1.5;
void drawTriangle(float points[3][2]){
glBegin(GL_TRIANGLES);
for(int i = 0;i < 3;i++){
glVertex2f(points[i][0],points[i][1]);
}
glEnd();
}
void scaling(float output[3][2]){
for(int i = 0;i < 3;i++){
output[i][0] = triangle[i][0] * sx;
output[i][1] = triangle[i][1] * sy;
}
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
// Original Triangle:- (RED)
glColor3f(1.0,0.0,0.0);
drawTriangle(triangle);
// Scaled Triangle:- (BLUE)
glColor3f(0.0,0.0,1.0);
float scale[3][2];
scaling(scale);
drawTriangle(scale);glFlush();
}
void myinit(){
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,640,0,480);
}
int main(int argc,char ** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("Translation");
myinit();
glutDisplayFunc(display);
glutMainLoop();
}
