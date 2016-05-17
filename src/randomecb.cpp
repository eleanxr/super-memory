#include <EcbCipherMode.hpp>

#include <iostream>

int main(int argc, char * argv[]) {
    EcbCipherMode crypto(4);
    crypto.encryptStream(std::cin, std::cout);
    return 0;
}
