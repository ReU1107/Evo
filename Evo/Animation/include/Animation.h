#pragma once

namespace Alpha
{
	// �S�ẴA�j���[�V�����̊��N���X
	class Animation
	{
	public:
		Animation();

		virtual ~Animation() {}

		virtual void OnUpdate(const float deltaTime) = 0;

		// �Đ����x
		void SetSpeed(const float speed);

		float GetSpeed() const;

	private:
		float m_speed;

	};

}