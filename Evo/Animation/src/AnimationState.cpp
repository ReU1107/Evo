#include "AnimationState.h"
#include "Animation.h"

namespace Alpha
{
	class AnimationState::Impl
	{
	private:
		Animation* m_animation;		// ��������A�j���[�V����
		void* m_data;				// �����Ώۂ̃I�u�W�F�N�g

	public:
		void SetAnimation(Animation* animation);

		void SetData(void* data);

		void Update(const float deltaTime)
		{
			float time = deltaTime;
			m_animation->OnUpdate(time, data);
		}

	};

}