install-commitizen
==================



# install

* install npm

```
  $ npm
  The program 'npm' is currently not installed. You can install it by typing:
  sudo apt install npm

  $ sudo apt install npm
```

* install commitizen

```
  $ sudo npm install -g commitizen

  uos@ubuntu:~/test/haha$ sudo npm install -g commitizen
  /usr/local/bin/git-cz -> /usr/local/lib/node_modules/commitizen/bin/git-cz
  /usr/local/bin/commitizen -> /usr/local/lib/node_modules/commitizen/bin/commitizen

  > spawn-sync@1.0.15 postinstall /usr/local/lib/node_modules/commitizen/node_modules/spawn-sync
  > node postinstall

  sh: 1: node: not found
  /usr/local/lib
  └── (empty)

  npm ERR! Linux 4.8.0-36-generic
  npm ERR! argv "/usr/bin/nodejs" "/usr/bin/npm" "install" "-g" "commitizen"
  npm ERR! node v4.2.6
  npm ERR! npm v3.5.2
  npm ERR! file sh
  npm ERR! code ELIFECYCLE
  npm ERR! errno ENOENT
  npm ERR! syscall spawn

  npm ERR! spawn-sync@1.0.15 postinstall: `node postinstall`
  npm ERR! spawn ENOENT
  npm ERR!
  npm ERR! Failed at the spawn-sync@1.0.15 postinstall script 'node postinstall'.
  npm ERR! Make sure you have the latest version of node.js and npm installed.
  npm ERR! If you do, this is most likely a problem with the spawn-sync package,
  npm ERR! not with npm itself.
  npm ERR! Tell the author that this fails on your system:
  npm ERR! node postinstall
  npm ERR! You can get information on how to open an issue for this project with:
  npm ERR! npm bugs spawn-sync
  npm ERR! Or if that isn't available, you can get their info via:
  npm ERR! npm owner ls spawn-sync
  npm ERR! There is likely additional logging output above.

  npm ERR! Please include the following file with any support request:
  npm ERR! /home/uos/test/haha/npm-debug.log
  npm ERR! code 1
  uos@ubuntu:~/test/haha$

  $ sudo apt install nodejs-legacy
  $ sudo npm install -g commitizen

```


# demo

* initialize the demo git repository

```
  $ git init
```

* configure commitizen

```
  uos@ubuntu:~/test/haha$ commitizen init cz-conventional-changelog --save --save-exact
  Attempting to initialize using the npm package cz-conventional-changelog
  npm WARN saveError ENOENT: no such file or directory, open '/home/uos/test/haha/package.json'
  /home/uos/test/haha
  └─┬ cz-conventional-changelog@2.0.0
  ├── conventional-commit-types@2.1.0
  ├── lodash.map@4.6.0
  ├── longest@1.0.1
  ├─┬ pad-right@0.2.2
  │ └── repeat-string@1.6.1
  ├── right-pad@1.0.1
  └── word-wrap@1.2.3

  npm WARN enoent ENOENT: no such file or directory, open '/home/uos/test/haha/package.json'
  npm WARN haha No description
  npm WARN haha No repository field.
  npm WARN haha No README data
  npm WARN haha No license field.
  { [Error: ENOENT: no such file or directory, open '/home/uos/test/haha/package.json']
  errno: -2,
  code: 'ENOENT',
  syscall: 'open',
  path: '/home/uos/test/haha/package.json' }
```

* npm initialize

```
  uos@ubuntu:~/test/haha$ npm init
  This utility will walk you through creating a package.json file.
  It only covers the most common items, and tries to guess sensible defaults.

  See `npm help json` for definitive documentation on these fields
  and exactly what they do.

  Use `npm install <pkg> --save` afterwards to install a package and
  save it as a dependency in the package.json file.

  Press ^C at any time to quit.
  name: (haha)
  version: (1.0.0)
  description: haha test
  entry point: (index.js)
  test command:
  git repository:
  keywords: haha
  author: gnsyxiang
  license: (ISC)
  About to write to /home/uos/test/haha/package.json:

  {
  "name": "haha",
  "version": "1.0.0",
  "description": "haha test",
  "main": "index.js",
  "dependencies": {},
  "devDependencies": {},
  "scripts": {
  "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [
  "haha"
  ],
  "author": "gnsyxiang",
  "license": "ISC"
  }


  Is this ok? (yes)
  uos@ubuntu:~/test/haha$
```

* add a commit

```
  $ git add .
  $ git cz
```

