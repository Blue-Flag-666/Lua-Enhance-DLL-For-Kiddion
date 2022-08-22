# Lua Enhance DLL For Kiddion
## 使用方法 Usage
将 BF.dll 放入 Kiddion.exe 所在的文件夹
Put BF.dll in the same folder as Kiddion.exe
将这行代码添加到 .lua 文件的第一行
add the code to the first line of your lua file
```lua
BF = require "BF"
```
## APIs
```lua
BF.print(string)		-- 输出 string, 不附加换行
						-- Print the string without line break
BF.read()				-- 读取控制台输入, 返回 string
						-- Read the console input, return a string
BF.getch()				-- 读取一个字符, 返回 ASCII
						-- Read a character, return it's ASCII
BF.getchar()			-- 读取一个字符, 返回长度为 2 的 string, 第一位为读取的字符, 第二位为'\0'
						-- Read a character, return a string with 2 characters. The first character is the character you want and the second one is '\0'
BF.getline()			-- 读取一整行, 返回 string
						-- Read the whole line, return a string
BF.system(string)		-- 执行命令
						-- Execute a command
BF.requireAllLibs()		-- 启用全部 lua 自带库
						-- Enable all lua libraries
```
