#ifndef _Block_hpp_
#define _Block_hpp_

#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
class Block {
public:

    typedef std::vector<T> Container;
    
    template<class InputIterator>
    Block(std::size_t blockSize, InputIterator bytes);

    const Container& bytes() const;
    std::size_t size() const;

private:
    const std::size_t mBlockSize;
    Container mBytes;
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
const typename Block<T>::Container& Block<T>::bytes() const {
    return mBytes;
}

template<typename T>
std::size_t Block<T>::size() const {
    return mBlockSize;
}

template<typename T>
bool operator<(const Block<T>& lhs, const Block<T>& rhs) {
    const typename Block<T>::Container& leftBytes = lhs.bytes();
    const typename Block<T>::Container& rightBytes = rhs.bytes();
    return std::lexicographical_compare(
        leftBytes.begin(), leftBytes.end(),
        rightBytes.begin(), rightBytes.end());
}

typedef Block<char> CharBlock;

#endif // _Block_hpp_
