#include <GL/glut.h> // Header file untuk menggunakan fungsi OpenGL dan GLUT

GLfloat xRotated, yRotated, zRotated; // Variabel global untuk menyimpan sudut rotasi pada sumbu x, y, dan z

// Fungsi untuk menampilkan objek
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Membersihkan buffer warna
    glLoadIdentity(); // Mereset matriks model-view

    glTranslatef(0.0, 0.0, -4.0); // Menerjemahkan objek ke posisi z = -4 untuk memindahkannya ke dalam layar

    glRotatef(xRotated, 1.0, 0.0, 0.0); // Rotasi objek di sekitar sumbu x dengan sudut xRotated
    glRotatef(yRotated, 0.0, 1.0, 0.0); // Rotasi objek di sekitar sumbu y dengan sudut yRotated
    glRotatef(zRotated, 0.0, 0.0, 1.0); // Rotasi objek di sekitar sumbu z dengan sudut zRotated

    glScalef(2.0, 1.0, 1.0); // Skala objek dengan memperbesar di sumbu x sebanyak 2 kali

    glutWireCube(1.0); // Menggambar kubus wireframe dengan ukuran 1.0
    glFlush(); // Memastikan semua perintah OpenGL dieksekusi secepat mungkin
    glutSwapBuffers(); // Menukar buffer untuk menghasilkan animasi yang halus
}

// Fungsi untuk mengatur ulang tampilan saat ukuran jendela diubah
void Reshape(int x, int y) {
    if (y == 0 || x == 0) return; // Mencegah pembagian dengan nol

    glMatrixMode(GL_PROJECTION); // Mengatur matriks proyeksi
    glLoadIdentity(); // Mereset matriks proyeksi
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0); // Mengatur perspektif dengan sudut 40 derajat

    glMatrixMode(GL_MODELVIEW); // Beralih ke matriks model-view
    glViewport(0, 0, x, y); // Menentukan viewport sesuai dengan ukuran jendela
}

// Fungsi yang dipanggil saat idle untuk mengupdate rotasi
void Idle(void) {
    xRotated += 0.3; // Menambahkan 0.3 derajat ke rotasi sumbu x
    yRotated += 0.1; // Menambahkan 0.1 derajat ke rotasi sumbu y
    zRotated += -0.4; // Mengurangi 0.4 derajat dari rotasi sumbu z
    Display(); // Memanggil fungsi Display untuk merender ulang objek
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT dengan argumen
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Mengatur mode tampilan dengan double buffering dan warna RGB
    glutInitWindowSize(300, 300); // Menentukan ukuran jendela
    glutCreateWindow("Cube example"); // Membuat jendela dengan judul "Cube example"

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Mengatur mode poligon untuk menggambar garis (wireframe)

    xRotated = yRotated = zRotated = 0.0; // Inisialisasi sudut rotasi ke 0
    glClearColor(0.0, 0.0, 0.0, 0.0); // Menentukan warna latar belakang sebagai hitam

    glutDisplayFunc(Display); // Menentukan fungsi callback untuk menggambar tampilan
    glutReshapeFunc(Reshape); // Menentukan fungsi callback untuk merespons perubahan ukuran jendela
    glutIdleFunc(Idle); // Menentukan fungsi callback yang dipanggil saat program idle

    glutMainLoop(); // Memulai loop utama GLUT untuk memproses event
    return 0; // Mengembalikan nilai 0 sebagai tanda program selesai dengan sukses
}

