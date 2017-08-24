install-changelog
=================


## install

* install conventional-changelog

```
  $ sudo npm install -g conventional-changelog-cli
```




## demo

* terminal command

```
  $ conventional-changelog -p angular -i CHANGELOG.md -w -s
```

* use command in script

```
  $ vim package.json
  {
      "scripts": {
      ...
          "changelog": "conventional-changelog -p angular -i CHANGELOG.md -w -s"
      ...
      }
  }
```


