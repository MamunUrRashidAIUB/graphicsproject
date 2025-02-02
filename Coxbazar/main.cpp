#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float boatPosX = 0;
float cloud1PosX = 700;
float cloud2PosX = 900;
float cloud3PosX = 350;
float balloonPosX = 200;
float day = true;
float boatSpeed = 2.0f;
bool raining = false;
float planePosX = 1500;

//boat
void boat() {
    glPushMatrix();
    glTranslatef(boatPosX, 0, 0);

    // Boat 1
    glColor3ub(211, 176, 56);
    glBegin(GL_POLYGON);
    glVertex2f(200, 500);
    glVertex2f(400, 500);
    glVertex2f(350, 450);
    glVertex2f(250, 450);
    glEnd();

    glColor3ub(229, 229, 229);
    glBegin(GL_POLYGON);
    glVertex2f(260, 500);
    glVertex2f(340, 540);
    glVertex2f(400, 500);
    glEnd();

    // Boat 2
    glColor3ub(229, 204, 153);
    glBegin(GL_POLYGON);
    glVertex2f(800, 500);
    glVertex2f(1000, 500);
    glVertex2f(950, 450);
    glVertex2f(850, 450);
    glEnd();

    glColor3ub(102, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2f(940, 540);
    glVertex2f(860, 500);
    glVertex2f(1000, 500);
    glEnd();

    glPopMatrix(); // Restore the original matrix
}

// stars only visible at night
void star() {
    if (!day) {
        // Star 1
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(600, 1120);
        glVertex2f(580, 1080);
        glVertex2f(600, 1100);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(600, 1120);
        glVertex2f(620, 1080);
        glVertex2f(600, 1100);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(580, 1100);
        glVertex2f(620, 1100);
        glVertex2f(600, 1080);
        glEnd();

        // Star 2
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(660, 1120);
        glVertex2f(640, 1080);
        glVertex2f(660, 1100);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(660, 1120);
        glVertex2f(680, 1080);
        glVertex2f(660, 1100);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(640, 1100);
        glVertex2f(680, 1100);
        glVertex2f(660, 1080);
        glEnd();
    }
}

// plane
void plane() {
    glPushMatrix();
    glTranslatef(planePosX, 0, 0);

    // Plane body
    glColor3ub(0, 102, 204);
    glBegin(GL_POLYGON);
    glVertex2f(570, 910);
    glVertex2f(768, 913);
    glVertex2f(750, 850);
    glVertex2f(539, 845);
    glEnd();
    //
    glColor3ub(204, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(768, 913);
    glVertex2f(814, 953);
    glVertex2f(843, 953);
    glVertex2f(750, 850);
    glEnd();
    //
    glColor3ub(204, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(501, 873);
    glVertex2f(789, 873);
    glVertex2f(750, 850);
    glVertex2f(539, 845);
    glEnd();
    //
    glColor3ub(230, 230, 230);
    glBegin(GL_POLYGON);
    glVertex2f(501.4236986901527, 873.9999236979464);
    glVertex2f(570.2523412282366, 910.3807776109325);
    glVertex2f(556, 873);
    glEnd();
    //
    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2f(659, 848);
    glVertex2f(682.344701933116, 823.8533412773442);
    glVertex2f(709.8761589483496, 825.8198739212894);
    glVertex2f(693.1273870115938, 848.9627981394879);
    glEnd();

    // tail
    glColor3ub(100, 100, 100);
    glBegin(GL_POLYGON);
    glVertex2f(658, 911);
    glVertex2f(695.8062440991109, 942.9567808612461);
    glVertex2f(715.5337787045539, 943.4626150818985);
    glVertex2f(694, 912);
    glEnd();

    // Windows of the plane
    glColor3ub(0, 0, 0);
    for (int i = 0; i < 6; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(572 + i * 26, 888);
        for (int j = 0; j <= 360; j++) {
            float angle = j * 3.14159 / 180;
            float x = 572 + i * 26 + 10 * cos(angle);
            float y = 888 + 10 * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }

    glPopMatrix();
}

// hills
void hill() {
    if (day) {
        glColor3ub(0, 255, 0);
    } else {
        glColor3ub(25, 76, 25);
    }

    // Draw multiple hills using triangles
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

//  umbrella
void umbrella() {
    // Umbrella 1
    glColor3ub(128, 89, 13);
    glBegin(GL_LINES);
    glVertex2f(200, 100); // Bottom
    glVertex2f(200, 200); // Top
    glEnd();

    glColor3ub(255, 0, 0); // umbrella top
    glBegin(GL_TRIANGLES);
    glVertex2f(200, 300);
    glVertex2f(100, 200);
    glVertex2f(300, 200);
    glEnd();

    // Chair 1
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(240, 100);
    glVertex2f(260, 60);
    glVertex2f(300, 80);
    glVertex2f(280, 100);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(260, 60);
    glVertex2f(380, 60);
    glVertex2f(380, 80);
    glVertex2f(300, 80);
    glEnd();

    // Umbrella 2
    glColor3ub(128, 89, 13);
    glBegin(GL_LINES);
    glVertex2f(500, 100); // Bottom
    glVertex2f(500, 200); // Top
    glEnd();

    glColor3ub(255, 0, 0); // Red  umbrella top
    glBegin(GL_TRIANGLES);
    glVertex2f(500, 300);
    glVertex2f(400, 200);
    glVertex2f(600, 200);
    glEnd();

    // Chair 2
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(560, 100);
    glVertex2f(580, 60);
    glVertex2f(640, 80);
    glVertex2f(620, 100);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(580, 60);
    glVertex2f(640, 80);
    glVertex2f(760, 80);
    glVertex2f(740, 60);
    glEnd();
}

//  tower
void tower() {
    // Triangle top
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(900, 200);
    glVertex2f(1000, 250);
    glVertex2f(1100, 200);
    glEnd();

    // Triangle legs
    glColor3ub(128, 89, 13);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(900, 200); // Left leg
    glVertex2f(900, 150);
    glVertex2f(1100, 200); // Right leg
    glVertex2f(1100, 150);
    glEnd();

    // Box body
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(850, 150);
    glVertex2f(1150, 150);
    glVertex2f(1150, 100);
    glVertex2f(850, 100);
    glEnd();

    // Two leg
    glColor3ub(128, 89, 13);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(850, 100); // Left leg
    glVertex2f(800, 50);
    glVertex2f(1150, 100); // Right leg
    glVertex2f(1200, 50);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(980, 100); // Left leg
    glVertex2f(1020, 100);
    glVertex2f(980, 80); // Right leg
    glVertex2f(1020, 80);
    glVertex2f(980, 60); // Right leg
    glVertex2f(1020, 60);
    glEnd();
}

//   sun / moon
void sun() {
    if (day) {
        glColor3ub(255, 255, 0); // Yellow color for the sun
    } else {
        glColor3ub(255, 255, 255); // White color for the moon
    }

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(1100, 1000); // Center of the sun/moon
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 1100 + 80 * cos(angle);
        float y = 1000 + 80 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

//  cloud
void drawCloud(float centerX, float centerY) {
    if (day) {
        glColor3ub(255, 255, 255); // Day White clouds
    } else {
        glColor3ub(128, 128, 128); // Night Gray clouds
    }

    // Circle 1 Left
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX - 50, centerY);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = (centerX - 50) + 40 * cos(angle);
        float y = centerY + 40 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Circle 2 Middle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = centerX + 50 * cos(angle);
        float y = centerY + 50 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Circle 3 Right
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX + 50, centerY);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = (centerX + 50) + 40 * cos(angle);
        float y = centerY + 40 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

//  air balloon
void hotAirBalloon() {
    glPushMatrix();
    glTranslatef(balloonPosX, 0, 0);

    // Balloon
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(250, 1000); // Center of the semicircle
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159 / 180;
        float x = 250 + 70 * cos(angle);
        float y = 1000 + 70 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Box
    glColor3ub(128, 89, 13);
    glBegin(GL_QUADS);
    glVertex2f(200, 850);
    glVertex2f(300, 850);
    glVertex2f(300, 800);
    glVertex2f(200, 800);
    glEnd();

    // Ropes
    if (day) {
        glColor3ub(255, 255, 0); // Yellow ropes at day
    } else {
        glColor3ub(255, 255, 255); // White ropes at night
    }
    glBegin(GL_LINES);
    glVertex2f(180, 1000);
    glVertex2f(200, 850);
    glVertex2f(320, 1000);
    glVertex2f(300, 850);
    glEnd();

    glPopMatrix();
}

//  rain
void drawRain() {
    if (!raining) return; // Only draw rain if it's raining

    float rainAngle = 30.0f; // Angle of the rain
    float angleRadians = rainAngle * 3.14159f / 180.0f;
    float speedFactor = 2.0f; // Speed of the rain


    float xOffset = speedFactor * cos(angleRadians);
    float yOffset = speedFactor * sin(angleRadians);

    glColor3ub(128, 128, 255); // Light blue color for raindrops
    glLineWidth(3.0f); // Set line width

    for (int i = 0; i < 1000; i++) {
        float x = (rand() % 1500); // Random x position
        float y = (rand() % 1200); // Random y position

        glBegin(GL_LINES);
        glVertex2f(x, y); // Start of the raindrop
        glVertex2f(x + xOffset, y - yOffset); // End of the raindrop
        glEnd();
    }

    glLineWidth(1.0f); // Reset line width to default
}

// Function to draw all objects
void draw_object() {
    // Adjust the full background color based on the time of day
    if (day) {
        glColor3ub(159, 237, 254); // Light blue for day
    } else {
        glColor3ub(0, 0, 0); // Black for night
    }

    //sky
    glBegin(GL_QUADS);
    glVertex2f(0, 1200); // Top-left
    glVertex2f(1500, 1200); // Top-right
    glVertex2f(1500, 0); // Bottom-right
    glVertex2f(0, 0); // Bottom-left
    glEnd();

    sun();// the sun / moon

    // Draw clouds
    drawCloud(cloud1PosX, 850); // Cloud 1
    drawCloud(cloud2PosX, 1050); // Cloud 2
    drawCloud(cloud3PosX, 950); // Cloud 3

    // Sea color
    if (day) {
        glColor3ub(0, 128, 204); // Day sea
    } else {
        glColor3ub(0, 0, 102); // Night sea
    }

    // sea
    glBegin(GL_QUADS);
    glVertex2f(0, 600);
    glVertex2f(1500, 600);
    glVertex2f(1500, 300);
    glVertex2f(0, 300);
    glEnd();

    // Sand color
    if (day) {
        glColor3ub(230, 204, 153); // Day sand
    } else {
        glColor3ub(77, 51, 26); // Night sand
    }

    //  sand
    glBegin(GL_QUADS);
    glVertex2f(0, 300);
    glVertex2f(1500, 300);
    glVertex2f(1500, 0);
    glVertex2f(0, 0);
    glEnd();

    // objects
    boat();
    hill();
    umbrella();
    hotAirBalloon();
    star();
    drawRain();
    tower();
    plane();
}

// Function to update positions of moving objects
void updatePositions(int value) {
    // Update boat position
    boatPosX += boatSpeed;
    if (boatPosX > 1500) {
        boatPosX = -400;
    }

    // Update cloud positions
    cloud1PosX += 0.5f;
    if (cloud1PosX > 1500) {
        cloud1PosX = -200;
    }

    cloud2PosX += 0.4f;
    if (cloud2PosX > 1500) {
        cloud2PosX = -200;
    }

    cloud3PosX += 0.3f;
    if (cloud3PosX > 1500) {
        cloud3PosX = -200;
    }

    // Update balloon position
    balloonPosX += 1.0f;
    if (balloonPosX > 1500) {
        balloonPosX = -200;
    }

    // Update plane position
    planePosX -= 7.0f;
    if (planePosX < -800) {
        planePosX = 1500;
    }

    glutPostRedisplay();
    glutTimerFunc(30, updatePositions, 0);
}

// Keyboard input handling
void keyboard(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
        day = true; // Switch to day mode
    } else if (key == 'n' || key == 'N') {
        day = false; // Switch to night mode
    } else if (key == 'a' || key == 'A') {
        boatSpeed -= 0.5f; // Decrease boat speed
        if (boatSpeed < 0.5f) {
            boatSpeed = 0.5f; // Minimum speed
        }
    } else if (key == 's' || key == 'S') {
        boatSpeed += 0.5f; // Increase boat speed
        if (boatSpeed > 5.0f) {
            boatSpeed = 5.0f; // Maximum speed
        }
    } else if (key == 'r' || key == 'R') {
        raining = !raining; // Toggle rain on/off
    }
    glutPostRedisplay(); // Redraw the scene with the new mode
}

// Display function
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
}

// Initialization function
void init(void) {
    glClearColor(0.6196f, 0.9333f, 0.9960f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1500.0, 0.0, 1200.0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sea Beach");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutTimerFunc(30, updatePositions, 0); // Start the timer for animation
    init();
    glutMainLoop();
    return 0;
}
