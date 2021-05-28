#include "AnimationState.h"
#include "Animation.h"

namespace Alpha
{
	class AnimationState::Impl
	{
	private:
		Animation* m_animation;		// 処理するアニメーション
		void* m_data;				// 処理対象のオブジェクト

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