#ifndef _BlockCipher_hpp_
#define _BlockCipher_hpp_

#include <Block.hpp>
#include <ostream>

class BlockCipher {
public:
    virtual ~BlockCipher();
    
    virtual std::size_t initialize() = 0;
    virtual CharBlock encrypt(const CharBlock& block) = 0;
    virtual void outputStats(std::ostream& out);

protected:
    BlockCipher();
};

#endif // _BlockCipher_hpp
