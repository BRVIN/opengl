#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawColoredSquare() {
    glBegin(GL_LINES);

    // Bottom (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);

    // Right (green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);

    // Top (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);

    // Left (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f,  0.5f);
    glVertex2f(-0.5f, -0.5f);

    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Colored Square", NULL, NULL);
    //GLFWwindow* window = glfwCreateWindow(400, 300, "Colored Square", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Background gray

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawColoredSquare();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

