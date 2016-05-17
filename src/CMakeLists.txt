project(image-crypto-cxx CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if( CMAKE_COMPILER_IS_GNUCXX )
    add_definitions( -std=c++11 )
endif()

set(HEADERS
    Block.hpp
    EcbCipherMode.hpp
)

set(SOURCES
    Block.cpp
    EcbCipherMode.cpp
)

add_library(crypto
    ${HEADERS}
    ${SOURCES}
)

add_executable(randomecb
    randomecb.cpp
)
target_link_libraries(randomecb crypto)
