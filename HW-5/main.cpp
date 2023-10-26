#include <GL/glut.h>
#include <cmath>

float angle = 0.0f;
float rotation_center_x = 1.0f;
float rotation_center_y = 7.0f;

// Titik A dan B
// NIM 12871 A(1,7) B(8,2)
float x1 = 1.0f;
float y1 = 7.0f;
float x2 = 8.0f;
float y2 = 2.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // Simpan matriks saat ini

    // Translasi agar pusat rotasi berada di (0, 0)
    glTranslatef(rotation_center_x, rotation_center_y, 0.0f);
    
    // Rotasi
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Translasi balik ke posisi semula
    glTranslatef(-rotation_center_x, -rotation_center_y, 0.0f);

    // Gambar garis yang menghubungkan titik A dan B
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);  // Warna hijau
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    glPopMatrix(); // Kembalikan matriks sebelumnya

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
            angle += 10.0f; // Rotasi sebesar 10 derajat searah jarum jam
            break;
        case 'R':
            angle -= 10.0f; // Rotasi sebesar 10 derajat berlawanan arah jarum jam
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotation in OpenGL with Points A(1,7) and B(8,2)");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

