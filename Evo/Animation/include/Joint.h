#pragma once
#include "AlphaImpl.h"
#include "Type.h"
#include "Matrix.h"

namespace Alpha
{

	class Joint
	{
	public:
		// 
		Joint();
		// 
		~Joint();

		// �e�W���C���g�ǉ�
		void SetParent(Joint* parent);

		// �q�W���C���g�ǉ�
		void AddChild(Joint* child);
		// �q�W���C���g�ݒ�
		void SetChild(Joint* child, int32 index);

		// �����p���s��ݒ�
		void SetBindPose(const Matrix4x4& pose);

		// ���[���h�ϊ��s��擾
		Matrix4x4 GetWorldMatrix() const;

		// ���[�J���ϊ��s��擾
		Matrix4x4 GetLocalMatrix() const;

		// �s��p���b�g�p�s��擾
		Matrix4x4 GetProductMatrix() const;

	private:
		AlphaImpl;

	};
}