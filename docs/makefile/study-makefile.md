study-makefile
==============




## 内置函数

### 模式字符串替换函数 -- patsubst

* 格式

```
  $(patsubst <pattern>, <replacement>, <text>)
```

* 功能
  查找<text>中的单词（单词以“空格”、“Tab”或“回车”“换行”分隔）是否符合模式<pattern>，
  如果匹配的话，则以<replacement>替换。这里，<pattern>可以包括通配符“%”，表示任意长度的字串。
  如果<replacement>中也包含“%”，那么，<replacement>中的这个“%”将是<pattern>中的那个“%”所代表的字串。

  > 注意：可以用“\”来转义，以“\%”来表示真实含义的“%”字符

* 返回
  函数返回被替换过后的字符串

* eg

```
  $(patsubst %.c,%.o,x.c.c bar.c)
  把字串“x.c.c bar.c”符合模式[%.c]的单词替换成[%.o]，返回结果是“x.c.o bar.o”
```

### 变量替换引用 -- $(VAR:A=B)

* 格式

```
  $(VAR:A=B) 或 ${VAR:A=B}
```

* 功能
  把变量$VAR中所有以A结尾的字(或字符)替换成以B结尾的字(或字符)，
  对变量$VAR其他的部分，A不进行替换。
  变量值多个字之间使用空格分开。

* 返回值
  返回被替换过后的字符串

* eg
```
  foo := a.o b.o c.o o.o
  bar := $(foo:.o=.c)
  把字符串"a.o b.o c.o o.o"中以o结尾的部分替换成以c结尾，返回结果为"a.c b.c c.c o.c"
```
  > 注意： o.o 替换成o.c，而不是c.c



