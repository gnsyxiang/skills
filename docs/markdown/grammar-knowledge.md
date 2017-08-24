grammar knowledge
=================


### 目录结构

GitBook使用SUMMURY.md文件实现目录结构的设定，在该文件中，可以通过缩进实现多级目录的效果，如：

```txt
* [第一章](section1/README.md)
    * [第一节](section1/example1.md)
    * [第二节](section1/example2.md)
* [第二章](section2/README.md)
    * [第一节](section2/example1.md)
        * [第1节](section2/example1.md)
```

如上所示，章节的md文件，还可以存放在子文件夹中。

用户还可以通过使用标题或者水平分割线标识将GitBook目录分为几个不同的部分：

```txt
# Summary

### Part I

* [Introduction](README.md)
* [Writing is nice](part1/writing.md)
* [GitBook is nice](part1/gitbook.md)

### Part II

* [We love feedback](part2/feedback_please.md)
* [Better tools for authors](part2/better_tools.md)

----

* [Last part without title](part3/title.md)
```




### 插入图片

插图的最基本格式是:

```txt
![Alt text](图片链接 "optional title")
```
> * Alt text：图片的Alt标签(可选)，用来描述图片的关键词。最初的本意是当图片因为某种原因不能被显示时而出现的替代文字，后来又被用于SEO，可以方便搜索引擎根据Alt text里面的关键词搜索到图片。  
> * 图片链接：可以是图片的本地地址或者是网址。  
> * "optional title"：鼠标悬置于图片上会出现的标题文字，可以不写。  

主要有以下三种方法:

* 插入本地图片  
  只需要在基础语法的括号中填入图片的位置路径即可，支持绝对路径和相对路径。

  例如：

  ```txt
  ![avatar](dog.png)
  ```

  ![avatar](dog.png)

  > 缺点: 是不灵活不好分享，本地图片的路径更改或丢失都会造成markdown文件调不出图。

* 插入网络图片  
  只需要在基础语法的括号中填入图片的网络链接即可，现在已经有很多免费/收费图床和方便传图的小工具可选。

  例如：

  ```txt
  ![avatar](http://baidu.com/pic/doge.png)
  ```

  ![avatar](http://baidu.com/pic/doge.png)

  > 缺点: 是图片存在网络服务器上，非常依赖网络。

* 把图片存入markdown文件  
  用base64转码工具把图片转成一段字符串，然后把字符串填到基础格式中链接的那个位置。

  基础用法：

  ```txt
  ![avatar](data:image/png;base64,iVBORw0......)
  ```

  ![avatar](data:image/png;base64,iVBORw0......)

  > 缺点: 这个时候会发现插入的这一长串字符串会把整个文章分割开，非常影响编写文章时的体验。

  进阶用法如下：

  文中引用语法：

  ```txt
  ![avatar][doge]
  ```

  ![avatar][doge]

  文末存储字符串语法：

  ```txt
  [doge]:data:image/png;base64,iVBORw0......
  ```

  [doge]:data:image/png;base64,iVBORw0......

  > 这个用法不常见，比较野路子。优点是很灵活，不会有链接失效的困扰。缺点是一大团base64的乱码看着不美观。

> note: 以上转载于: https://www.zhihu.com/question/21065229




















