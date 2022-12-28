#include "Window.h"

JPH::Window::Window()
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

JPH::Window::~Window()
{

}
