#pragma once
#include "Shape.h"

namespace FAL
{
	class Mesh : public Shape
	{
	public:
		// �R���X�g���N�^
		Mesh();
		// �f�X�g���N�^
		virtual ~Mesh();

	private:
		using Base = Shape;

		AlphaImpl;
	};

}