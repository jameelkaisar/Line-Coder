g++ -std=c++17 ./tests/assertions.cpp || { echo "Compilation Error: tests/assertions.cpp"; exit -1; } && echo "Compilation Success: tests/assertions.cpp";
./a.out
