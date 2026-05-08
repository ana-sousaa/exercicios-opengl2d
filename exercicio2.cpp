#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>



void desenhaCirculo() {
    glBegin(GL_POLYGON); 
        float numSegmentos = 100;
        float raio = 0.22;

        glColor3f(1.0, 0.0, 0.5);
       
        for (int i = 0; i < numSegmentos; i++) {
           
            float angulo = 2.0f * 3.1415926f * (float)i / (float)numSegmentos;
             
            float x = raio * cosf(angulo);
            float y = raio * sinf(angulo);
            
            glVertex2f(x, y);
            
        }
    glEnd();
}

void desenhaQuadrado(){
    glBegin(GL_QUADS);
    
        glColor3f(1.0, 0.7, 0.75);
        glVertex2f(0.2, 0.2); 
        glVertex2f(-0.2, 0.2); 
        glVertex2f(-0.2, -0.2);
        glVertex2f(0.2, -0.2); 

        
    glEnd();

}

void desenhaTriangulo(){
    glBegin(GL_TRIANGLES);
       
      glColor3f(0.1, 0.0, 0.5);
       glVertex2f(0.4, 0.0);
       glVertex2f(0.0, 0.0);
       glVertex2f(0.0,0.4);

       glEnd();
}

void desenhaRetangulo(){
    glBegin(GL_POLYGON);
        
       glColor3f(0.1, 0.5, 0.5);
         glVertex2f(0.3, 0.2);
        glVertex2f(-0.3, 0.2); 
         glVertex2f(-0.3, -0.2); 
        glVertex2f(0.3, -0.2); 
    

     glEnd();
    
    }

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);

   glPushMatrix();
     glTranslatef(-0.07, 0.0, 0.0);
     desenhaQuadrado();
     glPopMatrix();

   glPushMatrix(); 
      glTranslatef(0.75, 0.0, 0.0);
      desenhaCirculo();     
      glPopMatrix(); 

   glPushMatrix();
      glTranslatef(0.2, -0.2, 0.0);
      desenhaTriangulo();
      glPopMatrix();

   glPushMatrix();
      glTranslatef(-0.65, 0.0, 0.0);
      desenhaRetangulo();
      glPopMatrix();

    glFlush(); 
}


int main(int argc, char** argv) {
   

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("exercicio2");
   
    glutDisplayFunc(desenha);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutMainLoop();
    return 0;
}