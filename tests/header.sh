g++ -std=c++17 ./main.cpp || { echo "Compilation Error: main.cpp"; exit -1; } && echo "Compilation Success: main.cpp";
g++ -std=c++17 ./src/decoder/decoder.cpp || { echo "Compilation Error: src/decoder/decoder.cpp"; exit -1; } && echo "Compilation Success: src/decoder/decoder.cpp";
g++ -std=c++17 ./src/encoder/encoder.cpp || { echo "Compilation Error: src/encoder/encoder.cpp"; exit -1; } && echo "Compilation Success: src/encoder/encoder.cpp";
g++ -std=c++17 ./src/generator/generator.cpp || { echo "Compilation Error: src/generator/generator.cpp"; exit -1; } && echo "Compilation Success: src/generator/generator.cpp";
g++ -std=c++17 ./src/helper/helper.cpp || { echo "Compilation Error: src/helper/helper.cpp"; exit -1; } && echo "Compilation Success: src/helper/helper.cpp";
g++ -std=c++17 ./src/plotter/plotter.cpp || { echo "Compilation Error: src/plotter/plotter.cpp"; exit -1; } && echo "Compilation Success: src/plotter/plotter.cpp";
g++ -std=c++17 ./src/scrambler/scrambler.cpp || { echo "Compilation Error: src/scrambler/scrambler.cpp"; exit -1; } && echo "Compilation Success: src/scrambler/scrambler.cpp";
g++ -std=c++17 ./src/unscrambler/unscrambler.cpp || { echo "Compilation Error: src/unscrambler/unscrambler.cpp"; exit -1; } && echo "Compilation Success: src/unscrambler/unscrambler.cpp";
