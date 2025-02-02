#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float boatPosX = 0; // Horizontal position of the boats
float cloud1PosX = 700; // Horizontal position of cloud 1
float cloud2PosX = 900; // Horizontal position of cloud 2
float cloud3PosX = 350; // Horizontal position of cloud 3
float balloonPosX = 200;
float day =true;
float boatSpeed = 2.0f;
bool raining = true; // Set to false to stop rain
// Boat speed variable

void boat() {
    glPushMatrix();
    glTranslatef(boatPosX, 0, 0); // Translate the boat horizontally based on boatPosX

    /// Boat 1
 glColor3f(0.83f, 0.69f, 0.22f);
    glBegin(GL_POLYGON);
    glVertex3i(200, 500, 0);
    glVertex3i(400, 500, 0);
    glVertex3i(350, 450, 0);
    glVertex3i(250, 450, 0);
    glEnd();

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex3i(340, 540, 0);
    glVertex3i(300, 500, 0);
    glVertex3i(400, 500, 0);

    glEnd();

    /// Boat 2
   glColor3f(0.9f, 0.8f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex3i(800, 500, 0);
    glVertex3i(1000, 500, 0);
    glVertex3i(950, 450, 0);
    glVertex3i(850, 450, 0);
    glEnd();

  glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex3i(940, 540, 0);
    glVertex3i(880, 500, 0);
    glVertex3i(1000, 500, 0);

    glEnd();

    glPopMatrix(); // Restore the original matrix
}
//star
void star()
{
    //star1
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);

    glVertex3i(30, 1020, 0);
    glVertex3i(50, 1050, 0);
    glVertex3i(50, 1100, 0);

glEnd();
glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3i(70, 1020, 0);
    glVertex3i(50, 1100, 0);
    glVertex3i(50, 1050, 0);
glEnd();
glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3i(50, 1050, 0);
    glVertex3i(80, 1070, 0);
    glVertex3i(20, 1070, 0);
glEnd();}

void hill() {
    if (day) {
        glColor3f(0.0f, 1.0f, 0.0f); // Day: Green hills
    } else {
        glColor3f(0.1f, 0.3f, 0.1f); // Night: Dark green hills
    }
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
     glBegin(GL_TRIANGLES);
    glVertex2f(200, 300);
    glVertex2f(100, 200);
    glVertex2f(300, 200);
    glEnd();
//chair
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(210,60);
    glVertex2f(230,30);
    glVertex2f(280, 30);
    glVertex2f(260, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(360,30);
    glVertex2f(270,30);
    glVertex2f(270,40);
    glVertex2f(360,40);
    glEnd();
    glPopMatrix();
    // Second Umbrella
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(500, 100); // Bottom of the pole (P2)
    glVertex2f(500, 200); // Top of the pole (O2)
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the umbrella top
    glBegin(GL_TRIANGLE_FAN);
      glBegin(GL_TRIANGLES);
    glVertex2f(500, 300);
    glVertex2f(400, 200);
    glVertex2f(600, 200);
    glEnd();
//chair
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(510,60);
    glVertex2f(530,30);
    glVertex2f(580, 30);
    glVertex2f(560, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(660,30);
    glVertex2f(570,30);
    glVertex2f(560,40);
    glVertex2f(660,40);
    glEnd();
    glPopMatrix();
    // Third Umbrella
    glColor3f(0.5f, 0.35f, 0.05f); // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(900, 100); // Bottom of the pole (P3)
    glVertex2f(900, 200); // Top of the pole (O3)
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the umbrella top
      glBegin(GL_TRIANGLES);
    glVertex2f(900, 300);
    glVertex2f(800, 200);
    glVertex2f(1000, 200);
    glEnd();
      glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(910,60);
    glVertex2f(930,30);
    glVertex2f(980, 30);
    glVertex2f(960, 60);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(1060,30);
    glVertex2f(970,30);
    glVertex2f(960,40);
    glVertex2f(1060,40);
    glEnd();
}

void sun() {
    if (day){
        glColor3f(1.0f,1.0f,0.0f);
    }
    else{
       glColor3f(1.0f, 1.0f, 1.0f);
    }
 // Yellow color for the sun
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
       if (day) {
        glColor3f(1.0f, 1.0f, 1.0f); // Day: White clouds
    } else {
        glColor3f(0.5f, 0.5f, 0.5f); // Night: Gray clouds
    }
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
    if (day){
        glColor3f(1.0f,1.0f,0.0f);
    }
    else{
       glColor3f(1.0f, 1.0f, 1.0f);
    }
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

void drawRain() {
    if (!raining) return; // Only draw rain if it's raining

    float rainAngle = 30.0f; // Angle of the rain (30 degrees)
    float angleRadians = rainAngle * 3.14159f / 180.0f; // Convert to radians
    float speedFactor = 2.0f; // Speed of the rain

    // Calculate horizontal and vertical offsets based on the angle
    float xOffset = speedFactor * cos(angleRadians);
    float yOffset = speedFactor * sin(angleRadians);

    glColor3f(0.5f, 0.5f, 1.0f); // Light blue color for raindrops

    // Increase line width to make raindrops bolder
    glLineWidth(3.0f); // Set line width to 3.0 (default is 1.0)

    for (int i = 0; i < 1000; i++) {
        // Generate random positions for raindrops
        float x = (rand() % 1500); // Random x position (0 to 1500)
        float y = (rand() % 1200); // Random y position (0 to 1200)

        // Draw a raindrop as a line
        glBegin(GL_LINES);
        glVertex2f(x, y); // Start of the raindrop
        glVertex2f(x + xOffset, y - yOffset); // End of the raindrop
        glEnd();
    }

    // Reset line width to default (optional)
    glLineWidth(1.0f);
}




void draw_object() {
    // Adjust the full background color based on the time of day
    if (day) {
        glColor3f(0.6196f, 0.9333f, 0.9960f); // Light blue for day
    } else {
       glColor3f(0.0f, 0.0f, 0.0f);
    }

    // Cover the entire screen (sky)
    glBegin(GL_QUADS);
    glVertex2f(0, 1200);   // Top-left
    glVertex2f(1500, 1200); // Top-right
    glVertex2f(1500, 0);    // Bottom-right (fixed)
    glVertex2f(0, 0);       // Bottom-left (fixed)
    glEnd();

    sun(); // Draw the sun (or moon)

    // Draw clouds at their current positions
    drawCloud(cloud1PosX, 850);   // Cloud 1
    drawCloud(cloud2PosX, 1050);  // Cloud 2
    drawCloud(cloud3PosX, 950);   // Cloud 3
// **Sea Color**
    if (day) {
        glColor3f(0.0f, 0.5f, 0.8f); // Day sea (blue)
    } else {
        glColor3f(0.0f, 0.0f, 0.4f); // Night sea (dark blue)
    }
    // Draw sea

    glBegin(GL_QUADS);
    glVertex2f(0, 600);
    glVertex2f(1500, 600);
    glVertex2f(1500, 300);
    glVertex2f(0, 300);
    glEnd();

    // **Sand Color**
    if (day) {
        glColor3f(0.9f, 0.8f, 0.6f); // Day sand (light brown)
    } else {
        glColor3f(0.3f, 0.2f, 0.1f); // Night sand (dark brown)
    }
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
    star();
    drawRain();



}


void updatePositions(int value) {
    // Update boat position using the boatSpeed variable
    boatPosX += boatSpeed; // Use boatSpeed instead of a fixed value
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

    // Update balloon position
    balloonPosX += 1.0f; // Move balloon horizontally
    if (balloonPosX > 1500) {
        balloonPosX = -200; // Reset position when it goes off-screen
    }

    glutPostRedisplay(); // Request redisplay
    glutTimerFunc(30, updatePositions, 0); // Call this function again after 30ms
}
void keyboard(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
        day = true;  // Switch to day mode
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
glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutTimerFunc(30, updatePositions, 0); // Start the timer for animation
    init();
    glutMainLoop();
    return 0;
}
