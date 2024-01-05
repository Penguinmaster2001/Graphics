/*
    Anthony Cieri 2023/12/21

    Idk what I'm doing

    glfw and OpenGL with C++ yay!!!!!!!!!!!1
 */

# include "main.h"


# define WIN_INIT_WID 800
# define WIN_INIT_HEI 600

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <vertex shader path> <frag shader path>" << std::endl; 
        exit(0);
    }

    // Update context
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(WIN_INIT_WID, WIN_INIT_HEI, "Hello, World!", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(2);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load GLAD function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(3);
    }

    Shader shader(argv[1], argv[2]);

    // Make array of verts
    // float vertices[] = {
    //      0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
    //     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    //      0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
    // };
    float vertices[] = {
        // positions         // colors
         0.0f ,  0.24f, 0.0f,   1.0f, 0.0f, 0.0f, 
         0.17f,  0.42f, 0.0f,   0.0f, 1.0f, 0.0f, 
         0.22f,  0.36f, 0.0f,   0.0f, 0.0f, 1.0f  
    };

    uint VAO, VBO;

    // Set up vertex buffer object
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);



    // Interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0); 



    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        // Input
        handleInput(window);

        // Rendering
        glClearColor(0.1f, 0.15f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        float timeValue = glfwGetTime();
        float sinTime = (sin(timeValue) / 2.0f) + 0.5f;
        float cosTime = (cos(timeValue) / 2.0f) + 0.5f;
        shader.setFloat("sinTime", sinTime);
        shader.setFloat("offsetx", cosTime);
        shader.setFloat("offsety", sinTime);


        // glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // Check events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shader.ID);

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
