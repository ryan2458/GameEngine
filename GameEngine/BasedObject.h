#ifndef BASED_OBJECT_H
#define BASED_OBJECT_H

#include <string>

class BasedObject
{
private:
	BasedObject* parent;
	std::string name;
public:
	BasedObject(const std::string& name);
	virtual ~BasedObject() = 0;

	virtual void load();
	virtual void init();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();
	virtual void unload(); 

	//virtual void* getParent();

	inline const std::string& getName() { return name; }
};

#endif