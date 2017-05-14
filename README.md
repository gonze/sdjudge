# SDOJ测试城西


本程序为SDOJ 评测程序。 

**警告** 当前守护程序会以 root 权限运行。以后将加入更多的安全设置，并会增强安全措施。

---



### 系统与工作环境
我们选择cmake作为开发
So far, we do not have a efficient and effective way to manage our Git workflow so if you want to submit a PR, just set the destination as master.  
**In order to keep consistency, we extremely recommend you using an IDE called CLion to develop.**

### About DEB-Package
I assume you understand what the DEB-Package is, if not, please check Wikipedia Entries.  
In our project, there's one cmake script named DebPack.cmake. You can modify the packing arguments here in this file.  
And here's the bash commands you will need to pack a DEB-Package(We assume that you've already navigated your PWD into the root of the project):  
```sh
mkdir build
cd build
cmake ..
cd ..
make
make package
```
You may noticed that we use a certain out-of-source directory named `build` to storage the intermediate build files.  
This is a good habit to keep your workspace clean and you should perform it in the same way.

### About Docker
We're working in progress on here right now.

---

## 所需库
`apt install libmysqlclient-dev libmicrohttpd-dev libboost-all-dev`

intstall   yaml-cpp
创建一个文件夹yaml
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install
找到yaml-cpp/include 把立马打yaml-cpp文件夹复制到/usr/include 中

安装seccomp库
git clone https://github.com/seccomp/libseccomp.git
到源码文件夹
如果没有autoconf  先执行   sudo apt-get install autoconf
./outogen.sh
./configure
make 
sudo make install

## 配置文件
安装完成后，配置文件将被复制到 `/etc/sdojconfig.ini`。
配置文件说明：
```ini
[system]
datadir=评测数据存放目录
TempDir=内存盘目录（供 IO 加速使用，如果不需要可以不填此项，实测并没有什么卵用）
DATABASE_USER=数据库用户名
DATABASE_PASS=数据库密码
DATABASE_NAME=数据库名
```

## ~~安装~~ 构建和安装
我们的构建系统已经更新，我们已经从GNU Autotools迁移到CMake。  
现在，请在项目根目录使用以下指令进行构建和安装（请注意，在目前情况下，**后两个指令需要超级用户权限**）：  
```sh
mkdir build
cd build
cmake ..
make
make install
systemctl daemon-reload
```

systemctl daemon-reload
-- Installing: /usr/local/bin/OJdaemon
-- Installing: /etc/sdojconfig.ini
-- Installing: /lib/systemd/system/OJdaemon.service


## 运行
在安装后，可直接以系统服务方式运行 sdoj：
```sh
# 启用服务
systemctl enable OJdaemon
# 运行服务
systemctl start OJdaemon
```
