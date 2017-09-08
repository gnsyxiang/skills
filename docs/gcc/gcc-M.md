gcc生成文件关联信息
===================

## 测试文件

demo.h
```c
#ifndef _DEMO_H_
#define _DEMO_H_

#define WORLD "world"

#endif
```

demo.c
```c
#include <stdio.h>

#include "demo.h"

int main(int argc, const char *argv[])
{
    printf("hello %s \n", WORLD);

    return 0;

}
```
## gcc各种依赖选项

### -M
包含目标文件所依赖的所有源代码

```sh
uso@u-os:$ gcc -M demo.c
demo.o: demo.c /usr/include/stdc-predef.h /usr/include/stdio.h \
        /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
        /usr/include/x86_64-linux-gnu/bits/wordsize.h \
        /usr/include/x86_64-linux-gnu/gnu/stubs.h \
        /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
        /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h \
        /usr/include/x86_64-linux-gnu/bits/types.h \
        /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/libio.h \
        /usr/include/_G_config.h /usr/include/wchar.h \
        /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
        /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
        /usr/include/x86_64-linux-gnu/bits/sys_errlist.h demo.h
```

### -MM
和`-M`相同，但是忽略由`#include`造成的依赖关系

```sh
uso@u-os:$ gcc -MM demo.c
demo.o: demo.c demo.h
```

### -MMD
和`-MM`相同，但是将输出导入到`*.d`的文件里面

```sh
uso@u-os:$ gcc -MMD demo.c

uso@u-os:$ cat demo.d
demo.o: demo.c demo.h
```

### -MD
和`-MMD`相同，只是导出的内容不一样，内容与`-M`是一样的

```sh
uso@u-os:$ gcc -MD demo.c

uso@u-os:~/test/skills/docs/gcc$ cat demo.d
demo.o: demo.c /usr/include/stdc-predef.h /usr/include/stdio.h \
        /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
        /usr/include/x86_64-linux-gnu/bits/wordsize.h \
        /usr/include/x86_64-linux-gnu/gnu/stubs.h \
        /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
        /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h \
        /usr/include/x86_64-linux-gnu/bits/types.h \
        /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/libio.h \
        /usr/include/_G_config.h /usr/include/wchar.h \
        /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
        /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
        /usr/include/x86_64-linux-gnu/bits/sys_errlist.h demo.h
```

### -MF
指定的导出文件名，要配合`-M`或`-MM`使用

>note: `-MF`和`-MMD`, `-MF`和`-MD`混用，会覆盖`-MD`或`-MMD`的功能。

```sh
uso@u-os:$ gcc -MM -MF"test.d" demo.c

uso@u-os:$ cat test.d
demo.o: demo.c demo.h
```

### -MT
指定目标文件名

```sh
uso@u-os:$ gcc -MM -MT"haha.d" demo.c
haha.d: demo.c demo.h

uso@u-os:$ gcc -MM -MT"objs/demo.o" demo.c
objs/demo.o: demo.c demo.h

uso@u-os:$ gcc -MM -MT"haha.d" -MT"demo.o" demo.c
haha.d demo.o: demo.c demo.h
```
















