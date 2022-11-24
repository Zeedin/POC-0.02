#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"



const unsigned int width = 1920;
const unsigned int height = 1080;


float Trang_offset_x = 9;
float Trang_offset_z = 0;
float Trang_offset_y = 3;
float Trang_scall = 1;
// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 5.0f,      0.0f, -1.0f, 0.0f, // Bottom side
	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, -1.0f, 0.0f, // Bottom side

	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f, 	 0.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,     -0.8f, 0.5f,  0.0f, // Left Side
	Trang_offset_x + (Trang_scall) * 0.0f,	Trang_offset_z + (Trang_scall) * 0.8f,	Trang_offset_y + (Trang_scall) * 0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f, -0.8f, // Non-facing side
	Trang_offset_x + (Trang_scall) * 0.0f,	Trang_offset_z + (Trang_scall) * 0.8f,	Trang_offset_y + (Trang_scall) * 0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f, -0.8f, // Non-facing side

	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * -0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.8f, 0.5f,  0.0f, // Right side
	Trang_offset_x + (Trang_scall) * 0.0f,	Trang_offset_z + (Trang_scall) * 0.8f,	Trang_offset_y + (Trang_scall) * 0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.8f, 0.5f,  0.0f, // Right side

	Trang_offset_x + (Trang_scall) * 0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f,	 5.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	Trang_offset_x + (Trang_scall) * -0.5f,	Trang_offset_z + (Trang_scall) * 0.0f,	Trang_offset_y + (Trang_scall) * 0.5f,     0.83f, 0.70f, 0.44f,	 0.0f, 0.0f,      0.0f, 0.5f,  0.8f, // Facing side
	Trang_offset_x + (Trang_scall) * 0.0f,	Trang_offset_z + (Trang_scall) * 0.8f,	Trang_offset_y + (Trang_scall) * 0.0f,     0.92f, 0.86f, 0.76f,	 2.5f, 5.0f,      0.0f, 0.5f,  0.8f  // Facing side
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};


GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.10f, -0.10f,  0.10f, 
	-0.10f, -0.10f, -0.10f,
	 0.10f, -0.10f, -0.10f,
	 0.10f, -0.10f,  0.10f,
	-0.10f,  0.10f,  0.10f,
	-0.10f,  0.10f, -0.10f,
	 0.10f,  0.10f, -0.10f,
	 0.10f,  0.10f,  0.10f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
/*
(Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f),    //center
(Hex_offset + (Hex_scall) * -0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // left top
(Hex_offset + (Hex_scall) * 0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right top
(Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right
(Hex_offset + (Hex_scall) * 0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right bottom
(Hex_offset + (Hex_scall) * -0.5f), (Hex_offset + (Hex_scall) * -1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // left bottom
(Hex_offset + (Hex_scall) * -1.0f), (Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f)     // left
*/

const unsigned int Hex_offset = 3;
const unsigned int Hex_scall = 1;


GLfloat hex_Vertices[] =
{ //     COORDINATES     //
	(Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f),    //center
	(Hex_offset + (Hex_scall) * -0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // left top
	(Hex_offset + (Hex_scall) * 0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right top
	(Hex_offset + (Hex_scall) * 0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right bottom
	(Hex_offset + (Hex_scall) * 0.5f), (Hex_offset + (Hex_scall) * 1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // right bottom
	(Hex_offset + (Hex_scall) * -0.5f), (Hex_offset + (Hex_scall) * -1.0f), (Hex_offset + (Hex_scall) * 0.0f),    // left bottom
	(Hex_offset + (Hex_scall) * -1.0f), (Hex_offset + (Hex_scall) * 0.0f), (Hex_offset + (Hex_scall) * 0.0f),     // left
};

GLuint hex_Indices[] =
{
0, 1, 
2, 3, 
4, 5, 
6, 1
};

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "POC-1", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	//Tang

			// Generates Shader object using shaders default.vert and default.frag
			Shader shaderProgram("default.vert", "default.frag");


			// Generates Vertex Array Object and binds it
			VAO VAO1;
			VAO1.Bind();

			// Generates Vertex Buffer Object and links it to vertices
			VBO VBO1(vertices, sizeof(vertices));
			// Generates Element Buffer Object and links it to indices
			EBO EBO1(indices, sizeof(indices));

			// Links VBO attributes such as coordinates and colors to VAO
			// slits up the array into each data chunk by bits, then passes it to the VA0
			//aslo need to update shader such  that the new feilds are added.
			VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
			VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
			VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
			VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
			// Unbind all to prevent accidentally modifying them
			VAO1.Unbind();
			VBO1.Unbind();
			EBO1.Unbind();


			//enable and load the object
			glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::mat4 pyramidModel = glm::mat4(1.0f);
			pyramidModel = glm::translate(pyramidModel, pyramidPos);



	//Light 
	//need to create the shader function/deff

	// Shader for light cube
			Shader lightShader("light.vert", "light.frag");
			// Generates Vertex Array Object and binds it
			VAO lightVAO;
			lightVAO.Bind();
			// Generates Vertex Buffer Object and links it to vertices
			VBO lightVBO(lightVertices, sizeof(lightVertices));
			// Generates Element Buffer Object and links it to indices
			EBO lightEBO(lightIndices, sizeof(lightIndices));
			// Links VBO attributes such as coordinates and colors to VAO
			lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
			// Unbind all to prevent accidentally modifying them
			lightVAO.Unbind();
			lightVBO.Unbind();
			lightEBO.Unbind();

			//enable and color the light
			glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
			glm::mat4 lightModel = glm::mat4(1.0f);
			lightModel = glm::translate(lightModel, lightPos);



	//hex start

			// Shader for light cube
			Shader hex_Shader("hex.vert", "hex.frag");
			// Generates Vertex Array Object and binds it
			VAO hex_VAO;
			hex_VAO.Bind();
			// Generates Vertex Buffer Object and links it to vertices
			VBO hex_VBO(hex_Vertices, sizeof(hex_Vertices));
			// Generates Element Buffer Object and links it to indices
			EBO hex_EBO(hex_Indices, sizeof(hex_Indices));
			// Links VBO attributes such as coordinates and colors to VAO
			hex_VAO.LinkAttrib(hex_VBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
			hex_VAO.LinkAttrib(hex_VBO, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
			hex_VAO.LinkAttrib(hex_VBO, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
			hex_VAO.LinkAttrib(hex_VBO, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
			// Unbind all to prevent accidentally modifying them
			hex_VAO.Unbind();
			hex_VBO.Unbind();
			hex_EBO.Unbind();

			//enable the shape
			glm::vec3 hex_Pos = glm::vec3(0.5f, 0.5f, 0.5f);
			glm::mat4 hex_Model = glm::mat4(1.0f);
			hex_Model = glm::translate(hex_Model, hex_Pos);


	//hex end









	//export the the render

		//Light
			lightShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
			//give it light
			glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

		//Tang
			shaderProgram.Activate();
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
			glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

		//Hex
			hex_Shader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(hex_Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
			glUniform4f(glGetUniformLocation(hex_Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(hex_Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);


	// Original code from the tutorial
	Texture brickTex("moss.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);
	brickTex.texUnit(hex_Shader, "tex0", 0);



	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);


		// Tells OpenGL which Shader Program we want to use
				shaderProgram.Activate();
				// Exports the camera Position to the Fragment Shader for specular lighting
				glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
				// Export the camMatrix to the Vertex Shader of the pyramid
				camera.Matrix(shaderProgram, "camMatrix");
				// Binds texture so that is appears in rendering
				brickTex.Bind();
				// Bind the VAO so OpenGL knows to use it
				VAO1.Bind();
				// Draw primitives, number of indices, datatype of indices, index of indices
				glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);



		// Tells OpenGL which Shader Program we want to use
				lightShader.Activate();
				// Export the camMatrix to the Vertex Shader of the light cube
				camera.Matrix(lightShader, "camMatrix");
				// Bind the VAO so OpenGL knows to use it
				lightVAO.Bind();
				// Draw primitives, number of indices, datatype of indices, index of indices
				glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		//draw hex

				hex_Shader.Activate();
				// Exports the camera Position to the Fragment Shader for specular lighting
				glUniform3f(glGetUniformLocation(hex_Shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
				// Export the camMatrix to the Vertex Shader of the pyramid
				camera.Matrix(hex_Shader, "camMatrix");
				// Binds texture so that is appears in rendering
				brickTex.Bind();
				// Bind the VAO so OpenGL knows to use it
				hex_VAO.Bind();
				// Draw primitives, number of indices, datatype of indices, index of indices
				glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);


		//end draw of hex

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	hex_Shader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}