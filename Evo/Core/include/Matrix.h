#pragma once
#include "Vector.h"
#include <initializer_list>
/*

Matrix4x4(0,0,0,0,
          0,0,0,0,
		  0,0,0,0,
		  0,0,0,0);
���ł��Ȃ��悤�ɂȂ��Ă���

���̂悤�ɂ�肽���Ƃ���
Matrix4x4(Vector4(0,0,0,0),
          Vector4(0,0,0,0),
		  Vector4(0,0,0,0),
		  Vector4(0,0,0,0));
�ƋL�q���Ȃ��Ƃ����Ȃ��B

�L�q���߂�ǂ������Ȃ邪
�����ڂƂ��Ă͂킩��₷���Ǝv���B

Matrix4x4(1);
��
(1,0,0,0)
(0,1,0,0)
(0,0,1,0)
(0,0,0,1)
�ɂȂ�A
*/


namespace Alpha
{
	/*
	Row:�s
	Column:��
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

		// �Ίp����ɒl����
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
		// �p�����[�^�[�p�b�N�W�J�֐�
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