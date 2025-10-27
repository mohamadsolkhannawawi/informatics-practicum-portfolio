#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float r, int num_segments, float rColor, float gColor, float bColor) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(rColor, gColor, bColor);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawThickCurve(float cx, float cy, float r, float startAngle, float endAngle, float thickness) {
    glLineWidth(thickness);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= 50; i++) {
        float theta = startAngle + (endAngle - startAngle) * float(i) / 50.0f;
        float x = r * cosf(theta) + cx;
        float y = r * sinf(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
    glLineWidth(1.0);
}

void drawEmoji() {
    // Wajah (Gradasi Kuning ke Oranye)
    glPushMatrix();
    drawCircle(0.0, 0.0, 0.5, 100, 1.0, 0.85, 0.0); // Kuning
    glPopMatrix();

    // Mata kiri dengan kombinasi warna
    glPushMatrix();
    drawCircle(-0.17, 0.05, 0.08, 50, 0.0, 0.0, 0.0); // Hitam
    drawCircle(-0.17, 0.08, 0.03, 30, 1.0, 1.0, 1.0); // Putih sorotan
    drawCircle(-0.17, 0.02, 0.04, 30, 0.0, 0.3, 1.0); // Biru di bawah mata
    glPopMatrix();

    // Mata kanan dengan kombinasi warna
    glPushMatrix();
    drawCircle(0.17, 0.05, 0.08, 50, 0.0, 0.0, 0.0); // Hitam
    drawCircle(0.17, 0.08, 0.03, 30, 1.0, 1.0, 1.0); // Putih sorotan
    drawCircle(0.17, 0.02, 0.04, 30, 0.0, 0.3, 1.0); // Biru di bawah mata
    glPopMatrix();

    // Mulut (Garis melengkung tebal)
    glPushMatrix();
    drawThickCurve(0.0, -0.15, 0.15, 3.14, 2.0 * 3.14, 3.0);
    glPopMatrix();

    // Alis kiri (melengkung ke bawah)
    glPushMatrix();
    drawThickCurve(-0.17, 0.17, 0.12, 3.14, 2.0 * 3.14, 3.0);
    glPopMatrix();

    // Alis kanan (melengkung ke bawah)
    glPushMatrix();
    drawThickCurve(0.17, 0.17, 0.12, 3.14, 2.0 * 3.14, 3.0);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawEmoji();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Emoji OpenGL");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

