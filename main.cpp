#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL/glut.h>
#define ILUT_USE_OPENGL
#include <IL/il.h>
#include <IL/ilut.h>
#include <IL/ilu.h>


using namespace std;

GLuint backgroundTex, moonTex, platformTex;

float plane_s[] = {1.0,0.0,0.0,0.0};
float plane_t[] = {0.0,1.0,0.0,0.0};
const char background[] = "/home/x/c++/OpenGL/1.jpg"; // cube
const char moon[] = "/home/x/c++/OpenGL/2.jpg"; // ball
const char platform[] = "/home/x/c++/OpenGL/3.jpg"; // player

int DevILInit()
{
   if ( ilGetInteger ( IL_VERSION_NUM ) < IL_VERSION )
   {
       fprintf ( stderr, "Incorrect devil.dll version\n" );
       return 0;
   }
   if ( iluGetInteger ( ILU_VERSION_NUM ) < ILU_VERSION )
   {
       fprintf ( stderr, "Incorrect ilu.dll version\n" );
       return 0;
   }
   if ( ilutGetInteger ( ILUT_VERSION_NUM ) < ILUT_VERSION )
   {
       fprintf ( stderr, "Incorrect ilut.dll version\n" );
       return 0;
   }
   ilInit();
   iluInit();
   ilutInit();
}

void initTexture()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

	platformTex = ilutGLLoadImage((char*)platform);
	moonTex = ilutGLLoadImage((char*)moon);
    backgroundTex = ilutGLLoadImage((char*)background);
}


void resize(int w,int h)
{
if (h == 0) h = 1;
float ratio=w*1.0/h;
glViewport(0,0,w,h);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluPerspective(90.0, ratio, 0.1,100);
gluLookAt( 0,0,5, 0,0,0, 1,0,0 );
glMatrixMode( GL_MODELVIEW );
}

int score = 0;
float b_x=0.0, b_y=-2.0;
float p_x=0.0, p_y=-5.4, p_w=1.0;
float border_r=-6, border_l=6;
float s_x=1, s_y=-4;
int speed = 100;
float tap =1.0;

struct cube
{
    int x;
    int y;
};

vector<cube> cubes;

void initCubes(){

cubes.push_back(cube());
cubes[0].x=2;
cubes[0].y=1;

cubes.push_back(cube());
cubes[1].x=-1;
cubes[1].y=0.5;

cubes.push_back(cube());
cubes[2].x=-1;
cubes[2].y=-1;

cubes.push_back(cube());
cubes[3].x=1;
cubes[3].y=0;

cubes.push_back(cube());
cubes[4].x=0;
cubes[4].y=0;

cubes.push_back(cube());
cubes[5].x=0;
cubes[5].y=2;

    cubes.push_back(cube());
    cubes[6].x=1;
    cubes[6].y=2;

    cubes.push_back(cube());
    cubes[7].x=2;
    cubes[7].y=2;

    cubes.push_back(cube());
    cubes[8].x=3;
    cubes[8].y=2;
    cubes.push_back(cube());
    cubes[9].x=1;
    cubes[9].y=3;

    cubes.push_back(cube());
    cubes[10].x=2;
    cubes[10].y=3;

    cubes.push_back(cube());
    cubes[11].x=3;
    cubes[11].y=3;


cubes.push_back(cube());
cubes[6].x=1;
cubes[6].y=2;

}

void display(void)
{
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
glEnable(GL_TEXTURE_2D);


glPushMatrix();
glEnable(GL_TEXTURE_GEN_S);
glEnable(GL_TEXTURE_GEN_T);
glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_s);
glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_t);
glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

glBindTexture(GL_TEXTURE_2D,backgroundTex);
    for(int i=0;i<cubes.size();i++){
        glPushMatrix();
            glTranslatef(cubes[i].y,cubes[i].x,0.0);
            glutSolidCube(0.9);
        glPopMatrix();
    }

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,moonTex);
        glTranslatef(b_y,b_x,0.0);
        glutSolidSphere(0.2,20,20);
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,platformTex);
        glTranslatef(p_y,p_x,0.0);
        glutSolidCube(p_w);
    glPopMatrix();
glDisable(GL_TEXTURE_GEN_S);
glDisable(GL_TEXTURE_GEN_T);
glPopMatrix();

glDisable(GL_TEXTURE_2D);
glutSwapBuffers();
}

bool crash(cube c){
    if((b_x - c.x)*(b_x - c.x) + (b_y - c.y)*(b_y - c.y) - (1 + 0.45)>0){
        return false;
    }else{
        return true;
    }
}

void moving(void)
{
b_x+=s_x/1000*speed;

if(b_x>border_l||b_x<border_r){
    s_x*=(-1);
    b_x+=s_x/1000*speed;
    cout<<"b_x>border_l||b_x<border_r"<<"\n";
}
b_y+=s_y/1000*speed;
if(b_y>=5){
    s_y*=(-1);
    b_y+=s_y/1000*speed;
    cout<<"b_y>=5"<<"\n";

}else{
    if(b_y<=p_y+p_w&&b_x>=p_x-p_w&&b_x<=p_x+p_w){
    s_y=p_y-b_y;
    s_x=b_x-p_x;
    s_y*=(-1);
    b_y+=s_y/1000*speed;
        cout<<"b_y<=p_y+p_w&&b_x>=p_x-p_w&&b_x<=p_x+p_w"<<"\n";

    }
}
if(b_y<=p_y){
    glutIdleFunc(NULL);
    b_x=0.0;
    b_y=-2.0;
    s_x=0.0;
    p_x=0.0;
    cout<<"b_y<=p_y"<<"\n";

}

 for(int i=0;i<cubes.size();i++){
    if(crash(cubes[i])){
        cubes.erase(cubes.begin() + i);
        s_x*=(-1);
        s_y*=(-1);
        score++;

        if (cubes.size() == 0) {
            cout<<"YOU WIN";
            exit (0);
        }
        else{
            cout<<"score:  " << score <<"Живих залишилося: "<<cubes.size() << "\n";
        }
    }

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
    case 'a':
        if(p_x+tap<=border_l)p_x+=tap;
    break;
    case 'd':
        if(p_x-tap>=border_r)p_x-=tap;
    break;
    case ' ':
        glutIdleFunc(moving);
    break;
}
}

void arrow_keys (int keys,int x,int y)
{
    switch(keys){
    case GLUT_KEY_UP: glutFullScreen(); break;
    case GLUT_KEY_DOWN :glutReshapeWindow(800,600); break;
    }
}

int main(int argc, char **argv) {
initCubes();
glutInit(&argc, argv);
glutInitWindowPosition(50, 50);
glutInitWindowSize(640, 480);
glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
glutCreateWindow("Lab 7");
DevILInit();
initTexture();
glutIdleFunc(display);
glutDisplayFunc(display);
glutReshapeFunc(resize);
glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
glutSpecialFunc(arrow_keys);

glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);

glutMainLoop();
}
