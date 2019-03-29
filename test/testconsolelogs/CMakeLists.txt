file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testconsolelogs ${SRCS})

TARGET_LINK_LIBRARIES(testconsolelogs
    liblogs
    libgtest
    libgmock
)

add_test(NAME testconsolelogs
         COMMAND testconsolelogs)

