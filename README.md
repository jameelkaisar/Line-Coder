# Line-Coder
Line encoder, decoder and scrambler with digital data generator and graph plotter.

## Setup
- Install gnuplot
```
sudo apt update
sudo apt install gnuplot-x11
```

- Install sciplot
```
git clone https://github.com/sciplot/sciplot --recursive
cd sciplot
mkdir build && cd build
cmake ..
sudo cmake --build . --target install
```

- Install adwaita theme (For WSL only)
```
sudo apt install adwaita-icon-theme-full
```

## Usage
```
git clone https://github.com/JameelKaisar/Line-Coder.git
cd Line-Coder
g++ -std=c++17 main.cpp -o main.out
./main.out
```
