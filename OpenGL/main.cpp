/*
    Anthony Cieri 2023/12/21

    Idk what I'm doing

    glfw and OpenGL with C++ yay!!!!!!!!!!!1
*/

# include "main.h"

int main(int argc, char const *argv[])
{
    std::cout << "Hello, World!\n";

    // Update context
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello, World!", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    // Check that glad is working
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set size of the viewport
    glViewport(0, 0, 800, 600);

    // Update viewport size on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        handleInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void handleInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
