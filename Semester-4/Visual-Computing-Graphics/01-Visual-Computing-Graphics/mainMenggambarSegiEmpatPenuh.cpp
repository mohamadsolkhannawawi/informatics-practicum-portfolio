/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h> 

void SegiEmpat() {
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan buffer warna

    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk segiempat

    glRectf(-0.18f, 0.18f, 0.18f, -0.18f); // Menggambar segiempat

    glFlush(); // Memproses semua perintah OpenGL
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // Menggunakan single buffer dan mode warna RGBA
    glutInitWindowSize(640, 480); // Menentukan ukuran jendela
    glutCreateWindow("Segi Empat"); // Membuat jendela dengan judul "Segi Empat"

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Warna latar belakang biru

    glutDisplayFunc(SegiEmpat); // Menghubungkan fungsi display

    glutMainLoop(); // Memulai loop GLUT

    return 0;
}

