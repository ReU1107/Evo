#pragma once

namespace Alpha
{
	// より大きい(lhs > rhs)
	template<typename T>
	inline bool Greater(const T& lhs, const T& rhs)
	{
		return (lhs > rhs);
	}

	// より小さい(lhs < rhs)
	template<typename T>
	inline bool Less(const T& lhs, const T& rhs)
	{
		return (lhs < rhs);
	}

	// 等しい
	template<typename T>
	inline bool Equal(const T& lhs, const T& rhs)
	{
		return (lhs == rhs);
	}

	// 
	template<typename T>
	inline bool NotEqual(const T& lhs, const T& rhs)
	{
		return (lhs != rhs);
	}

}