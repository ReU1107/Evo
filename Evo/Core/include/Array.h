#pragma once
#include <vector>

namespace Alpha
{
	/*
	* Œ»İ‚ÌÀ—Í‚¾‚Æstd::vector‚Ì—ò‰»”Å‚É‚µ‚©‚È‚ç‚È‚¢‚½‚ß
	* std::vector‚ğg—p‚µ‚Ä‚­‚¾‚³‚¢
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