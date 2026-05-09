#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>


void desenhaTriangulo(){
    glBegin(GL_TRIANGLES);
         
        glVertex2f(0.5, 0); 
        glVertex2f(0, 0); 
        glVertex2f(0.5/2, 0.4);
      
       glEnd();

   }


void desenhaTexto(float x, float y, const char* frase) {
    glRasterPos2f(x, y); 
    for (int i = 0; frase[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, frase[i]);
    }
}
   
void desenhaEixos() {
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);
        glVertex2f(-1.0, 0.0);
        glVertex2f( 1.0, 0.0); 
        glVertex2f(0.0, -1.0); 
        glVertex2f(0.0,  1.0); 
    glEnd();

}
void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(-0.7, 0.2, 0); 
    glColor3f(0.0, 1.0, 0.0);
    desenhaTriangulo(); 
    desenhaTexto(0, -0.1, "(-0.7, 0.2)"); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.3, 0.2, 0); 
    glColor3f(1.0, 0.0, 0.0); 
    desenhaTriangulo(); 
    desenhaTexto(0, -0.1, "(0.3, 0.2)"); 
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, -0.6, 0);  
    glColor3f(0.0, 0.0, 1.0);
    desenhaTriangulo(); 
    desenhaTexto(0, -0.1, "(-0.7, -0.6)"); 
    glPopMatrix();

    desenhaEixos();
    glFlush(); 
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Ana");
   
    glutDisplayFunc(desenha);
    
    glutMainLoop();
    return 0;
}