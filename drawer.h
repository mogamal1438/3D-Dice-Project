#include <math.h>

#define v 60
#define PI 3.14159265359

void DrawCircle(float cx=0, float cy=0, float r=13,  int num_segments=30)
{
    float sectorAngle = 360.0/num_segments;
    glBegin(GL_POLYGON);
            for(int i = 0; i < num_segments; i++)
            {
                float theta = i * sectorAngle; // Degree

                float x = r * cos(theta *PI/180); // calculate the x component
                float y = r * sin(theta *PI/180); // calculate the y component

                glVertex3f(x+cx, y+cy, 61); //output vertex
            }
    glEnd();
}

void drawFaces()
{

    glBegin(GL_QUADS);              // 6 faces
                //Top face of the Dice
                glVertex3f(v, v, -v);
                glVertex3f(-v, v, -v);
                glVertex3f(-v, v, v);
                glVertex3f(v, v, v);

                //Bottom face of the Dice
                glVertex3f(v, -v, v);
                glVertex3f(-v, -v, v);
                glVertex3f(-v, -v, -v);
                glVertex3f(v, -v, -v);

                //Front face of the Dice
                glVertex3f(v, v, v);
                glVertex3f(-v, v, v);
                glVertex3f(-v, -v, v);
                glVertex3f(v, -v, v);

                //Back face of the Dice
                glVertex3f(v, -v, -v);
                glVertex3f(-v, -v, -v);
                glVertex3f(-v, v, -v);
                glVertex3f(v, v, -v);

                //Left face of the Dice
                glVertex3f(-v, v, v);
                glVertex3f(-v, v, -v);
                glVertex3f(-v, -v, -v);
                glVertex3f(-v, -v, v);

                //Right face of the Dice
                glVertex3f(v, v, -v);
                glVertex3f(v, v, v);
                glVertex3f(v, -v, v);
                glVertex3f(v, -v, -v);

        glEnd();  // End drawing of faces
}

void drawLines ()
{
        glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
                //Top face Edges
                glVertex3f(v, v, -v);
                glVertex3f(-v, v, -v);
                glVertex3f(-v, v, v);
                glVertex3f(v, v, v);
        glEnd();


        glBegin(GL_LINE_LOOP);
                //Bottom face Edges
                glVertex3f(v, -v, v);
                glVertex3f(-v, -v, v);
                glVertex3f(-v, -v, -v);
                glVertex3f(v, -v, -v);
        glEnd();

        glBegin(GL_LINE_LOOP);
                //Front face Edges
                glVertex3f(v,v,v);
                glVertex3f(-v,v,v);
                glVertex3f(-v,-v,v);
                glVertex3f(v,-v,v);
        glEnd();

        glBegin(GL_LINE_LOOP);
                //Back face Edges
                glVertex3f(v,-v,-v);
                glVertex3f(-v,-v,-v);
                glVertex3f(-v,v,-v);
                glVertex3f(v,v,-v);
        glEnd();

        glBegin(GL_LINE_LOOP);
                //Left face Edges
                glVertex3f(-v,v,v);
                glVertex3f(-v,v,-v);
                glVertex3f(-v,-v,-v);
                glVertex3f(-v,-v,v);
        glEnd();

        glBegin(GL_LINE_LOOP);
                //Right face Edges
                glVertex3f(v,v,v);
                glVertex3f(v,-v,v);
                glVertex3f(v,-v,-v);
                glVertex3f(v,v,-v);
        glEnd();
}


void drawDots()
{
        // 1
        DrawCircle(0, 0, 16);

        // 2
        glRotatef(-90, 1, 0, 0);

        DrawCircle(30, 0);
        DrawCircle(-30, 0);

        glRotatef(-90, -1, 0, 0);

        // 3
        glRotatef(-90, 0,1,0);

        DrawCircle(0, 0);
        DrawCircle(30, 30);
        DrawCircle(-30, -30);

        glRotatef(-90, 0, -1, 0);


        // 4
        glRotatef(90, 0, 1, 0);

        DrawCircle(30, 30);
        DrawCircle(-30, 30);
        DrawCircle(30, -30);
        DrawCircle(-30, -30);

        glRotatef(90, 0,-1, 0);

        // 5
        glRotatef(90, 1,0,0);

        DrawCircle(0, 0);
        DrawCircle(30, 30);
        DrawCircle(-30, 30);
        DrawCircle(30, -30);
        DrawCircle(-30, -30);

        glRotatef(90, -1,0,0);

        // 6
        glRotatef(180, 1,0,0);

        DrawCircle(30, 0);
        DrawCircle(-30, 0);
        DrawCircle(30, 30);
        DrawCircle(-30, 30);
        DrawCircle(30, -30);
        DrawCircle(-30, -30);

        glRotatef(180, -1,0,0);
}
