#pragma once
#include "gtest/gtest.h"

namespace logging_test {

class LoggerTest : public ::testing::Test {
protected:
    LoggerTest();
    virtual ~LoggerTest();
    virtual void SetUp();
    virtual void TearDown();
};
}
