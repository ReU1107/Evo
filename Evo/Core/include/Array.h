#pragma once
#include <vector>

namespace Alpha
{
	/*
	* ���݂̎��͂���std::vector�̗򉻔łɂ����Ȃ�Ȃ�����
	* std::vector���g�p���Ă�������
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