github连不上时执行以下操作更改代理
git config --global http.proxy 127.0.0.1:7890
完成拉取、提交等操作后恢复原状
git config --global --unset http.proxy