#pragma once
#include "Transform.h"

namespace Alpha
{
	struct Keyframe
	{
		float value;	// 
		float time;		// 
	};

	//using AnimationParameter = Keyframe;

	//template<typename Type>
	//class TKeyframe
	//{
	//public:
	//	TKeyframe();
	//	TKeyframe(const float time, const Type& value);

	//	// 時間設定
	//	void SetTime(const float time) { m_time = time; }
	//	// 値設定
	//	void SetValue(const Type& value) { m_value = value; }
	//	// 時間取得
	//	float GetTime() const { return m_time; }
	//	// 値取得
	//	const Type& GetValue() const { return m_value; }


	//private:
	//	float m_time;	// 時間
	//	Type m_value;	// 値

	//};

	//struct BezierControlPoint
	//{

	//};


	//// ベジェ曲線用キーフレーム
	//template<typename Type>
	//class TBezierKeyframe : public TKeyframe<Type>
	//{
	//public:
	//	TBezierKeyframe();
	//	TBezierKeyframe(const float time, const Type& value);
	//	TBezierKeyframe(const float time, const Type& value, const BezierControlPoint& point);
	//	

	//	//static BezierControlPoint EaseinEaseout();

	//private:
	//	// コントロールポイント
	//};

	//using Keyframe1 = TKeyframe<Vector1>;
	//using Keyframe2 = TKeyframe<Vector2>;
	//using Keyframe3 = TKeyframe<Vector3>;
	//using Keyframe4 = TKeyframe<Vector4>;
	//using KeyframeQ = TKeyframe<Quaternion>;
	//using KeyframeT = TKeyframe<Transform>;


	//template<typename Type>
	//inline bool operator<(const TKeyframe<Type>& lhs, const TKeyframe<Type>& rhs)
	//{
	//	return lhs.GetTime() < rhs.GetTime();
	//}

	//template<typename Type>
	//inline bool operator>(const TKeyframe<Type>& lhs, const TKeyframe<Type>& rhs)
	//{
	//	return lhs.GetTime() > rhs.GetTime();
	//}

	//template<typename Type>
	//inline TKeyframe<Type>::TKeyframe()
	//	: m_time()
	//	, m_value()
	//{

	//}
	//
	//template<typename Type>
	//inline TKeyframe<Type>::TKeyframe(const float time, const Type& value)
	//	: m_time(time)
	//	, m_value(value)
	//{

	//}
}