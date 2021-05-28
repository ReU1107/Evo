#include "Skeleton.h"
#include "Map.h"
#include "Joint.h"
#include "Array.h"

namespace Alpha
{
	class Skeleton::Impl
	{
	private:
		TMap<const char*,Joint*> m_joints;			// 骨群
		TMap<const char*, Joint*> m_attachmentJoint;// アタッチメントジョイント配列
		TArray<Vector3> m_matrixPallet;				// 行列パレット

	public:
		Impl();
		~Impl();

	public:
		// ジョイント追加
		void AddJoint(const char* name, Joint* bone);

		// アタッチメントジョイント取得
		Joint* GetAttachmentJoint(const char* name) const;

#if _CONSOLE
		void Show()
		{
			// 親子関係を表示する(cout版)
		}
#endif

		Joint* GetJoint();


		const TArray<Vector3>& GetMatrixPallet() const;
	};
	/*
	* Transform自体を親子関係を作る?
	* Jointクラスを作成しTransformを持った親子関係を作る?
	* 後者にする　理:Transformクラスはただのデータであってほしいから
	* Jointクラスでボーンを可視化できるようにしておく(差分等のデータがもらえるようにする)
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