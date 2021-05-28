#pragma once
#include "Type.h"
#include "AlphaImpl.h"
#include "Keyframe.h"
#include "Array.h"

namespace Alpha
{

	// �L�[�t���[���̏W����
	class AnimationCurve
	{
	public:
		AnimationCurve() noexcept;
		// �f�X�g���N�^
		~AnimationCurve() noexcept;

		// �L�[�t���[�����擾
		uint64 GetKeyframeCount() const;

		// �\�[�g(�^�C����)
		void Sort();
	private:
		AlphaImpl;

	};

}
