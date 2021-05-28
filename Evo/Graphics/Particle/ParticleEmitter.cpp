#include "ParticleEmitter.h"
#include "ParticleEmitter.h"
#include "RequiredModule.h"
#include "SpawnModule.h"
#include "../Math/Vector.h"
#include "../Container/Array.h"

namespace FAL
{

	class ParticleEmitter::Impl
	{
	public:
		RequiredModule* m_required;			// �K�{���W���[��1
		SpawnModule* m_spawn;				// �K�{���W���[��2

		Vector3 m_origin;					// �J�n�ʒu

		TArray<ParticleModule*> m_modules;	// ���W���[���z��

	public:
		// 
		Impl();
		// 
		~Impl();

		// ���W���[���ǉ�
		void AddModule(ParticleModule* mod);

		void RemoveModule();

	};

	ParticleEmitter::Impl::Impl()
		: m_required()
		, m_spawn()
		, m_origin(Vector3::Zero())
	{
		
	}

	ParticleEmitter::Impl::~Impl()
	{
		delete m_spawn;
		delete m_spawn;
	}

	void ParticleEmitter::Impl::AddModule(ParticleModule* mod)
	{
		m_modules.push_back(mod);
	}

	void ParticleEmitter::Impl::RemoveModule()
	{
		// m_modules.erase();
	}

	ParticleEmitter::ParticleEmitter()
		: m_impl(new Impl())
	{
	}

	ParticleEmitter::~ParticleEmitter()
	{
		delete m_impl;
	}


}