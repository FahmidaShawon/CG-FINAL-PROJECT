#include <windows.h>
#include <iostream>
#include<mmsystem.h>
#include <GL\glut.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.1416
#include <GL/gl.h>

using namespace std;


GLint i;
GLfloat p1 = 0.0f;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0,ar=0,cr=0,cr1=0,bs=0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
GLfloat spin1 = 0.0;
GLfloat spin2 = 0.0;
GLfloat spin3 = 0.0;
GLfloat spin4 = 0.0;

int ldr=255,ldg=255,ldb=255;

char Airport[] = "AIRPORT";
void print_Night( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(255, 255, 255);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void sound()
{

    PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}
void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void init(void)
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, -250.0, 900.0);
}

////*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}
void Tree_One_Model()
{
    glColor3f(0.3, 0,0);
    glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
    glEnd();

}
void HotelBelowWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}
void Hotel()
{

    glColor3ub(122,88,86);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();

    glColor3ub(70,130,180);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();

    glColor3ub(75,0,130);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();
    glPopMatrix();

    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();

     int HotelBelowStripe1=-430;
    for(int i=7;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,295);
    }
}

void Door()
{
    glColor3ub(8,32,19);
       // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();


}
void Hotel_position()
{
    glPushMatrix();
    glTranslatef(-360,-306,0);
    Hotel();
    Door();
    glPopMatrix();
}





void Hospital()
{
    int HospitalStripe1=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe1+=20;
    }

    int HospitalStripe2=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe2+=20;
    }

    int HospitalStripe3=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe3+=20;
    }


    int HospitalStripe4=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe4+=14;
    }

    int HospitalStripe5=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe5+=14;
    }

     int HospitalStripe6=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe6+=14;
    }
    glutPostRedisplay();
}

void Hospital_position()
{
    glPushMatrix();
    glTranslatef(220,-306,0);
    Hospital();
    glPopMatrix();

}

void LampPost()
{
    for(int i=0;i<10*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS); // thin line
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS); //last black part of stand
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS); // black stand
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS); // white circle bottom black
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
       glColor3ub(ldr,ldg,ldb);
        drawCircle(43+i,218,9);
        glPopMatrix();
    }
}
void Lampost_position()
{
    glPushMatrix();
    glTranslatef(0,-309,0);
    LampPost();
    glPopMatrix();
}

void SchoolWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School()
{
    glPushMatrix();
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,328);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,282);
    }

}
void SchoolDoor()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void School_position()
{
    glPushMatrix();
    glTranslatef(110,-306,0);
    School();
    SchoolDoor();
    glPopMatrix();
}

void Tree_One(){

    glPushMatrix();
    glTranslatef(0,-400,0);
    Tree_One_Model();
    glPopMatrix();
}

void Tree_Two(){
    glPushMatrix();
    glTranslatef(260,-400,0);
    Tree_One_Model();
    glPopMatrix();
}

void Tree_Three(){

    glPushMatrix();
    glTranslatef(665,-400,0);
    Tree_One_Model();
    glPopMatrix();
}

//// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(200,840,0);
    circle(30);
    glPopMatrix();
}
////*** Airplane model***///
void airplane_model()
{
    ////Airplane body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(5, 450);
	glVertex2i(30, 450);
	glVertex2i(45, 420);
	glVertex2i(5, 420);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 1.5);
	glVertex2i(5, 420);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(160, 410);
	glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glVertex2i(5, 420);
	glEnd();
    //./Airplane lower red part
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.0, 0.0);
    glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glEnd();
    ////Airplane windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(140, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 415);
	glVertex2i(105, 415);
	glVertex2i(105, 410);
	glVertex2i(100, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(110, 415);
	glVertex2i(115, 415);
	glVertex2i(115, 410);
	glVertex2i(110, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 415);
	glVertex2i(95, 415);
	glVertex2i(95, 410);
	glVertex2i(90, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 415);
	glVertex2i(85, 415);
	glVertex2i(85, 410);
	glVertex2i(80, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(70, 415);
	glVertex2i(75, 415);
	glVertex2i(75, 410);
	glVertex2i(70, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 415);
	glVertex2i(65, 415);
	glVertex2i(65, 410);
	glVertex2i(60, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(50, 415);
	glVertex2i(55, 415);
	glVertex2i(55, 410);
	glVertex2i(50, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(40, 415);
	glVertex2i(45, 415);
	glVertex2i(45, 410);
	glVertex2i(40, 410);
	glEnd();
    ////Airplane wings
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 420);
	glVertex2i(60, 435);
	glVertex2i(80, 435);
	glVertex2i(95, 420);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 390);
	glVertex2i(60, 375);
	glVertex2i(80, 375);
	glVertex2i(95, 390);
	glEnd();
}


////*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);
    ////Top_Left
    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ////Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ////Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ////middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ////Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ////Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ////Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ////Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();

}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ////Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ////Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ////Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ////Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();


}

////*** House_Model ***///
void house(){
    ////House

    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
	glVertex2i(190, 70);
	glVertex2i(190, 330);
	glVertex2i(570, 330);
	glVertex2i(570, 70);
	glEnd();

    ////House_Door
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	glVertex2i(350, 70);
	glVertex2i(350, 150);
	glVertex2i(420, 150);
	glVertex2i(420, 70);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
	glVertex2i(360, 70);
	glVertex2i(360, 140);
	glVertex2i(410, 140);
	glVertex2i(410, 70);
	glEnd();
	//door roof
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	glVertex2i(330, 150);
	glVertex2i(385, 200);
	glVertex2i(440, 150);
	glEnd();
	//----L

	glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
	glVertex2i(200, 75);
	glVertex2i(200, 340);
	glVertex2i(220, 340);
	glVertex2i(220, 75);
	glEnd();
//---------L1--------------
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 75);
	glVertex2i(265, 120);
	glVertex2i(305, 120);
	glVertex2i(305, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 75);
	glVertex2i(225, 120);
	glVertex2i(255, 120);
	glVertex2i(255, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(312, 75);
	glVertex2i(312, 120);
	glVertex2i(337, 120);
	glVertex2i(337, 75);
	glEnd();

//----------------LB---------------------

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 130);
	glVertex2i(265, 170);
	glVertex2i(305, 170);
	glVertex2i(305, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 130);
	glVertex2i(225, 170);
	glVertex2i(255, 170);
	glVertex2i(255, 130);
	glEnd();

    //------L3N-----------------

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 180);
	glVertex2i(265, 220);
	glVertex2i(305, 220);
	glVertex2i(305, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 180);
	glVertex2i(225, 220);
	glVertex2i(255, 220);
	glVertex2i(255, 180);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(312, 180);
	glVertex2i(312, 220);
	glVertex2i(337, 220);
	glVertex2i(337, 180);
	glEnd();


	//---------------------------L

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(435, 75);
	glVertex2i(435, 120);
	glVertex2i(460, 120);
	glVertex2i(460, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 75);
	glVertex2i(465, 120);
	glVertex2i(490, 120);
	glVertex2i(490, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 75);
	glVertex2i(495, 120);
	glVertex2i(520, 120);
	glVertex2i(520, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 75);
	glVertex2i(525, 120);
	glVertex2i(550, 120);
	glVertex2i(550, 75);
	glEnd();
/*---------------L3----------------------*/
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 130);
	glVertex2i(465, 170);
	glVertex2i(490, 170);
	glVertex2i(490, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 130);
	glVertex2i(495, 170);
	glVertex2i(520, 170);
	glVertex2i(520, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 130);
	glVertex2i(525, 170);
	glVertex2i(550, 170);
	glVertex2i(550, 130);
	glEnd();

	//-------------L4-------------------------
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(435, 180);
	glVertex2i(435, 225);
	glVertex2i(460, 225);
	glVertex2i(460, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 180);
	glVertex2i(465, 225);
	glVertex2i(490, 225);
	glVertex2i(490, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 180);
	glVertex2i(495, 225);
	glVertex2i(520, 225);
	glVertex2i(520, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 180);
	glVertex2i(525, 225);
	glVertex2i(550, 225);
	glVertex2i(550, 180);
	glEnd();
////----------top----

glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
	glVertex2i(200, 230);
	glVertex2i(200, 250);
	glVertex2i(570, 250);
	glVertex2i(570, 230);
	glEnd();


}

void road_model()
{
    glBegin(GL_QUADS);
    glColor3f(0.658824 , 0.658824 , 0.658824);
	glVertex2i(0,0);
	glVertex2i(0,-250);
	glVertex2i(1000,-250);
	glVertex2i(1000, 0);
	glEnd();
	//-------------------------------/
	glBegin(GL_QUADS);
    glColor3f(0.658824 , 0.658824 , 0.658824);
	glVertex2i(400,0);
	glVertex2i(400,50);
	glVertex2i(450,50);
	glVertex2i(450, 0);
	glEnd();
}
void RoadCorner1()
{
    for(int i=0;i<360;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
    for(int i=440;i<590;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
    for(int i=680;i<1000;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }

}

void RoadCorner2()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255); // bottom white part on zebra cross
        glBegin(GL_QUADS);
        glVertex2i(0+i,48); //148-100
        glVertex2i(16+i,48);
        glVertex2i(16+i,57); //157-100
        glVertex2i(0+i,57);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);    // bottom black part on zebra cross
        glBegin(GL_QUADS);
        glVertex2i(16+i,48); //148-100
        glVertex2i(39+i,48);
        glVertex2i(39+i,57); //157-100
        glVertex2i(16+i,57);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1_position()
{
    glPushMatrix();
    glTranslatef(0,-200,0);
    RoadCorner1();
    glPopMatrix();
}

void RoadCorner2_position()
{
    glPushMatrix();
    glTranslatef(0,-300,0);
    RoadCorner2();
    glPopMatrix();
}

void car_model_1()
{
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(10, -10);
	glVertex2i(80, -10);
	glVertex2i(95, -40);
	glVertex2i(95, -80);
	glVertex2i(10, -80);
	glEnd();
	//
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2i(95, -40);
	glVertex2i(125, -40);
	glVertex2i(135, -80);
	glVertex2i(95, -80);
	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(15, -15);
	glVertex2i(40, -15);
	glVertex2i(40, -40);
	glVertex2i(15, -40);
	glEnd();

	//window2
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(50, -15);
	glVertex2i(78, -15);
	glVertex2i(90, -40);
	glVertex2i(50, -40);
	glEnd();

	//line
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(9,-80 );
	glVertex2i(136,-80);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle(15);
    glPopMatrix();
    //circle small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle(10);
    glPopMatrix();

    //circle2

	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle(15);
    glPopMatrix();
    //circle2 small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle(10);
    glPopMatrix();
}

void car_model_2()
{
    glBegin(GL_POLYGON);
	glColor3f(0, 255, 255);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(280, -110);
	glVertex2i(480, -110);
	glVertex2i(480, -15);
	glEnd();
	//tringle
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(300, -52);
	glEnd();
	//square
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(305, -25);
	glVertex2i(305, -52);
	glVertex2i(470, -52);
	glVertex2i(470, -25);
	glEnd();
//big square
    glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2i(305, -28);
	glVertex2i(325, -28);
	glVertex2i(325, -60);
	glVertex2i(305, -60);
	glEnd();
	//big square white
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(325, -28);
	glVertex2i(340, -28);
	glVertex2i(340, -80);
	glVertex2i(325, -80);
	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(345, -28);
	glVertex2i(380, -28);
	glVertex2i(380, -50);
	glVertex2i(345, -50);
	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(385, -28);
	glVertex2i(415, -28);
	glVertex2i(415, -50);
	glVertex2i(385, -50);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(310,-110,0);
    circle(15);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(450,-110,0);
    circle(15);
    glPopMatrix();
}

////*** Field_Model ***///

void field(){
    ////Field
	glBegin(GL_POLYGON);
	glColor3f( 0.0 , 0.80 ,0.0);
	glVertex2i(0, 50);
	glVertex2i(0, 200);// ch=70to 200
	glVertex2i(1000, 200); //    ||
	glVertex2i(1000, 50);
	glEnd();
	//------tree

	glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(250, 180);
	glVertex2i(260, 180);
	glVertex2i(260, 280);
	glVertex2i(250, 280);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(250,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(260,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(270,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(240,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(245,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(265,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(255,300,0);
    circle(12);
    glPopMatrix();
//-------------------------
	glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(850, 180);
	glVertex2i(870, 180);
	glVertex2i(870, 280);
	glVertex2i(850, 280);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(850,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(860,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(870,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(840,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,300,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(885,280,0);
    circle(12);
    glPopMatrix();
     glPushMatrix();
    glTranslatef(885,300,0);
    circle(12);
    glPopMatrix();
 glPushMatrix();
    glTranslatef(875,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(855,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,310,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(855,330,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,330,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(860,340,0);
    circle(12);
    glPopMatrix();


//-------------------
glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(150, 150);
	glVertex2i(160, 150);
	glVertex2i(160, 250);
	glVertex2i(150, 250);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(150,250,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(180,250,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(140,250,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(170,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(175,260,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160,260,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(150,270,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160,250,0);
    circle(12);
    glPopMatrix();


    ////Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub(50,205,50);
	glVertex2i(0, -50);  //change
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, -50); //change
	glEnd();
	//----------------road-L----
	glBegin(GL_POLYGON);
	glColor3f(0.658824 , 0.658824 , 0.65882);
	glVertex2i(380, -50);
	glVertex2i(420, 200);
	glVertex2i(470, 200);
	glVertex2i(440, -50);
	glEnd();
//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(450, -50);
	glVertex2i(465, 100);
	glVertex2i(457, 100);
	glVertex2i(440, -50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(370, -50);
	glVertex2i(410, 200);
	glVertex2i(420, 200);
	glVertex2i(380, -50);
	glEnd();


	//-------------------Road-R-----
	glBegin(GL_POLYGON);
	glColor3f(0.658824 , 0.658824 , 0.65882);
	glVertex2i(610, -50);
	glVertex2i(590, 200);
	glVertex2i(640, 200);
	glVertex2i(680, -50);
	glEnd();

	//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(680, -50);
	glVertex2i(640, 200);
	glVertex2i(650, 200);
	glVertex2i(690, -50);
	glEnd();

	//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(610, -50);
	glVertex2i(599, 100);
	glVertex2i(589, 100);
	glVertex2i(600, -50);
	glEnd();

	//-------------------front------
	glBegin(GL_POLYGON);
	glColor3f(0.658824 , 0.658824 , 0.65882);
	glVertex2i(450, 100);
	glVertex2i(450, 200);
	glVertex2i(600, 200);
	glVertex2i(600, 100);
	glEnd();

	//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(455, 90);
	glVertex2i(590, 90);
	glVertex2i(590, 100);
	glVertex2i(465, 100);
	glEnd();
	//---Car
	glBegin(GL_POLYGON); //body
	glColor3ub(0 , 255 , 255);
	glVertex2i(470, 150);
	glVertex2i(470, 200);
	glVertex2i(475, 250);
	glVertex2i(520, 250);
	glVertex2i(530, 200);
	glVertex2i(550, 200);
	glVertex2i(555, 150);
	glEnd();

glBegin(GL_POLYGON); //window
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(475, 200);
	glVertex2i(480, 245);
	glVertex2i(495, 245);
	glVertex2i(495, 200);
	glEnd();
glBegin(GL_POLYGON); //window
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(500, 200);
	glVertex2i(500, 245);
	glVertex2i(518, 245);
	glVertex2i(525, 200);
	glEnd();

	glBegin(GL_POLYGON); //bumper
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(470, 150);
	glVertex2i(470, 155);
	glVertex2i(555, 155);
	glVertex2i(555, 150);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(490,155,0);
    circle(12);
    glPopMatrix();
    //circle
	glColor3ub(255, 255, 255);
	glPushMatrix();
    glTranslatef(490,155,0);
    circle(10);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(535,155,0);
    circle(12);
    glPopMatrix();
    //circle
	glColor3ub(255, 255, 255);
	glPushMatrix();
    glTranslatef(535,155,0);
    circle(10);
    glPopMatrix();

}

//// Tree model updated

void Tree_Model_circle_2(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(141, 47, 47); //dark red
	glVertex2f(133, 125);
	glVertex2f(133, 92);
    glEnd();

    glColor3f( 0, 0.198039,0);
    glBegin(GL_POLYGON);
	glVertex2f(123, 123);
	glVertex2f(134, 147);
	glVertex2f(147, 123);

	glEnd();

}

////*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(-spin4,0,0,90);
    Sun_Model();
    glPopMatrix();
}

////*** Cloud_One_Model_One ***///
void airplane(){
    glPushMatrix();
    glTranslatef(ar-300,200,0);
    airplane_model();
    glPopMatrix();

}

////*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,500,0);
    cloud_model_one();
    glPopMatrix();

}

////*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,300,0);
    cloud_model_one();
    glPopMatrix();

}

////*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,400,0);
    cloud_model_Two();
    glPopMatrix();

}
////*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,610,0);
    cloud_model_Two();
    glPopMatrix();

}
////*** Cloud_Five_Model_Three ***///
void cloud_five()
{
    glPushMatrix();
    glTranslatef(ax-300,456,0);
    cloud_model_Three();
    glPopMatrix();
}
////*** Cloud_Six_Model_Three ***///
void cloud_six()
{
    glPushMatrix();
    glTranslatef(cx+500,340,0);
    cloud_model_Three();
    glPopMatrix();
}
void house_three()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house();
    glPopMatrix();
}
void car_1(){
    glPushMatrix();
    glTranslatef(cr-200,-50,0);
    car_model_1();
    glPopMatrix();
}


void Bus(){
    glPushMatrix();
    glTranslatef(bs+800,-135,0);
    car_model_2();
    glPopMatrix();

}

////*** Night Function Start***///

////*** Circle_Model***///
void circle_Night(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
void drawCircle_Night(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}


void Tree_One_Model_Night()
{
    glColor3ub(139,69,19);
    glBegin(GL_POLYGON);
    glVertex3i(50, 350, 0);
    glVertex3i(70, 350, 0);
    glVertex3i(70, 500, 0);
    glVertex3i(50, 500, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex3i(10, 500, 0);
    glVertex3i(110, 500, 0);
    glVertex3i(60, 600, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(15, 550, 0);
    glVertex3i(105, 550, 0);
    glVertex3i(60, 650, 0);
    glEnd();

}
void HotelBelowWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(5,150,155);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}

void Hotel_Night()
{

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();

    glColor3ub(23,60,43);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();


    glColor3ub(15,47,106);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();
    glPopMatrix();

    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();

     int HotelBelowStripe1=-430;
    for(int i=7;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1_Night(HotelBelowStripe1,267);
    }

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1_Night(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1_Night(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1_Night(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1_Night(HotelAboveStripe4,295);
    }
}

void Door_Night()
{
    glColor3ub(8,402,19);
       // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();
     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();


}
void Hotel_position_Night()
{
    glPushMatrix();
    glTranslatef(-360,-306,0);
    Hotel_Night();
    Door_Night();
    glPopMatrix();
}

void HospitalMidWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}

void Hospital_Night()
{
    int HospitalStripe1=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe1+=20;
    }

    int HospitalStripe2=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe2+=20;
    }

    int HospitalStripe3=163;
    for(int i=11;i>=0;i--)
    {
        HospitalStripe3+=20;
    }
    int HospitalStripe4=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe4+=14;
    }

    int HospitalStripe5=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe5+=14;
    }

     int HospitalStripe6=260;
    for(int i=3;i>=0;i--)
    {
        HospitalStripe6+=14;
    }
    glutPostRedisplay();
}

void Hospital_position_Night()
{
    glPushMatrix();
    glTranslatef(220,-306,0);
    Hospital_Night();

    glPopMatrix();

}

void LampPost_Night()
{
    for(int i=0;i<10*115;i+=115)
    {
        glPushMatrix();
        glColor3ub(150,177,144);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255,200,255);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(100,50,10);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(ldr,ldg,ldb);
        drawCircle_Night(43+i,218,9);
        glPopMatrix();
    }
}
void Lampost_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-309,0);
    LampPost_Night();
    glPopMatrix();
}

void SchoolWindow1_Night(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School_Night()
{
    glPushMatrix();
    glColor3ub(214,530,520);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle_Night(762.0f,369.0f,10.0f);

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1_Night(SchoolStripe1,328);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1_Night(SchoolStripe2,304);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1_Night(SchoolStripe3,281);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1_Night(SchoolStripe4,328);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1_Night(SchoolStripe5,304);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1_Night(SchoolStripe6,282);
    }
}
void SchoolDoor_Night()
{
    glPushMatrix();
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,304);
    glVertex2i(792,304);
    glVertex2i(792,321);
    glVertex2i(733,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
    glPopMatrix();
}

void School_position_Night()
{
    glPushMatrix();
    glTranslatef(110,-306,0);
    School_Night();
    SchoolDoor_Night();
    glPopMatrix();
}

void Tree_One_Night(){
    glPushMatrix();
    glTranslatef(0,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();
}
void Tree_Two_Night(){
    glPushMatrix();
    glTranslatef(260,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();
}

void Tree_Three_Night(){

    glPushMatrix();
    glTranslatef(665,-400,0);
    Tree_One_Model_Night();
    glPopMatrix();
}

void Moon_Night()
{
    glPushMatrix();
    glColor3ub(247, 245, 245);
    drawCircle_Night(740.0f,640.0f,40.0f);
    glColor3ub(247, 245, 245);
    drawCircle_Night(740.0f,640.0f,40.0f);
    glPopMatrix();
}

void Moon_Night_Position()
{
    glPushMatrix();
    glTranslatef(-500,180,0);
    Moon_Night();
    glPopMatrix();
}
////*** Airplane model***///
void airplane_model_Night()
{
    //Airplane body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(5, 450);
	glVertex2i(30, 450);
	glVertex2i(45, 420);
	glVertex2i(5, 420);
	glEnd();
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 1.5);
	glVertex2i(5, 420);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(160, 410);
	glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glVertex2i(5, 420);
	glEnd();
    //Airplane lower red part
	glBegin(GL_POLYGON);
    glColor3f(0.8, 0.0, 0.0);
    glVertex2i(165, 400);
	glVertex2i(160, 390);
	glVertex2i(15, 390);
	glVertex2i(5, 400);
	glEnd();
    //Airplane windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(140, 420);
	glVertex2i(150, 410);
	glVertex2i(140, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 415);
	glVertex2i(105, 415);
	glVertex2i(105, 410);
	glVertex2i(100, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(110, 415);
	glVertex2i(115, 415);
	glVertex2i(115, 410);
	glVertex2i(110, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(90, 415);
	glVertex2i(95, 415);
	glVertex2i(95, 410);
	glVertex2i(90, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 415);
	glVertex2i(85, 415);
	glVertex2i(85, 410);
	glVertex2i(80, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(70, 415);
	glVertex2i(75, 415);
	glVertex2i(75, 410);
	glVertex2i(70, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(60, 415);
	glVertex2i(65, 415);
	glVertex2i(65, 410);
	glVertex2i(60, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(50, 415);
	glVertex2i(55, 415);
	glVertex2i(55, 410);
	glVertex2i(50, 410);
	glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
	glVertex2i(40, 415);
	glVertex2i(45, 415);
	glVertex2i(45, 410);
	glVertex2i(40, 410);
	glEnd();
    //Airplane wings
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 420);
	glVertex2i(60, 435);
	glVertex2i(80, 435);
	glVertex2i(95, 420);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
	glVertex2i(65, 390);
	glVertex2i(60, 375);
	glVertex2i(80, 375);
	glVertex2i(95, 390);
	glEnd();
}


//*** House_Model ***///

void house_Night(){

    ////House

    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
	glVertex2i(190, 70);
	glVertex2i(190, 330);
	glVertex2i(570, 330);
	glVertex2i(570, 70);
	glEnd();

    ////House_Door
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	glVertex2i(350, 70);
	glVertex2i(350, 150);
	glVertex2i(420, 150);
	glVertex2i(420, 70);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
	glVertex2i(360, 70);
	glVertex2i(360, 140);
	glVertex2i(410, 140);
	glVertex2i(410, 70);
	glEnd();
	//door roof
	glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
	glVertex2i(330, 150);
	glVertex2i(385, 200);
	glVertex2i(440, 150);
	glEnd();
	//----L

	glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
	glVertex2i(200, 75);
	glVertex2i(200, 340);
	glVertex2i(220, 340);
	glVertex2i(220, 75);
	glEnd();
//---------L1--------------
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 75);
	glVertex2i(265, 120);
	glVertex2i(305, 120);
	glVertex2i(305, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 75);
	glVertex2i(225, 120);
	glVertex2i(255, 120);
	glVertex2i(255, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(312, 75);
	glVertex2i(312, 120);
	glVertex2i(337, 120);
	glVertex2i(337, 75);
	glEnd();

//----------------LB---------------------

glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 130);
	glVertex2i(265, 170);
	glVertex2i(305, 170);
	glVertex2i(305, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 130);
	glVertex2i(225, 170);
	glVertex2i(255, 170);
	glVertex2i(255, 130);
	glEnd();

    //------L3N-----------------

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(265, 180);
	glVertex2i(265, 220);
	glVertex2i(305, 220);
	glVertex2i(305, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(225, 180);
	glVertex2i(225, 220);
	glVertex2i(255, 220);
	glVertex2i(255, 180);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(312, 180);
	glVertex2i(312, 220);
	glVertex2i(337, 220);
	glVertex2i(337, 180);
	glEnd();


	//---------------------------L

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(435, 75);
	glVertex2i(435, 120);
	glVertex2i(460, 120);
	glVertex2i(460, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 75);
	glVertex2i(465, 120);
	glVertex2i(490, 120);
	glVertex2i(490, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 75);
	glVertex2i(495, 120);
	glVertex2i(520, 120);
	glVertex2i(520, 75);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 75);
	glVertex2i(525, 120);
	glVertex2i(550, 120);
	glVertex2i(550, 75);
	glEnd();
/*---------------L3----------------------*/
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 130);
	glVertex2i(465, 170);
	glVertex2i(490, 170);
	glVertex2i(490, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 130);
	glVertex2i(495, 170);
	glVertex2i(520, 170);
	glVertex2i(520, 130);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 130);
	glVertex2i(525, 170);
	glVertex2i(550, 170);
	glVertex2i(550, 130);
	glEnd();

	//-------------L4-------------------------
	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(435, 180);
	glVertex2i(435, 225);
	glVertex2i(460, 225);
	glVertex2i(460, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(465, 180);
	glVertex2i(465, 225);
	glVertex2i(490, 225);
	glVertex2i(490, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(495, 180);
	glVertex2i(495, 225);
	glVertex2i(520, 225);
	glVertex2i(520, 180);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2i(525, 180);
	glVertex2i(525, 225);
	glVertex2i(550, 225);
	glVertex2i(550, 180);
	glEnd();
////----------top----

glBegin(GL_POLYGON);
    glColor3ub(255,160,122);
	glVertex2i(200, 230);
	glVertex2i(200, 250);
	glVertex2i(570, 250);
	glVertex2i(570, 230);
	glEnd();


}


void road_model_Night()
{

    glBegin(GL_QUADS);
    glColor3ub(82, 71, 67);
	glVertex2i(0,0);
	glVertex2i(0,-250);
	glVertex2i(1000,-250);
	glVertex2i(1000, 0);

	glEnd();

}
void RoadCorner1_Night()
{
    for(int i=0;i<360;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
    for(int i=440;i<590;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
    for(int i=680;i<1000;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner2_Night()
{
    for(int i=0;i<16*70;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148-100);
        glVertex2i(16+i,148-100);
        glVertex2i(16+i,157-100);
        glVertex2i(0+i,157-100);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148-100);
        glVertex2i(39+i,148-100);
        glVertex2i(39+i,157-100);
        glVertex2i(16+i,157-100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-200,0);
    RoadCorner1_Night();
    glPopMatrix();
}

void RoadCorner2_position_Night()
{
    glPushMatrix();
    glTranslatef(0,-300,0);
    RoadCorner2_Night();
    glPopMatrix();
}

void car_model_1_Night()
{
    glBegin(GL_POLYGON);
	glColor3f(21, 1, 1);
	glVertex2i(10, -10);
	glVertex2i(80, -10);
	glVertex2i(95, -40);
	glVertex2i(95, -80);
	glVertex2i(10, -80);
	glEnd();

	//
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(95, -40);
	glVertex2i(125, -40);
	glVertex2i(135, -80);
	glVertex2i(95, -80);
	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(15, -15);
	glVertex2i(40, -15);
	glVertex2i(40, -40);
	glVertex2i(15, -40);
	glEnd();

	//window2
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(50, -15);
	glVertex2i(78, -15);
 	glVertex2i(90, -40);
	glVertex2i(50, -40);
	glEnd();
	//line
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(9,-80 );
	glVertex2i(136,-80);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Night(15);
    glPopMatrix();
    //circle small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(110,-80,0);
    circle_Night(10);
    glPopMatrix();
    //circle2

	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Night(15);
    glPopMatrix();
    //circle2 small
    glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
    glTranslatef(35,-80,0);
    circle_Night(10);
    glPopMatrix();
}

void car_model_2_Night()
{
    glBegin(GL_POLYGON);
	glColor3f(0.4, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(280, -110);
	glVertex2i(480, -110);
	glVertex2i(480, -15);
	glEnd();

	//triagle
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2i(300, -15);
	glVertex2i(280, -52);
	glVertex2i(300, -52);
	glEnd();

	//square

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2i(305, -25);
	glVertex2i(305, -52);
	glVertex2i(470, -52);
	glVertex2i(470, -25);
	glEnd();

//big square
    glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2i(305, -28);
	glVertex2i(325, -28);
	glVertex2i(325, -60);
	glVertex2i(305, -60);
	glEnd();
	//big square white
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(325, -28);
	glVertex2i(340, -28);
	glVertex2i(340, -80);
	glVertex2i(325, -80);
	glEnd();

	//window 1

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(345, -28);
	glVertex2i(380, -28);
	glVertex2i(380, -50);
	glVertex2i(345, -50);
	glEnd();

	//window 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(385, -28);
	glVertex2i(415, -28);
	glVertex2i(415, -50);
	glVertex2i(385, -50);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(310,-110,0);
    circle_Night(15);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(450,-110,0);
    circle_Night(15);
    glPopMatrix();
}

//*** Field_Model ***///

void field_Night(){
    //Field
	glBegin(GL_POLYGON);
	glColor3ub( 50,205,50);
	glVertex2i(0, 50);
	glVertex2i(0, 200);// ch=70to 200
	glVertex2i(1000, 200);
	glVertex2i(1000, 50);
	glEnd();
	//------tree

	glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(250, 180);
	glVertex2i(260, 180);
	glVertex2i(260, 280);
	glVertex2i(250, 280);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(250,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(260,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(270,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(240,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(245,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(265,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(255,300,0);
    circle(12);
    glPopMatrix();

    //Field_Shadow
	glBegin(GL_POLYGON);
	glColor3ub( 34,139,34 );
	glVertex2i(0, -50);  //change
	glVertex2i(0, 50);
	glVertex2i(1000, 50);
	glVertex2i(1000, -50); //change
	glEnd();

	//----------------road-L----
	glBegin(GL_POLYGON);
	 glColor3ub(82, 71, 67);
	glVertex2i(380, -50);
	glVertex2i(420, 200);// ch=70to 200
	glVertex2i(470, 200); //    ||
	glVertex2i(440, -50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(370, -50);
	glVertex2i(410, 200);
	glVertex2i(420, 200);
	glVertex2i(380, -50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(450, -50);
	glVertex2i(465, 100);
	glVertex2i(457, 100);
	glVertex2i(440, -50);
	glEnd();

	//-------------------Road-R-----
	glBegin(GL_POLYGON);
	 glColor3ub(82, 71, 67);
	glVertex2i(610, -50);
	glVertex2i(590, 200);// ch=70to 200
	glVertex2i(640, 200);
	glVertex2i(680, -50);
	glEnd();

	//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(680, -50);
	glVertex2i(640, 200);
	glVertex2i(650, 200);
	glVertex2i(690, -50);
	glEnd();
//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(610, -50);
	glVertex2i(599, 100);
	glVertex2i(589, 100);
	glVertex2i(600, -50);
	glEnd();
glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(150, 150);
	glVertex2i(160, 150);
	glVertex2i(160, 250);
	glVertex2i(150, 250);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(150,250,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(180,250,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(140,250,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(170,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(175,260,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160,260,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(150,270,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(160,250,0);
    circle(12);
    glPopMatrix();

	//-------------------front------
	glBegin(GL_POLYGON);
	 glColor3ub(82, 71, 67);
	glVertex2i(450, 100);
	glVertex2i(450, 200);// ch=70to 200
	glVertex2i(600, 200);
	glVertex2i(600, 100);
	glEnd();
	//road island
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
    glVertex2i(455, 90);
	glVertex2i(590, 90);
	glVertex2i(590, 100);
	glVertex2i(465, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(128 , 0 ,0);
	glVertex2i(850, 180);
	glVertex2i(870, 180);
	glVertex2i(870, 280);
	glVertex2i(850, 280);
	glEnd();

	//circle
	glColor3ub(0, 100, 0);
	glPushMatrix();
    glTranslatef(850,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(860,280,0);
    circle(12);
    glPopMatrix();
	glPushMatrix();
    glTranslatef(870,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(840,280,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,290,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,300,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(885,280,0);
    circle(12);
    glPopMatrix();
     glPushMatrix();
    glTranslatef(885,300,0);
    circle(12);
    glPopMatrix();
 glPushMatrix();
    glTranslatef(875,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(855,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,320,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(845,310,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(855,330,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(865,330,0);
    circle(12);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(860,340,0);
    circle(12);
    glPopMatrix();
	//---Car
	glBegin(GL_POLYGON); //body
	glColor3ub(0 , 255 , 255);
	glVertex2i(470, 150);
	glVertex2i(470, 200);
	glVertex2i(475, 250);
	glVertex2i(520, 250);
	glVertex2i(530, 200);
	glVertex2i(550, 200);
	glVertex2i(555, 150);
	glEnd();

glBegin(GL_POLYGON); //window
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(475, 200);
	glVertex2i(480, 245);
	glVertex2i(495, 245);
	glVertex2i(495, 200);
	glEnd();
glBegin(GL_POLYGON); //window
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(500, 200);
	glVertex2i(500, 245);
	glVertex2i(518, 245);
	glVertex2i(525, 200);
	glEnd();

	glBegin(GL_POLYGON); //bumper
	glColor3f(0.1 , 0.0 , 0.0);
	glVertex2i(470, 150);
	glVertex2i(470, 155);
	glVertex2i(555, 155);
	glVertex2i(555, 150);
	glEnd();

	//circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(490,155,0);
    circle(12);
    glPopMatrix();
    //circle
	glColor3ub(255, 255, 255);
	glPushMatrix();
    glTranslatef(490,155,0);
    circle(10);
    glPopMatrix();

    //circle
	glColor3f(0, 0, 0);
	glPushMatrix();
    glTranslatef(535,155,0);
    circle(12);
    glPopMatrix();
    //circle
	glColor3ub(255, 255, 255);
	glPushMatrix();
    glTranslatef(535,155,0);
    circle(10);
    glPopMatrix();
}
////Tree model updated

void Tree_Model_circle_1_NIght(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0.3,0); //dark red
	glVertex2f(130, 130);
	glVertex2f(130, 95);
    glEnd();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,130,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(125,126,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(135,126,0);
    circle_Night(10);
    glPopMatrix();

    glColor3f( 0, 0.398039,0); //green
    glPushMatrix();
    glTranslatef(130,125,0);
    circle_Night(10);
    glPopMatrix();


}

void Tree_Model_circle_2_Night(){

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f( 0.3, 0,0); //dark red
	glVertex2f(133, 125);
	glVertex2f(133, 92);
    glEnd();

    glColor3f( 0, 0.198039,0);
    glBegin(GL_POLYGON);
	glVertex2f(123, 123);
	glVertex2f(134, 147);
	glVertex2f(147, 123);
	glEnd();
}

//star
void star()
{

	glBegin(GL_TRIANGLES);
    glColor3f(255.0f,255.0f,255.0f);
	glVertex2i(230, 175);
	glVertex2i(235, 175);
    glVertex2i(235, 170);
	glEnd();
	glBegin(GL_TRIANGLES);
    glColor3f(255.0f,255.0f,255.0f);
	glVertex2i(230, 175);
	glVertex2i(232, 179);
    glVertex2i(235, 175);
	glEnd();

}

//*** Cloud_One_Model_One ***///
void airplane_Night(){
    glPushMatrix();
    glTranslatef(ar-300,200,0);
    airplane_model_Night();
    glPopMatrix();
}

void house2_Night()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house_Night();
    glPopMatrix();
}

void house_three_Night()
{
    glPushMatrix();
    glTranslatef(140,130,0);
    house_Night();
    glPopMatrix();
}
void car_1_Night(){
    glPushMatrix();
    glTranslatef(cr-200,-40,0);
    car_model_1_Night();
    glPopMatrix();

}

void Bus_Night(){
    glPushMatrix();
    glTranslatef(bs+800,-135,0);
    car_model_2_Night();
    glPopMatrix();

}

void star_night1()
{
    glPushMatrix();
    glTranslatef(-155,700,0);
    star();
    glPopMatrix();
}
void star_night2()
{
    glPushMatrix();
    glTranslatef(-90,500,0);
    star();
    glPopMatrix();
}
void star_night3()
{
    glPushMatrix();
    glTranslatef(100,650,0);
    star();
    glPopMatrix();
}
void star_night4()
{
    glPushMatrix();
    glTranslatef(220,620,0);
    star();
    glPopMatrix();
}
void star_night5()
{
    glPushMatrix();
    glTranslatef(340,520,0);
    star();
    glPopMatrix();
}
void star_night6()
{
    glPushMatrix();
    glTranslatef(420,580,0);
    star();
    glPopMatrix();
}
void star_night7()
{
    glPushMatrix();
    glTranslatef(490,650,0);
    star();
    glPopMatrix();
}
void star_night8()
{
    glPushMatrix();
    glTranslatef(580,520,0);
    star();
    glPopMatrix();
}
void star_night9()
{
    glPushMatrix();
    glTranslatef(660,610,0);
    star();
    glPopMatrix();
}
void star_night()
{
    glPushMatrix();
    star_night1();
    star_night2();
    star_night3();
    star_night4();
    star_night5();
    star_night6();
    star_night7();
    star_night8();
    star_night9();
    glPopMatrix();
}




void Night(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor( 0.0, 0.0 , 0.3, 0);
    star_night();
    Moon_Night_Position();
    house_three_Night();

    airplane_Night();
    road_model_Night();
    car_1_Night();
    Bus_Night();
    field_Night();


    Hotel_position_Night();
    Hospital_position_Night();
    Tree_One_Night();
    Tree_Two_Night();
    Lampost_position_Night();
    School_position_Night();
    Tree_Three_Night();
    RoadCorner1_position_Night();
    RoadCorner2_position_Night();

     print_Night(500,400, Airport);

	glFlush();
}

//*** Night Function End ***///

//*** Day Function Start ***///

void Day(void)
{	glClearColor( 0.22, 0.69 , 0.87, 0);
	glClear(GL_COLOR_BUFFER_BIT);

    Sun();
    house_three();
    cloud_three();
    cloud_four();
    cloud_one();
    cloud_two();
    cloud_five();
    cloud_six();
    airplane();
    road_model();
    car_1();
    Bus();
    field();
    Hotel_position();
    Hospital_position();
    Tree_One();
    Tree_Two();
    Lampost_position();
    School_position();
    Tree_Three();
    RoadCorner1_position();
    RoadCorner2_position();
    print_Night(500,400, Airport);

	glFlush();
}

// *** Speed & Movement *** ///

void move_right(){

    spin = spin +.1;
    spin1 = spin1 +.000095;
    spin2 = spin2 +.00015;
    spin3 = spin3 +.00015;
    spin4 = spin4 +.0009;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1500){
        cx = -300;
    }
    if(bx>1500){
            bx= -400;
    }
    if(ax>1500){
            ax= -400;
    }
    if(dx>1500){
            dx= -500;
    }
    glutPostRedisplay();
}
void move_rightx()
{
    spin = spin +.1;
    spin1 = spin1 +.5;
    spin2 = spin2 +.5;
    spin3 = spin3 +.09;
    spin4 = spin4 +.0009;

    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    ar = ar + .20;
    cr = cr +.20;
    cr1 = cr1 +.20;
    bs =  bs -.30;
    if(cx>1500){
        cx = -300;
    }
    if(bx>1500){
            bx= -400;
    }
    if(ax>1500){
            ax= -400;

    }
    if(dx>1500){
            dx= -500;
    }
    if(ar>1500){
            ar= -400;
    }
     if(cr>1500){
            cr= -400;
    }
     if(cr1>600){
            cr1= +150;
    }
    if(bs<-1500)
    {
        bs=500;
    }
}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   //glLoadIdentity();

   glFlush();
}
void handleKeypress(unsigned char key, int x, int y) {

switch(key)
{
    case 'a':
        glLoadIdentity();
        glutDisplayFunc(display);
        sound();
        glutPostRedisplay();
    break;

    case 'd':
    glutDisplayFunc(Day);
break;

case 'n':
  glutDisplayFunc(Night);
break;

    case 'm':
        glutIdleFunc(move_rightx);
        break;

    case 'b':
        glutIdleFunc(move_right);
        break;
    case 's':
        glutIdleFunc(NULL);
        break;
    }
glutPostRedisplay();
}

int main(int argc, char** argv)
{
    cout << "01054-COMPUTER GRAPHICS[M]" << endl << endl;
    cout << "AIRPORT VIEW" << endl << endl;
    cout << "Submitted by Group [5] The Circle" << endl << endl<<endl;


    cout << "ID              Name                Contribution" << endl << endl;
    cout << "19-40625-1  Ali Rafsan Kabir             20%"  << endl << endl;
    cout << "19-40351-1  Khanam, Fahmida              22% "  << endl << endl;
    cout << "19-39618-1  Rahman, Md. Asifur           20%% "  << endl << endl;
    cout << "19-39439-1  Rumzum, Swapnila Das         19%"  << endl << endl;
    cout << "19-40693-1  Das, Debashish               19%  "  << endl << endl<<endl;
    cout << "Submitted to" << endl << endl;
    cout << "MAHFUJUR RAHMAN" << endl << endl;
    cout << "FACULTY OF SCIENCE & TECHNOLOGY" << endl << endl;
    cout << "American International University - Bangladesh " << endl << endl<<endl<<endl;


    cout << "Press m : Start to Move" << endl << endl;
    cout << "Press d : Shift to Day Mode" << endl << endl;
    cout << "Press n : Shift to Night Mode" << endl << endl;

    cout << "Press s : Stop All movement " << endl << endl;
    cout << "Press b : Brake Bus,Car & Airplane" << endl << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 620);
	glutCreateWindow("Airport VIew");
	init();
	glutDisplayFunc(Day);
	glutKeyboardFunc(handleKeypress);
    glutIdleFunc(Idle);
	glutMainLoop();
}
