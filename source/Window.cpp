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
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

}

void JPH::Window::start()
{

    unsigned int buffer;
    glGenBuffers(-1, &buffer);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(this->window))
    {
        /* Render here */
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(this->window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
}
