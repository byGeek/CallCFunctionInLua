#pragma once

#ifdef TESTLUA_EXPORTS

#define TESTLUA_API __declspec(dllexport)	
#else
#define TESTLUA_API __declspec(dllimport)

#endif // TESTLUA_EXPORTS

#include "lua.hpp"

extern "C"
{
	/*TESTLUA_API*/ int myadd(lua_State *L);

	/*TESTLUA_API*/ const struct luaL_Reg mylib[] = {
		{"myadd", myadd},
		{NULL, NULL}
	};

	//must dllexport this function
	TESTLUA_API int luaopen_TestLua(lua_State* L) {
		luaL_newlib(L, mylib);
		return 1;
	};
}

