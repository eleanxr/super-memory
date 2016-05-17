#include <EcbCipherMode.hpp>
#include <FakeCipher.hpp>

#include <iostream>

int main(int argc, char * argv[]) {
    EcbCipherMode ecb;
    FakeCipher cipher(4);
    ecb.encryptStream(std::cin, std::cout, cipher);
    
    return 0;
}
