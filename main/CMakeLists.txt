set(Main_SRCS
    main.cpp
)

add_executable(myApp
    ${Main_SRCS}
)

SET(CMAKE_CXX_FLAGS -pthread)

target_link_libraries(myApp
    liblogs
)

install(TARGETS myApp DESTINATION bin)
