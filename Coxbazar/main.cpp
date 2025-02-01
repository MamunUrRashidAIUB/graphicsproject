#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float boatPosX = 0; // Horizontal position of the boats
float cloud1PosX = 700; // Horizontal position of cloud 1
float cloud2PosX = 900; // Horizontal position of cloud 2
float cloud3PosX = 350; // Horizontal position of cloud 3
float balloonPosX = 200;

void boat() {
    glPushMatrix();
    glTranslatef(boatPosX, 0, 0); // Translate the boat horizontally based on boatPosX

    /// Boat 1
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(200, 500, 0);
    glVertex3i(400, 500, 0);
    glVertex3i(350, 450, 0);
    glVertex3i(250, 450, 0);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(240, 500, 0);
    glVertex3i(360, 500, 0);
    glVertex3i(360, 540, 0);
    glVertex3i(240, 540, 0);
    glEnd();

    /// Boat 2
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(800, 500, 0);
    glVertex3i(1000, 500, 0);
    glVertex3i(950, 450, 0);
    glVertex3i(850, 450, 0);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(850, 500, 0);
    glVertex3i(950, 500, 0);
    glVertex3i(950, 550, 0);
    glVertex3i(850, 550, 0);
    glEnd();

    glPopMatrix(); // Restore the original matrix
}

void hill() {
    // Hill drawing (unchanged)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(150, 600);
    glVertex2f(300, 700);
    glVertex2f(300, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(200, 600);
    glVertex2f(400, 700);
    glVertex2f(500, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(900, 600);
    glVertex2f(1100, 800);
    glVertex2f(1200, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1000, 600);
    glVertex2f(1200, 700);
    glVertex2f(1300, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1200, 600);
    glVertex2f(1300, 800);
    glVertex2f(1400, 600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1300, 600);
    glVertex2f(1400, 700);
    glVertex2f(1500, 600);
    glEnd();
}

void umbrella() {
    // Umbrella drawing (unchanged)
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(200, 100); // Bottom of the pole (P1)
    glVertex2f(200, 200); // Top of the pole (O1)
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the umbrella top
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(200, 200); // Center of the semicircle (O1)
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180; // Convert degrees to radians
        float x = 200 + 70 * cos(angle); // Horizontal radius: 70, adjust the center
        float y = 200 + 70 * sin(angle); // Vertical radius: 70, adjust the center
        glVertex2f(x, y);
    }
    glEnd();

    // Second Umbrella
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(500, 100); // Bottom of the pole (P2)
    glVertex2f(500, 200); // Top of the pole (O2)
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the umbrella top
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(500, 200); // Center of the semicircle (O2)
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180; // Convert degrees to radians
        float x = 500 + 70 * cos(angle); // Horizontal radius: 70, adjust the center
        float y = 200 + 70 * sin(angle); // Vertical radius: 70, adjust the center
        glVertex2f(x, y);
    }
    glEnd();

    // Third Umbrella
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(900, 100); // Bottom of the pole (P3)
    glVertex2f(900, 200); // Top of the pole (O3)
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the umbrella top
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(900, 200); // Center of the semicircle (O3)
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180; // Convert degrees to radians
        float x = 900 + 70 * cos(angle); // Horizontal radius: 70, adjust the center
        float y = 200 + 70 * sin(angle); // Vertical radius: 70, adjust the center
        glVertex2f(x, y);
    }
    glEnd();
}

void sun() {
    // Sun drawing (unchanged)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for the sun
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1100, 1000); // Center of the sun
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180; // Convert degrees to radians
        float x = 1100 + 80 * cos(angle); // Horizontal radius: 80
        float y = 1000 + 80 * sin(angle); // Vertical radius: 80
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCloud(float centerX, float centerY) {
    // Circle 1 (Left)
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX - 50, centerY); // Center of the first circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180; // Convert degrees to radians
        float x = (centerX - 50) + 40 * cos(angle); // Radius: 40
        float y = centerY + 40 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Circle 2 (Middle)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the second circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = centerX + 50 * cos(angle); // Radius: 50
        float y = centerY + 50 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Circle 3 (Right)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX + 50, centerY); // Center of the third circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = (centerX + 50) + 40 * cos(angle); // Radius: 40
        float y = centerY + 40 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void hotAirBalloon() {
    glPushMatrix();
    glTranslatef(balloonPosX, 0, 0); // Translate the balloon horizontally

    // Balloon Envelope (Red semicircle)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(250, 1000); // Center of the semicircle
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180;
        float x = 250 + 70 * cos(angle); // Horizontal radius: 70
        float y = 1000 + 70 * sin(angle); // Vertical radius: 70
        glVertex2f(x, y);
    }
    glEnd();

    // Basket (Brown rectangle)
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(200, 850); // Top-left corner (A3)
    glVertex2f(300, 850); // Top-right corner (B3)
    glVertex2f(300, 800); // Bottom-right corner
    glVertex2f(200, 800); // Bottom-left corner
    glEnd();

    // Ropes (Two lines connecting balloon to basket)
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINES);

    // Left rope: Connects bottom-left of balloon to top-left of basket
    glVertex2f(180,1000); // Start at balloon (x=200, y=930)
    glVertex2f(200, 850);             // End at basket's top-left (A3)

    // Right rope: Connects bottom-right of balloon to top-right of basket
    glVertex2f(320,1000); // Start at balloon (x=300, y=930)
    glVertex2f(300, 850);            // End at basket's top-right (B3)

    glEnd();

    glPopMatrix();
}





void draw_object() {
    // Sky
    glColor3f(0.6196f, 0.9333f, 0.9960f);
    glBegin(GL_QUADS);
    glVertex2f(0, 1200);
    glVertex2f(1500, 1200);
    glVertex2f(1500, 900);
    glVertex2f(0, 900);
    glEnd();
    sun();

    // Draw clouds at their current positions
  drawCloud(cloud1PosX, 850);   // Cloud 1
    drawCloud(cloud2PosX, 1050);  // Cloud 2
    drawCloud(cloud3PosX, 950);   // Cloud 3 (previously missing)
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

    // Draw objects
    boat();
    hill();
    umbrella();
    hotAirBalloon();
}

void updatePositions(int value) {
    // Update boat position
    boatPosX += 2.0f;
    if (boatPosX > 1500) {
        boatPosX = -400;
    }

    // Update cloud positions
    cloud1PosX += 0.5f; // Move cloud 1 slowly
    if (cloud1PosX > 1500) {
        cloud1PosX = -200;
    }

    cloud2PosX += 0.4f; // Move cloud 2 slowly
    if (cloud2PosX > 1500) {
        cloud2PosX = -200;
    }

    cloud3PosX += 0.3f; // Move cloud 3 slowly
    if (cloud3PosX > 1500) {
        cloud3PosX = -200;
    }

    //Update balloon position
balloonPosX += 1.0f; // Move balloon horizontally
    if (balloonPosX > 1500) {
    balloonPosX = -200; // Reset position when it goes off-screen
   }

    glutPostRedisplay(); // Request redisplay
    glutTimerFunc(30, updatePositions, 0); // Call this function again after 30ms
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
    glutTimerFunc(30, updatePositions, 0); // Start the timer for animation
    init();
    glutMainLoop();
    return 0;
}
