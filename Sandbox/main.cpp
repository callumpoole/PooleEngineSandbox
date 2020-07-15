#include "Poole.h"

class Sandbox : public Poole::Engine
{
public:
	Sandbox() : Engine()
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