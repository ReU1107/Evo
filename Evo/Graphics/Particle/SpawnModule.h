#pragma once
#include "ParticleModule.h"

namespace FAL
{

    class SpawnModule : public ParticleModule
    {
    public:
        // �R���X�g���N�^
        SpawnModule();
        // �f�X�g���N�^
        virtual ~SpawnModule();

    private:
        using Base = ParticleModule;
        AlphaImpl;
    };


}