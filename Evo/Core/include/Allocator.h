#pragma once

namespace Alpha
{
	/*
	* 	バイトサイズを一定にする
	* @parameter 第一引数を
	* @parameter 第二引数のサイズにする
	*/
	template<typename T, typename U>
	inline T Alignment(T base, U alignment)
	{
		return ((base + alignment - 1) / alignment) * alignment;
	}
}