#pragma once

#include "ExplicitContext.h"

class Kernel {
public:
	Kernel(ExplicitContext ctx): ctx(ctx) {}
	~Kernel() { /*Do nothing, since ctx is created outside of cpp*/ }

	ExplicitContext GetContext() { return ctx; }
private:
	ExplicitContext ctx;
};
