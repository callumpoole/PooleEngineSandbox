#include "poole.h"

class Sandbox : public Poole::Engine
{
public:
	Sandbox() : Engine("Sandbox", glm::uvec2(640, 480))
	{
		
	}
	~Sandbox()
	{
	}
};

Poole::Engine* Poole::CreateApplication()
{
	return new Sandbox();
}