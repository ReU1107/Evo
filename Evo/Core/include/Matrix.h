#pragma once
#include "Vector.h"
#include <initializer_list>
/*

Matrix4x4(0,0,0,0,
          0,0,0,0,
		  0,0,0,0,
		  0,0,0,0);
ができないようになっている

↑のようにやりたいときは
Matrix4x4(Vector4(0,0,0,0),
          Vector4(0,0,0,0),
		  Vector4(0,0,0,0),
		  Vector4(0,0,0,0));
と記述しないといけない。

記述がめんどくさくなるが
見た目としてはわかりやすいと思う。

Matrix4x4(1);
で
(1,0,0,0)
(0,1,0,0)
(0,0,1,0)
(0,0,0,1)
になる、
*/


namespace Alpha
{
	/*
	Row:行
	Column:列
	*/

	template<typename Type, int32 Row, int32 Column>
	class TMatrix
	{
	public:
		union
		{
			TVector<Type, Column> v[Row];
			Type e[Row * Column];
		};
	public:
		static constexpr TMatrix<Type, Row, Column> Identity();
		static constexpr TMatrix<Type, Row, Column> Zero();

		TMatrix()
			: v()
		{
		}

		// 対角線上に値を代入
		TMatrix(const Type scalar)
			: v()
		{
			for (uint32_t i = 0; i < Row; i++)
			{
				v[i][i] = scalar;
			}
		}
		
		template<typename... Args>
		TMatrix(const Args... args)
			: v()
		{
			constexpr auto argsCount = sizeof...(Args);
			static_assert(Row >= argsCount, "Count is less than Args(TMatrx)");

			Assign(G(args)...);
		}

		inline TMatrix<Type, Row, Column>& operator=(const TMatrix<Type, Row, Column>& other);

		inline TMatrix<Type, Row, Column>& operator*=(const TMatrix<Type, Row, Column>& other);

		inline TVector<Type, Column>& operator[](const int32 index);

		inline TVector<Type, Column> At(const int32 index) const;

	private:
		// パラメーターパック展開関数
		inline TVector<Type, Column> G(const TVector<Type, Column>& t) { return t; }

		template<typename... Args>
		void Assign(Args const&... args)
		{
			int32_t i = 0;
			for (auto const& value : { args... })
			{
				v[i++] = value;
			}
		}

	};

	template<typename Type, int32 Row, int32 Column>
	inline TMatrix<Type, Row, Column> operator*(const TMatrix<Type, Row, Column>& lhs, const TMatrix<Type, Row, Column>& rhs);

	using Matrix2x2 = TMatrix<float, 2, 2>;
	using Matrix3x3 = TMatrix<float, 3, 3>;
	using Matrix3x4 = TMatrix<float, 3, 4>;
	using Matrix4x3 = TMatrix<float, 4, 3>;
	using Matrix4x4 = TMatrix<float, 4, 4>;

	using matrix2x2 = Matrix2x2;
	using matrix3x3 = Matrix3x3;
	using matrix3x4 = Matrix3x4;
	using matrix4x3 = Matrix4x3;
	using matrix4x4 = Matrix4x4;

	using float2x2 = Matrix2x2;
	using float3x3 = Matrix3x3;
	using float3x4 = Matrix3x4;
	using float4x3 = Matrix4x3;
	using float4x4 = Matrix4x4;

	//template<int32 Row, int32 Column>
	//inline TMatrix<float,Row,Column> Cast(const Matrix4x4& mat)
	//{
	//	TMatrix<float, Row, Column> m;
	//	for (int32_t i = 0; i < Row; i++)
	//	{
	//		for (int32_t j = 0; j < Column; j++)
	//		{
	//			m[i][j] = mat.At(i).At(j);
	//		}
	//	}

	//	return m;
	//}
}

#include "MatrixImpl.h"