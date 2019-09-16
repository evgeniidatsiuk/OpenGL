#include <GL/glut.h>

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // трикутник
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0,1.0,1.0);
//    glVertex3f(-0.25,0.0,0.0);
//    glVertex3f(0.0,0.75,0.0);
//    glVertex3f(0.25,0.0,0.0);
//    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-0.25,0.0,0.0);
    glVertex3f(0.0,0.75,0.0);
    glVertex3f(0.25,0.0,0.0);
    glEnd();


    // лінія
    glLineWidth(2.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0xAAAA);
    glBegin(GL_LINES);
    glVertex2f(-1.50,0.8);
    glVertex2f(1.50,0.8);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // точки
    glPointSize(12);
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.25,0.6,0.0);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(0.0,0.75,0.0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.25,0.6,0.0);
    glEnd();


    // "трапеція"
    glLineWidth(2.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0x00FF);
    glBegin(GL_QUADS);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.5f, -1.0f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.25f, 0.0f);

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("EUGENE");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}