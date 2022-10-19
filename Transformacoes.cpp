#include<Windows.h>
//Biblioteca que irá desenhar a tela
#include <GLFW/glfw3.h>
#include<gl/GLU.h>
#include<iostream>
#include "Cores.h"

//Definindo a porcao da janela que sera desenhada
void redimensiona(int w, int h) //w & h sao largura e altura de acordo com o frame buffer
{
	//Define a area da tela
	glViewport(0, 0, w, h);

	//Razao de aspecto para evitar deformacao com a janela
	float aspect = (float)w / (float)h;

	//Matriz projecao -> pega a cordenada e leva para a parte mapeada da tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Criando projecao perspectiva
	gluPerspective(45.0, aspect, 0.1, 500.0);

	//Criando a camera de angulo de visao da figura
	glMatrixMode(GL_MODELVIEW);
}

//Funcao para ligar os pontos dos vertices
void rect(float p1[3], float p2[3], float p3[3], color cor)
{
	//Recebe a cor da figura
	glColor3fv(cor);

	//Inicializa a figura geometrica
	glBegin(GL_TRIANGLES);
	//Inicializa os vertices
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glEnd();
}

//Funcao que define a forma geometrica
void desenhaTriangulo(float s)
{
	float d = s / 0.5;

	//Definindo os vertices
	float v1[3] = { 0.0, d, 0.0 };
	float v2[3] = { -d, -d, 0.0 };
	float v3[3] = { d, -d, 0.0 };

	//frente
	rect(v1, v2, v3, violeta);
}

//Funcao que desenha a figura
void desenha()
{
	//Inicializa na matriz identidade
	glLoadIdentity();

	//TRANSLACAO
	//Transladar(/val x, val y, val z)
	glTranslatef(-20.0, 0.0, -50.0);

	//ROTACAO
	//Rotacionar(angulo, val x, val y, val z)
	glRotatef(30.0, 1.0, 1.0, 1.0);

	//ESCALA
	//Escalar(val x, val y, val z)
	glScalef(1.0, 1.0, 1.0);

	//Desenha conforme o que foi passado
	desenhaTriangulo(5.0);

	//Permite que a matriz seja reinicializada na matriz identidade
	glLoadIdentity();

	//Criando o 2º triangulo
	glTranslatef(20.0, 0.0, -50.0);
	glRotatef(-30.0, -1.0, -1.0, -1.0);
	glScalef(-1.0, -1.0, -1.0);
	desenhaTriangulo(5.0);
}


int main(void)
{
	//Define o tamanho da janela que sera criada
	const int LARGURA = 800;
	const int ALTURA = 600;

	//Inicializa a biblioteca
	glfwInit();

	//Cria uma janela em modo janela no contexto do OpenGL
	GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Desenha Triangulo", NULL, NULL);

	//Cria a janela nesse contexto
	glfwMakeContextCurrent(window);

	//Cor de fundo da janela
	glClearColor(0.0, 0.15, 0.25, 1.0);
	glEnable(GL_DEPTH_TEST);

	//Loop enquanto usuario nao fecha a janela
	while (!glfwWindowShouldClose(window))
	{
		/* Poll for and process events */
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			//A janela fecha ao pressionar ESQ
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		//Renderizaçao da janela e limpa
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Pega o tamanho da janela do frame buffer para a area do desenho
		int largura, altura;
		glfwGetFramebufferSize(window, &largura, &altura);

		//Funcao que redimensiona a porcao usada da janela para o desenho
		redimensiona(largura, altura); //Deve ficar antes do desenho

		//Funcao que faz o desenho passado
		desenha();

		//Swap buffers frontais e traseiros
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}