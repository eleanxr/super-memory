#ifndef _EcbCipherMode_hpp_
#define _EcbCipherMode_hpp_

#include <Block.hpp>

#include <istream>
#include <ostream>
#include <map>

class EcbCipherMode {
public:
    EcbCipherMode(const std::size_t& blockSize);
    virtual ~EcbCipherMode();

    void encryptStream(std::istream& in, std::ostream& out);
private:
    const std::size_t mBlockSize;
    
    std::map<CharBlock, CharBlock> mDictionary;
    CharBlock findOrEncryptBlock(const CharBlock& block);
};

#endif // _EcbCipherMode_hpp_
