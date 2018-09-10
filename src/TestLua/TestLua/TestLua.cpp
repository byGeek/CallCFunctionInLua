// TestLua.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "lua.hpp"
#include "TestLua.h"

int myadd(lua_State * L)
{
	int a = lua_tonumber(L, 1);
	int b = lua_tonumber(L, 2);

	auto ret = a + b;
	lua_pushnumber(L, ret);

	return 1;
}
