#include "testlogs.h"

#include "logger.h"
#include "logger_factory.h"
#include "console_out_logger.h"
#include "file_out_logger.h"
#include "error.h"

namespace logging_test {

LoggerConfTest::LoggerConfTest() {;
}

LoggerConfTest::~LoggerConfTest() {};

void LoggerConfTest::SetUp() {};

void LoggerConfTest::TearDown() {};


TEST_F(LoggerConfTest, FileConfTest) {
    logging::logging_config_t logging_config;
    logging_config.insert(std::make_pair<std::string, std::string>("type", "file_out"));
    logging_config.insert(std::make_pair<std::string, std::string>("file_name", "test.log"));
    logging_config.insert(std::make_pair<std::string, std::string>("reopen_interval", "100"));

    auto error = logging::configuration(logging_config);
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConfTest, ConsoleConfTest) {
    logging::logging_config_t logging_config;
    logging_config.insert(std::make_pair<std::string, std::string>("type", "console_out"));

    auto error = logging::configuration(logging_config);
    EXPECT_EQ(error.has_error(), false);
}

TEST_F(LoggerConfTest, ConsoleDebug) {
    logging::logging_config_t logging_config_file;
    logging_config_file.insert(std::make_pair<std::string, std::string>("type", "file_out"));
    logging_config_file.insert(std::make_pair<std::string, std::string>("file_name", "test.log"));
    logging_config_file.insert(std::make_pair<std::string, std::string>("reopen_interval", "100"));

    logging::logging_config_t logging_config_confole;
    logging_config_confole.insert(std::make_pair<std::string, std::string>("type", "console_out"));


    logging::logging_config_list_t logging_config_list;
    logging_config_list.push_back(logging_config_file);
    logging_config_list.push_back(logging_config_confole);

    auto error = logging::configuration(logging_config_list);

    EXPECT_EQ(error.has_error(), false);
}

}
