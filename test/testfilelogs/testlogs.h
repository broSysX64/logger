#pragma once
#include "gtest/gtest.h"

namespace logging_test {
class LoggerFileTest : public ::testing::Test {
protected:
    LoggerFileTest();
    virtual ~LoggerFileTest();
    virtual void SetUp();
    virtual void TearDown();

};

}
