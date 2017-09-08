Linux静态库与动态库制作
=======================

## 静态库

### 特点:

* 把静态库中的相关可执行程序编译到程序中，所用存储空间大  
* 程序的可移植性好  
* 程序升级不方便  
* 所用内存资源较少，因为需要的才会链接  
* 不利于资源的共享，比如相同的代码可能存在很多不同的程序中  


### 创建和使用

* 用-c来生成.o文件  

```sh
  $ gcc -c hello.c
```

* 生成静态库  

```sh
  $ ar rcsv libhello.a hello.o
```

> 注意：库名要以lib开头

* 生成静态库的参数  

* 使用  

```sh
  $ gcc -static world-test.c -L./ -lworld -o world-test
```

> 注意：
> 1) 写库名的时候，将前面的lib去掉，后缀.a也要去掉，前面必须加-l。
> 2) -L 表示链接库文件的位置。
> 3) 声明使用静态库




## 动态库

### 特点:

* 把动态库的版本信息放到程序中，所用存储空间小  
* 移植性不好  
* 程序升级方便  
* 所用内存资源较多，因为要使用库里面的一个函数，必须要加载整个库  
* 很好的资源共享，不同的程序可以共享一个库  

### 动态库的版本号

格式:  
```txt
   libname.so.x.x.x
```
* name是动态库标识名，后面3个x分别表示大版本号，小版本号, 维护号  
* 大版本号: 在改变库里的任何函数接口时才进行改变，接口改变后前面的程序就不能运行了  
* 小版本号: 是不该任何函数接口，只加了几个新的函数，这样前面的程序也能运行  
* 维护号  : 修改函数的bug时才改变  

给动态库设置大版本号:  
```txt
   -Wl,-soname,libname.so.x
```
> 给生成的动态库起别名，其中name和x是可变的

查看动态库大版本号：  

```sh
uso@u-os:$ readelf -d libhello.so

Dynamic section at offset 0xe08 contains 25 entries:
Tag        Type                         Name/Value
0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
0x000000000000000e (SONAME)             Library soname: [libhello.so.1]
0x000000000000000c (INIT)               0x550
0x000000000000000d (FINI)               0x6b4
0x0000000000000019 (INIT_ARRAY)         0x200df0
0x000000000000001b (INIT_ARRAYSZ)       8 (bytes)
0x000000000000001a (FINI_ARRAY)         0x200df8
0x000000000000001c (FINI_ARRAYSZ)       8 (bytes)
0x000000006ffffef5 (GNU_HASH)           0x1f0
0x0000000000000005 (STRTAB)             0x380
0x0000000000000006 (SYMTAB)             0x230
0x000000000000000a (STRSZ)              188 (bytes)
0x000000000000000b (SYMENT)             24 (bytes)
0x0000000000000003 (PLTGOT)             0x201000
0x0000000000000002 (PLTRELSZ)           24 (bytes)
0x0000000000000014 (PLTREL)             RELA
0x0000000000000017 (JMPREL)             0x538
0x0000000000000007 (RELA)               0x478
0x0000000000000008 (RELASZ)             192 (bytes)
0x0000000000000009 (RELAENT)            24 (bytes)
0x000000006ffffffe (VERNEED)            0x458
0x000000006fffffff (VERNEEDNUM)         1
0x000000006ffffff0 (VERSYM)             0x43c
0x000000006ffffff9 (RELACOUNT)          3
0x0000000000000000 (NULL)               0x0
```


### 创建和使用

* 生成.o文件  

```sh
  $ gcc -fPIC -c hello.c
```

* 生成库  

```sh
  $ gcc -shared hello.o -Wl,soname,libhello.so.x -o libhello.so.x.x.x
```

* 使用  
```sh
  $ gcc -o world-test world-test.c -L./ -lworld
```

### 找动态库和版本兼容

* 在程序链接阶段  
  -lname: 给可执行程序传递个动态库的信息，执行的时候需要这个动态库, 执行`ln -s libname.so libname.so.x.x.x`  
  -L: 指定libname.so所在的目录，而libname.so链接到实际库文件，这就把soname的信息保存在可执行程序中  
  这样执行的时候就会去找soname，同时我们编译时不需要知道实际版本号  

* 在程序执行阶段  
  程序在执行期间，回去找soname这个动态库，但是soname和实际动态库名是不一样的，  
  这时要创建一个软链接来指向实际的动态库, 执行`ls -s libname.so.x libname.so.x.x.x 或 ls -s libname.so.x libname.so (双重链接)`


## 几个注意事项

* 动态库的搜索路径搜索的先后顺序是：  

```txt
  1. 编译目标代码时指定的动态库搜索路径；
  2. 环境变量LD_LIBRARY_PATH指定的动态库搜索路径；
  3. 配置文档/etc/ld.so.conf中指定的动态库搜索路径；
  4. 默认的动态库搜索路径/lib；
  5. 默认的动态库搜索路径/usr/lib.
```

* 查看依赖库

```txt
uso@u-os:$ ldd main
        linux-vdso.so.1 =>  (0x00007ffd00ec9000)
        libhello.so.1 => ./hello-dynamic/libhello.so.1 (0x00007f2959da8000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f29599c3000)
        /lib64/ld-linux-x86-64.so.2 (0x000055b541245000)
```


