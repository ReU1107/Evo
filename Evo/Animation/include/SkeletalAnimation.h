#pragma once
#include "AlphaImpl.h"

namespace Alpha
{

	// �s��p���b�g�̐����܂ł͍s��
	// �������̏����͏�ʑw�ł̒S�������ɂȂ�

	class SkeletalAnimation
	{
	public:
		// 
		SkeletalAnimation();
		// 
		~SkeletalAnimation();

		// �X�V����
		void Update();
		// �s��p���b�g�擾
	private:
		AlphaImpl;
	};
}