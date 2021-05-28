#pragma once
#include "Type.h"
/*
hlslのような書き方ができる
型指定と数指定

At(index)
[index]
使い分け
[]は変更可能
At()は変更できない const指定
*/

/*
float4 a;
float4 b = a.XYZ();

float4 c = float4(a,XY(),b.XY());

float4 d = float4(c.XYZ(),float1(1));	// floatだけどfloat1にしてください。

float4 e = float4(a.XY(),b.X(),c.X()); // これはできません。

float4 == Vector4;
同じになっている。

.x
.xy
.xyz
↓
.X()
.XY()
.XYZ()
にしないといけない。

*/

namespace Alpha
{

	template<typename Type, int32 N>
	class TVector
	{
	private:
		Type v[N];

	public:
		static constexpr TVector<Type, N> Zero();
		static constexpr TVector<Type, N> One();

		TVector()
			: v()
		{
			static_assert(N > 0, "");
		}

		TVector(const Type x)
			: v()
		{
			static_assert(N > 0, "ElementCount is less than Args(x)");
			v[0] = x;
		}

		TVector(const Type x, const Type y)
			: v()
		{
			static_assert(N > 1, "ElementCount is less than Args(x,y)");
			v[0] = x;
			v[1] = y;
		}

		TVector(const Type x, const Type y, const Type z)
			: v()
		{
			static_assert(N > 2, "ElementCount is less than Args(x,y,z)");
			v[0] = x;
			v[1] = y;
			v[2] = z;
		}

		TVector(const Type x, const Type y, const Type z, const Type w)
			: v()
		{
			static_assert(N > 3, "ElementCount is less than Args(x,y,z,w)");
			v[0] = x;
			v[1] = y;
			v[2] = z;
			v[3] = w;
		}

		template<typename T, int32 I>
		TVector(const TVector<T, I>& vec)
			: v()
		{
			// Vector4 = Vector3
			// Vector3 = Vector4もできるようにする
			const int32_t count = (I > N) ? N : I;
			
			for (int32_t i = 0; i < count; i++)
			{
				v[i] = vec.At(i);
			}
		}

		template<typename T, int32 I>
		TVector(const TVector<T, I>& vec, const TVector<T, N - I>& vec1)
			: v()
		{
			static_assert(N >= I,"Count is less than Args");

			const int32_t count = (I > N) ? N : I;

			for (int32_t i = 0; i < count; i++)
			{
				v[i] = vec.At(i);
			}

			for (int32_t i = 0; i < N - I; i++)
			{
				v[count + i] = vec1.At(i);
			}
		}

		inline TVector<Type, 1>& X();
		inline TVector<Type, 1>& Y();
		inline TVector<Type, 1>& Z();
		inline TVector<Type, 1>& W();

		inline TVector<Type, 2>& XY();
		inline TVector<Type, 3>& XYZ();
		inline TVector<Type, 4>& XYZW();

		inline TVector<Type, N>& operator=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator+=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator-=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator*=(const TVector<Type, N>& other);
		inline TVector<Type, N>& operator/=(const TVector<Type, N>& other);

		inline TVector<Type, N>& operator=(const Type other);
		inline TVector<Type, N>& operator+=(const Type other);
		inline TVector<Type, N>& operator-=(const Type other);
		inline TVector<Type, N>& operator*=(const Type other);
		inline TVector<Type, N>& operator/=(const Type other);

		inline Type& operator[](const int32 index);

		inline Type At(const int32 index) const;

	};

	// 
	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

	// 
	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const Type lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const Type lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const Type lhs, const TVector<Type, N>& rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const Type lhs, const TVector<Type, N>& rhs);

	// 
	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const Type rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const Type rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const Type rhs);
	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const Type rhs);


	/*
	コンストラクタを複数作成する方法が思いつかなかった
	(可変長引数含む)
	そのためこの形になりましたとさ
	*/

	using Vector1 = TVector<float, 1>;
	using Vector2 = TVector<float, 2>;
	using Vector3 = TVector<float, 3>;
	using Vector4 = TVector<float, 4>;

	using float1 = Vector1;
	using float2 = Vector2;
	using float3 = Vector3;
	using float4 = Vector4;
}

#include "VectorImpl.h"