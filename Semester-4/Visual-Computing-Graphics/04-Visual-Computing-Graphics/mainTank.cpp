#include <GL/glut.h>
#include <cmath>

// Variabel rotasi turret dan elevasi meriam
float turretRotation = 0.0f;
float gunElevation = 0.0f;

// Fungsi menggambar lingkaran (roda)
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

// Fungsi menggambar track (bantalan roda) yang mengelilingi roda
void drawTrack() {
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam
    glBegin(GL_POLYGON);
    glVertex2f(-0.55f, -0.35f);
    glVertex2f(0.55f, -0.35f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.55f, 0.1f);
    glVertex2f(-0.55f, 0.1f);
    glVertex2f(-0.6f, 0.05f);
    glVertex2f(-0.6f, -0.3f);
    glEnd();
}

// Fungsi menggambar tank 2D
void drawTank() {
    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau

    // *BADAN TANK*
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glEnd();

    // *TURRET (KEPALA TANK)*
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);
    glRotatef(turretRotation, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    // *MERIAM*
    glPushMatrix();
    glTranslatef(0.1f, 0.1f, 0.0f);
    glRotatef(gunElevation, 0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(0.3f, 0.02f);
    glVertex2f(0.3f, -0.02f);
    glVertex2f(0.0f, -0.02f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    // *TRACK (BANTALAN RODA)*
    drawTrack();

    // *RODA-RODA TANK*
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = -2; i <= 2; i++) {
        drawCircle(i * 0.2f, -0.25f, 0.07f);
    }
}

// Fungsi tampilan utama
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawTank();

    glutSwapBuffers();
}

// Fungsi kontrol keyboard
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') turretRotation += 5.0f;
    if (key == 'd') turretRotation -= 5.0f;
    if (key == 'w') gunElevation += 2.0f;
    if (key == 's') gunElevation -= 2.0f;
    glutPostRedisplay();
}

// Inisialisasi OpenGL
void init() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Tank OpenGL");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
