# cocos2d-x代码笔记
------

创建于2016年11月15日21:46:20：

> * 整理知识，学习笔记

## 一、Cocos2d-x环境搭建

### 1. Cocos引擎官网 [点此跳转](http://www.cocos.com/download)
    将cocos2d-x-3.13.1\tools\cocos2d-console\bin添加到path
### 2.Python官网  [点此跳转](https://www.python.org/)
    下载好Python27版本同样添加到path
### 3. VS2013
---
# 二、使用cmd创建项目
```
cocos new Chapter_1 -l cpp -p com.github -d D:\workpace 
```
说明：
> * new Chapter_1: Chapter_1是项目名
> * -p : 包名
> * -l ：语言（cpp是指c++）
> * -d ：项目生成路径

# 三、将项目导入VS2012
双击 Chapter1\proj.win32 下的 **Chapter1.sln** 导入