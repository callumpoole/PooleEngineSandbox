#include "poole.h"

class Sudoku : public Poole::Engine
{
public:
	Sudoku(std::vector<std::string_view>&& commandArgs) : Engine(std::move(commandArgs), "Sandbox", uvec2(640, 480))
	{
	}
	~Sudoku()
	{
	}

	virtual void BeginApp() override;
	virtual void UpdateApp(float deltaTime) override;
	virtual void EndApp() override;
};

Poole::Engine* Poole::CreateApplication(std::vector<std::string_view>&& commandArgs)
{
	return new Sudoku(std::move(commandArgs));
}