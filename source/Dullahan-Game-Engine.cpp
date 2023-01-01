// Dullahan-Game-Engine.cpp : Defines the entry point for the application.
//

#include "Dullahan-Game-Engine.h"
#include "IMGUI.h"
#include "Window.h"
#include "Math.h"






int main()
{
	JPH::Window *win = new JPH::Window();
	JPH::Vector2 hi = { 0,1 };
	std::cout << hi.y;
	win->start();
	
	return 0;
}
