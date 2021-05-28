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
	* 事前条件確認:
	* 処理を行う前にデータ等が入っていることを確認する
	*/
	template<typename T>
	void PreCondition(T condition)
	{
		Check(condition);
	}

	/*
	* 事後条件確認:
	* 処理を行った後に意図した状態になっていることを確認する
	*/
	template<typename T>
	void PostCondition(T condition)
	{
		Check(condition);
	}

	// 引数未使用の警告対策
	template<class T>
	inline void UnusedArgment(T t)
	{
		(t);
	}

}