#include <FakeCrypto.hpp>

#include <cstdlib>

FakeCrypto::FakeCrypto(const std::size_t& blockSize) :
    mBlockSize(blockSize),
    mDictionary()
{
}

FakeCrypto::~FakeCrypto()
{
}

void FakeCrypto::encryptStream(std::istream& in, std::ostream& out)
{
}
