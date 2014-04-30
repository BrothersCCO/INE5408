#include <gtest/gtest.h>
#include <stdexcept>
#include "LinkedQueue.h"

class LinkedQueueTest: public testing::Test {
public:
	LinkedQueue<int> lq;

	LinkedQueueTest() {
	}
};

TEST_F(LinkedQueueTest, pushShiftOneElement) {
	lq.push(3);
	EXPECT_EQ(lq.length(), 1);
	EXPECT_EQ(lq.shift(), 3);
	EXPECT_EQ(lq.length(), 0);
}

TEST_F(LinkedQueueTest, pushShiftMuchElement) {
	lq.push(3);
	lq.push(15);
	lq.push(42);
	lq.push(1908);
	EXPECT_EQ(lq.length(), 4);
	EXPECT_EQ(lq.shift(), 3);
	EXPECT_EQ(lq.shift(), 15);
	EXPECT_EQ(lq.shift(), 42);
	EXPECT_EQ(lq.shift(), 1908);
	EXPECT_EQ(lq.length(), 0);
}

TEST_F(LinkedQueueTest, shiftFromEmptyList) {
		EXPECT_THROW(lq.shift(), std::out_of_range);
}
