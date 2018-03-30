#pragma once

#include "kernelContext.h"

class Kernel {
public:
	Kernel(KernelContext ctx): ctx(ctx) {}
	~Kernel() { /*Do nothing, since ctx is created outside of cpp*/ }

	KernelContext GetContext() { return ctx; }
private:
	KernelContext ctx;
};
