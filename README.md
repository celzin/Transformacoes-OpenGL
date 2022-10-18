# Tranformaçoes Geométricas Básicas em OpenGL

<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img align="center" alt="CMake" src="https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white" />
  <img align="center" alt="OpenGL" src="https://img.shields.io/badge/OpenGL-%23FFFFFF.svg?style=for-the-badge&logo=opengl" />
</div><br/>

Aplicar as transformações de Translação, Rotação e Escala à um triângulo.

## CMakeLists.txt

Primeiramente, favor adicionar as linhas de código abaixo ao arquivo CMakeLists.txt para que possa ser criado um executável de acordo com as dependências utilizadas no projeto.

```c
target_include_directories(Transformacoes PRIVATE dependencias/glm
						  dependencias/stb 
                                                  dependencias/glfw/include
					          dependencias/glew/include
				                  dependencias/glu/include)

target_link_directories(Transformacoes PRIVATE dependencias/glfw/lib-vc2022
					       dependencias/glew/lib/Release/x64)

target_link_libraries(Transformacoes PRIVATE glfw3.lib
					     glew32.lib
					     opengl32.lib
					     glu32.lib)
```

## Cores.h

Em segundo plano, foi criado um arquivo de cabeçalho que servirá de suporte para facilitar o uso de cores no projeto principal. Segue abaixo seu conteúdo.

```cpp
#pragma once

typedef float color[3];

color vermelho = { 0.85, 0.12, 0.0 };
color verde = { 0.0, 1.0, 0.0 };
color azul = { 0.0, 0.15,0.35 };
color preto = { 0.0, 0.0, 0.0 };
color branco = { 1.0, 1.0, 1.0 };
color amarelo = { 1.0, 1.0, 0.0 };
color violeta = { 0.54, 0.17, 0.88 };
color cinza = { 0.8, 0.8, 0.8 };
color laranja = { 1.0, 0.6, 0.2 };
```

## Transformações no OpenGL
Para realizar as transformações geométricas de Translação, Rotação e Escala, basicamente utilizou-se, respectivamente, das funções glTranslatef, glRotatef e glScalef. Então segue a parte do código que realiza tais ações.

```cpp
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
}
```
