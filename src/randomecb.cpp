#include <FakeCrypto.hpp>

#include <iostream>

int main(int argc, char * argv[]) {
    FakeCrypto crypto(4);
    crypto.encryptStream(std::cin, std::cout);
    return 0;
}
