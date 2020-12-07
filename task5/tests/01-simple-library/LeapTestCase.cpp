//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase, throw1) {
    ASSERT_THROW(IsLeap(-5), std::invalid_argument);
}

TEST(LeapTestCase, throw2) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}


TEST(LeapTestCase, no_throw1) {
    ASSERT_NO_THROW(IsLeap(5));
}

TEST(LeapTestCase, no_throw2) {
    ASSERT_NO_THROW(IsLeap(12));
}


TEST(LeapTestCase, true1) {
    ASSERT_TRUE(IsLeap(1200));
}

TEST(LeapTestCase, true2) {
    ASSERT_TRUE(IsLeap(1996));
}

TEST(LeapTestCase, true3) {
    ASSERT_TRUE(IsLeap(2012));
}


TEST(LeapTestCase, false1) {
    ASSERT_FALSE(IsLeap(1900));
}

TEST(LeapTestCase, false2) {
    ASSERT_FALSE(IsLeap(2013));
}

TEST(LeapTestCase, false3) {
    ASSERT_FALSE(IsLeap(7));
}