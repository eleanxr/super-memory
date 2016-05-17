#ifndef _BlockCipher_hpp_
#define _BlockCipher_hpp_

#include <Block.hpp>

class BlockCipher {
public:
    virtual ~BlockCipher();
    
    virtual std::size_t initialize() = 0;
    virtual CharBlock encrypt(const CharBlock& block) = 0;

protected:
    BlockCipher();
};

#endif // _BlockCipher_hpp
