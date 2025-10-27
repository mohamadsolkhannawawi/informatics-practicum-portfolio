#include <GL/glut.h> // Header file untuk menggunakan fungsi OpenGL dan GLUT

// Fungsi untuk menggambar tampilan
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan buffer warna
    glLoadIdentity(); // Mereset transformasi matriks model-view

    glBegin(GL_POLYGON); // Memulai penggambaran poligon
        glColor3f(0.0, 0.0, 0.0); // Menetapkan warna hitam untuk vertex berikutnya
        glVertex3f(-0.5, -0.5, -3.0); // Menentukan koordinat titik pertama dari poligon
        
        glColor3f(1.0, 0.0, 0.0); // Menetapkan warna merah untuk vertex berikutnya
        glVertex3f(0.5, -0.5, -3.0); // Menentukan koordinat titik kedua dari poligon
        
        glColor3f(0.0, 0.0, 1.0); // Menetapkan warna biru untuk vertex berikutnya
        glVertex3f(0.5, 0.5, -3.0); // Menentukan koordinat titik ketiga dari poligon
    glEnd(); // Mengakhiri penggambaran poligon

    glFlush(); // Memastikan semua perintah OpenGL dieksekusi secepat mungkin
}

// Fungsi untuk menangani perubahan ukuran jendela
void Reshape(int x, int y) {
    if (y == 0 || x == 0) return; // Mencegah pembagian dengan nol saat ukuran jendela nol

    glMatrixMode(GL_PROJECTION); // Mengatur matriks proyeksi
    glLoadIdentity(); // Mereset matriks proyeksi
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0); // Mengatur perspektif dengan sudut 40 derajat

    glMatrixMode(GL_MODELVIEW); // Beralih kembali ke matriks model-view
    glViewport(0, 0, x, y); // Menetapkan viewport agar sesuai dengan ukuran jendela
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT dengan argumen
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Mengatur mode tampilan dengan buffer tunggal dan warna RGB
    glutInitWindowSize(300, 300); // Menentukan ukuran jendela awal
    glutCreateWindow("Intro"); // Membuat jendela dengan judul "Intro"

    glClearColor(0.0, 0.0, 0.0, 0.0); // Menentukan warna latar belakang sebagai hitam

    glutDisplayFunc(Display); // Menentukan fungsi callback untuk menggambar tampilan
    glutReshapeFunc(Reshape); // Menentukan fungsi callback untuk menangani perubahan ukuran jendela
    
    glutMainLoop(); // Memulai loop utama GLUT untuk menunggu dan memproses event
    return 0; // Mengembalikan nilai 0 sebagai tanda program selesai dengan sukses
}
