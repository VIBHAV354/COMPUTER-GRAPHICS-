#include <GL/freeglut.h>

// Function to display content
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the drawing color to red
    glColor3f(1.0f, 0.0f, 0.0f);

    // Draw a rectangle
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set the display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the window size
    glutInitWindowSize(500, 500);
    // Set the window position
    glutInitWindowPosition(100, 100);
    // Create the window with a title
    glutCreateWindow("Simple FreeGLUT Program");

    // Set the background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
