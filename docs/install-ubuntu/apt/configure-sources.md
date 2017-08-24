configure-sources
=================


## problem

* 获取不到锁  

  ```txt
  E: Could not get lock /var/lib/apt/lists/lock - open (11: Resource temporarily unavailable)
  E: Unable to lock the list directory

  执行如下命令:
   $ sudo rm /var/lib/apt/lists/lock
   $ sudo rm /var/cache/apt/archives/lock
  ```
