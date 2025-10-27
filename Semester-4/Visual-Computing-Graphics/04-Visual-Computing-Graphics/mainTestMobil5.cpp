#include <GL/glut.h>
#include <cmath>

void drawCloud(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glScalef(scale, scale, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(i * 0.1f, 0.0, 0.0);
        glBegin(GL_POLYGON);
        for (int angle = 0; angle < 360; angle += 10) {
            float rad = angle * 3.14159 / 180;
            glVertex2f(cos(rad) * 0.1, sin(rad) * 0.05);
        }
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Background - Sky
    glColor3f(0.529, 0.808, 0.922);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
    
    // Sun
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(0.7 + 0.1 * cos(i * 3.14159 / 180), 0.7 + 0.1 * sin(i * 3.14159 / 180));
    glEnd();
    
    // Sun Rays
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < 360; i += 30) {
    	float xStart = 0.7 + 0.1 * cos(i * 3.14159 / 180);
    	float yStart = 0.7 + 0.1 * sin(i * 3.14159 / 180);
    	float xEnd = 0.7 + 0.15 * cos(i * 3.14159 / 180);
    	float yEnd = 0.7 + 0.15 * sin(i * 3.14159 / 180);
    
    	glBegin(GL_LINES);
    	glVertex2f(xStart, yStart);
    	glVertex2f(xEnd, yEnd);
    	glEnd();
	}

    
    // Draw Clouds
    drawCloud(-0.7, 0.8, 1.0);
    drawCloud(0.5, 0.75, 1.2);
    drawCloud(-0.2, 0.6, 0.8);
    drawCloud(0.2, 0.9, 0.9);
    
    // Background - Grass
    glColor3f(0.196, 0.804, 0.196);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();

    // Car Body with upward curve
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, 0.1);
    for (float angle = 0; angle <= 180; angle += 10) {
        glVertex2f(0.3 * cos(angle * 3.14159 / 180), 0.1 + 0.05 * sin(angle * 3.14159 / 180));
    }
    glVertex2f(-0.5, 0.1);
    glEnd();

    // Car Roof
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.2, 0.3);
    glVertex2f(-0.2, 0.3);
    glEnd();

    // Single Window with Middle Cut
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.22, 0.12);
    glVertex2f(0.22, 0.12);
    glVertex2f(0.15, 0.28);
    glVertex2f(-0.15, 0.28);
    glEnd();

    // Middle Cut
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.02, 0.12);
    glVertex2f(0.02, 0.12);
    glVertex2f(0.02, 0.28);
    glVertex2f(-0.02, 0.28);
    glEnd();

    // Door Handles
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, -0.05);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.18, 0.0);

    glVertex2f(0.1, -0.05);
    glVertex2f(0.18, -0.05);
    glVertex2f(0.18, 0.0);
    glVertex2f(0.1, 0.0);
    glEnd();

    // Front and Rear Lights (adjusted to be inside car body)
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.48, -0.18);
    glVertex2f(0.5, -0.18);
    glVertex2f(0.5, -0.1);
    glVertex2f(0.48, -0.1);

    glVertex2f(-0.5, -0.18);
    glVertex2f(-0.48, -0.18);
    glVertex2f(-0.48, -0.1);
    glVertex2f(-0.5, -0.1);
    glEnd();

    // Siren
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.3);
    glVertex2f(0.05, 0.3);
    glVertex2f(0.05, 0.35);
    glVertex2f(-0.05, 0.35);
    glEnd();

    // Wheels - Outer Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(-0.3 + 0.08 * cos(i * 3.14159 / 180), -0.2 + 0.08 * sin(i * 3.14159 / 180));
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(0.3 + 0.08 * cos(i * 3.14159 / 180), -0.2 + 0.08 * sin(i * 3.14159 / 180));
    glEnd();

    // Wheels - Inner White (Rim)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(-0.3 + 0.04 * cos(i * 3.14159 / 180), -0.2 + 0.04 * sin(i * 3.14159 / 180));
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(0.3 + 0.04 * cos(i * 3.14159 / 180), -0.2 + 0.04 * sin(i * 3.14159 / 180));
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Mobil 2D OpenGL");
    glutInitWindowSize(800, 600);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

