#include "pch.h"
#include "../algorANDSD/List.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(ListTest, CTOR)
{
	List a;
	EXPECT_EQ(0, a.Size());
}