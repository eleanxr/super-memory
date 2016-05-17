#include <EcbCipherMode.hpp>

#include <algorithm>
#include <memory>

// We'll use this for random numbers right now, but maybe replace this later.
#include <cstdlib>
#include <ctime>

EcbCipherMode::EcbCipherMode() {
}

EcbCipherMode::~EcbCipherMode() {
}

void EcbCipherMode::encryptStream(std::istream& in, std::ostream& out, BlockCipher& cipher) {
    std::size_t blockSize = cipher.initialize();
    std::unique_ptr<char[]> inputBuffer(new char[blockSize]);
    while (in) {
        in.read(inputBuffer.get(), blockSize);
        if (in.eof()) {
            // handle end of stream before block boundary.
        }
        CharBlock inputBlock(blockSize, inputBuffer.get());
        CharBlock outputBlock = cipher.encrypt(inputBlock);
        out.write(&outputBlock.bytes()[0], outputBlock.size());
    }
}

