#pragma once
#include "Arithmetic.h"

namespace Alpha
{
	template<class Type, int32 N>
	Type VectorLengthSq(const TVector<Type, N>& vec)
	{
		Type value = 0.0f;
		for (int32 i = 0; i < N; i++)
		{
			value += vec.At(i) * vec.At(i);
		}

		return value;
	}

	template<class Type, int32 N>
	Type VectorLength(const TVector<Type, N>& vec)
	{
		return Math::Sqrt(VectorLengthSq(vec));
	}

	template<class Type, int32 N>
	Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		float value = 0.0f;
		for (int32 i = 0; i < N; i++)
		{
			value += lhs.At(i) * rhs.At(i);
		}
		return value;
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec)
	{
		return vec / VectorLength(vec);
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorLerp(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs, const float s)
	{
		return lhs * (1.0f - s) + rhs * s;
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * VectorDot(normal, -dir) + dir;
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir)
	{
		return normal * VectorDot(normal, -dir) * 2 + dir;
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max)
	{
		TVector<Type, N> v;
		for (int32 i = 0; i < N; i++)
		{
			v[i] = Clamp(vec.At(i), min, max);
		}

		return v;
	}

	template<class Type, int32 N>
	TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max)
	{
		TVector<Type, N> v;
		for (int32 i = 0; i < N; i++)
		{
			v[i] = Clamp(vec.At(i), min.At(i), max.At(i));
		}

		return v;
	}

	template<class Type, int32 R, int32 C>
	TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base)
	{
		TMatrix<Type, R, C> m;

		for (int32 i = 0; i < R; i++)
		{
			for (int32 j = 0; j < C; j++)
			{
				m[i][j] = base.At(j).At(i);
			}
		}

		return m;
	}

	template<class Type, int32 Row, int32 Column>
	TVector<Type, Column> VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat)
	{
		TVector<Type, Column> v = TVector<Type, Column>::Zero();
		for (int32 i = 0; i < Column; i++)
		{
			for (int32 j = 0; j < Row; j++)
			{
				v[i] += vec.At(j) * mat.At(j).At(i);
			}
		}

		return v;
	}

	template<class Type, int32 Row, int32 Column>
	TVector<Type, Column> Mul(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat)
	{
		TVector<Type, Column> v = TVector<Type, Column>::Zero();
		for (int32 i = 0; i < Column; i++)
		{
			for (int32 j = 0; j < Row; j++)
			{
				v[i] += vec.At(j) * mat.At(j).At(i);
			}
		}

		return v;
	}

}
