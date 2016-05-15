project(image-crypto-cxx)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    Block.hpp
    FakeCrypto.hpp
)

set(SOURCES
    main.cpp
    FakeCrypto.cpp
)

add_executable(image-crypto-cxx
    ${HEADERS}
    ${SOURCES}
)
