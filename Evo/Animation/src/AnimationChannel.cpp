#include "AnimationChannel.h"
#include "AnimationCurve.h"
#include "Array.h"

namespace Alpha
{
	/*
	* 例:
	* 平行移動チャンネル
	* 回転チャンネル
	* スケールチャンネル
	*/
	/*
	* 格納されるアニメーションカーブで配置されているキーフレームの時間は
	* 全て共通にしないといけない
	*/

	enum class AnimationChannelType
	{

	};

	struct AnimationParameter
	{
		union
		{
			Vector3 location;		// 移動
			Quaternion rotation;	// 回転
			Vector3 scale;			// 大きさ
		};
	};

	class AnimationChannel::Impl
	{
	private:
		TArray<AnimationCurve*> m_parameterCures;	// アニメーションパラメータ用アニメーションカーブ
		AnimationCurve* m_timeCurve;				// アニメーション時刻用アニメーションカーブ
	public:
		Impl();
		~Impl();

		// アニメーションカーブ追加
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