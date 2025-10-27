//#include <GL/glut.h>
//
//// Fungsi untuk menggambar satu kubus
//void drawCube(float x, float y, float size) {
//    glBegin(GL_QUADS);
//        glColor3f(0.2, 0.5, 0.8); // Warna biru muda
//        glVertex2f(x, y);
//        glVertex2f(x + size, y);
//        glVertex2f(x + size, y + size);
//        glVertex2f(x, y + size);
//    glEnd();
//
//    // Garis tepi kubus
//    glColor3f(0, 0, 0); // Hitam
//    glBegin(GL_LINE_LOOP);
//        glVertex2f(x, y);
//        glVertex2f(x + size, y);
//        glVertex2f(x + size, y + size);
//        glVertex2f(x, y + size);
//    glEnd();
//}
//
//// Fungsi untuk menggambar semua kubus bertingkat
//void drawCubes() {
//    float size = 0.2;
//
//    // Baris bawah (3 kubus)
//    drawCube(-0.3, -0.3, size);
//    drawCube(-0.1, -0.3, size);
//    drawCube(0.1, -0.3, size);
//
//    // Baris atas (2 kubus)
//    drawCube(-0.2, -0.1, size);
//    drawCube(0.0, -0.1, size);
//}
//
//// Fungsi utama untuk menampilkan semua objek
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    drawCubes();
//
//    glFlush();
//}
//
//// Inisialisasi OpenGL
//void init() {
//    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//}
//
//// Main program
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Kubus Bertingkat OpenGL");
//
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}

#include <GL/glut.h>

// Fungsi untuk menggambar satu kubus dengan jarak antar kubus
void drawCube(float x, float y, float size) {
    glBegin(GL_QUADS);
        glColor3f(0.2, 0.5, 0.8); // Warna biru muda
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();

    // Garis tepi kubus
    glColor3f(0, 0, 0); // Warna hitam untuk outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

// Fungsi untuk menggambar semua kubus bertingkat dengan jarak
void drawCubes() {
    float size = 0.2;
    float spacing = 0.02; // Jarak antar kubus

    // Baris bawah (3 kubus)
    drawCube(-0.35, -0.3, size);
    drawCube(-0.1, -0.3, size);
    drawCube(0.15, -0.3, size);

    // Baris atas (2 kubus)
    drawCube(-0.225, -0.1, size);
    drawCube(0.025, -0.1, size);
}

// Fungsi utama untuk menampilkan semua objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCubes();

    glFlush();
}

// Inisialisasi OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

// Main program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kubus Bertingkat OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


