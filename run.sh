clang-format -i --style=file main.cpp
g++ -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -o main.out main.cpp
chmod +x main.out
./main.out