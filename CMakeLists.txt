cmake_minimum_required(VERSION 3.12)

project(Projeto3D)

add_executable(Projeto3D main.cpp "main.cpp")


target_include_directories(Projeto3D PRIVATE dependencias/glm
											dependencias/stb
											dependencias/glfw/include
											dependencias/glew/include)


target_link_directories(Projeto3D PRIVATE dependencias/glfw/lib-vc2022
										 dependencias/glew/lib/Release/x64)

target_link_libraries(Projeto3D PRIVATE glfw3.lib
									    glew32.lib
										opengl32.lib)

add_custom_command(TARGET Projeto3D POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/dependencias/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}")

add_executable(Vectors  "Vectors.cpp")

target_include_directories(Vectors PRIVATE dependencias/glm)


add_executable(Matrizes  "Matrizes.cpp")

target_include_directories(Matrizes PRIVATE dependencias/glm)

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
