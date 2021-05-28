#pragma once
#include "Shape.h"

namespace FAL
{
	class Mesh : public Shape
	{
	public:
		// コンストラクタ
		Mesh();
		// デストラクタ
		virtual ~Mesh();

	private:
		using Base = Shape;

		AlphaImpl;
	};

}