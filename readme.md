# 环境配置
## 虚拟机安装库
```bash
# 
sudo apt-get update
sudo apt-get install -y g++
sudo apt-get install -y make
# 添加Cmake的官方仓库
#sudo apt-get install -y software-properties-common
#sudo add-apt-repository ppa:deadsnakes/ppa  # 添加PPA仓库
#sudo apt-get update
#sudo apt-get install -y cmake
wget https://github.com/Kitware/CMake/releases/download/v3.26.6/cmake-3.26.6-linux-x86_64.sh
chmod +x cmake-3.26.6-linux-x86_64.sh
sudo ./cmake-3.26.6-linux-x86_64.sh --skip-license --prefix=/usr

cmake --version
#sudo apt-get install git
sudo apt-get install gdb
#sudo apt-get install libstdc++6
#sudo apt-get install libboost-all-dev
sudo apt-get install ufw
sudo ufw enable
sudo ufw allow 22
sudo ufw allow 8082

```
## 调试
```bash
# 开启代理
export https_proxy=http://10.108.8.111:4080 http_proxy=http://10.108.8.111:4080 all_proxy=socks5://10.108.8.111:4081

# 关闭代理
unset https_proxy http_proxy all_proxy
```
Clion远程开发调试配置[参考](https://zhuanlan.zhihu.com/p/584737705)

虚拟机开启1200->22 的NAT映射 & 网络桥接

# 第三方库手动安装
## spdlog
```bash
git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake .. && make -j
```
## cpp-httplib
```bash
git clone https://github.com/yhirose/cpp-httplib.git
cd cpp-httplib && mkdir build && cd build
cmake .. && make -j
sudo make install # make install是为了方便直接findpackage
```