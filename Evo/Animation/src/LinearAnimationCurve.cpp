#include "LinearAnimationCurve.h"
#include "Check.h"
#include "Transform.h"
#include "Arithmetic.h"

namespace Alpha
{
	template<>
	void TLinearAnimationCurve<KeyframeT>::OnUpdate(const float time, void* target)
	{
		// 引数で貰ってきた時間を基にデータ内の情報を更新する
		// dataが入ってこなかったら止める
		PreCondition(target);

		const uint64 keyframeCount = m_keyframes.size();

		uint64 left = 0;
		uint64 middle = 0;
		uint64 right = keyframeCount - 1;
		do
		{
			middle = (left + right) / 2;
			// middleの時間の方が大きい≒timeは真ん中より前にある≒最大値を減らす
			if (m_keyframes.at(middle).GetTime() > time)
			{
				right = middle;
			}
			else
			{
				left = middle;
			}

		} while (left + 1 < right);

		KeyframeT& lhs = m_keyframes.at(left);
		KeyframeT& rhs = m_keyframes.at(right);

		// 両側の時間と補間に必要な値を基にデータの中身を書き換える
		// TODO:現在仮置き中(ここの処理を関数処理に変換)
		const float a = ((time - lhs.GetTime()) / (rhs.GetTime() - lhs.GetTime()));

		Transform* transform = reinterpret_cast<Transform*>(target);
		// 型チェック
#if 0
		Check(transform->GetType() == Transform::Type());
#endif

		transform->GetLocation();

		const Vector3 t = VectorLerp(lhs.GetValue().GetLocation(), rhs.GetValue().GetLocation(), a);
		const Quaternion q = QuaternionSlerp(lhs.GetValue().GetRotation(), rhs.GetValue().GetRotation(), a);
		const Vector3 s = VectorLerp(lhs.GetValue().GetScale(), rhs.GetValue().GetScale(), a);

		transform->SetLocation(t);
		transform->SetRotation(q);
		transform->SetScale(s);
	}
}