#pragma once

namespace Alpha
{
	// 全てのアニメーションの基底クラス
	class Animation
	{
	public:
		Animation();

		virtual ~Animation() {}

		virtual void OnUpdate(const float deltaTime) = 0;

		// 再生速度
		void SetSpeed(const float speed);

		float GetSpeed() const;

	private:
		float m_speed;

	};

}