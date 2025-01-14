#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void boat()
{
    ///boat1
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(200,500, 0);
    glVertex3i(400,500, 0);
    glVertex3i(350,450, 0);
    glVertex3i(250,450, 0);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(240, 500, 0);
    glVertex3i(360, 500, 0);
    glVertex3i(360,540, 0);
    glVertex3i(240,540, 0);
    glEnd();
//boat 2
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(800,500, 0);
    glVertex3i(1000,500, 0);
    glVertex3i(950,450, 0);
    glVertex3i(850,450, 0);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);

    glVertex3i(850, 500, 0);
    glVertex3i(950, 500, 0);
    glVertex3i(950,550, 0);
    glVertex3i(850,550, 0);
    glEnd();
}
void hill() {
    // Hill 1
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(150, 600);  // Left bottom corner of the triangle
    glVertex2f(300, 700);  // Peak of the hill (higher point)
    glVertex2f(300, 600); // Right bottom corner of the triangle
    glEnd();


         // Hill 2
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(200, 600);  // Left bottom corner of the triangle
    glVertex2f(400, 700);  // Peak of the hill (higher point)
    glVertex2f(500, 600); // Right bottom corner of the triangle
    glEnd();

       // Hill 3
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(900, 600);  // Left bottom corner of the triangle
    glVertex2f(1100, 800);  // Peak of the hill (higher point)
    glVertex2f(1200, 600); // Right bottom corner of the triangle
    glEnd();

          // Hill 4
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1000, 600);  // Left bottom corner of the triangle
    glVertex2f(1200, 700);  // Peak of the hill (higher point)
    glVertex2f(1300, 600); // Right bottom corner of the triangle
    glEnd();

             // Hill 5
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1200, 600);  // Left bottom corner of the triangle
    glVertex2f(1300, 800);  // Peak of the hill (higher point)
    glVertex2f(1400, 600); // Right bottom corner of the triangle
    glEnd();
               // Hill 6
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(1300, 600);  // Left bottom corner of the triangle
    glVertex2f(1400, 700);  // Peak of the hill (higher point)
    glVertex2f(1500, 600); // Right bottom corner of the triangle
    glEnd();

}


void draw_object() {
    // Sky
    glColor3f(0.6196f, 0.9333f, 0.9960f);
    glBegin(GL_QUADS);
    glVertex2f(0, 1200);
    glVertex2f(1500, 900);
    glVertex2f(1500, 900);
    glVertex2f(0, 900);
    glEnd();

    // Sea
    glColor3f(0.0f, 0.5f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0, 600);
    glVertex2f(1500, 600);
    glVertex2f(1500, 300);
    glVertex2f(0, 300);
    glEnd();

    // Sand
    glColor3f(0.9f, 0.8f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(0, 300);
    glVertex2f(1500, 300);
    glVertex2f(1500, 0);
    glVertex2f(0, 0);
    glEnd();

    // Draw the boats
    boat();
    hill();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}

void init(void) {
    glClearColor(0.6196f, 0.9333f, 0.9960f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1500.0, 0.0, 1200.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sea Beach");

    glutDisplayFunc(display);

    init();
    glutMainLoop();
    return 0;
}
