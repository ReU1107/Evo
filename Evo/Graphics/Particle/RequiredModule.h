#pragma once
#include "ParticleModule.h"

/*
* パーティクルエミッターが必ず一つ持つモジュール
*/

namespace FAL
{

	// 必須モジュール
	class RequiredModule final : public ParticleModule
	{
	public:
		// コンストラクタ
		RequiredModule();
		// デストラクタ
		virtual ~RequiredModule();

	private:
		using Base = ParticleModule;
		AlphaImpl;

	};
}