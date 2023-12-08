mkdir -p ~/sft/3rd && cd ~/sft/3rd

git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake .. && make -j
sudo make install

git clone https://github.com/yhirose/cpp-httplib.git
cd cpp-httplib && mkdir build && cd build
cmake .. && make -j
sudo make install # make install是为了方便直接findpackage


git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp && mkdir build && cd build
cmake .. && make -j
sudo make install