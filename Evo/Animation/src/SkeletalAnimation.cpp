#include "SkeletalAnimation.h"
#include "Matrix.h"
#include "Map.h"
#include "Motion.h"
#include "Skeleton.h"
#include "Joint.h"

namespace Alpha
{

	class SkeletalAnimation::Impl
	{
	private:
		TMap<const char*, Motion*> m_motions;	// �W���C���g��,������������郂�[�V����

	public:

		void Update(const float time);

	};


	void SkeletalAnimation::Impl::Update(const float time)
	{
		Skeleton* skeleton = nullptr;	// �����Ŗ���Ă���

		// �����ŃX�P���g���I�u�W�F�N�g�̍s��p���b�g���X�V����
		// ���C���[�N���X����x�[�X�����Z������Ă���K�v������


		for (auto&& m : m_motions)
		{
			auto joint = skeleton->GetJoint(m.first);
			m.second;
			joint;
		}



	}

	SkeletalAnimation::SkeletalAnimation()
	{
	}

	SkeletalAnimation::~SkeletalAnimation()
	{
	}

	void SkeletalAnimation::Update()
	{

	}

}