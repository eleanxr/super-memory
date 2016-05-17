#include <FakeCipher.hpp>

#include <Block.hpp>

#include <memory>

#include <cstdlib>
#include <ctime>

FakeCipher::FakeCipher(std::size_t blockSize) :
    mBlockSize(blockSize),
    mDictionary() {
}

FakeCipher::~FakeCipher() {
}

std::size_t FakeCipher::initialize() {
    std::time_t seed;
    time(&seed);
    srand(seed);
    return mBlockSize;
}

CharBlock FakeCipher::encrypt(const CharBlock& block) {
    auto storedBlock = mDictionary.find(block);
    if (storedBlock != mDictionary.end()) {
        return storedBlock->second;
    }

    std::unique_ptr<char[]> buffer(new char[block.size()]);
    std::transform(
        block.bytes().begin(), block.bytes().end(),
        buffer.get(),
        [](char _){ return static_cast<char>(rand()); });
    CharBlock outputBlock(mBlockSize, buffer.get());
    mDictionary.insert(std::make_pair(block, outputBlock));
    return outputBlock;
}

