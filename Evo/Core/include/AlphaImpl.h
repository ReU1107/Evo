#pragma once

// AlphaImpl(private Implement)�C�f�B�I��

#define AlphaImpl \
class Impl; \
Impl* m_impl 

#define AlphaImplDefine(base) \
class base::Impl