file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testlogs ${SRCS})

TARGET_LINK_LIBRARIES(testlogs
    liblogs
    libgtest
    libgmock
)

add_test(NAME testlogs
         COMMAND testlogs)

