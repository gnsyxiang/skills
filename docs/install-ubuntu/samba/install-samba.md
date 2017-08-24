install-samba
=============


### install

* 更新源  

```sh
  $ sudo apt update
```

* 安装  

```sh
  $ sudo apt-get install samba smbfs samba-common smbclient
  $ sudo apt-get install samba cifs-utils samba-common smbclient (64bit)
```

* 配置文件  

```txt
  $ sudo cp /etc/samba/smb.conf /etc/samba/smb.conf.bak
  $ sudo vim /etc/samba/smb.conf

    #xia add for samba
    [samba]
    path=/home/uos/samba
    available=yes
    browseable=yes
    writable=yes
    ;public=yes
    valid users = xia
```

* 创建samba帐户

```sh
  $ sudo smbpasswd -a xia
```

* 重启samba服务器

```sh
  $ sudo /etc/init.d/smbd reload   (修改过smb.conf的话要执行一次)
  $ sudo /etc/init.d/smbd restart
```

* 测试

```txt
  如：\\192.168.7.100
  smbclient -L //localhost/share
```




