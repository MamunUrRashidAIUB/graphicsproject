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
bool raining = false;
float planePosX = 1500; // Initial position of the plane (off-screen to the right)


 // Set to false to stop rain
// Boat speed variable

void boat() {
    glPushMatrix();
    glTranslatef(boatPosX, 0, 0); // Translate the boat horizontally based on boatPosX

    /// Boat 1
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

    /// Boat 2
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
//star
void star() {
    if (!day) { // Only draw stars if it's night
        //star1
        glColor3ub(255, 255, 255);

        glBegin(GL_POLYGON);
        glVertex2f(600, 1120);
        glVertex2f(580, 1080);
       glVertex2f(600, 1100);
        glEnd();

       glColor3ub(255, 255, 255);

        glBegin(GL_POLYGON);
        glVertex2f(600, 1120);
       glVertex2f(620, 1080);
        glVertex2f(600, 1100);
        glEnd();

glColor3ub(255, 255, 255);

        glBegin(GL_POLYGON);
        glVertex2f(580, 1100);
        glVertex2f(620, 1100);
        glVertex2f(600, 1080);
        glEnd();

        // star 2
      glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
       glVertex2f(660, 1120);
       glVertex2f(640, 1080);
        glVertex2f(660, 1100);
        glEnd();

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
       glVertex2f(660, 1120);
        glVertex2f(680, 1080);
        glVertex2f(660, 1100);
        glEnd();

      glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(640, 1100);
       glVertex2f(680, 1100);
        glVertex2f(660, 1080);
        glEnd();
    }
}
void plane(){
    glPushMatrix();
    glTranslatef(planePosX, 0, 0); // Translate the plane horizontally
    glColor3ub(0, 102, 204); // Blue plane body
    glBegin(GL_POLYGON);
    glVertex2f(570, 910);
    glVertex2f(768, 913);
    glVertex2f(750, 850);
    glVertex2f(539, 845);
    glEnd();

    glColor3ub(204, 0, 0); // Red wing
    glBegin(GL_POLYGON);
    glVertex2f(768, 913);
    glVertex2f(814, 953);
    glVertex2f(843, 953);
    glVertex2f(750, 850);
    glEnd();

    glColor3ub(204, 0, 0); // Red bottom wing
    glBegin(GL_POLYGON);
    glVertex2f(501, 873);
    glVertex2f(789, 873);
    glVertex2f(750, 850);
    glVertex2f(539, 845);
    glEnd();

    glColor3ub(230, 230, 230); // Light gray highlight
    glBegin(GL_POLYGON);
    glVertex2f(501.4236986901527, 873.9999236979464);
    glVertex2f(570.2523412282366, 910.3807776109325);
    glVertex2f(556, 873);
    glEnd();

    glColor3ub(100, 100, 100);  // Darker gray for details
    glBegin(GL_POLYGON);
    glVertex2f(659, 848);
    glVertex2f(682.344701933116, 823.8533412773442);
    glVertex2f(709.8761589483496, 825.8198739212894);
    glVertex2f(693.1273870115938, 848.9627981394879);
    glEnd();

    glColor3ub(100, 100, 100);  // Darker gray tail
    glBegin(GL_POLYGON);
    glVertex2f(658, 911);
    glVertex2f(695.8062440991109, 942.9567808612461);
    glVertex2f(715.5337787045539, 943.4626150818985);
    glVertex2f(694, 912);
    glEnd();

    // Windows of the plane (black)
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(572, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 572 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(594, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 594 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(618, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 618 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(641, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 641 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(665, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 665 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(688, 888);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        float x = 688 + 10 * cos(angle);
        float y = 888 + 10 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
     glPopMatrix();
}

void hill() {
    if (day) {
       glColor3ub(0, 255, 0);
// Day: Green hills
    } else {
       glColor3ub(25, 76, 25);
 // Night: Dark green hills
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
glColor3ub(128, 89, 13);
 // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(200, 100); // Bottom of the pole (P1)
    glVertex2f(200, 200); // Top of the pole (O1)
    glEnd();

    glColor3ub(255, 0, 0);
 // Red color for the umbrella top
     glBegin(GL_TRIANGLES);
    glVertex2f(200, 300);
    glVertex2f(100, 200);
    glVertex2f(300, 200);
    glEnd();
//chair
    glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(240,100);
    glVertex2f(260,60);
    glVertex2f(300, 80);
    glVertex2f(280, 100);
    glEnd();
     glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(260,60);
    glVertex2f(380,60);
    glVertex2f(380, 80);
    glVertex2f(300, 80);
    glEnd();

    // Second Umbrella
   glColor3ub(128, 89, 13);
 // Brown color for the pole
    glBegin(GL_LINES);
    glVertex2f(500, 100); // Bottom of the pole (P2)
    glVertex2f(500, 200); // Top of the pole (O2)
    glEnd();

   glColor3ub(255, 0, 0);
 // Red color for the umbrella top
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
    glVertex2f(560, 100);
    glVertex2f(580, 60);
    glVertex2f(640, 80);
    glVertex2f(620, 100);
    glEnd();
     glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(580, 60);
    glVertex2f(640, 80);
    glVertex2f(760, 80);
    glVertex2f(740, 60);
    glEnd();

}
void tower() {
    // Triangle top (red)
   glColor3ub(255, 0, 0);
 // Red color
    glBegin(GL_TRIANGLES);
        glVertex2f(900, 200);
        glVertex2f(1000, 250);
        glVertex2f(1100, 200);
    glEnd();

    // Triangle legs (brown)
   glColor3ub(128, 89, 13);
 // Brown color
    glLineWidth(5.0f); // Set line thickness to 5 pixels
    glBegin(GL_LINES);
        glVertex2f(900, 200); // Left leg
        glVertex2f(900, 150);
        glVertex2f(1100, 200); // Right leg
        glVertex2f(1100, 150);
    glEnd();

    // Box body (white)
    glColor3ub(255, 255, 255); // White color
    glBegin(GL_QUADS);
        glVertex2f(850, 150);
        glVertex2f(1150, 150);
        glVertex2f(1150, 100);
        glVertex2f(850, 100);
    glEnd();

    // Two legs (brown)
    glColor3ub(128, 89, 13);
 // Brown color
    glLineWidth(5.0f); // Set line thickness to 5 pixels
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


void sun() {
    if (day){
        glColor3ub(255, 255, 0);

    }
    else{
       glColor3ub(255, 255, 255);

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
        glColor3ub(255, 255, 255);
 // Day: White clouds
    } else {
       glColor3ub(128, 128, 128);
 // Night: Gray clouds
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
    glColor3ub(255, 0, 0);

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
    glColor3ub(128, 89, 13);

    glBegin(GL_QUADS);
    glVertex2f(200, 850); // Top-left corner (A3)
    glVertex2f(300, 850); // Top-right corner (B3)
    glVertex2f(300, 800); // Bottom-right corner
    glVertex2f(200, 800); // Bottom-left corner
    glEnd();

    // Ropes (Two lines connecting balloon to basket)
    if (day){
        glColor3ub(255, 255, 0);

    }
    else{
       glColor3ub(255, 255, 255);

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

    glColor3ub(128, 128, 255);
 // Light blue color for raindrops

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
       glColor3ub(159, 237, 254);
 // Light blue for day
    } else {
       glColor3ub(0, 0, 0);

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
       glColor3ub(0, 128, 204);
 // Day sea (blue)
    } else {
        glColor3ub(0, 0, 102);
 // Night sea (dark blue)
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
      glColor3ub(230, 204, 153);
 // Day sand (light brown)
    } else {
       glColor3ub(77, 51, 26);
 // Night sand (dark brown)
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
    tower();
    plane();




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
     planePosX -= 4.0f; // Move the plane to the left
    if (planePosX < -800) { // Reset position when it goes off-screen
        planePosX = 1500;
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
