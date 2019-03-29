#pragma once
#include "gtest/gtest.h"

namespace logging_test {
class LoggerConsoleOutTest : public ::testing::Test {
protected:
    LoggerConsoleOutTest();
    virtual ~LoggerConsoleOutTest();
    virtual void SetUp();
    virtual void TearDown();;
};
}
