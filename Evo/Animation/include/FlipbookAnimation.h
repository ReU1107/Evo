#pragma once
#include "Type.h"
#include "Animation.h"
#include "AlphaImpl.h"

namespace Alpha
{
	/*
	* �e�N�X�`����؂�ւ���^�C�v�̃A�j���[�V����
	* ���ŋ����C���[�W����Ƃ킩��₷��
	*/
	// �ꖇ�̃e�N�X�`�����c�A���ɕ������ĕ\������
	// �}�e���A���ɂ����������
	class Flipbook
	{
		uint32 m_rowCount;		// �s�̐�(�c�����̕�����)
		uint32 m_columnCount;		// ��̐�(�������̕�����)
		//Texture2DPtr m_texture;	// 
	};

	class FlipbookAnimation final : public Animation
	{
	public:
		FlipbookAnimation();
		~FlipbookAnimation();

	private:
		AlphaImpl;
	};

}
