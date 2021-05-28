#include "Joint.h"
#include "Transform.h"
#include "Array.h"
#include "Arithmetic.h"

namespace Alpha
{
	/*
	* �������ύX���ꂽ��
	* �q�I�u�W�F�N�g��
	*/
	class Joint::Impl
	{
	private:
		Joint* m_parent;				// �e�I�u�W�F�N�g
		TArray<Joint*> m_children;	// �q���I�u�W�F�N�g�z��

		Transform m_transform;		// 

		Matrix4x4 m_bindPose;				// �����p���s��
		Matrix4x4 m_offsetMatrix;			// �����p���t�s��
		mutable Matrix4x4 m_worldMatrix;	// ���[���h�ϊ��s��
		mutable Matrix4x4 m_localMatrix;	// ���[�J���ϊ��s��(������������Ȃ�)

		mutable bool m_isDirty;				// 

	public:
		Impl();
		~Impl();
		// �e�W���C���g�ǉ�
		void SetParent(Joint* parent);

		// �q�W���C���g�ǉ�
		void AddChild(Joint* child);
		// �q�W���C���g�ݒ�
		void SetChild(Joint* child, int32 index);

		void SetBindPose(const Matrix4x4& pose);

		Matrix4x4 GetWorldMatrix() const;

		Matrix4x4 GetLocalMatrix() const;

		Matrix4x4 GetProductMatrix() const;

	private:
		void Calculate() const;
	};
	
	Joint::Impl::Impl()
		: m_parent(nullptr)
		, m_transform()
		, m_worldMatrix(Matrix4x4::Identity)
		, m_localMatrix(Matrix4x4::Identity)
		, m_isDirty(true)
	{
	}
	
	Joint::Impl::~Impl()
	{
	}

	void Joint::Impl::SetParent(Joint* parent)
	{
		m_parent = parent;
	}

	void Joint::Impl::AddChild(Joint* child)
	{
		m_children.push_back(child);
	}

	void Joint::Impl::SetChild(Joint* child, int32 index)
	{
	}

	void Joint::Impl::SetBindPose(const Matrix4x4& pose)
	{
		m_bindPose = pose;
	}

	Matrix4x4 Joint::Impl::GetWorldMatrix() const
	{
		Calculate();
		return m_worldMatrix;
	}

	Matrix4x4 Joint::Impl::GetLocalMatrix() const
	{
		Calculate();
		return m_localMatrix;
	}

	Matrix4x4 Joint::Impl::GetProductMatrix() const
	{
		return m_offsetMatrix* GetWorldMatrix();
	}

	void Joint::Impl::Calculate() const
	{
		if (!m_isDirty)
			return;
		
		// �g�偨��]���ړ��̏��Ŋ|����K�v������
		const auto scaleMatrix = Matrix4x4Scaling(m_transform.GetScale());
		const auto rotateMatrix = Matrix4x4Rotation(m_transform.GetRotation());
		const auto translateMatrix = Matrix4x4Translation(m_transform.GetLocation());

		Matrix4x4 matrix = scaleMatrix * rotateMatrix * translateMatrix;

		Matrix4x4 parentMatrix = Matrix4x4::Identity();

		if (m_parent)
			parentMatrix = m_parent->GetWorldMatrix();

		m_worldMatrix = matrix * parentMatrix;

		m_localMatrix = Matrix4x4Inverse(m_worldMatrix);

		m_isDirty = false;
	}

	Joint::Joint()
		: m_impl(new Impl())
	{
	}

	Joint::~Joint()
	{
		delete m_impl;
	}

	void Joint::SetParent(Joint* parent)
	{
		m_impl->SetParent(parent);
	}

	void Joint::AddChild(Joint* child)
	{
		m_impl->AddChild(child);
	}

	void Joint::SetChild(Joint* child, int32 index)
	{
		m_impl;
	}

	Matrix4x4 Joint::GetWorldMatrix() const
	{
		return m_impl->GetWorldMatrix();
	}

	Matrix4x4 Joint::GetLocalMatrix() const
	{
		return m_impl->GetLocalMatrix();
	}

	Matrix4x4 Joint::GetProductMatrix() const
	{
		return m_impl->GetProductMatrix();
	}

}