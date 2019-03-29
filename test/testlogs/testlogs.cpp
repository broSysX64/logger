#include "testlogs.h"

#include "logger.h"
#include "logger_factory.h"
#include "console_out_logger.h"
#include "file_out_logger.h"
#include "error.h"

namespace logging_test {

LoggerTest::LoggerTest() {
}

LoggerTest::~LoggerTest() {};

void LoggerTest::SetUp() {};

void LoggerTest::TearDown() {};

TEST_F(LoggerTest, ConsoleInfo) {
    auto error = logging::INFO("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerTest, ConsoleWARN) {
    auto error = logging::WARN("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerTest, ConsoleDebug) {
    auto error = logging::DEBUG("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerTest, ConsoleTrace) {
    auto error = logging::TRACE("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerTest, ConsoleError) {
    auto error = logging::ERROR("message");
    EXPECT_EQ(error.has_error(), false);
}
}
