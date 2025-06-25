# git config命令的–global参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。
 
# 1.查看git配置信息
$ git config --list
 
 
# 2.查看git用户名、密码、邮箱的配置
$ git config user.name
$ git config user.password
$ git config user.email
 
 
# 3.设置git用户名、密码、邮箱的配置
$ git config user.name "freedom"
$ git config user.password "123456"
$ git config user.email "1548429568@qq.com"
# 3.设置git用户名、密码、邮箱的配置（全局配置）
$ git config --global user.name 用户命
$ git config --global user.name "Yikun Shang"
$ git config --global user.password 密码
$ git config --global user.password abc0506abc
$ git config --global user.password 邮箱
$ git config --global user.email "13302191904@163.com"
 
 
# 4.修改git用户名、密码、邮箱的配置（跟设置语法一样，没有用户名就添加，有了用户名就修改）
$ git config user.name "freedom"
# 4.修改git用户名、密码、邮箱的配置（全局配置）
$ git config --global user.name "freedom"
 
 
# 5.删除git用户名、密码、邮箱的配置

github连不上时执行以下操作更改代理
git config --global http.proxy 127.0.0.1:7890
完成拉取、提交等操作后恢复原状
git config --global --unset http.proxy

栅栏效应，FFT频谱的分辨率是fs/N，频率没对齐目标频率时就会缺失

