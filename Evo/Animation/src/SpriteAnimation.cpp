#include "SpriteAnimation.h"
#include "SpriteBone.h"

namespace Alpha
{
	/*
	* ‚ ‚­‚Ü‚Å‚à‚Á‚Ä‚¨‚­‚Ì‚ÍÀ•W‚ğ“®‚©‚·î•ñ‚Ì‚İ
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