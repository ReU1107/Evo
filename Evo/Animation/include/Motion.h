#pragma once

namespace Alpha
{
	class AnimationParameter;

	class Motion
	{
	public:
		Motion();
		virtual ~Motion();

		// アニメーション適用率設定
		void SetWeight(const float weight);

		// アニメーション適用率取得
		float GetWeight() const;

		void GetAnimationParameter(AnimationParameter* parameter);

	private:
		float m_weight;		// 
	};

}