// Sound doesn't work error with the file :-(
///////////////////////////
//Group 20 Graphics Lab 2nd assingment :-)

//1:-) Hesham Omar Mahmoud Ahemd   20200060
//2:-) Motaz Ismail Mohamed        20200544
//3:-) Abdallah Mohamed Hussein    20200235

// including libraries
#include<windows.h>
#include<MMsystem.h>
#include<glut.h>
#include <math.h>
//global variables
float x = 0;
float var1 = 0.0;
float var12 = 0.0;
float var13 = 0.0;
float var14 = 0.0;
float var15 = 0.0;
float var16 = 0.0;
bool timer_run = false;
GLUquadricObj* gl = gluNewQuadric();

void KeyboardActions(unsigned char key, int x, int y) {
    switch (key) {
        //Seperate body parts
    case 'q':
        var1 = 100;
        var12 = 40;
        var13 = -100;
        var14 = -40;
        break;

        //Combine body parts
    case 'w':
        var1 = 0;
        var15 = 0;
        var12 = 0;
        var13 = 0;
        var14 = 0;
        break;

        //Rotate body
    case 'e':
        timer_run = false;
        break;

        //Stop Body Rotation
    case 'r':
        timer_run = true;
        break;


    default:
        break;
    }
    glutPostRedisplay();
}



void AnimationTimer1(int valu) {
    var16 += 10;
    glutPostRedisplay();
    glutTimerFunc(300, AnimationTimer1, 0);
}

void AnimationTimer2(int valu) {
    var15 += 0;
    glutPostRedisplay();
    if (timer_run == true) {
        var15 += 10;
        glutTimerFunc(50, AnimationTimer2, 0);
    }
    else if (timer_run == false) {
        var15 = 0;
        glutTimerFunc(50, AnimationTimer2, 0);
    }
}

void Display() {

    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    ///////////////////////////////////////////////////////////////////////

        //Right shape
    glPushMatrix();
    glTranslated(300, 300, 0);
    glRotated(var16, 0, 0, -1);
    glTranslated(-300, -300, 0);
    glBegin(GL_QUADS);
    glColor3f(0.43f, 0.35f, 0.48f);
    glVertex2f(300, 300);
    glVertex2f(500, 300);
    glVertex2f(470, 200);
    glVertex2f(320, 500);
    glEnd();
    glPopMatrix();

    //Left shape
    glPushMatrix();
    glTranslated(100, 225, 0);
    glRotated(var16, 0, 0, 6);
    glTranslated(-70, -225, 0);
    glBegin(GL_QUADS);
    glColor3f(0.93f, 0.31f, 0.3f);
    glVertex2f(40, 350);
    glVertex2f(100, 380);
    glVertex2f(200, 200);
    glVertex2f(300, 400);
    glEnd();
    glPopMatrix();

    //human body (:-
///////////////////////////////////////////////////////////////////////
    //1) Neck
    glPushMatrix();
    glTranslated(290, 390, 0);
    glRotated(var15, 0, 0, -1);
    glTranslated(-290, -390, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.85f, 0.65f, 0.4f);
    glVertex2f(300, 500);
    glVertex2f(350, 300);
    glVertex2f(250, 300);
    glVertex2f(280, 300);
    glEnd();
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////

        //2) Head Shape
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3d(0.85f, 0.65f, 0.4f);

    int x = 295, y = 520, r = 61;

    double pi = 22.0 / 7.0;

    for (float i = 0; i <= 360; i++)
    {
        glVertex2f(x + sin(i) * r, y + cos(i) * r);
    }
    glEnd();
    glPopMatrix();


    //3) Hair
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.79f, 0.32f, 0);
    glVertex2f(340, 600);
    glVertex2f(250, 600);
    glVertex2f(340, 570);
    glVertex2f(250, 570);
    glVertex2f(200, 600);
    glEnd();
    glPopMatrix();

    //4) Right Eye
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(315, 545);
    glVertex2f(332, 545);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslated(325, 530, 0);
    gluDisk(gl, 0, 7, 10, 10);
    glPopMatrix();

    //5) Left Eye
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(255, 545);
    glVertex2f(272, 545);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslated(265, 530, 0);
    gluDisk(gl, 0, 7, 10, 10);
    glPopMatrix();

    //6) Nose
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -475, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.79f, 0.32f, 0);
    glVertex2f(295, 520);
    glVertex2f(285, 490);
    glVertex2f(305, 490);
    glEnd();
    glPopMatrix();

    //7) Mouth
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(270, 475);
    glVertex2f(330, 475);
    glVertex2f(300, 470);
    glEnd();
    glPopMatrix();

    //BODY DESIGN
///////////////////////////////////////////////////////////////////////
    //1) Main Shape
    glPushMatrix();
    glTranslated(290, 390, 0);
    glRotated(var15, 0, 0, -1);
    glTranslated(-290, -390, 0);
    glBegin(GL_QUADS);
    glColor3f(0.83f, 0.81f, 0.02f);
    glVertex2f(370, 250);
    glVertex2f(210, 250);
    glVertex2f(220, 430);
    glVertex2f(360, 430);
    glEnd();
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////


    //2) left arm
    glPushMatrix();
    glTranslated(var13 + 300, var14 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.83f, 0.81f, 0.02f);
    glVertex2f(170, 250);
    glVertex2f(135, 250);
    glVertex2f(222, 433);
    glEnd();
    glPopMatrix();

    //3) Right arm
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.83f, 0.81f, 0.02f);
    glVertex2f(410, 250);
    glVertex2f(450, 250);
    glVertex2f(360, 430);

    glEnd();
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////
    //4) Left hand
    glPushMatrix();
    glTranslated(var13 + 300, var14 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3d(0.85f, 0.65f, 0.4f);

    x = 153, y = 233, r = 17;

    pi = 22.0 / 7.0;

    for (float i = 0; i <= 370; i++)
    {
        glVertex2f(x + sin(i) * r, y + cos(i) * r);
    }
    glEnd();
    glPopMatrix();

    //5) Right hand
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3d(0.85f, 0.65f, 0.4f);

    x = 430, y = 233, r = 17;

    pi = 22.0 / 7.0;

    for (float i = 0; i <= 370; i++)
    {
        glVertex2f(x + sin(i) * r, y + cos(i) * r);
    }
    glEnd();
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////

    //6) Left leg
    glPushMatrix();
    glTranslated(var13 + 300, var14 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3f(0.21f, 0.31f, 0.44f);
    glVertex2f(260, 50);
    glVertex2f(220, 50);
    glVertex2f(210, 250);
    glVertex2f(295, 250);
    glEnd();
    glPopMatrix();

    //7) Right leg
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3f(0.21f, 0.31f, 0.44f);
    glVertex2f(360, 50);
    glVertex2f(320, 50);
    glVertex2f(295, 250);
    glVertex2f(370, 250);
    glEnd();
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////

    //8) Right shoes
    glPushMatrix();
    glTranslated(var1 + 300, var12 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.05f, 0.02f);
    glVertex2f(320, 50);
    glVertex2f(370, 50);
    glVertex2f(370, 30);
    glVertex2f(320, 30);
    glEnd();
    glPopMatrix();

    //9) Left shoes
    glPushMatrix();
    glTranslated(var13 + 300, var14 + 500, 0);
    glTranslated(-300, -500, 0);
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.05f, 0.02f);
    glVertex2f(260, 50);
    glVertex2f(210, 50);
    glVertex2f(210, 30);
    glVertex2f(260, 30);
    glEnd();
    glPopMatrix();

    glFlush();
}

void main() {
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Group 20 Assingment 2");
    glutDisplayFunc(Display);
    glutKeyboardFunc(KeyboardActions);

    glutTimerFunc(0, AnimationTimer1, 0);
    glutTimerFunc(0, AnimationTimer2, 0);
    glClearColor(255, 255, 255, 0);    glBegin(GL_QUADS);
    glColor3d(0.85f, 0.65f, 0.4f);

    int x = 295, y = 520, r = 61;

    double pi = 22.0 / 7.0;

    for (float i = 0; i <= 360; i++)
    {
        glVertex2f(x + sin(i) * r, y + cos(i) * r);
    }
    glEnd();
    glPopMatrix();
    gluOrtho2D(0, 600, 0, 600);
    glutMainLoop();
}