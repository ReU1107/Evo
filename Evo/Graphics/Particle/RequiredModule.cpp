#include "RequiredModule.h"
#include "../Shape/Shape.h"


namespace FAL
{
	class RequiredModule::Impl
	{
	public:
		Shape* m_shape;

	public:
		Impl();
		~Impl();
	};

	RequiredModule::RequiredModule()
		: Base()
		, m_impl(new Impl())
	{
	}

	RequiredModule::~RequiredModule()
	{
	}

}