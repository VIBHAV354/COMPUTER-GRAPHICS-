//hut

#include <GL/glut.h>
GLfloat bgColor[3] = { 0.53f, 0.81f, 0.92f }; 
GLfloat windowColor[3] = { 1.0f, 1.0f, 1.0f }; 

bool isDark = false;

void drawHut() {
    
    glColor3f(0.6f, 0.4f, 0.2f); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(-0.5f, 0.2f);
    glEnd();

   
    glColor3f(0.7f, 0.1f, 0.1f); 
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.55f, 0.2f);
    glVertex2f(0.55f, 0.2f);
    glVertex2f(0.0f, 0.6f);
    glEnd();

   
    glColor3f(0.3f, 0.2f, 0.1f); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    
    glColor3fv(windowColor); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glEnd();
}

void display() {
   
    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawHut();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isDark) {
            bgColor[0] = 0.53f; bgColor[1] = 0.81f; bgColor[2] = 0.92f; 
            windowColor[0] = 1.0f; windowColor[1] = 1.0f; windowColor[2] = 1.0f; 
        }
        else {
            bgColor[0] = 0.0f; bgColor[1] = 0.0f; bgColor[2] = 0.5f; 
            windowColor[0] = 1.0f; windowColor[1] = 1.0f; windowColor[2] = 0.0f; 
        }
        isDark = !isDark;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hut Toggle Colors");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}




//line mouse click
/*

#include <GL/freeglut.h>
#include <cstdlib>

GLfloat lineColor[3] = { 1.0f, 1.0f, 1.0f };

float startX = -1.0f, startY = -1.0f;
float endX = -1.0f, endY = -1.0f;
bool isFirstClick = true;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float winX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2.0f - 1.0f;
        float winY = 1.0f - (float)y / glutGet(GLUT_WINDOW_HEIGHT) * 2.0f;

        if (isFirstClick) {
            startX = winX;
            startY = winY;
            isFirstClick = false;
        }
        else {
            endX = winX;
            endY = winY;
            isFirstClick = true;
        }

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        lineColor[0] = 1.0f; // Red
        lineColor[1] = 0.0f;
        lineColor[2] = 0.0f;
    }
    else if (key == 'g' || key == 'G') {
        lineColor[0] = 0.0f;
        lineColor[1] = 1.0f; // Green
        lineColor[2] = 0.0f;
    }
    else if (key == 'b' || key == 'B') {
        lineColor[0] = 0.0f;
        lineColor[1] = 0.0f;
        lineColor[2] = 1.0f; // Blue
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(lineColor);

    if (!isFirstClick) {
        glBegin(GL_LINES);
        glVertex2f(startX, startY);
        glVertex2f(endX, endY);
        glEnd();
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Drawing on Click");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
*/
