#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GLFWwindow* window;

/* Initialize vertices of our triangle */
glm::vec3 vertices[] = { glm::vec3(0.0f,  1.0f, 0.0f),
                         glm::vec3(1.0f, -1.0f, 0.0f),
                         glm::vec3(-1.0f, -1.0f, 0.0f)
};

/* Initialize Vertex Buffer Object */
GLuint VBO = NULL;

int init(int width, int height)
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello Triangle", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	if (glewInit() != GLEW_OK)
		return -1;

	/* Set the viewport */
	glViewport(0, 0, width, height);

	return true;
}

int loadContent()
{
	/* Create new buffer to store our triangle's vertices */
	glGenBuffers(1, &VBO);

	/* Tell OpenGL to use this buffer and inform that this buffer will contain an array of vertices*/
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	/* Fill buffer with data */
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* Enable a generic vertex attribute array */
	glEnableVertexAttribArray(0);

	/* Tell OpenGL how to interpret the data in the buffer */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	return true;
}

void render(float tpf)
{
	/* Draw our triangle */
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void update()
{
	float oldTime = 0.0f;
	float newTime = 0.0f;
	float gameTime = 0.0f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Update game time value */
		oldTime = newTime;
		newTime = (float)glfwGetTime();
		gameTime = newTime - oldTime;

		/* Render here */
		render(gameTime);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
}

int main(void)
{
	if (!init(640, 480))
		return -1;

	if (!loadContent())
		return -1;

	update();

	glfwTerminate();
	return 0;
}