#include "testlogs.h"

#include "logger.h"
#include "logger_factory.h"
#include "console_out_logger.h"
#include "file_out_logger.h"

#include "error.h"

namespace logging_test {

LoggerFileTest::LoggerFileTest() {
    logging::logging_config_t logging_config;
    logging_config.insert(std::make_pair<std::string, std::string>("type", "file_out"));
    logging_config.insert(std::make_pair<std::string, std::string>("file_name", "test.log"));
    logging_config.insert(std::make_pair<std::string, std::string>("reopen_interval", "100"));

    logging::configuration(logging_config);
}

LoggerFileTest::~LoggerFileTest() {};

void LoggerFileTest::SetUp() {};

void LoggerFileTest::TearDown() {};

TEST_F(LoggerFileTest, FileOutInfo) {
    auto error = logging::INFO("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerFileTest, FileOutWarn) {
    auto error = logging::WARN("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerFileTest, FileOutDebug) {
    auto error = logging::DEBUG("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerFileTest, FileOutTrace) {
    auto error = logging::TRACE("message");
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerFileTest, FileOutError) {
    auto error = logging::ERROR("message");
    EXPECT_EQ(error.has_error(), false);
}
}
