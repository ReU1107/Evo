#include "..\include\MorphTarget.h"
#include "Array.h"
#include "Vector.h"


namespace Alpha
{
	class MorphTarget::Impl
	{
	private:
		TArray<Vector3> m_positions;
		TArray<Vector3> m_normals;
		TArray<Vector3> m_tangents;

	public:
		Impl();
		~Impl();



	};

	MorphTarget::MorphTarget()
	{
	}

	MorphTarget::~MorphTarget()
	{
	}
}