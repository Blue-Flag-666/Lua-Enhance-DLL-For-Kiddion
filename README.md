# Lua Enhance DLL For Kiddion

# 使用方法 Usage

将 BF.dll 放入 Kiddion.exe 所在的文件夹

Put BF.dll in the same folder as Kiddion.exe

将这行代码添加到 .lua 文件的第一行

add the code to the first line of your lua file

```lua
BF = require "BF"
```

## APIs

```lua
void BF.version() 						-- 输出版本信息
	void BF.about()						-- Print version info

-- IO
void BF.print(string text)				-- 输出 string, 不附加换行
										-- Print the string without line break
string BF.read()						-- 读取控制台输入
										-- Read the console input
int BF.getch()							-- 读取一个字符, 返回 ASCII
										-- Read a character, return it's ASCII
string BF.getchar()						-- 读取一个字符, 返回长度为 2 的 string, 第一位为读取的字符, 第二位为'\0'
										-- Read a character, return a string with 2 characters. The first character is the character you want and the second one is '\0'
string BF.getline()						-- 读取一整行
										-- Read the whole line

-- Map	可用于在不同脚本中传递数据  Transfer data in different scripts
void BF.OpenMap(string name)			-- 打开一个 map, 这将关闭已打开的 map
										-- Open a map, this will close the map which has been opened
void BF.CloseMap()						-- 关闭已打开的 map
										-- Close the opened map
bool BF.IsMapOpen()						-- 获取 map 打开状态
										-- Get map open status
int BF.GetMap(string key)				-- 获取 map 中 key 对应的值
										-- Get the value corresponding to the key in the map
void BF.SetMap(string key, int value)	-- 将 key 对应的 value 写入 map

-- Other
void BF.system(string command)			-- 执行命令
										-- Execute a command
void BF.requireAllLibs()				-- 启用全部 lua 自带库
										-- Enable all lua libraries
void BF.AllocCon()						-- 呼出控制台
										-- Allocate Console
```

注意: 虽然 `getch`、`getchar`、`getline` 会等待输入，但可能会读取空行或换行符 ('\n')
	 不要忘记关闭 map 否则将不会被保存

Note: Although `getch`, `getchar` and `getline` will wait for input, they may read blank lines or line breaks ('\n')
	  Don't forget to close te map or it won't be saved
