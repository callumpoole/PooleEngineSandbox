#include "poole.h"

class Sandbox : public Poole::Engine
{
public:
	Sandbox(std::vector<std::string_view>&& commandArgs) : Engine(std::move(commandArgs), "Sandbox", uvec2(640, 480))
	{
	}
	~Sandbox()
	{
	}

	virtual void BeginApp() override;
	virtual void UpdateApp(float deltaTime) override;
	virtual void EndApp() override;
};

Poole::Engine* Poole::CreateApplication(std::vector<std::string_view>&& commandArgs)
{
	return new Sandbox(std::move(commandArgs));
}