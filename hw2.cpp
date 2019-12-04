/*******************************************************
 * Homework 2: OpenGL                                  *
 * CS 148 (Summer 2016), Stanford University           *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples
float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {  
    int num_teapots = 10;

    // Find the angle we have to rotate each teapot to fill the ring
	int angle = 360/num_teapots;

	// Step by each angle
	for (int i = 0; i < 360; i+=angle) {
    	glPushMatrix();  
		glRotatef(i, 0.0f, 0.0f, 1.0f); // Rotate the teapot around the z axis for given angle
		glTranslatef (1, 0, 0); // Translate to the amount of radius of the ring
		glutSolidTeapot(0.2); // Then create the teapot in the location
	    glPopMatrix();
	}
}

void problem2() {
	int steps = 15; // Number of steps
	glPushMatrix(); 
	// Start from -1.6 on x axis
	glTranslatef(-1.60,0,0);	
	for (int i = 0; i < steps; i++) {
		// We cannot draw the step just using one cube. We stack them to create it.
		for(int j = 0; j <= i; j++){
			glPushMatrix();
			// Each cube is 1/4 swifted up than the previous one.
			glTranslatef(i*0.2,0.25*j*0.2,0);
			glutSolidCube(0.2);
			glPopMatrix();
		}
	}
	glPopMatrix();
}


void problem3() {
	// Number of rows of the triangle
    int height = 6;

    // Distance from one teapot to the other.
    float dist = 0.8;
    float x = 0;
    float y = 1;
    // For each row
	for (int i = 0; i < height; i++) {
		// For each teapot
		for (int j = 0; j <= i; j++) {
			glPushMatrix();  
			// Translate to the required position and draw the teapot
			glTranslatef (x+j*dist, y, 0);
			glutSolidTeapot(0.2);
		    glPopMatrix();
		}
		x = x-dist/2;
		y = y-0.5;
	}
}


void problem4() {
	// Draw the palm of the hand using a triangle 
    glBegin(GL_TRIANGLES);
      glVertex3f(-0.6f,0,0);
      glVertex3f(0.6f,0,0);
      glVertex3f(0,-2.0f,0);
    glEnd();

    // Little finger
	glPushMatrix();

	// Translate and rotate the whole finger to our desired location
	glTranslatef (-0.45, 0.2, 0);
	glRotatef(6, 0.0f, 0.0f, 1.0f);
	glPushMatrix(); 

	// We create each segment using a cube and position it. The bent effect is achieved by rotating sequentially 
	glRotatef(80, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(80, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(80, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

    // Ring finger
	glPushMatrix();

	// Translate and rotate the whole finger to our desired location
	glTranslatef (-0.15, 0.2, 0);
	glRotatef(2, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	// We create each segment using a cube and position it. The bent effect is achieved by rotating sequentially 
	glRotatef(50, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(50, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(50, 1.0f, 0.0f, 0.0f);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

    // Middle finger
	glPushMatrix();

	// Translate and rotate the whole finger to our desired location
	glTranslatef (0.15, 0.2, 0);
	glRotatef(-2, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	// We create each segment using a cube and position it.
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

    // Index finger
	glPushMatrix();

	// Translate and rotate the whole finger to our desired location
	glTranslatef (0.45, 0.2, 0);
	glRotatef(-6, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	// We create each segment using a cube and position it.
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

    // Thumb
    glPushMatrix();

	// Translate and rotate the whole finger to our desired location
	glTranslatef (0.6, -0.5, 0);
	glRotatef(20, 1.0f, 0.0f, 0.0f);
	glRotatef(-16, 0.0f, 0.0f, 1.0f);
	glPushMatrix();

	// We create each segment using a cube and position it. The bent effect is achieved by rotating sequentially 
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(50, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glRotatef(50, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();
}


void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis

	glEnd(/*GL_LINES*/);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);
	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);
	glRotatef(yRot,0,1,0);
	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);
	lastPos[0] = x;
	lastPos[1] = y;
}


void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}
	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){ exit(0);}
	glutPostRedisplay();
}


void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");
	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
