#ifndef _TEST_SCRIPT
#define _TEST_SCRIPT

#include "GlacierAPI.h"

class TestScript : public Script
{
public:
	TestScript();
	~TestScript() = default;

	virtual void OnUpdate(float dt);
};

#endif 