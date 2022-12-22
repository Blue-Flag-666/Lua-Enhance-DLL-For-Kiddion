#include "pch.h"

static int about(lua_State* L)
{
	cout << R"(
Lua Enhance DLL For Kiddion v1.0.3
Github:	 Galaxy-Studio-Code/Lua-Enhance-DLL-For-Kiddion
Discord: Blue-Flag#5246
)";
	return 1;
}

static int read(lua_State* L)
{
	string s;
	cin >> s;
	lua_pushstring(L, s.c_str());
	return 1;
}

static int print(lua_State* L)
{
	const string s = luaL_tolstring(L, 1, nullptr);
	cout << s;
	return 1;
}

static int getc(lua_State* L)
{
	char c;
	cin.get(c);
	lua_pushinteger(L, c);
	return 1;
}

static int getch(lua_State* L)
{
	char c[2] = { 0 };
	cin.get(c[0]);
	c[1] = '\0';
	lua_pushstring(L, c);
	return 1;
}

static int getl(lua_State* L)
{
	string s;
	getline(cin, s);
	lua_pushstring(L, s.c_str());
	return 1;
}

static void CloseM()
{
	if (MapName.empty())
	{
		return;
	}
	ofstream fout(MapName, ios_base::out | ios_base::trunc | ios_base::binary);
	for (const auto& [fst, snd] : m)
	{
		pair tmp { fst, snd };
		fout.write(reinterpret_cast <char*>(&tmp), sizeof tmp);
	}
	fout.close();
	MapName.clear();
	m.clear();
}

static int CloseMap(lua_State* L)
{
	CloseM();
	return 1;
}

static int OpenMap(lua_State* L)
{
	CloseM();
	MapName = luaL_tolstring(L, 1, nullptr);
	if (!MapName.ends_with(".dat"))
	{
		MapName = MapName + ".dat";
	}
	cout << "renamed to " << MapName << endl;
	ifstream           fin(MapName, ios_base::in | ios_base::binary);
	pair <string, int> tmp;
	while (fin.read(reinterpret_cast <char*>(&tmp), sizeof tmp))
	{
		m[tmp.first] = tmp.second;
	}
	fin.close();
	return 1;
}

static int IsMapOpen(lua_State* L)
{
	lua_pushboolean(L, !MapName.empty());
	return 1;
}

static int GetMap(lua_State* L)
{
	const string name = luaL_tolstring(L, 1, nullptr);
	lua_pushinteger(L, m[name]);
	return 1;
}

static int SetMap(lua_State* L)
{
	const string name = luaL_tolstring(L, 1, nullptr);
	const int    key  = lua_tointeger(L, 2);
	m[name]           = key;
	return 1;
}

static int sysdo(lua_State* L)
{
	const string command = luaL_tolstring(L, 1, nullptr);
	system(command.c_str());  // NOLINT(concurrency-mt-unsafe)
	return 1;
}

static int requireAllLibs(lua_State* L)
{
	luaL_openlibs(L);
	return 1;
}

static int AllocCon(lua_State* L)
{
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CON", "r", stdin);		// NOLINT(cert-err33-c)
	freopen_s(&stream, "CON", "w", stdout);		// NOLINT(cert-err33-c)
	freopen_s(&stream, "CON", "w", stderr);		// NOLINT(cert-err33-c)
	return 1;
}

static constexpr luaL_Reg BF[] =
{
	{ "version", about },
	{ "about", about },
	{ "print", print },
	{ "read", read },
	{ "getch", getc },
	{ "getchar", getch },
	{ "getline", getl },
	{ "OpenMap", OpenMap },
	{ "CloseMap", CloseMap },
	{ "IsMapOpen", IsMapOpen },
	{ "GetMap", GetMap },
	{ "SetMap", SetMap },
	{ "system", sysdo },
	{ "requireAllLibs", requireAllLibs },
	{ "AllocCon", AllocCon },
	{ nullptr, nullptr }
};

extern "C" BF_API int luaopen_BF(lua_State* L)
{
	luaL_newlib(L, BF);
	return 1;
}
