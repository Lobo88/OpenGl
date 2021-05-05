
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "windows.h"
#include <GL/glut.h>
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"
#include <GLFW/glfw3.h>
#endif


#include <stdlib.h>
#include <time.h>
#include <random>
#include <math.h>
#include <vector>
static int slices = 16;
static int stacks = 16;
GLdouble side = 0;
long start_time = 0;
 bool isSphere=true;
GLfloat x,y,z,angle;
bool draw_bullet = false;
glm::vec3 pos;

    double currentFrame = glfwGetTime();
    double lastFrame = currentFrame;
    double deltaTime;

    double a2=0;
    double a3=0;
    double speed = 0.6;
bool block=false;
GLfloat red = 1.0, green = 1.0, blue = 1.0;


 void bullet(){

if(a2>500){
draw_bullet=false;block=false;
  //a2=a2-3000;// jesli chcemy by wracalo
}

glPushMatrix();

 glTranslated(0.3+side*0.9,-0.5,-4);
glTranslatef(0, 1*0.5*a2/100, 0.0f);
 glColor4f (1.0f, 0.0f, 0.00f, 0.7f);//ustawiamy kolor obiektow
glDisable (GL_LIGHTING);// musimy wylaczyć światlo
glEnable (GL_BLEND); //wlaczamy mieszanie kolorow
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);; // równanie mieszania kolorów
glLineWidth(10);
glBegin(GL_LINES) ;// początek definicji obiektów

glVertex3f(0.0f, 0.0f, 0.0f); // kolejne wierzchołki
glVertex3f(0.0f, 0.1f, 0.0f); // kolejne wierzchołki
glEnd(); // koniec definicji wielokątów
glLineWidth(1);
//glTranslatef(0.0,0.0,0.0);
//glutSolidCube(0.2);
glDisable (GL_BLEND);
glEnable (GL_LIGHTING);
glPopMatrix();

}


static void fire(){

for(double i=0;i<1.5;i+=0.1)////////////zbliza nam komety******mozna zrobic ogień******************************
    //for(int i=0;i<10;i++)///////////zamiast tego
		for(int j=-5;j<1;j++)
			for(int k=0;k<1;k++)
			{
			glPushMatrix();
			glTranslated(-0.65,-2.25,0);
			//glTranslatef(i,k,j*-6);
			glTranslatef(i,k,j-8);
            for( int i = 0; i < 6; i++ )
                {if(a3>3000){

  a3=a3-300;
}
            // glTranslatef(0.0, 0-up, 0.0f);
glTranslatef(0.0+side*0.4, -0.01*a3/100, 0.0f);
            }
glColor4f (1.0f, 0.0f, 0.02f, 0.7f);//ustawiamy kolor obiektow
glDisable (GL_LIGHTING);// musimy wylaczyć światlo
glEnable (GL_BLEND); //wlaczamy mieszanie kolorow
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);; // równanie mieszania kolorów
glutSolidSphere(0.05,16,16);
glDisable (GL_BLEND);
glEnable (GL_LIGHTING);

			glPopMatrix();
			}
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);// obszar renderingu - ca³e okno
    glMatrixMode(GL_PROJECTION);   // wybór macierzy modelowania
    glLoadIdentity();//przyporzadkowanie poczatkowych wartosci maierzy jednostkowej
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);//ustawienie obserwatora- kamery
//gluLookAt( left, 0, 3, 0, 0, -100, 0, 1, 0 );//// ustawienie obserwatora- kamery
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

}
//maly torusik
static void adisplay(void){

    glTranslated(1.25,1.76,-5);
    glTranslatef(0.0f+side, 0.0f, 0.0f);
        glRotated(20+side,1,50,10);
        glutSolidTorus(0.03,0.08,slices,stacks);

}

static bool resultSide(double side,bool sideLeft){

    if(side==3 && sideLeft==false){
            side=0;
            return false;
    }else if (side==-3 && sideLeft==true){
        side=0;
        return false;
    }else{return true;}
}

 void a2display(){
//glTranslated(2.4,(rand() % 80) - 40,-6);//pozycja obiektu
glTranslated(2.4,1,-6);//pozycja obiektu
       // glTranslatef(0.0f+side, 0.0f, 0.0f);
        for( int i = 0; i < 5; i++ ){
            glTranslatef((0.0f-i)*0.01*start_time/100, 0.0f, 0.0f);
        if(start_time>3000){
          //glColor3d(0,1,0);
             //glTranslated(2.4,1.2,-6);//pozycja obiektu
          // glScalef(1,1,1);
           start_time-=3000;
            }
        }

}
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    const float lef=0;
    start_time = clock();

 currentFrame = clock();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

 a2 += deltaTime * speed;
 a3+=deltaTime * speed;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// czysci t³o i wype³nia bufor koloru


//for(double i=0;i<5;i+=0.3)////////////zbliza nam komety******mozna zrobic ogień******************************
    for(int i=0;i<10;i++)///////////zamiast tego
		for(int j=-5;j<5;j++)
			for(int k=0;k<25;k++)
			{
			glPushMatrix();
			glTranslated(-5,3,0);
			//glTranslatef(i,k,j*-6);
			glTranslatef(i,k,j-6);
			 for( int i = 0; i < 5; i++ ){
            glTranslatef(0.0, (0.0f-i)*0.01*start_time/100, 0.0f);
            }
glColor4f (0.91f, 0.3f, 0.02f, 0.7f);//ustawiamy kolor obiektow
//glColor4f (0.0f,1.0f, 0.0f, 0.9f);//ustawiamy kolor obiektow
glDisable (GL_LIGHTING);// musimy wylaczyć światlo
glEnable (GL_BLEND); //wlaczamy mieszanie kolorow
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);; // równanie mieszania kolorów
glutSolidSphere(0.1,6,6);
glDisable (GL_BLEND);
glEnable (GL_LIGHTING);

			glPopMatrix();
			}


			glColor3d(0,1,0); // wype³nienie obiektów kolorem
    if(isSphere==true){
    glPushMatrix();//umieszczenie macierzy na stosie

    // a2display();

      glRotated(60,1,0,-0); //obrót obiektu
        glRotated(-a,50,0,1); //obracanie w czasie rzeczywistym
        glutSolidSphere(0.4,slices,stacks);//utworzenie obiektu
    glPopMatrix(); //zdjęcie macierzy ze stosu
   }

//dziub
 glPushMatrix();
glTranslated(0.1+side,-0.15,-5);
 glRotated(95,-2,15,-25);
 glScalef(0.6f, 0.6f, 0.6f);
glutSolidTetrahedron();
glPopMatrix();

//srodek
glPushMatrix();
 glTranslated(0.1+side,-0.8,-5);
 glRotated(160,0.01,1,-0.1);
  glScalef(0.6f, 0.6f, 0.6f);
 glutSolidCube(1.3);
 glPopMatrix();

//skrzydlo prawe
 glPushMatrix();
glTranslated(0.6+side,-0.8,-4.5);
 glRotated(45,-2.2,15,-25);
  glScalef(0.6f, 0.6f, 0.6f);
glutSolidTetrahedron();
 glPopMatrix();
//skrzydlo lewe
 glPushMatrix();
glTranslated(-0.5+side*1.1,-0.7,-5.5);
 glRotated(45+side*10,60,0,80);
  glScalef(0.6f, 0.6f, 0.6f);
glutSolidTetrahedron();
 glPopMatrix();

    glPushMatrix();
        glTranslated(0+side,-1.8,-5);
        glRotated(102,-40,1.2,-0.2);
        glRotated(a,0,0,1);
         glScalef(0.6f, 0.6f, 0.6f);
        glutWireCone(1,1.2,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.03+side/1.2,-0.19,-4);
        glRotated(0,1,0,0);
        glRotated(a,0,0,1);
         glScalef(0.6f, 0.6f, 0.6f);
        glutSolidTorus(0.05,0.12,slices,stacks);
    glPopMatrix();
//okno
    glPushMatrix();
        glTranslated(0.17+side/1.15,-0.03,-4);
        glRotated(20,1,50,10);
         glScalef(0.6f, 0.6f, 0.6f);
        glutSolidTorus(0.03,0.08,slices,stacks);
    glPopMatrix();

     glPushMatrix();

     fire();
// adisplay(); glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    glPopMatrix();

    glPushMatrix();
 if ( draw_bullet ){

bullet();
}
 glPopMatrix();

 glPushMatrix();
 glRotated(0,0.1,0,0);
glRotated(a/10,0,0,1);
 glColor4f (0.40f, 0.95f, 0.97f, 0.7f);//ustawiamy kolor obiektow
//glColor4f (0.0f,1.0f, 0.0f, 0.9f);//ustawiamy kolor obiektow
glDisable (GL_LIGHTING);// musimy wylaczyć światlo
glEnable (GL_BLEND); //wlaczamy mieszanie kolorow
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);; // równanie mieszania kolorów
glBegin(GL_LINES);
z = -7.0f;
//z=-3.0f;
for(angle = 0.0f; angle <= 1*3.0f; angle += 0.1f)
 {
 // Górna połowa okręgu
 x = 1.10f*sin(angle)*(0.01*start_time/100);
 y = 1.10f*cos(angle)*(0.01*start_time/100);
 glVertex3f(x, y, z);
 // Dolna połowa okręgu
 x = 1.10f*sin(angle+3.1415f)*(0.01*start_time/100);
 y = 1.10f*cos(angle+3.1415f)*(0.01*start_time/100);
 glVertex3f(x, y, z);
 }
 glEnd();
glDisable (GL_BLEND);
glEnable (GL_LIGHTING);
  glPopMatrix();
    glutSwapBuffers();//Funkcja wykorzystywana w przypadku ustawienia podwójnego
                        //bufora GLUT_DOUBLE, służy do przełączania bufora

}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
        case 'a':

            if( resultSide(side,true)==true){
           side=side-1;isSphere=false;}
           break;

           case 'd':
               if( resultSide(side,false)==true){
           side=side+1;isSphere=true;}
           break;

           case GLFW_KEY_SPACE :
             if(block==false){ a2=1;
            draw_bullet = true;block=true;}
            break;
    }

    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}
GLfloat fPozycja_swiatla[4] = {-2.0f, 0.0f, 0.0f, 1.0f};


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//Inicjalizacje bufora ramki

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);  //kolor t³a
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0); // włączenie światła 0  (parametr GL_LIGHT0 do GL_LIGHT7)
    glEnable(GL_NORMALIZE);//wektory normalne w wektory jednostkowe
    glEnable(GL_COLOR_MATERIAL);// włączenie odbicia s
    glEnable(GL_LIGHTING);// włączenie oświetlenia


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);//światło otaczające - nie pochodzi z żadnego kierunku, choć ma
                                    //źródło. Wszystkie obiekty na scenie są nim równomiernie oświetlone ze wszystkich
                                    //stron i na wszystkich powierzchniach
    //glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);//światło rozproszone - ma zdefiniowane źródło i z tego kierunku
                                        //pochodzi. Jasność powierzchni zależy od kąta, pod jakim pada na nią światło
    //glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);//światło odbite - ma kierunek i jest odbijane od powierzchni                                                       //ednym konkretnym kierunku
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//swiatlo_pozycja

    //glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);//odbicie swiatła przez material
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    //glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutSwapBuffers();
    glutMainLoop();

    return EXIT_SUCCESS;
}
