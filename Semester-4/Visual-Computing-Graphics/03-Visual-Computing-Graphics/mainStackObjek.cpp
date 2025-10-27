#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glPushMatrix();  // Save current transformation matrix

    // Draw a line
    	glLineWidth(2.0f);  // Set line width
    	glBegin(GL_LINES);
        	glColor3f(1.0f, 1.0f, 1.0f);  // Set line color to white
        	glVertex3f(0.00, 0.20, 0.0);  // Start point of line
        	glVertex3f(0.00, -0.20, 0.0); // End point of line
    	glEnd();
    	glPopMatrix();  // Restore previous transformation matrix

    // Draw a point
    glPushMatrix();  
    	glPointSize(5.0f);  // Set point size
    	glTranslatef(0.35, 0.35, 0.0);  // Translate the point position
   		glBegin(GL_POINTS);
        	glColor3f(1.0f, 1.0f, 1.0f);  // Set point color to white
        	glVertex3f(0.25, 0.25, 0.0);  // Define point location
    glEnd();
    glPopMatrix();  // Restore previous transformation matrix

    // Draw a triangle strip
    glPushMatrix();
    glTranslatef(0.50, 0.50, 0.00);  // Translate the triangle position
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);  // Set color to red
        glVertex3f(-0.05, -0.05, 0.00);  // First vertex
        glColor3f(0.0f, 1.0f, 0.0f);  // Set color to green
        glVertex3f(0.15, -0.05, 0.00);  // Second vertex
        glColor3f(1.0f, 1.0f, 1.0f);  // Set color to blue
        glVertex3f(-0.05, 0.05, 0.00);  // Third vertex
    glEnd();
    glPopMatrix();  // Restore previous transformation matrix

    // Draw a circle using line loop
    glPushMatrix();
    #define PI 3.1415926535898
    GLint circle_points = 100;  // Define the number of points for the circle
    int i;
    float angle;
    glBegin(GL_LINE_LOOP);  // Begin drawing the circle
        for (i = 0; i < circle_points; i++) {
            angle = 2 * PI * i / circle_points;
            glVertex2f(cos(angle), sin(angle));  // Calculate vertex position
        }
    glEnd();
    glPopMatrix();  // Restore previous transformation matrix

    glFlush();  // Render all OpenGL commands
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitWindowSize(640, 480);  // Set window size
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutCreateWindow("Simple");  // Create the window
    glutDisplayFunc(RenderScene);  // Set the function to render the scene
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // Set the background color to blue
    glutMainLoop();  // Start the GLUT main loop
    return 0;
}
