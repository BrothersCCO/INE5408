#include <gtest/gtest.h>
#include <exception>
#include "CircularlyLinkedList.h"

class CircularlyLinkedListTest: public testing::Test {
public:
	CircularlyLinkedList<int> cll;

	CircularlyLinkedListTest() {
	}
};

TEST_F(CircularlyLinkedListTest, unshiftOneElement) {
	cll.unshift(3);
	EXPECT_EQ(cll.length(), 1);
}

TEST_F(CircularlyLinkedListTest, pushOneElement) {
	cll.push(3);
	EXPECT_EQ(cll.length(), 1);
}

TEST_F(CircularlyLinkedListTest, unshiftMuchElement) {
	cll.unshift(3);
	cll.unshift(15);
	cll.unshift(42);
	cll.unshift(1908);
	EXPECT_EQ(cll.length(), 4);
}

TEST_F(CircularlyLinkedListTest, pushMuchElement) {
	cll.push(3);
	cll.push(15);
	cll.push(42);
	cll.push(1908);
	EXPECT_EQ(cll.length(), 4);
}

/*TEST_F(CircularlyLinkedListTest, unshiftPopMuchElement) {
	cll.unshift(3);
	cll.unshift(15);
	cll.unshift(42);
	cll.unshift(1908);
	EXPECT_EQ(cll.length(), 4);
	EXPECT_EQ(cll.pop(), 3);
	EXPECT_EQ(cll.pop(), 15);
	EXPECT_EQ(cll.pop(), 42);
	EXPECT_EQ(cll.pop(), 1908);
	EXPECT_EQ(cll.length(), 0);
}

TEST_F(CircularlyLinkedListTest, pushShiftMuchElement) {
	cll.push(3);
	cll.push(15);
	cll.push(42);
	cll.push(1908);
	EXPECT_EQ(cll.length(), 4);
	EXPECT_EQ(cll.shift(), 3);
	EXPECT_EQ(cll.shift(), 15);
	EXPECT_EQ(cll.shift(), 42);
	EXPECT_EQ(cll.shift(), 1908);
	EXPECT_EQ(cll.length(), 0);
}

TEST_F(CircularlyLinkedListTest, removeFromPosition) {
	cll.push(3);
	cll.push(15);
	cll.push(42);
	cll.push(1908);
	EXPECT_EQ(cll.length(), 4);
	EXPECT_EQ(cll.remove(1), 15);
	EXPECT_EQ(cll.remove(2), 1908);
	EXPECT_EQ(cll.remove(1), 42);
	EXPECT_EQ(cll.remove(0), 3);
	EXPECT_EQ(cll.length(), 0);
}

TEST_F(CircularlyLinkedListTest, insertToPosition) {
	cll.insert(0, 3);
	cll.insert(1, 15);
	cll.insert(1, 42);
	cll.insert(2, 1908);
	EXPECT_EQ(cll.length(), 4);
	EXPECT_EQ(cll.pop(), 15);
	EXPECT_EQ(cll.pop(), 1908);
	EXPECT_EQ(cll.pop(), 42);
	EXPECT_EQ(cll.pop(), 3);
	EXPECT_EQ(cll.length(), 0);
}

TEST_F(CircularlyLinkedListTest, iterateForward) {
	int list[4] = { 3, 15, 42, 1908 };
	for (int i = 0; i < 4; ++i) {
		cll.push(list[i]);
	}
	EXPECT_EQ(cll.length(), 4);
	int i = 0;
	for (CircularlyLinkedList<int>::iterator it = cll.begin(); it != cll.end();
			++it) {
		EXPECT_EQ(*it, list[i++]);
	}
}

TEST_F(CircularlyLinkedListTest, iterateBackward) {
	int list[4] = { 3, 15, 42, 1908 };
	for (int i = 0; i < 4; ++i) {
		cll.unshift(list[i]);
	}
	EXPECT_EQ(cll.length(), 4);
	int i = 0;
	for (CircularlyLinkedList<int>::iterator it = cll.rbegin(); it != cll.rend();
			--it) {
		EXPECT_EQ(*it, list[i++]);
	}
}*/
