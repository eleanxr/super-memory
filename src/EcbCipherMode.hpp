#ifndef _EcbCipherMode_hpp_
#define _EcbCipherMode_hpp_

#include <Block.hpp>
#include <BlockCipher.hpp>

#include <istream>
#include <ostream>
#include <map>

class EcbCipherMode {
public:
    EcbCipherMode();
    virtual ~EcbCipherMode();

    void encryptStream(std::istream& in, std::ostream& out, BlockCipher& cipher);

private:
};

#endif // _EcbCipherMode_hpp_
