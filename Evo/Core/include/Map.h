#pragma once
#include <unordered_map>

namespace Alpha
{
#if 0
	template<typename Key,typename Type>
	class TMap
	{
	private:

	public:
		// 
		TMap();
		// 
		~TMap();



	};
#else
#define TMap std::unordered_map
#endif

}