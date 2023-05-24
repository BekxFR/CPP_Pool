#include <iostream>

int main() {
    int num = 1;
    char *byte = reinterpret_cast<char*>(&num);

    if (*byte == 1) {
        std::cout << "Little-endian" << std::endl;
    } else {
        std::cout << "Big-endian" << std::endl;
    }

    return 0;
}