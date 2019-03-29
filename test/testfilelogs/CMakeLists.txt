file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testfilelogs ${SRCS})

TARGET_LINK_LIBRARIES(testfilelogs
    liblogs
    libgtest
    libgmock
)

add_test(NAME testfilelogs
         COMMAND testfilelogs)

