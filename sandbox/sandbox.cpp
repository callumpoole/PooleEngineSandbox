#include "poole.h"

class sandbox : public poole::engine
{
public:
	sandbox() : engine("Sandbox", glm::uvec2(640, 480))
	{
		
	}
	~sandbox()
	{
	}
};

poole::engine* poole::create_application()
{
	return new sandbox();
}