#include "testlogs.h"

#include "logger.h"
#include "logger_factory.h"
#include "console_out_logger.h"
#include "file_out_logger.h"
#include "error.h"

namespace logging_test {

LoggerConsoleOutTest::LoggerConsoleOutTest() {
    logging::logging_config_t logging_config;
    logging_config.insert(std::make_pair<std::string, std::string>("type", "console_out"));

    logging::configuration(logging_config);
}

LoggerConsoleOutTest::~LoggerConsoleOutTest() {};

void LoggerConsoleOutTest::SetUp() {};

void LoggerConsoleOutTest::TearDown() {};

TEST_F(LoggerConsoleOutTest, ConsoleOutInfo) {
    auto error = logging::INFO("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConsoleOutTest, ConsoleOutWARN) {
    auto error = logging::WARN("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConsoleOutTest, ConsoleOutDebug) {
    auto error = logging::DEBUG("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConsoleOutTest, ConsoleOutTrace) {
    auto error = logging::TRACE("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConsoleOutTest, ConsoleOutError) {
    auto error = logging::ERROR("message");
    EXPECT_EQ(error.has_error(), false);
}
}
