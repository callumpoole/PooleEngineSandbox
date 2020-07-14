#include "poole.h"
#include <memory>

std::unique_ptr<PooleEngine> engine;

int main()
{
	engine = std::make_unique<PooleEngine>("Poole Engine Sandbox", glm::uvec2(640, 480));
}