﻿#pragma once
#include "XComplex.h"
#include "XConstant.h"
#include "XDistance.h"
#include "XEquation.h"
#include "XIntersect.h"

namespace xmath
{
	inline void SinCos(float ang, float& fSin, float& fCos)
	{
		fSin = std::sin(ang);
		fCos = std::cos(ang);
	}
}