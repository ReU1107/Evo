#pragma once
#include "ParticleModule.h"

/*
* �p�[�e�B�N���G�~�b�^�[���K��������W���[��
*/

namespace FAL
{

	// �K�{���W���[��
	class RequiredModule final : public ParticleModule
	{
	public:
		// �R���X�g���N�^
		RequiredModule();
		// �f�X�g���N�^
		virtual ~RequiredModule();

	private:
		using Base = ParticleModule;
		AlphaImpl;

	};
}