#pragma once

namespace Alpha
{
	class AnimationParameter;

	class Motion
	{
	public:
		Motion();
		virtual ~Motion();

		// �A�j���[�V�����K�p���ݒ�
		void SetWeight(const float weight);

		// �A�j���[�V�����K�p���擾
		float GetWeight() const;

		void GetAnimationParameter(AnimationParameter* parameter);

	private:
		float m_weight;		// 
	};

}