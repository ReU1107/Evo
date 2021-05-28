#pragma once
#include "ParticleModule.h"

namespace FAL
{

    class SpawnModule : public ParticleModule
    {
    public:
        // コンストラクタ
        SpawnModule();
        // デストラクタ
        virtual ~SpawnModule();

    private:
        using Base = ParticleModule;
        AlphaImpl;
    };


}