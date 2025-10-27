#include <gl/glut.h>

void SegiEmpat(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(-0.50, 0.50, 0.0);  // Move the rectangle
    glColor3f(1.0f, 0.0f, 0.0f);     // Set the color to red
    glRectf(-0.18, 0.18, 0.18, -0.18); // Draw the rectangle
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(SegiEmpat);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set background color to blue
    glutMainLoop();
    return 0;
}
