#pragma once
#include <vector>

namespace Alpha
{
	/*
	* 現在の実力だとstd::vectorの劣化版にしかならないため
	* std::vectorを使用してください
	*/
#if 0
	template<typename T>
	class TArray
	{
	private:

	public:
		// 
		TArray();
		// 
		~TArray();

	};

	template<typename T>
	inline TArray<T>::TArray()
	{
	}

	template<typename T>
	inline TArray<T>::~TArray()
	{
	}
#else
#define TArray std::vector
#endif
}