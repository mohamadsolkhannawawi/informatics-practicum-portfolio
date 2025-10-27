#include <gl/glut.h>

void Segitiga(void)
{
    glTranslatef(0.25, -0.25, 0.0);  // Translate the triangle's position
    glRotated(60.0, 0.0, 0.0, 1.0);  // Rotate the triangle 60 degrees around the Z-axis

    glBegin(GL_TRIANGLES);  // Begin drawing a triangle
        glColor3f(1.0f, 0.0f, 0.0f);  // Set the first vertex color to red
        glVertex3f(-0.05, -0.05, -0.00);  // Define first vertex
        glColor3f(0.0f, 1.0f, 0.0f);  // Set the second vertex color to green
        glVertex3f(0.15, -0.05, -0.00);  // Define second vertex
        glColor3f(0.0f, 0.0f, 1.0f);  // Set the third vertex color to blue
        glVertex3f(-0.05, 0.05, -0.00);  // Define third vertex
    glEnd();  // End drawing the triangle
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitWindowSize(640, 480);  // Set window size
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutCreateWindow("Segi Empat");  // Create a window with the title "Segi Empat"
    glutDisplayFunc(Segitiga);  // Set the display function to draw the triangle
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // Set background color to blue
    glutMainLoop();  // Start the GLUT main loop
    return 0;
}
