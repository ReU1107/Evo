#include "ParticleModule.h"

namespace FAL
{
	class ParticleModule::Impl
	{
	private:

	public:
		// 
		Impl();

		~Impl();

	};

	ParticleModule::ParticleModule()
		: m_impl(new Impl())
	{
	}

	ParticleModule::~ParticleModule()
	{
		delete m_impl;
	}
}