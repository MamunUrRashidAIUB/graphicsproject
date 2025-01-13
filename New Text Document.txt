#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

// Remove unused variables related to the balloon
float posx = 0.0f;
float speed = 0.0f;

void boat()
{
    ///boat1
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(10,550-100,0);
    glVertex3i(150+50,550-100,0);
    glVertex3i(120+50,500-100,0);
    glVertex3i(30,500-100,0);
    glEnd();
  glColor3f(1,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(50,550-100,0);
    glVertex3i(150,550-100,0);
    glVertex3i(150,600-100,0);
    glVertex3i(50,600-100,0);
    glEnd();
    ///boat2
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(10+200,550-50,0);
    glVertex3i(150+50+200,550-50,0);
    glVertex3i(120+50+200,500-50,0);
    glVertex3i(30+200,500-50,0);
    glEnd();
  glColor3f(1,0,0);
    glBegin(GL_POLYGON);

    glVertex3i(50+200,550-50,0);
    glVertex3i(150+200,550-50,0);
    glVertex3i(150+200,600-50,0);
    glVertex3i(50+200,600-50,0);
    glEnd();
}

void draw_object() {
    // Sky
    glColor3f(0.6196f, 0.9333f, 0.9960f);
    glBegin(GL_QUADS);
    glVertex2f(0, 1200);
    glVertex2f(1200, 1200);
    glVertex2f(1200, 600);
    glVertex2f(0, 600);
    glEnd();

    // Sea
    glColor3f(0.0f, 0.5f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0, 600);
    glVertex2f(1200, 600);
    glVertex2f(1200, 300);
    glVertex2f(0, 300);
    glEnd();

    // Sand
    glColor3f(0.9f, 0.8f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(0, 300);
    glVertex2f(1200, 300);
    glVertex2f(1200, 0);
    glVertex2f(0, 0);
    glEnd();

    // Draw the boat
    glPushMatrix();
    glTranslatef(posx, 0, 0);
    boat();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}

void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': case 'A':
            speed = 0.0f;
            break;
        case 'w': case 'W':
            speed += 2.0f;
            break;
    }
}

void update(int value) {
    posx += speed;
    if (posx >= 1200)
        posx = 0;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void init(void) {
    glClearColor(0.6196f, 0.9333f, 0.9960f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 1200.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sea Beach");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);

    init();
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
