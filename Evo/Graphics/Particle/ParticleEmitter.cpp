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
		RequiredModule* m_required;			// 必須モジュール1
		SpawnModule* m_spawn;				// 必須モジュール2

		Vector3 m_origin;					// 開始位置

		TArray<ParticleModule*> m_modules;	// モジュール配列

	public:
		// 
		Impl();
		// 
		~Impl();

		// モジュール追加
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