install nvm and node
====================

# install nvm

## introduce

Node Version Manager（Node版本管理器），用它可以方便的在机器上安装并维护多个Node的版本

## source installation

* download source code

```
$ mkdir -p /home/uos/office/install_soft
$ cd /home/uos/office/install_soft
$ git clone https://github.com/creationix/nvm
```

* setting environment variables

```
$ vim ~/.bashrc
. "$HOME/office/install_soft/nvm/nvm.sh"
```

* check version

```
$ nvm --version
```

# install node

```
$ nvm install node
$ node --version
```

# nvm common commands

* nvm install <version>
安装指定版本，可模糊安装，如：安装v4.4.0，既可nvm install v4.4.0，又可nvm install 4.4

* nvm install stable
安装最稳定版本

* nvm uninstall <version>
删除已安装的指定版本，语法与install类似

* nvm use <version>
切换使用指定的版本node

* nvm ls
列出所有安装的版本

* nvm ls-remote
列出所以远程服务器的版本（官方node version list）

* nvm current
显示当前的版本

* nvm alias <name> <version>
给不同的版本号添加别名

* nvm alias default <version>
设定系统默认的node版本

* nvm unalias <name>
删除已定义的别名

* nvm reinstall-packages <version>
在当前版本node环境下，重新全局安装指定版本号的npm包

# 使用.nvmrc配置项目所使用的node版本

如果你使用默认的node版本与项目所需要的版本不同，则可以在项目根目录下创建.nvmrc文件，在文件中指定使用的node
版本号

```
$ cd demo
$ echo 4.4.0 > .nvmrc
$ nvm use //无需指定版本号，会自动使用 .nvmrc 文件中配置的版本
$ node -v //查看版本是否为需要版本
```

