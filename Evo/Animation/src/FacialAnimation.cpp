#include "FacialAnimation.h"
#include "Array.h"
#include "Vector.h"
#include "Map.h"
#include "MorphTarget.h"

namespace Alpha
{
	class FacialAnimation::Impl
	{
	private:
		TArray<Vector3> m_pos;
		TMap<const char*, MorphTarget*> m_targets;


	public:

		// 
		void Update(const float time);

		TArray<Vector3>& GetBlendPositions();

	};

	void FacialAnimation::Impl::Update(const float time)
	{
		// ターゲット毎のウエイトを変化させる



	}

}