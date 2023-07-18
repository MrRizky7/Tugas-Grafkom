#include<windows.h>
#include<gl/glut.h>
#include<stdlib.h>
#include "imageloader.h"

using namespace std;

void init(void);
void idle(void);
void tampil(void);
void ukuran(int, int);

void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

GLuint _textureId; //ID OpenGL untuk tekstur
GLuint _textureId2; //ID OpenGL untuk tekstur
GLuint _textureId3; //ID OpenGL untuk tekstur

bool mouseDown = false;

int is_depth;

GLuint loadTexture(Image* image) {
GLuint textureId;
glGenTextures(1, &textureId);
glBindTexture(GL_TEXTURE_2D, textureId);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
return textureId;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
	Image* image1 = loadBMP("logo.bmp");    //ganti nama file foto anda formatx harus .bmp
	_textureId = loadTexture(image1);
	delete image1;

	Image* image2 = loadBMP("1.bmp");//ganti nama file foto anda formatx harus .bmp
	_textureId2 = loadTexture(image2);
	delete image2;

	Image* image3 = loadBMP("2.bmp");//ganti nama file foto anda formatx harus .bmp
	_textureId3 = loadTexture(image3);
	delete image3;
}


void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);// posisi mata
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    // Codenya tulis disini
  // depan
  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0, -20.0, 20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0, 20.0, 20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0, 20.0, 20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0, -20.0, 20);
    glEnd();

    // belakang
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0, -20.0, -20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0, 20.0, -20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0, 20.0, -20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0, -20.0, -20);
    glEnd();

    // atas
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0, 20.0, 20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0, 20.0, -20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0, 20.0, -20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0, 20.0, 20);
    glEnd();

    // bawah
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0,-20.0, 20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0,-20.0, -20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0,-20.0, -20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0,-20.0, 20);
    glEnd();

    // kiri
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-20.0,20.0, 20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-20.0,-20.0, 20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0,-20.0, -20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0,20.0, -20);
    glEnd();

    // kanan
        glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(20.0,20.0, 20);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(20.0,-20.0, 20);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0,-20.0, -20);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0,20.0, -20);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.3f;
    }
}

void mouse(int button, int state, int x, int y) {//mouse ketika ditekan
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = y - xrot;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y) {//mouse ketika lakukan motion
    if (mouseDown) {
        xrot = y - xdiff;
        yrot = x + ydiff;glutPostRedisplay();
}
}

void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);//atur ukuran
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("672020148-672020150");
    init();

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
