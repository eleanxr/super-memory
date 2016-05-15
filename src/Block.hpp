#ifndef _Block_hpp_
#define _Block_hpp_

#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
class Block {
public:
    
    template<class InputIterator>
    Block(std::size_t blockSize, InputIterator bytes);

    bool operator<(const Block<T>& other) const;

private:
    const std::size_t mBlockSize;
    std::vector<T> mBytes;
};

template<typename T>
template<typename InputIterator>
Block<T>::Block(std::size_t blockSize, InputIterator bytes):
    mBlockSize(blockSize),
    mBytes(blockSize)
{
    std::copy(bytes, bytes + blockSize, mBytes.begin());
}

template<typename T>
bool Block<T>::operator<(const Block<T>& other) const {
    return this < &other;
}

typedef Block<char> CharBlock;

#endif // _Block_hpp_
