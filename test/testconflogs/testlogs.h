#pragma once

#include "gtest/gtest.h"

namespace logging_test {

class LoggerConfTest : public ::testing::Test {
protected:
    LoggerConfTest();
    virtual ~LoggerConfTest();
    virtual void SetUp();
    virtual void TearDown();
};
}
