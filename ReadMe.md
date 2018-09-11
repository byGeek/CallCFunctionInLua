## Demo code for calling c function from Lua

This project use Lua5.2.4, visual studio 2017.  You can find the lua binary file located in `TestLua/lua`folder.



To create a C library and export function to lua. Follow this steps:

- Define your function with following signature

  ```c
  typedef int (*lua_CFunction)(lua_State* L)
  ```

  example

  ```c
  int myadd(lua_State* L);
  ```

- Construct a `luaL_Reg` array

  ```c
  const struct luaL_Reg mylib[] ={
      {"myadd", myadd},
      {NULL, NULL}
  }
  ```

  and `luaL_Reg` is defined in `lauxlib.h`

  ```c
  typedef struct luaL_Reg {
    const char *name;
    lua_CFunction func;
  } luaL_Reg;
  ```

So the first is the function name which will be used in lua, and the second is the function address in c library. Note that the last element in this array must be `{NULL, NULL}`.

- Define a `luaopen_DLLName` function

  ```c
  int luaopen_TestLua(lua_State *L){
      luaL_newlib(L, mylib);
      return 1;
  }
  ```

  This function name should be match pattern `luaopen_dllname`, dllname is your dll's name

- Use this c library in your lua code.

  ```lua
  -- test.lua
  
  local t = require "TestLua"
  print(t.myadd(1, 2))
  ```

  when you run this `test.lua` script in lua environment, it should output correct answer. Remerber to use **same lua exe version** to run this script.

  Note that the module name is **case sensitive** because internally lua interpreter will call `luaopen_Modulename` function which exported by your c library.

- La