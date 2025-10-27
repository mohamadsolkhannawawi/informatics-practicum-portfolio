#include <GL/glut.h>
#include <cmath>

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

    // Background - Grass
    glColor3f(0.196, 0.804, 0.196);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();

    // Clouds
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.5, 0.65);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.5, 0.55);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.4, 0.7);
    glVertex2f(0.5, 0.75);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.5, 0.65);
    glEnd();

    // Car Body with slanted front and rear
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.5, -0.25);
    glVertex2f(0.5, -0.25);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();

    // Car Roof
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.1);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.3, 0.3);
    glVertex2f(-0.3, 0.3);
    glEnd();

    // Single Window with Middle Cut
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.28, 0.12);
    glVertex2f(0.2, 0.28);
    glVertex2f(-0.2, 0.28);
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
    glVertex2f(-0.25, -0.05);
    glVertex2f(-0.15, -0.05);
    glVertex2f(-0.15, 0.0);
    glVertex2f(-0.25, 0.0);

    glVertex2f(0.15, -0.05);
    glVertex2f(0.25, -0.05);
    glVertex2f(0.25, 0.0);
    glVertex2f(0.15, 0.0);
    glEnd();

    // Front and Rear Lights
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.65, -0.1);
    glVertex2f(0.65, 0.0);
    glVertex2f(0.6, 0.0);

    glVertex2f(-0.65, -0.1);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.65, 0.0);
    glEnd();

    // Siren
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.3);
    glVertex2f(0.05, 0.3);
    glVertex2f(0.05, 0.35);
    glVertex2f(-0.05, 0.35);
    glEnd();

    // Wheels
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(-0.4 + 0.08 * cos(i * 3.14159 / 180), -0.25 + 0.08 * sin(i * 3.14159 / 180));
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10)
        glVertex2f(0.4 + 0.08 * cos(i * 3.14159 / 180), -0.25 + 0.08 * sin(i * 3.14159 / 180));
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

