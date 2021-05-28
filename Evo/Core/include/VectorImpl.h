#pragma once
#include "Vector.h"
#include <cassert>

namespace Alpha
{
	template<typename Type, int32 N>
	inline constexpr TVector<Type, N> TVector<Type, N>::Zero()
	{
		return TVector<Type, N>();
	}

	template<typename Type, int32 N>
	inline constexpr TVector<Type, N> TVector<Type, N>::One()
	{
		TVector<Type, N> vec = TVector<Type, N>::Zero();
		for (int32 i = 0; i < N; i++)
		{
			vec[i] = 1.0f;
		}
		return vec;
	}

	template<typename Type, int32 N>
	inline TVector<Type, 1>& TVector<Type, N>::X()
	{
		static_assert(N >= 1, "Count is less than 1(X)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[0]);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 1>& TVector<Type, N>::Y()
	{
		static_assert(N >= 2, "Count is less than 2(Y)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[1]);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 1>& TVector<Type, N>::Z()
	{
		static_assert(N >= 3, "Count is less than 3(Z)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[2]);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 1>& TVector<Type, N>::W()
	{
		static_assert(N >= 4, "Count is less than 4(W)");
		return *reinterpret_cast<TVector<Type, 1>*>(&v[3]);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 2>& TVector<Type, N>::XY()
	{
		static_assert(N >= 2, "Count is less than 2(XY)");
		return *reinterpret_cast<TVector<Type, 2>*>(this);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 3>& TVector<Type, N>::XYZ()
	{
		static_assert(N >= 3, "Count is less than 3(XYZ)");
		return *reinterpret_cast<TVector<Type, 3>*>(this);
	}

	template<typename Type, int32 N>
	inline TVector<Type, 4>& TVector<Type, N>::XYZW()
	{
		static_assert(N >= 4, "Count is less than 4(XYZW)");
		return *reinterpret_cast<TVector<Type, 4>*>(this);
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator=(const TVector<Type, N>& other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] = other.v[i];
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator+=(const TVector<Type, N>& other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] += other.v[i];
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator-=(const TVector<Type, N>& other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] -= other.v[i];
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator*=(const TVector<Type, N>& other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] *= other.v[i];
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator/=(const TVector<Type, N>& other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] /= other.v[i];
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator=(const Type other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] = other;
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator+=(const Type other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] += other;
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator-=(const Type other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] -= other;
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator*=(const Type other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] *= other;
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N>& TVector<Type, N>::operator/=(const Type other)
	{
		for (int32 i = 0; i < N; i++)
		{
			this->v[i] /= other;
		}

		return *this;
	}

	template<typename Type, int32 N>
	inline Type& TVector<Type, N>::operator[](const int32 index)
	{
		assert(index < N && "Index is greater than Num");
		return v[index];
	}

	template<typename Type, int32 N>
	inline Type TVector<Type, N>::At(const int32 index) const
	{
		assert(index < N && "Index is greater than Num");
		return v[index];
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type,N>(lhs) += rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) += rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const Type lhs, const TVector<Type, N>& rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator+(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) += rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator-(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) -= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator*(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) *= rhs;
	}

	template<typename Type, int32 N>
	inline TVector<Type, N> operator/(const TVector<Type, N>& lhs, const Type rhs)
	{
		return TVector<Type, N>(lhs) /= rhs;
	}

}