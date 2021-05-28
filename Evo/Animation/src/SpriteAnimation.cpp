#include "SpriteAnimation.h"
#include "SpriteBone.h"

namespace Alpha
{
	/*
	* あくまでも持っておくのは座標を動かす情報のみ
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