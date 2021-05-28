#pragma once

namespace Alpha
{
	/*
	* 	�o�C�g�T�C�Y�����ɂ���
	* @parameter ��������
	* @parameter �������̃T�C�Y�ɂ���
	*/
	template<typename T, typename U>
	inline T Alignment(T base, U alignment)
	{
		return ((base + alignment - 1) / alignment) * alignment;
	}
}