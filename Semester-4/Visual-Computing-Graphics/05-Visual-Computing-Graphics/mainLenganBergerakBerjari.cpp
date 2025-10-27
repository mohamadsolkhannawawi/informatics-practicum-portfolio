#include <GL/glut.h>

// Variabel rotasi untuk setiap bagian
static int bahu = 0, siku = 0, pergelangan = 0;
static int ibu_jari = 0, telunjuk = 0, jari_tengah = 0, jari_manis = 0, kelingking = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    //bahu
	glTranslatef(-1.0, 0.0, 0.0); // Memindahkan objek ke kiri sebelum rotasi
	glRotatef((GLfloat) bahu, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Pergelangan tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) pergelangan, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.7);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari-jari
    int jari_angles[] = {ibu_jari, telunjuk, jari_tengah, jari_manis, kelingking};
    float posisi_jari[] = {0.3, 0.15, 0.0, -0.15, -0.3};

    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(0.5, posisi_jari[i], 0.0);
        glRotatef((GLfloat) jari_angles[i], 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
        glPushMatrix();
        glScalef(0.4, 0.1, 0.1);
        glutWireCube(1.0);
        glPopMatrix();
        glPopMatrix();
    }
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, -0.5, -7.0); 
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'b': bahu = (bahu + 5) % 360; break;
        case 'B': bahu = (bahu - 5) % 360; break;
        case 's': siku = (siku + 5) % 360; break;
        case 'S': siku = (siku - 5) % 360; break;
        case 'p': pergelangan = (pergelangan + 5) % 360; break;
        case 'P': pergelangan = (pergelangan - 5) % 360; break;
        case '1': ibu_jari = (ibu_jari + 5) % 90; break;
        case '!': ibu_jari = (ibu_jari - 5) % 90; break;
        case '2': telunjuk = (telunjuk + 5) % 90; break;
        case '@': telunjuk = (telunjuk - 5) % 90; break;
        case '3': jari_tengah = (jari_tengah + 5) % 90; break;
        case '#': jari_tengah = (jari_tengah - 5) % 90; break;
        case '4': jari_manis = (jari_manis + 5) % 90; break;
        case '$': jari_manis = (jari_manis - 5) % 90; break;
        case '5': kelingking = (kelingking + 5) % 90; break;
        case '%': kelingking = (kelingking - 5) % 90; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan Robot dengan Telapak dan Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

