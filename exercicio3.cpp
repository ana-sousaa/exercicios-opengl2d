#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>


float posX[5] = {-0.8,  0.2,  0.2, 0.5, 0.4}; 
float posY[5] = { 0.5, -0.3,  0.4, 0.2, 0.7};

float largura[5];
float altura[5];

float cores[5][3] = {
    {1.0, 0.0, 0.0}, 
    {0.0, 1.0, 0.0}, 
    {0.0, 0.0, 1.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 1.0} 
};

void desenhaTriangulo(int i){
    glBegin(GL_TRIANGLES);
         
        glVertex2f(largura[i], 0); 
        glVertex2f(0, 0); 
        glVertex2f(largura[i]/2, altura[i]);
      
       glEnd();
   }
   


void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i = 0; i < 5; i++){
    glPushMatrix();
    glTranslatef(posX[i],posY[i], 0.0);
    glColor3f(cores[i][0], cores[i][1], cores[i][2]);
    desenhaTriangulo(i);
    glPopMatrix();
    }
    glFlush(); 
}


int main(int argc, char** argv) {
   
    for(int i = 0; i < 5; i++){
    printf("Digite a largura e depois a altura (ex: 0.5 0.8): ");
    scanf("%f %f", &largura[i], &altura[i]);
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Ana");
   
    glutDisplayFunc(desenha);
    glClearColor(0.0, 0.0, 0.0,0.0);
    
    glutMainLoop();
    return 0;
}