#include <GL/glew.h>          // GLEW provides access to modern OpenGL functions
#include <GLFW/glfw3.h>       // GLFW handles window and input

int main() {

	// Initialize GLFW
	if (!glfwInit()) return -1;

	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(800, 800, "Colorful Square", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Initialize GLEW (must be done after making a context current)
	if (glewInit() != GLEW_OK) {
		return -1;
	}

	// Set up viewport size
	glViewport(0, 0, 800, 800);

	// Main render loop
	while (!glfwWindowShouldClose(window)) {

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);

		// Clear the screen with black color
		glClear(GL_COLOR_BUFFER_BIT);

		// Set up 2D orthographic projection for simple drawing
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1, 1, -1, 1, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Draw a square using 4 lines
		glBegin(GL_LINES);

		/// cross ///
		//glColor3f(0.0f, 0.0f, 1.0f);        // Set color to red
		glColor3f(1.0f, 1.0f, 0.0f);        // Set color to red
		glVertex2f(-0.003f, 0.0f);           // Line start
		glVertex2f( 0.003f, 0.0f);           // Line end
		
		//glColor3f(1.0f, 1.0f, 0.0f);        // Set color to red
		//glVertex2f(0.0f, 0.005f);           // Line start
		//glVertex2f( 0.0f, -0.005f);           // Line end
		/// cross ///

		/// triangle ///
		
		/// down
		glColor3f(1.0f, 1.0f, 0.0f);        // Set color to red
		glVertex2f(-0.3f, -0.3f);           // Line start
		glVertex2f( 0.3f, -0.3f);           // Line end

		/// left
		glColor3f(1.0f, 1.0f, 0.0f);        // Set color to red
		glVertex2f(-0.3f, -0.3f);           // Line start
		glVertex2f( 0.0f, 0.3f);           // Line end

		/// right
		glColor3f(1.0f, 1.0f, 0.0f);        // Set color to red
		glVertex2f( 0.0f, 0.3f);           // Line end
		glVertex2f(0.3f, -0.3f);           // Line start


		/// triangle ///
						    
		/*
		// Bottom edge - Red
		glColor3f(1.0f, 0.0f, 0.0f);        // Set color to red
		glVertex2f(-0.5f, -0.5f);           // Line start
		glVertex2f( 0.5f, -0.5f);           // Line end

		// Right edge - Green
		glColor3f(0.0f, 1.0f, 0.0f);        // Set color to green
		glVertex2f(0.5f, -0.5f);            // Line start
		glVertex2f(0.5f,  0.5f);            // Line end

		// Top edge - Blue
		glColor3f(0.0f, 0.0f, 1.0f);        // Set color to blue
		glVertex2f(0.5f,  0.5f);            // Line start
		glVertex2f(-0.5f, 0.5f);            // Line end

		// Left edge - Yellow
		glColor3f(1.0f, 1.0f, 0.0f);        // Set color to yellow
		glVertex2f(-0.5f, 0.5f);            // Line start
		glVertex2f(-0.5f, -0.5f);           // Line end
	
		*/

		glEnd();

		// Swap front and back buffers (display rendered frame)
		glfwSwapBuffers(window);

		// Poll for and process input events
		glfwPollEvents();
	}

	// Clean up and close the window
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

