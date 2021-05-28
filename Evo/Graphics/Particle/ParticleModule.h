#pragma once
#include "AlphaImpl.h"

namespace FAL
{

	class ParticleModule
	{
	public:
		// コンストラクタ
		ParticleModule();
		// デストラクタ
		virtual ~ParticleModule();

	private:
		AlphaImpl;

	};

}