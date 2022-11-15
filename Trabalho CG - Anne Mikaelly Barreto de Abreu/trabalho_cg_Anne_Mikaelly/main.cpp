// Anne Mikaelly Barreto de Abreu - 404805
// Link do Vídeo no Youtube: https://youtu.be/Hxx5XOQNxWw

#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <cmath>


// Variáveis Globais
GLfloat angle, fAspect,eyex, eyey, eyez, centrox, centroy, centroz;
float posx = 0.0;
float posy = 0.0;
float posz = 0.0; // Posição Móvel do Carro do Jogador
float speed = 50; // Velocidade Inicial do Carro do Jogador

float faixa_posx = 500; // Posição Móvel das Faixas da pista
float zebraB_posx = 500; // Posição Móvel da Zebra Branca da pista
float zebraV_posx = 500; // Posição Móvel da Zebra Vermelha da pista

float car1_posX = -3600; // Posição Móvel do Carro NPC_1
float car2_posX = -9000; // Posição Móvel do Carro NPC_2


// Cenário
void horizonte(){
    // Céu
    float b1[] = {-3500, -150,-100000};
    float b2[] = {-3500, -150,100000};
    float b3[] = {-3500, -150};
    float b4[] = {-3500, 1500};
    glColor3f(0.0,0.0,0.8);
    glBegin(GL_QUADS);
    glVertex3fv(b1);
    glVertex3fv(b2);
    glVertex2fv(b3);
    glVertex2fv(b4);
    glEnd();

    // Lua
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(-3490,300, -150);
    glutSolidSphere(170.0f,100,100);
    glPopMatrix();

    // Estrelas
    glPointSize(2);
    glColor3d(1,1,0.1);
    glBegin(GL_POINTS);
    glVertex3d(-3490,100, 150);
    glVertex3d(-3490,200, 150);
    glVertex3d(-3490,100, 300);
    glVertex3d(-3490,150, 200);
    glVertex3d(-3490,300, 650);
    glVertex3d(-3490,150, 500);
    glVertex3d(-3490,300, 150);
    glVertex3d(-3490,550, 150);
    glVertex3d(-3490,300, 300);
    glVertex3d(-3490,450, 200);
    glVertex3d(-3490,300, 650);
    glVertex3d(-3490,450, 500);
    glVertex3d(-3490,300, 650);
    glVertex3d(-3490,550, 950);
    glVertex3d(-3490,300, 1000);
    glVertex3d(-3490,450, 800);
    glVertex3d(-3490,300, 1050);
    glVertex3d(-3490,450, 2000);
    glVertex3d(-3490,800, 800);
    glVertex3d(-3490,750, 950);
    glVertex3d(-3490,600, 1000);
    glVertex3d(-3490,450, 800);
    glVertex3d(-3490,300, 1050);
    glVertex3d(-3490,150, 1500);
    glVertex3d(-3490,100, -500);
    glVertex3d(-3490,200, -350);
    glVertex3d(-3490,200, -400);
    glVertex3d(-3490,150, -600);
    glVertex3d(-3490,500, -500);
    glVertex3d(-3490,550, -350);
    glVertex3d(-3490,450, -400);
    glVertex3d(-3490,450, -600);
    glVertex3d(-3490,500, -600);
    glVertex3d(-3490,550, -750);
    glVertex3d(-3490,450, -700);
    glVertex3d(-3490,450, -650);
    glVertex3d(-3490,500, -900);
    glVertex3d(-3490,550, -750);
    glVertex3d(-3490,450, -900);
    glVertex3d(-3490,450, -1050);
    glVertex3d(-3490,100, -900);
    glVertex3d(-3490,200, -950);
    glVertex3d(-3490,200, -900);
    glVertex3d(-3490,100, -1150);
glEnd();


}
void pista(){
    //Asfalto
    glColor3f(0.3,0.3 ,0.3 );
    glBegin(GL_QUADS);
        glVertex3f(1000, -150, 300);
        glVertex3f(1000, -150, -300);
        glVertex3f(-3500, -150, -300);
        glVertex3f(-3500, -150, 300);
    glEnd();
}

void faixas(float faixa_posx){
    float posx_1 = faixa_posx;
    float posx_2 = faixa_posx - 500;
    float posx_3 = faixa_posx - 1000;
    float posx_4 = faixa_posx - 1500;
    float posx_5 = faixa_posx - 2000;
    float posx_6 = faixa_posx - 2500;
    float posx_7 = faixa_posx - 3000;
    float posx_8 = faixa_posx - 3500;
    float posx_9 = faixa_posx - 4000;



    float zebraB_posx1 = faixa_posx;
    float zebraB_posx2 = faixa_posx - 500;
    float zebraB_posx3 = faixa_posx - 1000;
    float zebraB_posx4 = faixa_posx - 1500;
    float zebraB_posx5 = faixa_posx - 2000;
    float zebraB_posx6 = faixa_posx - 2500;
    float zebraB_posx7 = faixa_posx - 3000;
    float zebraB_posx8 = faixa_posx - 3500;
    float zebraB_posx9 = faixa_posx - 4000;



    float zebraV_posx1 = faixa_posx - 300;
    float zebraV_posx2 = faixa_posx - 800;
    float zebraV_posx3 = faixa_posx - 1200;
    float zebraV_posx4 = faixa_posx - 1700;
    float zebraV_posx5 = faixa_posx - 2200;
    float zebraV_posx6 = faixa_posx - 2700;
    float zebraV_posx7 = faixa_posx - 3200;
    float zebraV_posx8 = faixa_posx - 3700;
    float zebraV_posx9 = faixa_posx - 4200;




    // Definição das Posições das Faixas
    glColor3f(1,1,0.2);
    glBegin(GL_QUADS); // Faixa 1
        glVertex3f(posx_1, -149, 20);
        glVertex3f(posx_1, -149, -20);
        glVertex3f(posx_1 - 300, -149, -20);
        glVertex3f(posx_1 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 2
        glVertex3f(posx_2, -149, 20);
        glVertex3f(posx_2, -149, -20);
        glVertex3f(posx_2 - 300, -149, -20);
        glVertex3f(posx_2 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 3
        glVertex3f(posx_3, -149, 20);
        glVertex3f(posx_3, -149, -20);
        glVertex3f(posx_3 - 300, -149, -20);
        glVertex3f(posx_3 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 4
        glVertex3f(posx_4, -149, 20);
        glVertex3f(posx_4, -149, -20);
        glVertex3f(posx_4 - 300, -149, -20);
        glVertex3f(posx_4 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 5
        glVertex3f(posx_5, -149, 20);
        glVertex3f(posx_5, -149, -20);
        glVertex3f(posx_5 - 300, -149, -20);
        glVertex3f(posx_5 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 6
        glVertex3f(posx_6, -149, 20);
        glVertex3f(posx_6, -149, -20);
        glVertex3f(posx_6 - 300, -149, -20);
        glVertex3f(posx_6 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 7
        glVertex3f(posx_7, -149, 20);
        glVertex3f(posx_7, -149, -20);
        glVertex3f(posx_7 - 300, -149, -20);
        glVertex3f(posx_7 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 8
        glVertex3f(posx_8, -149, 20);
        glVertex3f(posx_8, -149, -20);
        glVertex3f(posx_8 - 300, -149, -20);
        glVertex3f(posx_8 - 300, -149, 20);
    glEnd();

    glBegin(GL_QUADS); // Faixa 9
        glVertex3f(posx_9, -149, 20);
        glVertex3f(posx_9, -149, -20);
        glVertex3f(posx_9 - 300, -149, -20);
        glVertex3f(posx_9 - 300, -149, 20);
    glEnd();


    // Definição Zebra Branca Lado Esquerdo
    glColor3f(1,1,1);

    glBegin(GL_QUADS); // Zebra Branca 1
        glVertex3f(zebraB_posx1, -149, 280);
        glVertex3f(zebraB_posx1, -149, 320);
        glVertex3f(zebraB_posx1 - 300, -149, 320);
        glVertex3f(zebraB_posx1 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 2
        glVertex3f(zebraB_posx2, -149, 280);
        glVertex3f(zebraB_posx2, -149, 320);
        glVertex3f(zebraB_posx2 - 300, -149, 320);
        glVertex3f(zebraB_posx2 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 3
        glVertex3f(zebraB_posx3, -149, 280);
        glVertex3f(zebraB_posx3, -149, 320);
        glVertex3f(zebraB_posx3 - 300, -149, 320);
        glVertex3f(zebraB_posx3 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 4
        glVertex3f(zebraB_posx4, -149, 280);
        glVertex3f(zebraB_posx4, -149, 320);
        glVertex3f(zebraB_posx4 - 300, -149, 320);
        glVertex3f(zebraB_posx4 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 5
        glVertex3f(zebraB_posx5, -149, 280);
        glVertex3f(zebraB_posx5, -149, 320);
        glVertex3f(zebraB_posx5 - 300, -149, 320);
        glVertex3f(zebraB_posx5 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 6
        glVertex3f(zebraB_posx6, -149, 280);
        glVertex3f(zebraB_posx6, -149, 320);
        glVertex3f(zebraB_posx6 - 300, -149, 320);
        glVertex3f(zebraB_posx6 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 7
        glVertex3f(zebraB_posx7, -149, 280);
        glVertex3f(zebraB_posx7, -149, 320);
        glVertex3f(zebraB_posx7 - 300, -149, 320);
        glVertex3f(zebraB_posx7 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 8
        glVertex3f(zebraB_posx8, -149, 280);
        glVertex3f(zebraB_posx8, -149, 320);
        glVertex3f(zebraB_posx8 - 300, -149,320);
        glVertex3f(zebraB_posx8 - 300, -149, 280);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 9
        glVertex3f(zebraB_posx9, -149, 280);
        glVertex3f(zebraB_posx9, -149, 320);
        glVertex3f(zebraB_posx9 - 300, -149, 320);
        glVertex3f(zebraB_posx9 - 300, -149, 280);
    glEnd();


    // Definição da Zebra Vermelha do Lado Esquerdo
    glColor3f(1,0,0);

    glBegin(GL_QUADS); // Zebra Vermelha 1
        glVertex3f(zebraV_posx1, -149, 320);
        glVertex3f(zebraV_posx1, -149, 280);
        glVertex3f(zebraV_posx1 - 300, -149, 280);
        glVertex3f(zebraV_posx1 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 2
        glVertex3f(zebraV_posx2, -149, 320);
        glVertex3f(zebraV_posx2, -149, 280);
        glVertex3f(zebraV_posx2 - 300, -149,280);
        glVertex3f(zebraV_posx2 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 3
        glVertex3f(zebraV_posx3, -149, 320);
        glVertex3f(zebraV_posx3, -149, 280);
        glVertex3f(zebraV_posx3 - 300, -149,280);
        glVertex3f(zebraV_posx3 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 4
        glVertex3f(zebraV_posx4, -149, 320);
        glVertex3f(zebraV_posx4, -149, 280);
        glVertex3f(zebraV_posx4 - 300, -149,280);
        glVertex3f(zebraV_posx4 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 5
        glVertex3f(zebraV_posx5, -149, 320);
        glVertex3f(zebraV_posx5, -149, 280);
        glVertex3f(zebraV_posx5 - 300, -149,280);
        glVertex3f(zebraV_posx5 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 6
        glVertex3f(zebraV_posx6, -149, 320);
        glVertex3f(zebraV_posx6, -149, 280);
        glVertex3f(zebraV_posx6 - 300, -149, 280);
        glVertex3f(zebraV_posx6 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 7
        glVertex3f(zebraV_posx7, -149, 320);
        glVertex3f(zebraV_posx7, -149, 280);
        glVertex3f(zebraV_posx7 - 300, -149,280);
        glVertex3f(zebraV_posx7 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 8
        glVertex3f(zebraV_posx8, -149, 320);
        glVertex3f(zebraV_posx8, -149, 280);
        glVertex3f(zebraV_posx8 - 300, -149,280);
        glVertex3f(zebraV_posx8 - 300, -149, 320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 9
        glVertex3f(zebraV_posx9, -149, 320);
        glVertex3f(zebraV_posx9, -149, 280);
        glVertex3f(zebraV_posx9 - 300, -149,280);
        glVertex3f(zebraV_posx9 - 300, -149, 320);
    glEnd();


    // Definição Zebra Branca Lado Direito
    glColor3f(1,1,1);

    glBegin(GL_QUADS); // Zebra Branca 1
        glVertex3f(zebraB_posx1, -149, -320);
        glVertex3f(zebraB_posx1, -149, -280);
        glVertex3f(zebraB_posx1 - 300, -149, -280);
        glVertex3f(zebraB_posx1 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 2
        glVertex3f(zebraB_posx2, -149, -320);
        glVertex3f(zebraB_posx2, -149, -280);
        glVertex3f(zebraB_posx2 - 300, -149, -280);
        glVertex3f(zebraB_posx2 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 3
        glVertex3f(zebraB_posx3, -149, -320);
        glVertex3f(zebraB_posx3, -149, -280);
        glVertex3f(zebraB_posx3 - 300, -149, -280);
        glVertex3f(zebraB_posx3 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 4
        glVertex3f(zebraB_posx4, -149, -320);
        glVertex3f(zebraB_posx4, -149, -280);
        glVertex3f(zebraB_posx4 - 300, -149, -280);
        glVertex3f(zebraB_posx4 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 5
        glVertex3f(zebraB_posx5, -149, -320);
        glVertex3f(zebraB_posx5, -149, -280);
        glVertex3f(zebraB_posx5 - 300, -149, -280);
        glVertex3f(zebraB_posx5 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 6
        glVertex3f(zebraB_posx6, -149, -320);
        glVertex3f(zebraB_posx6, -149, -280);
        glVertex3f(zebraB_posx6 - 300, -149, -280);
        glVertex3f(zebraB_posx6 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 7
        glVertex3f(zebraB_posx7, -149, -320);
        glVertex3f(zebraB_posx7, -149, -280);
        glVertex3f(zebraB_posx7 - 300, -149, -280);
        glVertex3f(zebraB_posx7 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 8
        glVertex3f(zebraB_posx8, -149, -320);
        glVertex3f(zebraB_posx8, -149, -280);
        glVertex3f(zebraB_posx8 - 300, -149, -280);
        glVertex3f(zebraB_posx8 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Branca 9
        glVertex3f(zebraB_posx9, -149, -320);
        glVertex3f(zebraB_posx9, -149, -280);
        glVertex3f(zebraB_posx9 - 300, -149, -280);
        glVertex3f(zebraB_posx9 - 300, -149, -320);
    glEnd();


    // Definição da Zebra Vermelha do Lado Direito
    glColor3f(1,0,0);
    glBegin(GL_QUADS); // Zebra Vermelha 1
        glVertex3f(zebraV_posx1, -149, -320);
        glVertex3f(zebraV_posx1, -149, -280);
        glVertex3f(zebraV_posx1 - 300, -149, -280);
        glVertex3f(zebraV_posx1 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 2
        glVertex3f(zebraV_posx2, -149, -320);
        glVertex3f(zebraV_posx2, -149, -280);
        glVertex3f(zebraV_posx2 - 300, -149, -280);
        glVertex3f(zebraV_posx2 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 3
        glVertex3f(zebraV_posx3, -149, -320);
        glVertex3f(zebraV_posx3, -149, -280);
        glVertex3f(zebraV_posx3 - 300, -149, -280);
        glVertex3f(zebraV_posx3 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 4
        glVertex3f(zebraV_posx4, -149, -320);
        glVertex3f(zebraV_posx4, -149, -280);
        glVertex3f(zebraV_posx4 - 300, -149, -280);
        glVertex3f(zebraV_posx4 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 5
        glVertex3f(zebraV_posx5, -149, -320);
        glVertex3f(zebraV_posx5, -149, -280);
        glVertex3f(zebraV_posx5 - 300, -149, -280);
        glVertex3f(zebraV_posx5 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 6
        glVertex3f(zebraV_posx6, -149, -320);
        glVertex3f(zebraV_posx6, -149, -280);
        glVertex3f(zebraV_posx6 - 300, -149, -280);
        glVertex3f(zebraV_posx6 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 7
        glVertex3f(zebraV_posx7, -149, -320);
        glVertex3f(zebraV_posx7, -149, -280);
        glVertex3f(zebraV_posx7 - 300, -149, -280);
        glVertex3f(zebraV_posx7 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 8
        glVertex3f(zebraV_posx8, -149, -320);
        glVertex3f(zebraV_posx8, -149, -280);
        glVertex3f(zebraV_posx8 - 300, -149, -280);
        glVertex3f(zebraV_posx8 - 300, -149, -320);
    glEnd();

    glBegin(GL_QUADS); // Zebra Vermelha 9
        glVertex3f(zebraV_posx9, -149, -320);
        glVertex3f(zebraV_posx9, -149, -280);
        glVertex3f(zebraV_posx9 - 300, -149, -280);
        glVertex3f(zebraV_posx9 - 300, -149, -320);
    glEnd();
}


//Carros
// Carro do Jogador
void lateral_Esquerda(){
    float z = posz + 90;
    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(0,-90,z);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void lateral_direita(){
    float z = posz - 90;

    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(0,-90,z);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void frente_Carro(){

    float z = posz;


    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(-120,-90,z);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-90,-30,z);
    glRotatef(-45,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutWireCube(200);
    glPopMatrix();
}
void traseira_Carro(){
    float z = posz;

    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(120,-90,z);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(95,-30,z);
    glRotatef(36,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void teto_Carro(){
    float z = posz;

    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(5,0,z);
    glScalef(0.65,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void assoalho_Carro(){
    float z = posz;

    glColor3f(0.3,0.2,0.8);
    glPushMatrix();
    glTranslatef(0,-120,z);
    glScalef(1.2,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void borda_Porta(){
    float z1 = posz - 90.1;
    float z2 = posz + 90.1;


    glPushMatrix();
    glTranslatef(-25,-60,z1);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-60,z2);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void rodas_Carro(){
    float z1 = posz + 55;
    float z2 = posz - 55;


    glPushMatrix();
    glTranslatef(-80,-125,z1);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,z1);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80,-125,z2);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,z2);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

}
void carro_Jogador(){
    rodas_Carro();
    assoalho_Carro();
    lateral_Esquerda();
    lateral_direita();
    borda_Porta();
    frente_Carro();
    traseira_Carro();
    teto_Carro();

}


// Carro do Adversário_1
void lateral_Esquerda_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(0,-90,-110);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void lateral_direita_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(0,-90,-290);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void frente_Carro_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(-120,-90,-200);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-90,-30,-200);
    glRotatef(-45,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutWireCube(200);
    glPopMatrix();
}
void traseira_Carro_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(120,-90,-200);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(95,-30,-200);
    glRotatef(36,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void teto_Carro_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(5,0,-200);
    glScalef(0.65,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void assoalho_Carro_adv(){
    glColor3f(0.5,0,0);
    glPushMatrix();
    glTranslatef(0,-120,-200);
    glScalef(1.2,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void borda_Porta_adv(){
    glPushMatrix();
    glTranslatef(-25,-60, - 290.1);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-60,- 109.9);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void rodas_Carro_adv(){
    glPushMatrix();
    glTranslatef(-80,-125,-155);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,-155);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80,-125,-255);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,-255);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

}
void carro_Jogador_adv(){
    rodas_Carro_adv();
    assoalho_Carro_adv();
    lateral_Esquerda_adv();
    lateral_direita_adv();
    borda_Porta_adv();
    traseira_Carro_adv();
    frente_Carro_adv();
    teto_Carro_adv();

}


// Carro do Adversário_2
void lateral_Esquerda_adv2(){
    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(0,-90,-110);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void lateral_direita_adv2(){
    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(0,-90,-290);
    glScalef(1.2,0.3,0.01);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

}
void frente_Carro_adv2(){
    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(-120,-90,-200);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-90,-30,-200);
    glRotatef(-45,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutWireCube(200);
    glPopMatrix();
}
void traseira_Carro_adv2(){

    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(120,-90,-200);
    glScalef(0.01,0.3,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(95,-30,-200);
    glRotatef(36,0,0,1);
    glScalef(0.01,0.4,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void teto_Carro_adv2(){


    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(5,0,-200);
    glScalef(0.65,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void assoalho_Carro_adv2(){
    glColor3f(1,0,0.1);
    glPushMatrix();
    glTranslatef(0,-120,-200);
    glScalef(1.2,0.01,0.90);
    glutSolidCube(200);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void borda_Porta_adv2(){
    glPushMatrix();
    glTranslatef(-25,-60, - 290.1);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,-60,- 109.9);
    glScalef(0.01,0.6,0.01);
    glColor3f(1,1,1);
    glutWireCube(200);
    glPopMatrix();
}
void rodas_Carro_adv2(){
    glPushMatrix();
    glTranslatef(-80,-125,-155);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,-155);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80,-125,-255);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,-125,-255);
    glColor3f(0,0,0);
    glutSolidTorus(10,15,100,100);
    glPopMatrix();

}
void carro_Jogador_adv2(){
    rodas_Carro_adv2();
    assoalho_Carro_adv2();
    lateral_Esquerda_adv2();
    lateral_direita_adv2();
    borda_Porta_adv2();
    traseira_Carro_adv2();
    frente_Carro_adv2();
    teto_Carro_adv2();

}


// Movimentações
void mov_Pista(int){

    faixa_posx +=speed;
    while(faixa_posx >= 1000){faixa_posx = 500;}

    glutPostRedisplay();
    glutTimerFunc(1000/60, mov_Pista, 0 );
}

void mov_Car1(int){

    car1_posX +=speed;
    while(car1_posX >= 1500){car1_posX = -6500;}

    glutPostRedisplay();
    glutTimerFunc(1000/60, mov_Car1, 0 );
}

void mov_Car2(int){

    car2_posX +=speed;
    while(car2_posX >= 1500){car2_posX = -13000;}

    glutPostRedisplay();
    glutTimerFunc(1000/60, mov_Car2, 0 );
}


// Definições
void inicio(){
    glClearColor(0.05, 0.5, 0.05, 0.0);
    glShadeModel (GL_FLAT);
    angle= 45;
    eyex = 900.0;
    eyey = 300.0;
    eyez = 0;
    centrox=1.0;
    centroy=1.0;
    centroz=1.0;
}

void visao(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle,fAspect,0,600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glLoadIdentity ();
    gluLookAt (eyex, eyey, eyez, centrox, centroy, centroz, 0.0, 1.0, 0.0);
    pista();
    faixas(faixa_posx);

    // Criação do Carro_Adversario1
    glPushMatrix();
    glTranslatef(car1_posX,0,-400);
    glRotatef(180,0,-200,0);
    carro_Jogador_adv();
    glPopMatrix();

    // Criação do Carro_Adversario2
    glPushMatrix();
    glTranslatef(car2_posX,0,0);
    glRotatef(180,0,-200,0);
    carro_Jogador_adv2();
    glPopMatrix();

    horizonte();
    carro_Jogador();
    glFlush ();
    glutSwapBuffers();
}

void reshape (GLsizei w, GLsizei h){
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;
    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;
    visao();
}


void teclado_Carro(int key,int x, int y){ // Função de Movimento do carro_Jogador
    switch(key){
        case GLUT_KEY_LEFT:  posz += 100; break;
        case GLUT_KEY_RIGHT: posz -= 100; break;
        case GLUT_KEY_UP:  speed +=25; break; //  Aumenta a velocidade do carro_Jogador
        case GLUT_KEY_DOWN:  speed -=25; break; //  Diminui a velocidade do carro_Jogador
        }

       // Limites de Pista e Velocidade
        while(posz>200){posz = 200;}
        while(posz<-200){posz = -200;}
        while(faixa_posx >= 1000){faixa_posx = 500;}

        while(speed>100){speed = 100;} // Velocidade Máxima 100
        while(speed<0){speed = 0;} // Velocidade Mínima 0

        glutPostRedisplay();
}

void GMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) { // Zoom-in
        if (angle >= 10) angle -= 5;
            while (angle < 35){angle = 35;}}

    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) { // Zoom-out
            if (angle <= 130) angle += 5;
                while(angle > 60){angle = 60;}}
    visao();
    glutPostRedisplay();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(700,700);
    glutCreateWindow("Jogo de Corrida");
    glutTimerFunc(1000/60, mov_Pista, 0 );
    glutTimerFunc(1000/60, mov_Car1, 0 );
    glutTimerFunc(1000/60, mov_Car2, 0 );
    glutMouseFunc(GMouse);
    inicio();
    glutDisplayFunc(display);
    glutSpecialFunc(teclado_Carro);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
