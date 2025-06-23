github连不上时执行以下操作更改代理
git config --global http.proxy 127.0.0.1:7890
完成拉取、提交等操作后恢复原状
git config --global --unset http.proxy

栅栏效应，FFT频谱的分辨率是fs/N，频率没对齐目标频率时就会缺失

