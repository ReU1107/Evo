#pragma once
#include "AlphaImpl.h"
#include "Array.h"
#include "Vector.h"

namespace Alpha
{
	/*
	*�@�X�P���^���A�j���[�V�����@���i
	*/
	class Joint;

	class Skeleton
	{
	public:
		// 
		Skeleton();
		// 
		~Skeleton();

		// �s��p���b�g�擾
		const TArray<Vector3>& GetMatrixPallet() const;

		// �W���C���g�擾
		Joint* GetJoint(const char* name) const;

	private:
		AlphaImpl;

	};
}