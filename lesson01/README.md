lesson01：配置 node-gyp 环境
===================
本例讲的是在**window**下**node-gyp**的环境配置。
**参考**： https://github.com/Microsoft/nodejs-guidelines/blob/master/windows-environment.md#compiling-native-addon-modules

----------


方法1 · npm安装windows-build-tools（推荐）
-------------
需安装好**node.js**，在命令行内执行`npm install -g windows-build-tools`
耐心等待其完成，**npm**速度慢的可以配置淘宝源，因为其中会下载**python**安装包，将对应安装包先下载放到下载位置也是可以的。

方法2 
-------------
- 安装vc环境
 - 选择一：安装 [Visual C++ Build Tools](http://go.microsoft.com/fwlink/?LinkId=691126)，选择默认安装即可。
 - 选择二：安装 [Visual Studio 2015](https://www.visualstudio.com/products/visual-studio-community-vs)，微软的一个编辑器，有带编译环境，也是选默认安装就可以。
- 安装[Python 2.7](https://www.python.org/downloads/)（注意不能装Python 3.x版本），将**python**加入到系统环境变量中。
- Windows Vista / 7 还需要[.NET Framework 4.5.1](http://www.microsoft.com/en-us/download/details.aspx?id=40773)
- 在命令行内执行`npm config set msvs_version 2015`
