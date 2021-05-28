#include "Mesh.h"
namespace FAL
{
	class Mesh::Impl
	{
	private:

	public:
		Impl();
		~Impl();

	};


	Mesh::Mesh()
		: Base()
		, m_impl(new Impl())
	{
	}

	Mesh::~Mesh()
	{
		delete m_impl;
	}
}