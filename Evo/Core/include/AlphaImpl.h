#pragma once

// AlphaImpl(private Implement)イディオム

#define AlphaImpl \
class Impl; \
Impl* m_impl 

#define AlphaImplDefine(base) \
class base::Impl