#pragma once
#include "AlphaImpl.h"

namespace FAL
{

	class ParticleModule
	{
	public:
		// �R���X�g���N�^
		ParticleModule();
		// �f�X�g���N�^
		virtual ~ParticleModule();

	private:
		AlphaImpl;

	};

}