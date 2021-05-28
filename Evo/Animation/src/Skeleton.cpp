#include "Skeleton.h"
#include "Map.h"
#include "Joint.h"
#include "Array.h"

namespace Alpha
{
	class Skeleton::Impl
	{
	private:
		TMap<const char*,Joint*> m_joints;			// ���Q
		TMap<const char*, Joint*> m_attachmentJoint;// �A�^�b�`�����g�W���C���g�z��
		TArray<Vector3> m_matrixPallet;				// �s��p���b�g

	public:
		Impl();
		~Impl();

	public:
		// �W���C���g�ǉ�
		void AddJoint(const char* name, Joint* bone);

		// �A�^�b�`�����g�W���C���g�擾
		Joint* GetAttachmentJoint(const char* name) const;

#if _CONSOLE
		void Show()
		{
			// �e�q�֌W��\������(cout��)
		}
#endif

		Joint* GetJoint();


		const TArray<Vector3>& GetMatrixPallet() const;
	};
	/*
	* Transform���̂�e�q�֌W�����?
	* Joint�N���X���쐬��Transform���������e�q�֌W�����?
	* ��҂ɂ���@��:Transform�N���X�͂����̃f�[�^�ł����Ăق�������
	* Joint�N���X�Ń{�[���������ł���悤�ɂ��Ă���(�������̃f�[�^�����炦��悤�ɂ���)
	*/

	Skeleton::Impl::Impl()
	{

	}

	Skeleton::Impl::~Impl()
	{

	}

	void Skeleton::Impl::AddJoint(const char* name, Joint* joint)
	{
		m_joints.insert({ name,joint });
	}

	const TArray<Vector3>& Skeleton::Impl::GetMatrixPallet() const
	{
		return m_matrixPallet;
	}

	Skeleton::Skeleton()
		: m_impl(new Impl())
	{
	}

	Skeleton::~Skeleton()
	{
		delete m_impl;
	}

	const TArray<Vector3>& Skeleton::GetMatrixPallet() const
	{
		return m_impl->GetMatrixPallet();
	}
}