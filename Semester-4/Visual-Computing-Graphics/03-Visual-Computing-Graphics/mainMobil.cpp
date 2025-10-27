#include <GL/glut.h>
#include <cmath>


void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawLamborghini() {
    // Body of the car
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.3, 0.25);
    glVertex2f(-0.3, 0.25);
    glVertex2f(-0.5, 0.1);
    glEnd();

    // Car windows
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 0.1);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();

    // Car doors
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, -0.2);
    glVertex2f(0.0, 0.1);
    glEnd();

    // Door handles
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINES);
    glVertex2f(-0.15, 0.0);
    glVertex2f(-0.05, 0.0);
    glVertex2f(0.05, 0.0);
    glVertex2f(0.15, 0.0);
    glEnd();

    // Wheels
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.4, -0.25, 0.1, 50);
    drawCircle(0.4, -0.25, 0.1, 50);

    // Wheel rims
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(-0.4, -0.25, 0.05, 30);
    drawCircle(0.4, -0.25, 0.05, 30);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawLamborghini();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lamborghini OpenGL");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
