install-usb
===========

# install

* configuring the kernel enables usb monitor  

```txt
  $ make menuconfig

    Device Drivers -->
        USB Support -->
            USB Monitor --> Select * not M

  $ make uImage

  /lib/modules/4.8.0-58-generic/kernel/drivers/usb/mon/usbmon.ko
```

* configuring monitor  

```sh
  $ sudo  mount -t debugfs none  /sys/kernel/debug
  $ sudo modprobe usbmon
```

* view data  

```txt
  cat /sys/kernel/debug/usb/devices

  监听全部bus上的USB数据包，cat /sys/kernel/debug/usb/usbmon/0u
  监听Bus=2上的USB数据包，cat /sys/kernel/debug/usb/usbmon/2u
```

* reference manual  

```txt
  linux-3.11.1\Documentation\usb\usbmon.txt

> URB tag  ：标志
> TimeStamp：毫秒数
> Event Type：
> S - submission,
> C - callback,
> E - submission error.
> URBType：BusNo：DeviceAddr：EndPointNum
> Ci Co   Control input and output
> Zi Zo   Isochronous input and output
> Ii Io   Interrupt input and output
> Bi Bo   Bulk input and output
> URB Status： 0为没有错误。-XXX是错误码。
```


