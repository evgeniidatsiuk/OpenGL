#include <iostream>
#include <assert.h>
#include "math.h"
#include <GL/glut.h>

#include "Breakout.h"


Breakout game;

void myDisplay()
{
    game.display();
}

void myReshape(int width, int height)
{
    game.reshape(width, height);
}

void myMouseClick(int button, int state, int x, int y)
{
    game.mouseClick(button, state, x, y);
}

void myMouseMove(int x, int y)
{
    game.mouseMove(x, y);
}

void myKeyStroke(unsigned char key, int x, int y)
{
    game.keyStroke(key, x, y);
}

void mySpecialKeyStroke(int key, int x, int y)
{
    game.specialKeyPos(key, x, y);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);

    glutInitWindowSize(WINWIDTH, WINHEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(WINTITLE);

    game.init();

    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouseClick);
    glutPassiveMotionFunc(myMouseMove);
    glutKeyboardFunc(myKeyStroke);
    glutSpecialFunc(mySpecialKeyStroke);
    glutMainLoop();

    return 0;
}