#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

float aCor = 0.0, bCor = 0.0, cCor = 0.0;




void desenhaTriangulo(){
    glBegin(GL_TRIANGLES);
       
       glColor3f(aCor, bCor, cCor);
       glVertex2f(0.4, 0.0);
       glVertex2f(0.0, 0.0);
       glVertex2f(0.4/2,0.4);

       glEnd();
}

void desenhaRetangulo(){
    glBegin(GL_POLYGON);
        
        glColor3f(aCor, bCor, cCor);
        glVertex2f(0.0, 0.1); 
        glVertex2f(-0.2, 0.1); 
        glVertex2f(-0.2, -0.1); 
        glVertex2f(0.0, -0.1); 
    

     glEnd();
    
    }

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);

   glPushMatrix();
      glTranslatef(0.2, -0.2, 0.0);
      glRotatef(90, 0.0, 0.0, 1.0);
      desenhaTriangulo();
      glPopMatrix();

   glPushMatrix();
      glTranslatef(-0.4, 0.2, 0.0);
      glRotatef(-90, 0.0, 0.0, 1.0);
      desenhaTriangulo();
      glPopMatrix();

   glPushMatrix();
      glTranslatef(0.1, 0.3, 0.0);
      glRotatef(180, 0.0, 0.0, 1.0);
      desenhaTriangulo();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.3, -0.3, 0.0);
      desenhaTriangulo();
      glPopMatrix();

   glPushMatrix();
      glTranslatef(0.0, 0.0, 0.0);
      desenhaRetangulo();
      glPopMatrix();

    glFlush(); 
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 'c'|| tecla == 'C') { 

     aCor = (float)rand() / RAND_MAX;
     bCor = (float)rand() / RAND_MAX;
     cCor = (float)rand() / RAND_MAX;
     
        glutPostRedisplay(); 
    }
}

int main(int argc, char** argv) {
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ana");
     
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutMainLoop();
    return 0;
}