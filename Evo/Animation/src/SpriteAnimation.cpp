#include "SpriteAnimation.h"
#include "SpriteBone.h"

namespace Alpha
{
	/*
	* �����܂ł������Ă����͍̂��W�𓮂������̂�
	*/

	class SpriteAnimation::Impl
	{
	private:

	public:
		Impl();
		~Impl();

		


	};


	SpriteAnimation::SpriteAnimation()
		: m_impl(new Impl())
	{
	}

	SpriteAnimation::~SpriteAnimation()
	{
		delete m_impl;
	}
}