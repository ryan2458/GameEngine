#include "BasedObject.h"

BasedObject::BasedObject(const std::string& name) : parent(nullptr)
{
	this->name = name;
}

//*******************
// FUNCTION STUBS
//*******************
BasedObject::~BasedObject()
{

}

void BasedObject::load()
{
}

void BasedObject::init()
{
}

void BasedObject::update(float dt)
{
}

void BasedObject::draw()
{
}

void BasedObject::shutdown()
{
}

void BasedObject::unload()
{
}

//*******************
//*******************
