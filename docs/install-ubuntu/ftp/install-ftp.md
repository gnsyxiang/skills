install-tftp
===========

### install

* 安装: 安装程序会给本地创建一个名为“ftp”的用户组，并自动启动服务  

```sh
  $ sudo apt-get install tftp tftpd
  $ sudo apt-get install openbsd-inetd
```

* 设置：  

```sh
  $ sudo cp /etc/inetd.conf /etc/inetd.conf.bak
  $ sudo vim /etc/inetd.conf

  增加以下内容：
  $ tftp dgram udp wait nobody /usr/sbin/tcpd /usr/sbin/in.tftpd /home/uos/tftpboot

  新建：sudo vim /etc/default/tftpd-hpa
  # defaults for tftpd-hpa
    RUN_DAEMON="yes"
    OPTIONS="-l -s /home/uos/tftpboot"
```

* 开启、停止、重启  

```sh
  $ sudo /etc/init.d/openbsd-inetd reload
  $ sudo /etc/init.d/openbsd-inetd restart | start | stop
```

* 查看  

```sh
  $ tftp 192.168.1.119
  $ tftp>get uImage
  $ tftp>quit
```

* 以后每次启动系统的时候，要执行以下：  

```sh
  $ sudo /etc/init.d/openbsd-inetd restart
```


