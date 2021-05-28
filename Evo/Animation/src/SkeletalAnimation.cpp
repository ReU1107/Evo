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
		TMap<const char*, Motion*> m_motions;	// ジョイント名,それを処理するモーション

	public:

		void Update(const float time);

	};


	void SkeletalAnimation::Impl::Update(const float time)
	{
		Skeleton* skeleton = nullptr;	// 引数で貰ってくる

		// ここでスケルトンオブジェクトの行列パレットを更新する
		// レイヤークラスからベースか加算か貰ってくる必要がある


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