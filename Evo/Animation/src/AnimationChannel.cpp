#include "AnimationChannel.h"
#include "AnimationCurve.h"
#include "Array.h"

namespace Alpha
{
	/*
	* ��:
	* ���s�ړ��`�����l��
	* ��]�`�����l��
	* �X�P�[���`�����l��
	*/
	/*
	* �i�[�����A�j���[�V�����J�[�u�Ŕz�u����Ă���L�[�t���[���̎��Ԃ�
	* �S�ċ��ʂɂ��Ȃ��Ƃ����Ȃ�
	*/

	enum class AnimationChannelType
	{

	};

	struct AnimationParameter
	{
		union
		{
			Vector3 location;		// �ړ�
			Quaternion rotation;	// ��]
			Vector3 scale;			// �傫��
		};
	};

	class AnimationChannel::Impl
	{
	private:
		TArray<AnimationCurve*> m_parameterCures;	// �A�j���[�V�����p�����[�^�p�A�j���[�V�����J�[�u
		AnimationCurve* m_timeCurve;				// �A�j���[�V���������p�A�j���[�V�����J�[�u
	public:
		Impl();
		~Impl();

		// �A�j���[�V�����J�[�u�ǉ�
		void AddAnimationCurve(AnimationCurve* curve);

		void AddAnimationParameter(const float time);

		void GetAnimationParameter(const float time);

		void Update(const float time, void* data);

	};

	class TranslationAnimationChannel
	{

	};

	AnimationChannel::Impl::Impl()
	{

	}

	AnimationChannel::Impl::~Impl()
	{

	}
}