install-sogou
=============


### Download and install

  website: http://pinyin.sogou.com/linux/

```sh
  $ sudo dpkg -i sogoupinyin_2.1.0.0086_amd64.deb
  $ sudo apt install -f
```

> 注意: 配置完成后需要注销，重新登入后才可以使用搜狗输入法

### problem

#### Sogou input method can not input Chinese

* method one: restart the Sogou input method  

```sh
  $ killall fcitx
  $ killall sogou-qinpanel
  $ fcitx
```

* method two: check fix installation dependency  

```sh
  $ sudo apt install -f
```

* method three: delete configuration file  

```sh
  $ rm ~/.config/SogouPY -rf
  $ rm ~/.config/SogouPY.users -rf
  $ rm ~/.config/sogou-qimpanel -rf
```





