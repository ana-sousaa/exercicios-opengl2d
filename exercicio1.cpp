#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>


float largura = 0.0f;
float altura = 0.0f;




void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        glVertex2f(largura, altura); 
        glVertex2f(-largura, altura); 
        glVertex2f(-largura, -altura); 
        glVertex2f(largura, -altura); 
    glEnd();

    glFlush(); 
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 32) { 

        float rFundo = (float)rand() / RAND_MAX;
        float gFundo = (float)rand() / RAND_MAX;
        float bFundo = (float)rand() / RAND_MAX;
      
        float rQuad = (float)rand() / RAND_MAX;
        float gQuad = (float)rand() / RAND_MAX;
        float bQuad = (float)rand() / RAND_MAX;

        glClearColor(rFundo, gFundo, bFundo, 1.0);
        glColor3f(rQuad, gQuad, bQuad); 
    

        glutPostRedisplay(); 
    }
}

int main(int argc, char** argv) {
   

    printf("Digite a largura e depois a altura (ex: 0.5 0.8): ");
    scanf("%f %f", &largura, &altura);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("exercicio1");
   
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    
    glutMainLoop();
    return 0;
}