#include "sandbox.h"

#include <iostream>

void Sandbox::BeginApp()
{
	std::cout << "Sandbox::BeginApp()\n";
}

void Sandbox::UpdateApp(float deltaTime)
{
	std::cout << "Sandbox::UpdateApp(" << deltaTime << ")\n";
}

void Sandbox::EndApp()
{
	std::cout << "Sandbox::EndApp()\n";
}
