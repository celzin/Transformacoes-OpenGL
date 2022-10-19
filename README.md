# Tranformaçoes Geométricas Básicas em OpenGL

<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img align="center" alt="CMake" src="https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white" />
  <img align="center" alt="OpenGL" src="https://img.shields.io/badge/OpenGL-%23FFFFFF.svg?style=for-the-badge&logo=opengl" />
</div><br/>

## Abstract

<p align="justify">

A ideia geral do trabalho é aplicar as transformações de **Translação**, **Rotação**, **Escala** e **Reflexão** à uma figura geométrica triangular em [**OpenGL**](https://www.opengl.org/).

</p>

## CMakeLists.txt

<p align="justify">

Primeiramente, afirmo que foi usada uma biblioteca diferente das apresentadas em sala, sendo ela a GLU. Então, favor adicionar as linhas de código abaixo ao arquivo <code>CMakeLists.txt</code> para que possa ser criado um executável de acordo com as dependências utilizadas no projeto. 

</p>

```c
add_executable(Transformacoes  "Transformacoes.cpp")

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

<p align="justify">

Em segundo plano, foi criado um arquivo de cabeçalho que servirá de suporte para facilitar o uso de cores no projeto principal. Segue abaixo seu conteúdo.

</p>

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

## Criando o Triângulo Base

<p align="justify">

Antes de realizar as transformações geométricas propostas é necessário criar um triângulo orignal (base), que, posteriormente, auxiliará na comparação com as transformações sofridas de uma segunda figura ao seu lado. Para isso, foi adotada a seguinte ideia:

</p>

```cpp

```

<div align="center">
<img src="" width="800px"/>

**Figura 1: Visão da janela do terminal onde temos nosso triângulo base.**
</div>

## Transformações no OpenGL

<p align="justify">

Posteriormente, para realizar as transformações geométricas de Translação, Rotação e Escala, basicamente utilizou-se, respectivamente, das funções <code>glTranslatef(x, y, z)</code>, <code>glRotatef(Angulo, x, y, z)</code> e <code>glScalef(-x, -y, -z)</code>. Então segue a parte do código que realiza tais ações.

</p>

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

## Translação

<p align="justify">

Para aplicar a trasnformação de **Translação** utilizaremos a função <code>glTranslatef(x, y, z)</code>, passando os valores dos pontos de trasnlação que desejamos em <code>(x, y, z)</code>, para assim transladar nossa figura.

</p>

<div align="center">
<img src="" width="800px"/>

**Figura 2: Visão da janela do terminal onde à direira temos a Translação do triângulo.**
</div>

## Rotação

<p align="justify">

Para aplicar a trasnformação de **Rotação** ao triângulo utilizaremos a função <code>glRotatef(Angulo, x, y, z)</code>, , passando o valor do ângulo que queremos rotacionar a figura e os valores dos pontos de rotação que desejamos em <code>(Angulo, x, y, z)</code>, para assim rotacionar nossa figura.

</p>

<div align="center">
<img src="" width="800px"/>

**Figura 3: Visão da janela do terminal onde à direira temos a Rotação do triângulo.**
</div>

## Escala

<p align="justify">

Para aplicar a trasnformação de **Escala** ao triângulo utilizaremos a função <code>glScalef(x, y, z)</code>, passando os valores dos pontos de rotação que desejamos em <code>(x, y, z)</code>, para assim escalar nossa figura.

</p>

<div align="center">
<img src="" width="800px"/>

**Figura 4: Visão da janela do terminal onde à direira temos a Escala do triângulo.**
</div>

## Reflexão

<p align="justify">

Para aplicar a trasnformação de **Reflexão** ao triângulo utilizaremos a função <code>glScalef(-x, -y, -z)</code>, porém com seus valores invertidos, ou seja, negativos, para assim refletir nossa figura.

</p>

<div align="center">
<img src="https://user-images.githubusercontent.com/84411392/196703482-a6ce86ee-a2bf-4bfa-9753-450bb27b6c15.png" width="800px"/>

**Figura 5: Visão da janela do terminal onde à direira temos a Reflexão do triângulo.**
</div>
