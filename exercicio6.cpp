#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <math.h>

#define MAX_ESTRELAS 20

float posX[MAX_ESTRELAS];
float posY[MAX_ESTRELAS];
float raio[MAX_ESTRELAS];

float cores[MAX_ESTRELAS][3];

int quantidadeEstrelas = 7;

int modoNoturno = 0;


void gerarEstrela(int i){
    
    posX[i] = ((float)rand() / RAND_MAX) * 1.8f - 0.9f;
    posY[i] = ((float)rand() / RAND_MAX) * 1.8f - 0.9f;

    raio[i] = ((float)rand() / RAND_MAX) * 0.08f + 0.02f;

    cores[i][0] = (float)rand() / RAND_MAX;
    cores[i][1] = (float)rand() / RAND_MAX;
    cores[i][2] = (float)rand() / RAND_MAX;
}


void desenharEstrela(float x, float y, float r, int i){

    glBegin(GL_POLYGON);

    if(modoNoturno){
        glColor3f(1.0, 1.0, 0.0);
    }else{
        glColor3f(cores[i][0], cores[i][1], cores[i][2]);
    }

    for(int j = 0; j < 100; j++){

        float angulo = 2.0f * 3.1415926f * j / 100;

        float px = x + r * cosf(angulo);
        float py = y + r * sinf(angulo);

        glVertex2f(px, py);
    }
    glEnd();
}


void desenhaConexoes(){

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINES);

    for(int i = 0; i < quantidadeEstrelas - 1; i++){

        glVertex2f(posX[i], posY[i]);
        glVertex2f(posX[i + 1], posY[i + 1]);
    }

    glEnd();
}

void desenha(){

    glClear(GL_COLOR_BUFFER_BIT);

    desenhaConexoes();

    for(int i = 0; i < quantidadeEstrelas; i++){

        desenharEstrela(posX[i], posY[i], raio[i], i);
    }

    glFlush();
}


void teclado(unsigned char tecla, int x, int y){

    if((tecla == 'n' || tecla == 'N') && quantidadeEstrelas < MAX_ESTRELAS){
        gerarEstrela(quantidadeEstrelas);
        quantidadeEstrelas++;
        glutPostRedisplay();
    }
    if((tecla == 'x' || tecla == 'X') && quantidadeEstrelas > 0){

        quantidadeEstrelas--;
        glutPostRedisplay();
    }
    if(tecla == 'r' || tecla == 'R'){
        quantidadeEstrelas = 7;

        for(int i = 0; i < quantidadeEstrelas; i++){

            gerarEstrela(i);
        }

        glutPostRedisplay();
    }
    if(tecla == 't' || tecla == 'T'){

        modoNoturno = !modoNoturno;

        if(modoNoturno){
            glClearColor(0.0, 0.0, 0.0, 1.0);
        }else{
            glClearColor(0.1, 0.1, 0.2, 1.0);
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv){

    srand(time(NULL));

    for(int i = 0; i < quantidadeEstrelas; i++){

        gerarEstrela(i);
    }

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Constelacao dos Guardioes");

    glClearColor(0.1, 0.1, 0.2, 1.0);

    glutDisplayFunc(desenha);

    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}