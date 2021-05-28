#pragma once

namespace Alpha
{
	// ‚æ‚è‘å‚«‚¢(lhs > rhs)
	template<typename T>
	inline bool Greater(const T& lhs, const T& rhs)
	{
		return (lhs > rhs);
	}

	// ‚æ‚è¬‚³‚¢(lhs < rhs)
	template<typename T>
	inline bool Less(const T& lhs, const T& rhs)
	{
		return (lhs < rhs);
	}

	// “™‚µ‚¢
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