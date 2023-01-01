#include "Window.h"

JPH::Window::Window()
{

    this->initglfw();

    this->initglew();
   
}

JPH::Window::~Window()
{

}

void JPH::Window::initglfw()
{

    if (!glfwInit()) {
        std::cerr << "Error al inicializar glfw" << std::endl;
    }

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    this->window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!this->window)
    {
        glfwTerminate();

    }


    glfwMakeContextCurrent(this->window);

}
//error print callback
void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam) {
    std::cout << "Error From Opengl (" << type << ") " << message << std::endl;
}

void JPH::Window::initglew()
{

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        std::cerr << "Error al inicializar glew" << glewGetErrorString(err) << std::endl;
    }
    //set error system
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

}

void JPH::Window::start()
{
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };
    GLuint VertexBuffer;
    glGenBuffers(1, &VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(this->window))
    {
        /* Render here */
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        
        glBindVertexArray(VertexBuffer);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        /* Swap front and back buffers */
        glfwSwapBuffers(this->window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
}
