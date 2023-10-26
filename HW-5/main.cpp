#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;
float rotation_center_x = 0.0f;
float rotation_center_y = 5.0f;


float x1 = 0.0f;
float y1 = 5.0f;
float x2 = 6.0f;
float y2 = 2.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); 


    glTranslatef(rotation_center_x, rotation_center_y, 0.0f);
    

    glRotatef(angle, 0.0f, 0.0f, 1.0f);


    glTranslatef(-rotation_center_x, -rotation_center_y, 0.0f);

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);  
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glPopMatrix(); 

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
            angle += 10.0f; 
            break;
        case 'R':
            angle -= 10.0f; 
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotation in OpenGL with Points A(0,5) and B(6,2)");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

