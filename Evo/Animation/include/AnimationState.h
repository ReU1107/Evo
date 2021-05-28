#pragma once
#include "AlphaImpl.h"

namespace Alpha
{

	class AnimationState
	{
	public:

	private:
		AlphaImpl;

	};
	/*	class AnimationStateBase
	{
	public:
		virtual void OnUpdate(const float deltaTime) = 0;

		Motion* GetMotion() const;

		void SetMotion(Motion* motion);

		// 
		void SetTime(const float time);

		// 
		float GetTime() const;
	};


	class AnimationState final : public AnimationStateBase
	{
	private:
		AnimationClip* m_clip;
	public:
		AnimationState();
		~AnimationState();

	};
	*/

}