set arg=%1
g++ arg.cpp -o a && %arg%.exe < in > out
