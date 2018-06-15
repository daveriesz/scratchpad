/* from http://www.glprogramming.com/red/chapter08.html */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

GLubyte rastersF[24] = {
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xff, 0x00, /* 65: [ XXXXXXXX........ ] */
  0xff, 0x00, /* 65: [ XXXXXXXX........ ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xc0, 0x00, /* 65: [ XX.............. ] */
  0xff, 0xc0, /* 65: [ XXXXXXXXXX...... ] */
  0xff, 0xc0, /* 65: [ XXXXXXXXXX...... ] */
};

GLubyte rastersA[10] = {
  0x00, /* [ ........ ] */
  0x00, /* [ ........ ] */
  0x44, /* [ .X...X.. ] */
  0x44, /* [ .X...X.. ] */
  0x7c, /* [ .XXXXX.. ] */
  0x44, /* [ .X...X.. ] */
  0x44, /* [ .X...X.. ] */
  0x28, /* [ ..X.X... ] */
  0x10, /* [ ...X.... ] */
  0x00, /* [ ........ ] */
};

void init(void)
{
  glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (20, 20);
  glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rastersF);
  glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rastersF);
  glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rastersF);
  glBitmap ( 7, 10, 0.0, 0.0, 11.0, 0.0, rastersA);
  glBitmap ( 7, 10, 0.0, 0.0, 11.0, 0.0, rastersA);
  glBitmap ( 7, 10, 0.0, 0.0, 11.0, 0.0, rastersA);
  glFlush();
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho (0, w, 0, h, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27: case 'q':
      exit(0);
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(100, 100);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

