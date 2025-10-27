// **Header file yang diperlukan**
#include <stdlib.h>  // Standard library (untuk fungsi umum seperti exit)
#include <stdio.h>   // Standard I/O (untuk sprintf)
#include <math.h>    // Standard matematika (untuk operasi trigonometri)
#include <GL/glut.h> // OpenGL Utility Toolkit (GLUT) untuk manajemen jendela dan event handling

// **Variabel global**
double rotAngle = 10;  // Sudut rotasi untuk sumbu Y (global variable)
double rotAngle1 = 10; // Sudut rotasi untuk sumbu X (global variable)

//------------------------------------------------------------------
// **Fungsi init()**
// - Mengatur properti awal OpenGL
//------------------------------------------------------------------
void init()
{
    glClearColor(0, 0, 0, 0);  // Mengatur warna background menjadi hitam
    glClearDepth(1.0);         // Mengatur nilai kedalaman latar belakang

    glMatrixMode(GL_PROJECTION); // Beralih ke mode proyeksi
    glLoadIdentity();            // Mengatur matriks identitas
    gluPerspective(60, 1, 1, 1000); // Menentukan perspektif kamera: FOV = 60 derajat, aspek rasio = 1, jarak dekat = 1, jarak jauh = 1000

    glMatrixMode(GL_MODELVIEW); // Kembali ke mode model-view
    glLoadIdentity();
    gluLookAt(  
        0.0, 0.0, 5.0,  // Posisi kamera (eye position)
        0.0, 0.0, 0.0,  // Titik yang dilihat (look at position)
        0.0, 1.0, 0.0   // Arah atas (up vector)
    );
}

//------------------------------------------------------------------
// **Fungsi display()**
// - Dipanggil setiap kali layar perlu di-refresh
//------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan layar dan buffer kedalaman

    glPushMatrix(); // Menyimpan transformasi saat ini

        glRotated(rotAngle, 0, 1, 0); // Rotasi objek terhadap sumbu Y
        glRotated(rotAngle1, 1, 0, 0); // Rotasi objek terhadap sumbu X

        glEnable(GL_COLOR_MATERIAL); // Mengaktifkan warna material objek
        glColor3f(1.0, 0.1, 0.1); // Mengatur warna objek menjadi kemerahan
        glutSolidTeapot(1); // Menggambar objek berupa teko 3D (teapot)

    glPopMatrix(); // Mengembalikan transformasi sebelumnya

    glFlush();           // Memaksa OpenGL untuk merender sekarang
    glutSwapBuffers();   // Menukar buffer untuk double buffering (menghindari flickering)
}

//------------------------------------------------------------------
// **Fungsi keyboard()**
// - Dipanggil setiap kali tombol keyboard ditekan
//------------------------------------------------------------------
void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
        case 'a':
            rotAngle += 5; // Rotasi ke kanan (sumbu Y)
            break;
        case 'y':
            rotAngle1 += 5; // Rotasi ke atas (sumbu X)
            break;
        case 'b':
            rotAngle1 -= 5; // Rotasi ke bawah (sumbu X)
            break;
        case 'l':
            rotAngle -= 5; // Rotasi ke kiri (sumbu Y)
            break;
        case 'q':
            exit(0); // Keluar dari program
    }
    glutPostRedisplay(); // Meminta redisplay agar perubahan langsung terlihat
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            rotAngle -= 5; // Rotasi ke kiri
            break;
        case GLUT_KEY_RIGHT:
            rotAngle += 5; // Rotasi ke kanan
            break;
    }
    glutPostRedisplay();
}


//------------------------------------------------------------------
// **Fungsi main()**
// - Fungsi utama yang menjalankan program
//------------------------------------------------------------------
int main()
{
    // Inisialisasi GLUT dengan mode tampilan
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); 

    glutCreateWindow("GLUT Example"); // Membuat jendela dengan judul "GLUT Example"
    
    glutDisplayFunc(display);   // Menghubungkan fungsi display() ke event refresh
    glutKeyboardFunc(keyboard); // Menghubungkan fungsi keyboard() ke event keyboard
	glutSpecialFunc(specialKeys);
    init(); // Memanggil fungsi inisialisasi

    glutMainLoop(); // Memulai loop utama OpenGL (GLUT akan menangani event)
    
    
    return 0;
}
