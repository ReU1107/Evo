#pragma once
#include "AlphaImpl.h"
#include "Motion.h"

namespace Alpha
{
	class AnimationCurve;

	class AnimationClip final : public Motion
	{
	public:
		AnimationClip();

		~AnimationClip();

	private:
		AlphaImpl;

	};
}