#include <string.h>
#include <GL/glut.h>

GLfloat position[] = { 0.0,0.0,0.0, 1.0 };

float digit = 1;
int r = 100;
int loop = 1;
float cx=0.0, cy=0.0, tap = 0.1;
float spin1=0,spin2=45,spin3=90,spin4=135,spin5=180,spin6=225,spin7=270,spin8=315;

void resize(int w, int h)
{
    if (h == 0) h = 1;
    float ratio=w*1.0/h;
    glViewport(0,0,w,h);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(45.0, ratio, 0.1,100);
    gluLookAt( 15,15,15, 0,0,0, 0,1,0 );
    glMatrixMode( GL_MODELVIEW );
}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //сонце

    glPushMatrix();
    glPushMatrix();
    // Для управления свойствами источника света используются команды glLight
    // Параметр light указывает OpenGL для какого источника света задаются параметры.
    // GL_POSITION позиция источника света (по умолчанию источник света направленный)
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glDisable(GL_LIGHTING);
    glTranslatef(cx,0.0,cy);
    glColor3f(1.0,0.8,0.0);
    glutSolidSphere(digit*1*loop,30,30);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    //меркурій

    glPushMatrix();
    glRotatef(spin1,0.0,1.0,0.0);
    glTranslatef(r*0.013,0.0,0.0);
    glColor3f(1.0,0.5,0.0);
    glutSolidSphere(digit*0.03427*loop,10,10);
    glPopMatrix();

    //венера

    glPushMatrix();
    glRotatef(spin2,0.0,1.0,0.0);
    glTranslatef(r*0.024,0.0,0.0);
    glColor3f(0.8,0.8,0.0);
    glutSolidSphere(digit*0.08462*loop,10,10);
    glPopMatrix();

    //земля

    glPushMatrix();

    glRotatef(spin3,0.0,1.0,0.0);
    glTranslatef(r*0.033,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glutSolidSphere(digit*0.08951*loop,10,10);

    // місяць

    glPushMatrix();
    glRotatef(spin2,0.0,0.0,0.0);
    glTranslatef(-r*0.002,0.0,0.0);
  //  glTranslatef(-r*0.002,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glutSolidSphere(digit*0.05,10,10);
    glPopMatrix();

    glPopMatrix();

    //марс

    glPushMatrix();
    glRotatef(spin4,0.0,1.0,0.0);
    glTranslatef(r*0.05,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glutSolidSphere(digit*0.04755*loop,10,10);
    glPopMatrix();

    //Юпітер

    glPushMatrix();
    glRotatef(spin5,0.0,1.0,0.0);
    glTranslatef(r*0.1,0.0,0.0);
    glColor3f(1.0,0.5,1.0);
    glutSolidSphere(digit*1*loop,10,10);
    glPopMatrix();

    //Сатурн

    glPushMatrix();
    glRotatef(spin6,0.0,1.0,0.0);
    glTranslatef(r*0.12,0.0,0.0);
    glColor3f(1.0,0.5,0.0);
    glutSolidSphere(digit*0.8392*loop,10,10);
    glPopMatrix();

    //Уран

    glPushMatrix();
    glRotatef(spin7,0.0,1.0,0.0);
    glTranslatef(r*0.14,0.0,0.0);
    glColor3f(0.0,0.0,0.5);
    glutSolidSphere(digit*0.3566*loop,10,10);
    glPopMatrix();

    //Нептун

    glPushMatrix();
    glRotatef(spin8,0.0,1.0,0.0);
    glTranslatef(r*0.12,0.0,0.0);
    glColor3f(0.0,0.0,0.8);
    glutSolidSphere(digit*0.3357*loop,10,10);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void moving(void)
{
    spin1+=(360.0/88);
    if(spin1>=360){
        spin1=0;
    }
    spin2+=(360.0/225);
    if(spin2>=360){
        spin2=0;
    }
    spin3+=(360.0/365);
    if(spin3>=360){
        spin3=0;
    }
    spin4+=(360.0/686);
    if(spin4>=360){
        spin4=0;
    }
    spin5+=(360.0/4329);
    if(spin5>=360){
        spin5=0;
    }
    spin6+=(360.0/10753);
    if(spin6>=360){
        spin6=0;
    }
    spin7+=(360.0/30667);
    if(spin7>=360){
        spin7=0;
    }
    spin8+=(360.0/60145);
    if(spin8>=360){
        spin8=0;
    }

    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){glutIdleFunc(NULL);}
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){glutIdleFunc(moving);}
}

void keyboard(unsigned char key, int x,int y)
{
    switch(key){
        case 'a': cx=cx-tap; break;
        case 'd': cx=cx+tap; break;
        case 'w': cy=cy-tap; break;
        case 's': cy=cy+tap; break;
        case '2': loop=loop+1;break;
        case '8': loop=loop-1;break;
    }
}

void arrow_keys (int keys,int x,int y)
{
    switch(keys){
        case GLUT_KEY_UP:   glutFullScreen(); break;
        case GLUT_KEY_DOWN: glutReshapeWindow(800,600); break;
    }
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
    glutCreateWindow("SOLLAR SYSTEM");
    glEnable(GL_LIGHT0);

    // змушує колір матеріалу відстежувати поточний колір
    glEnable(GL_COLOR_MATERIAL);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_keys);

    //glEnable(GL_DEPTH_TEST);

    glutIdleFunc(moving);

    glutMainLoop();
}
