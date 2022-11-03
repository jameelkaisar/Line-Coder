# Line-Coding
Line coding encoder, decoder and scrambler with digital data generator and graph plotter.

## Setup
- Install gnuplot
```
sudo apt update
sudo apt install gnuplot-nox
```

- Install sciplot
```
git clone https://github.com/sciplot/sciplot --recursive
cd sciplot
mkdir build && cd build
cmake ..
sudo cmake --build . --target install
```

## Usage
```
git clone https://github.com/JameelKaisar/Line-Coding.git
cd Line-Coding
g++ -std=c++17 main.cpp -o main.out
./main.out
```
