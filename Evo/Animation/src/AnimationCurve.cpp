#include "AnimationCurve.h"
#include "Array.h"

namespace Alpha
{
	class AnimationCurve::Impl
	{
	private:
		TArray<Keyframe> m_keyframes;	// キーフレーム配列

	public:
		Impl();
		~Impl();

		uint64 GetKeyframeCount() const;

		void AddKeyframe(const Keyframe& keyframe);

		void Sort();

	};

	AnimationCurve::AnimationCurve() noexcept
		: m_impl(new Impl())
	{
	}
	
	AnimationCurve::~AnimationCurve() noexcept
	{
		delete m_impl;
	}
	
	uint64 AnimationCurve::GetKeyframeCount() const
	{
		return m_impl->GetKeyframeCount();
	}

	void AnimationCurve::Sort()
	{
		m_impl->Sort();
	}
}