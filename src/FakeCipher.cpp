#include <FakeCipher.hpp>

#include <Block.hpp>

#include <memory>

#include <cstdlib>
#include <ctime>

FakeCipher::FakeCipher(std::size_t blockSize) :
  mBlockSize(blockSize),
  mDictionary(),
  mTotalBlocks(0) {
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
  mTotalBlocks++;
  auto storedBlock = mDictionary.find(block);
  if (storedBlock != mDictionary.end()) {
    return storedBlock->second;
  }

  std::vector<char> buffer(block.size());
  std::transform(
                 block.bytes().begin(), block.bytes().end(),
                 buffer.begin(),
                 [](char _){ return static_cast<char>(rand()); });
  CharBlock outputBlock(mBlockSize, buffer.begin());
  mDictionary.insert(std::make_pair(block, outputBlock));
  return outputBlock;
}

void FakeCipher::outputStats(std::ostream& out) {
  out << "Processed " << mTotalBlocks
      << " Blocks (" << mDictionary.size() << " unique)";
}
