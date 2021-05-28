#pragma once
#include "Matrix.h"

namespace Alpha
{
	template<typename Type, int32 Row, int32 Column>
	inline constexpr TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Identity()
	{
		return TMatrix<Type, Row, Column>(1.0f);
	}
	
	template<typename Type, int32 Row, int32 Column>
	inline constexpr TMatrix<Type, Row, Column> TMatrix<Type, Row, Column>::Zero()
	{
		return TMatrix<Type, Row, Column>(0.0f);
	}

	template<typename Type, int32 Row, int32 Column>
	inline TMatrix<Type, Row, Column>& TMatrix<Type, Row, Column>::operator=(const TMatrix<Type, Row, Column>& other)
	{
		for (int32 i = 0; i < Row; i++)
		{
			this->v[i] = other.At(i);
		}

		return *this;
	}

	template<typename Type, int32 Row, int32 Column>
	inline TMatrix<Type, Row, Column>& TMatrix<Type, Row, Column>::operator*=(const TMatrix<Type, Row, Column>& other)
	{
#ifdef _OPENMP
#pragma omp parallel for
#endif
		for (int32_t i = 0; i < Row; i++)
		{
			for (int32_t j = 0; j < Column; j++)
			{
				for (int32_t k = 0; k < Row; k++)
				{
					v[i][j] *= other.v[k].At(j);
				}
			}
		}
		return *this;
	}

	template<typename Type, int32 Row, int32 Column>
	inline TVector<Type, Column>& TMatrix<Type, Row, Column>::operator[](const int32 index)
	{
		return v[index];
	}

	template<typename Type, int32 Row, int32 Column>
	inline TVector<Type, Column> TMatrix<Type, Row, Column>::At(const int32 index) const
	{
		return v[index];
	}

	template<typename Type, int32 Row, int32 Column>
	inline TMatrix<Type,Row,Column> operator*(const TMatrix<Type, Row, Column>& lhs, const TMatrix<Type, Row, Column>& rhs)
	{
		return TMatrix<Type, Row, Column>(lhs) *= rhs;
	}

}