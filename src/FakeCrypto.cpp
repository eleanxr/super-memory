#include <FakeCrypto.hpp>

#include <algorithm>
#include <memory>

// We'll use this for random numbers right now, but maybe replace this later.
#include <cstdlib>
#include <ctime>

FakeCrypto::FakeCrypto(const std::size_t& blockSize) :
    mBlockSize(blockSize),
    mDictionary() {
}

FakeCrypto::~FakeCrypto() {
}

void FakeCrypto::encryptStream(std::istream& in, std::ostream& out) {
    std::time_t seed;
    time(&seed);
    srand(seed);

    std::unique_ptr<char[]> inputBuffer(new char[mBlockSize]);
    while (in) {
        in.read(inputBuffer.get(), mBlockSize);
        if (in.eof()) {
            // handle end of stream before block boundary.
        }
        CharBlock inputBlock(mBlockSize, inputBuffer.get());
        CharBlock outputBlock = findOrEncryptBlock(inputBlock);
        out.write(&outputBlock.bytes()[0], outputBlock.size());
    }
}

CharBlock FakeCrypto::findOrEncryptBlock(const CharBlock& block) {
    auto storedBlock = mDictionary.find(block);
    if (storedBlock != mDictionary.end()) {
        return storedBlock->second;
    }

    // The block is not stored. "Encrypt" it and save it for later.
    std::unique_ptr<char[]> buffer(new char[block.size()]);
    std::transform(
        block.bytes().begin(), block.bytes().end(),
        buffer.get(),
        [](char _){ return static_cast<char>(rand()); });
    CharBlock outputBlock(mBlockSize, buffer.get());
    mDictionary.insert(std::make_pair(block, outputBlock));
    return outputBlock;
}
