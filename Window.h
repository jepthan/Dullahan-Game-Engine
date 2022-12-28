#pragma once
#include <iostream>
#include "gl/glew.h"
#include "glfw/glfw3.h"
namespace JPH {
	class Window {

	public:
		Window();
		~Window();
	private:
		GLFWwindow* window;



	};
}