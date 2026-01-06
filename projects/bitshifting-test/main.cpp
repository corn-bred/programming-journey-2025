#include <iostream>
#include <cstdint>
int main() {
    int r = 0,g = 0,b = 0;
    uint8_t bitshift =  (0xFF << 8 * 3) | (r << 8 * 2) | (g << 8 * 1) | b;
    std::cout << bitshift << std::endl;
}