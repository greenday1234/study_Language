//
//  Point Rotate.cpp
//  Graphics
//
//  Created by 이찬희 on 2023/04/13.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <iostream>

void draw_cube() {
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.4);
    glVertex2f(0.8, 0.4);
    glVertex2f(0.8, 0.6);
    glVertex2f(0.2, 0.6);
    glEnd();
}

void draw_point() {
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.5, 0.5);
    glEnd();
}

void draw_lines() {
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);   //red
    draw_cube();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);   //green
    glRotatef(45, 0.0, 0.0, 1.0);
    draw_cube();
    glPopMatrix();

    glColor3f(0.0, 0.0, 1.0);   //blue
    glTranslatef(0.5, 0.5, 0.0);
    glRotatef(45, 0.0, 0.0, 1.0);
    glTranslatef(-0.5, -0.5, 0.0);
    draw_cube();

    glColor3f(0.0, 0.0, 0.0);
    draw_point();

    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.0);
    draw_lines();

    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
}

void reshape(int new_w, int new_h) {
    glViewport(0, 0, new_w, new_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Point Rotate");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
