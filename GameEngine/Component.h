#include "Engine.h"

class Component
{
private:
	unsigned int entityId;
public:
	Component(unsigned int entityId);
	virtual void start();
	virtual void update();
};