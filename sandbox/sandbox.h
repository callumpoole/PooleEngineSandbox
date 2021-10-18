#include "poole.h"

class Sandbox : public Poole::Engine
{
public:
	Sandbox() : Engine("Sandbox", uvec2(640, 480))
	{
	}
	~Sandbox()
	{
	}

	virtual void BeginApp() override;
	virtual void UpdateApp(float deltaTime) override;
	virtual void EndApp() override;
};

Poole::Engine* Poole::CreateApplication()
{
	return new Sandbox();
}