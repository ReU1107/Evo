#pragma once

namespace Alpha
{
	// ���傫��(lhs > rhs)
	template<typename T>
	inline bool Greater(const T& lhs, const T& rhs)
	{
		return (lhs > rhs);
	}

	// ��菬����(lhs < rhs)
	template<typename T>
	inline bool Less(const T& lhs, const T& rhs)
	{
		return (lhs < rhs);
	}

	// ������
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