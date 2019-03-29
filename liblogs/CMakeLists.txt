set(liblogs_SRCS
    log_level.h
    logger.h
    console_out_logger.h
    console_out_logger.cpp
    file_out_logger.h
    file_out_logger.cpp
    logger_factory.h
    logger_factory.cpp
    error.h
    error.cpp
)

# Declare the library
add_library(liblogs STATIC
    ${liblogs_SRCS}
)


# Specify here the include directories exported
# by this library
target_include_directories(liblogs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
