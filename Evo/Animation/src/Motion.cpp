#include "..\include\Motion.h"

namespace Alpha
{
	Motion::Motion()
		: m_weight()
	{
	}

	Motion::~Motion()
	{
	}

	void Motion::SetWeight(const float weight)
	{
		m_weight = weight;
	}

	float Motion::GetWeight() const
	{
		return m_weight;
	}
}