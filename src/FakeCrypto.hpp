#ifndef _FakeCrypto_hpp_
#define _FakeCrypto_hpp_

#include <Block.hpp>

#include <istream>
#include <ostream>
#include <map>

class FakeCrypto {
public:
    FakeCrypto(const std::size_t& blockSize);
    virtual ~FakeCrypto();

    void encryptStream(std::istream& in, std::ostream& out);
private:
    const std::size_t mBlockSize;
    
    std::map<CharBlock, CharBlock> mDictionary;
    CharBlock findOrEncryptBlock(const CharBlock& block);
};

#endif // _FakeCrypto_hpp_
