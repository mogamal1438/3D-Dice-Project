#include <GL/glut.h>
#include "drawer.h"
#include <iostream>
using namespace std;
#define v 60.0

#define Left_click 0
#define Right_click 2

float xAngle = 200.0;
float yAngle = 10.0;

float xTranslation = 0;
float yTranslation = 0;

float scale = 1.0;


void Initialization()
{
        glClearColor(0.7f, 0.8f, 0.8f, 0);               // Background color
        glEnable(GL_DEPTH_TEST);
}

void display();
void reshape(int, int);
void mouseClick (int button, int state, int x, int y);
void keyboardPress (unsigned char key, int x, int y);
void specialKeyPress (int key, int x, int y);

int main (int argc, char * argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


        glutInitWindowSize(720, 500);
        glutInitWindowPosition(550, 100);

        glutCreateWindow("Dice");

        Initialization();

        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouseClick);
        glutKeyboardFunc(keyboardPress);
        glutSpecialFunc(specialKeyPress);

        cout<<"Documentation :"<<endl<<endl<<"The W key rotates up"<<endl;
        cout<<"The S key rotates down"<<endl<<"The D key rotates right"<<endl;
        cout<<"The A key rotates left"<<endl<<"___________________________________________________"<<endl<<endl;
        cout<<"The UP arrow key Moves up "<<endl<<"The Down arrow key Moves down"<<endl;
        cout<<"The Left arrow key Moves left"<<endl<<"The Right arrow key Moves right"<<endl;
        cout<<"___________________________________________________"<<endl<<endl;
        cout<<"The Left Click for bigger scaling "<<endl<<"The Right Click for smaller scaling "<<endl;
        glutMainLoop();
}



void display()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // clear
        glLoadIdentity();                              // reset origin

        glTranslatef(xTranslation, yTranslation, 0);

        glRotatef(yAngle, 0, -1,0);
        glRotatef(xAngle, -1,0,0);

        glScaled(scale, scale, scale);

        glColor3f(1.0f,1.0f,1.0f);
        drawFaces();



        glColor3f(0.0f,0.0f,0.0f);
        drawLines();

        drawDots();

        glutSwapBuffers();                              // swap DOUBLE buffers and display
}

void reshape (int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-360,  360,  -250,  250, -250, 250);
        glMatrixMode(GL_MODELVIEW);
}



void mouseClick (int button, int state, int x, int y)
{
    if (state == GLUT_UP)
        return;

    switch (button)
    {

    case Left_click:
        scale += 0.05;
        glutPostRedisplay();
        break;

    case Right_click:
        if (scale > 0.10)
        {
            scale -= 0.05;
            glutPostRedisplay();
        }
        break;

    default:
        break;
    }
}



void keyboardPress (unsigned char key, int x, int y)
{
        switch (key)
        {
        case 'w':
        case 'W':
                xAngle += 8;
                glutPostRedisplay();
                break;

        case 'a':
        case 'A':
                yAngle += 8;
                glutPostRedisplay();
                break;

        case 's':
        case 'S':
                xAngle -= 8;
                glutPostRedisplay();
                break;

        case 'd':
        case 'D':
                yAngle -= 8;
                glutPostRedisplay();
                break;

        default:
                break;
        }
}

void specialKeyPress (int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
                    xTranslation -= 10;
                    glutPostRedisplay();
                    break;

        case GLUT_KEY_RIGHT:
                xTranslation +=10;
                glutPostRedisplay();
                break;

        case GLUT_KEY_UP:
                yTranslation += 10;
                glutPostRedisplay();
                break;

        case GLUT_KEY_DOWN:
                yTranslation -= 10;
                glutPostRedisplay();
                break;

        default:
            break;
    }
}
