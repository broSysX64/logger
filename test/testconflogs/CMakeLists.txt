file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testconflogs ${SRCS})

TARGET_LINK_LIBRARIES(testconflogs
    liblogs
    libgtest
    libgmock
)

add_test(NAME testconflogs
         COMMAND testconflogs)

