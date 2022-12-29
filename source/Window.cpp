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



    this->window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!this->window)
    {
        glfwTerminate();

    }


    glfwMakeContextCurrent(this->window);

}

void JPH::Window::initglew()
{

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        std::cerr << "Error al inicializar glew" << glewGetErrorString(err) << std::endl;
    }

}

void JPH::Window::start()
{
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
