#ifndef _ROLLING_MARBLE
#define _ROLLING_MARBLE

#include "GlacierAPI.h"

class RollingMarble : public Glacier::Application
{
public:
	RollingMarble(const int window_width, const int window_height, const char* const icon_path = nullptr);

	virtual void LoadResources() override;
};

#endif // !_ROLLING_MARBLE
