#pragma once

namespace Alpha
{
	enum class AnimationLayerType
	{
		Base,	// ベースとなる下位レイヤー
		Add,	// ベースに対して加算合成を行う上位レイヤー
	};
	/*
	* 下位レイヤーは=
	* 上位レイヤーは+
	* 処理が施される
	* もし同部位の下位レイヤーが2つ以上存在したら一番後に追加されたものの結果になる
	*/

	class AnimationLayer
	{
	public:
		virtual ~AnimationLayer() noexcept {}

		
	private:
		// AnimationStateMachine* m_stateMachine;	// ステートマシーン

	};

	// ベースレイヤー
	class AnimationBaseLayer final : public AnimationLayer
	{

	};

	// 加算レイヤー
	class AnimationAddLayer final : public AnimationLayer
	{

	};
}