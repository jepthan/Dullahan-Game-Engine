#pragma once
#include <iostream>
#include "gl/glew.h"
#include "glfw/glfw3.h"

namespace JPH {
	class Window {

	public:
		Window();
		virtual ~Window();
		void initglfw();
		void initglew();
		void start();
	private:
		GLFWwindow* window;



	};
}