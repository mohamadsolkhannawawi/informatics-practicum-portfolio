#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// Variabel bola
GLfloat ballPosX = 0.0f, ballPosZ = 5.0f;
GLfloat ballVelX = 0.0f, ballVelZ = 0.0f;
const float friction = 0.98f;
const float arenaMin = -9.8f, arenaMax = 9.8f;

// Variabel kamera mengikuti bola
float cameraDistance = 5.0f; // Jarak tetap kamera dari bola
float cameraAngle = 0.0f;    // Arah kamera mengikuti bola

// Inisialisasi OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
}

// Menggambar lantai (ground)
void drawGround() {
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-10.0f, 0.0f, -10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(10.0f, 0.0f, -10.0f);
    glEnd();
}

// Menggambar bola
void drawBall() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
        glTranslatef(ballPosX, 0.2f, ballPosZ);
        glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
}

// Menghitung posisi kamera mengikuti bola
void updateCamera() {
    // Jika bola bergerak, hitung sudut pergerakannya
    if (ballVelX != 0.0f || ballVelZ != 0.0f) {
        cameraAngle = atan2(ballVelZ, ballVelX);  // Sudut berdasarkan kecepatan bola
    }

    // Posisi kamera selalu di belakang bola
    float cameraX = ballPosX - cameraDistance * cos(cameraAngle);
    float cameraZ = ballPosZ - cameraDistance * sin(cameraAngle);
    float cameraY = 2.0f; // Ketinggian tetap agar bisa melihat bola

    // Atur kamera untuk mengikuti bola
    gluLookAt(cameraX, cameraY, cameraZ,  // Posisi kamera
              ballPosX, 0.5f, ballPosZ,   // Fokus ke bola
              0.0f, 1.0f, 0.0f);          // Up vector
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    updateCamera(); // Kamera mengikuti bola

    drawGround();
    drawBall();

    glutSwapBuffers();
}

// Fungsi update untuk memindahkan bola
void update(int value) {
    ballPosX += ballVelX;
    ballPosZ += ballVelZ;

    // Gesekan
    ballVelX *= friction;
    ballVelZ *= friction;

    // Batasi bola dalam arena
    if (ballPosX < arenaMin) { ballPosX = arenaMin; ballVelX = -ballVelX * 0.7f; }
    if (ballPosX > arenaMax) { ballPosX = arenaMax; ballVelX = -ballVelX * 0.7f; }
    if (ballPosZ < arenaMin) { ballPosZ = arenaMin; ballVelZ = -ballVelZ * 0.7f; }
    if (ballPosZ > arenaMax) { ballPosZ = arenaMax; ballVelZ = -ballVelZ * 0.7f; }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Fungsi keyboard untuk menggerakkan bola dengan WASD
void keyboard(unsigned char key, int x, int y) {
    float speed = 0.1f;
    switch (key) {
        case 'w': ballVelZ -= speed; break;
        case 's': ballVelZ += speed; break;
        case 'a': ballVelX -= speed; break;
        case 'd': ballVelX += speed; break;
        case 27:  exit(0); break;
    }
}

// Fungsi reshape
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Mini Golf - Kamera Mengikuti Bola");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}

