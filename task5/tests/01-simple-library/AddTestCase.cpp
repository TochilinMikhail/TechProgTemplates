//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, first) {
	ASSERT_EQ(Add(1, 2), 3);
}

TEST(AddTestCase, second) {
	ASSERT_EQ(Add(1, 0), 1);
}

TEST(AddTestCase, third) {
	ASSERT_EQ(Add(1, -1), 0);
}

TEST(AddTestCase, fourth) {
	ASSERT_NE(Add(1, 2), 4);
}