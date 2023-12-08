#sudo adduser wangxin
#sudo usermod -aG sudo wangxin
export https_proxy=http://10.108.8.111:4080 http_proxy=http://10.108.8.111:4080 all_proxy=socks5://10.108.8.111:4081

mkdir -p ~/tmp && cd ~/tmp
sudo apt-get update
sudo apt-get install -y g++
sudo apt-get install make

wget https://github.com/Kitware/CMake/releases/download/v3.26.6/cmake-3.26.6-linux-x86_64.sh
chmod +x cmake-3.26.6-linux-x86_64.sh
sudo ./cmake-3.26.6-linux-x86_64.sh --skip-license --prefix=/usr
sudo apt-get install -y gdb
sudo apt-get install -y ufw
sudo ufw enable
sudo ufw allow 22
sudo ufw allow 8082