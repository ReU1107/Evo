#include "LinearAnimationCurve.h"
#include "Check.h"
#include "Transform.h"
#include "Arithmetic.h"

namespace Alpha
{
	template<>
	void TLinearAnimationCurve<KeyframeT>::OnUpdate(const float time, void* target)
	{
		// �����Ŗ���Ă������Ԃ���Ƀf�[�^���̏����X�V����
		// data�������Ă��Ȃ�������~�߂�
		PreCondition(target);

		const uint64 keyframeCount = m_keyframes.size();

		uint64 left = 0;
		uint64 middle = 0;
		uint64 right = keyframeCount - 1;
		do
		{
			middle = (left + right) / 2;
			// middle�̎��Ԃ̕����傫����time�͐^�񒆂��O�ɂ�����ő�l�����炷
			if (m_keyframes.at(middle).GetTime() > time)
			{
				right = middle;
			}
			else
			{
				left = middle;
			}

		} while (left + 1 < right);

		KeyframeT& lhs = m_keyframes.at(left);
		KeyframeT& rhs = m_keyframes.at(right);

		// �����̎��Ԃƕ�ԂɕK�v�Ȓl����Ƀf�[�^�̒��g������������
		// TODO:���݉��u����(�����̏������֐������ɕϊ�)
		const float a = ((time - lhs.GetTime()) / (rhs.GetTime() - lhs.GetTime()));

		Transform* transform = reinterpret_cast<Transform*>(target);
		// �^�`�F�b�N
#if 0
		Check(transform->GetType() == Transform::Type());
#endif

		transform->GetLocation();

		const Vector3 t = VectorLerp(lhs.GetValue().GetLocation(), rhs.GetValue().GetLocation(), a);
		const Quaternion q = QuaternionSlerp(lhs.GetValue().GetRotation(), rhs.GetValue().GetRotation(), a);
		const Vector3 s = VectorLerp(lhs.GetValue().GetScale(), rhs.GetValue().GetScale(), a);

		transform->SetLocation(t);
		transform->SetRotation(q);
		transform->SetScale(s);
	}
}