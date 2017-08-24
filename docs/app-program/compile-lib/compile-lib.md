Linux静态库与动态库制作
=======================

* 静态链接后的程序比动态链接的所用存储空间大，因为执行程序中包含了库中代码拷贝
* 动态链接的程序比静态链接的所用的运行空间大，因为它将不需要的代码也加载到运行空间。

### 静态库

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

* 测试  

```sh
  $ gcc -o world-test world-test.c -L./ -lworld
```

> 注意：
> 1) 写库名的时候，将前面的lib去掉，后缀.a也要去掉，前面必须加-l。
> 2) -L 表示链接库文件的位置。




### 动态库

* 生成.o文件  

```sh
  $ gcc -fPIC -Wall -c hello.c
```

* 生成库  

```sh
  $ gcc -shared -o libhello.so hello.o
```

* 测试  
```sh
  $ gcc -o world-test world-test.c -L./ -lworld
```



### 几个注意事项

* 动态库的搜索路径搜索的先后顺序是：  

```txt
  1. 编译目标代码时指定的动态库搜索路径；
  2. 环境变量LD_LIBRARY_PATH指定的动态库搜索路径；
  3. 配置文档/etc/ld.so.conf中指定的动态库搜索路径；
  4. 默认的动态库搜索路径/lib；
  5. 默认的动态库搜索路径/usr/lib.
```

* -L、-rpath和-rpath-link的区别  



* 同一系统中使用不同的版本库  

```txt
为了在同一系统中使用不同版本的库，可以在库文件名后加上版本号为后缀。
通常使用建立符号连接的方式：
ln -s libled.so libled.so.1.0
ln -s libled.so libled.so.1
```

