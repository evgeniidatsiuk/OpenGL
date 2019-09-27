#include<GL/glut.h>

void Init_OpenGL()
{
    // set background color to Black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // set shade model to Flat
   // glShadeModel(GL_FLAT);
}
// Display_Objects() function
void Display_Objects(void)
{
    // clearing the window or remove all drawn objects
    glClear(GL_COLOR_BUFFER_BIT);
    /*glPushMatrix(), which copies the current matrix and adds
    the copy to the top of the stack, and
    glPopMatrix(), which discards the top matrix on the stack*/
    glPushMatrix();
    //the glTranslatef() routine in the display list alters the position of the next object to be drawn
    glTranslatef(0.0, 0.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireOctahedron();

    glPopMatrix();

    glPushMatrix();
    // draw a wire torus
    glTranslatef(-2.4, 1.6, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireTorus(0.1, 0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    // draw a wire torus
    glTranslatef(-1.4, 1.6, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutSolidTorus(0.1, 0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    // draw a wire teapot
    glTranslatef(1.0, 1.6, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireTeapot(0.5);
    glPopMatrix();

    glPushMatrix();
    // draw a solid teapot
    glTranslatef(2.8, 1.6, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutSolidTeapot(0.5);
    glPopMatrix();

    glPushMatrix();
    // draw a wire teapot
    glTranslatef(-2.4, 0.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPushMatrix();
    // draw a solid teapot
    glTranslatef(-1.4, 0.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();

    glPushMatrix();
    // draw a wire teapot
    glTranslatef(2.6, 0.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireSphere(0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
    // draw a solid teapot
    glTranslatef(1.6, 0.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutSolidSphere(0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
    // draw a wire teapot
    glTranslatef(1.4, -1.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutWireCone(0.4, 1.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    // draw a solid teapot
    glTranslatef(-1.4, -1.0, 0.0);
    glColor3f(1.0, 0.3, 1.0);
    glutSolidCone(0.4, 1.5, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}
// Reshape() function
void Reshape(int w, int h)
{
    //adjusts the pixel rectangle for drawing to be the entire new window
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    //matrix specifies the projection transformation
    glMatrixMode(GL_PROJECTION);
    // load the identity of matrix by clearing it.
    glLoadIdentity();
    gluPerspective(70.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    //matrix specifies the modelview transformation
    glMatrixMode(GL_MODELVIEW);
    // again  load the identity of matrix
    glLoadIdentity();
    // gluLookAt() this function is used to specify the eye.
    // it is used to specify the coordinates to view objects from a specific position
      gluLookAt(0, 0, 4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
// main function
int main(int argc, char** argv)
{
    // initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // set window size
    glutInitWindowSize(800, 600);
    // set window location
    glutInitWindowPosition(250, 50);
    // create window with window text
    glutCreateWindow("EUGENE");
    // call Init_OpenGL() function
    Init_OpenGL();
    // call glutDisplayFunc() function & pass parameter as Display_Objects() function
    glutDisplayFunc(Display_Objects);
    // call glutReshapeFunc() function & pass parameter as Reshape() function
    glutReshapeFunc(Reshape);
    //glutMainLoop() is used to redisplay the objects
    glutMainLoop();
    return 0;
}