#pragma once
#ifdef __cplusplus
#include <cassert>
#else
#include <assert.h>
#endif // __cplusplus

namespace Alpha
{

#if _DEBUG
	template<typename T>
	void Check(T condition)
	{
		assert(condition);
	}
#else
	template<typename T>
	void Check(T condition)
	{
		(condition);
	}
#endif

	/*
	* ���O�����m�F:
	* �������s���O�Ƀf�[�^���������Ă��邱�Ƃ��m�F����
	*/
	template<typename T>
	void PreCondition(T condition)
	{
		Check(condition);
	}

	/*
	* ��������m�F:
	* �������s������ɈӐ}������ԂɂȂ��Ă��邱�Ƃ��m�F����
	*/
	template<typename T>
	void PostCondition(T condition)
	{
		Check(condition);
	}

	// �������g�p�̌x���΍�
	template<class T>
	inline void UnusedArgment(T t)
	{
		(t);
	}

}