#include "AnimationClip.h"
#include "Check.h"
#include "AnimationChannel.h"
#include "AnimationCurve.h"

namespace Alpha
{
	/*
	* AnimationClip:�A�j���[�V�������(�L�[�t���[���z��̏W�܂�����������̂ł����Ȃ�)
	* �P��̃W���C���g�ɑ΂��ẴN���b�v
	* �O��:�A�j���[�V�����N���b�v���X�P���g���P�ʂ�����
	*/

	// �������I�u�W�F�N�g���Ƃ���ɔ���
	class AnimationClip::Impl
	{
	private:
		TArray<AnimationChannel*> m_channels;	// �A�j���[�V�����`�����l���z��

		float m_blendCoeff;
	public:
		Impl();
		~Impl();
		// �A�j���[�V�����`�����l���ǉ�
		void AddAnimationChannel(AnimationChannel* channel);
		// �u�����h���ݒ�
		void SetBlendCoeff(const float coeff);

	};


	AnimationClip::Impl::Impl()
	{

	}

	AnimationClip::Impl::~Impl()
	{

	}

	AnimationClip::AnimationClip()
		: m_impl(new Impl())
	{
	}

	AnimationClip::~AnimationClip()
	{
		delete m_impl;
	}
}