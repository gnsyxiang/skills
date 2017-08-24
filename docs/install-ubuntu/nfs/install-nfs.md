install-nfs
===========

### install

* 设置共享目录  

```sh
  $ mkdir /home/uos/nfs
  $ chmod 777 /home/uos/nfs
```

* 设置IP地址  
  保证开发板和PC机在同一个网段

* PC安装NFS  

```txt
  $ sudo apt install portmap
  $ sudo apt install nfs-kernel-server

  $ sudo cp /homeetc/exports /etc/exports.bak
  $ sudo vim /etc/exports
    /home/uos/nfsfs  *(rw,sync,no_root_squash)

    /opt/filesystem     #目标系统的根文件系统最后映射的路径
    *:                  #所有IP都可以和我相连，也可以用某一个具体IP替换
    subtree_check:      #子目录权限检查
    rw:                 #数据具有写权限
    no_root_squash:     #当访问这个目录，具有root权限
    async:              #动态同步

  $ sudo exportfs -a (最好每修改过/etc/exports后需要执行一次)
  $ sudo /etc/init.d/portmap restart
  $ sudo /etc/init.d/nfs-kernel-server restart
```

* 配置内核支持NFS  

```txt
    File systems  --->
        Network File Systems  --->
        [*]   NFS client support                 ## 必选
        [*]     NFS client support for NFS version 3   ## 可选

        [*] Root file system on NFS        ## 必选

    [*] Networking support
        Networking options  --->
            [*]   IP: kernel level autoconfiguration       ## 必选
                [*]     IP: DHCP support                   ## 必选
                [*]     IP: BOOTP support                  ## 必选
                [*]     IP: RARP support                   ## 必选
```

> 注意： NFS Client Support不能是模块，必须编译进内核

* 挂在  

```txt
  $ mount -t nfs -o nolock 192.168.3.137:/home/uos/nfs /mnt/sdcard/

    192.168.3.nfs137    被挂载点ip地址
    /home/xia/mips_nfs  被挂载的目录
    /mnt/sdcard/        挂载点
    -t nfs           固定选项
```

* 取消挂载点  

```txt
  $ sudo umount  -t nfs 192.168.3.137:/home/uos/nfs /mnt/sdcard/
```


