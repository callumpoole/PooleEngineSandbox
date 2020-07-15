#include "Poole.h"
#include <memory>

std::unique_ptr<Poole::Engine> engine;

int main()
{
	engine = std::make_unique<Poole::Engine>("Poole Engine Sandbox", glm::uvec2(640, 480));
}