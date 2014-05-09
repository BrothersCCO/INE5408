#include <gtest/gtest.h>
#include <exception>
#include "DoublyLinkedList.h"

class DoublyLinkedListTest: public testing::Test {
public:
	DoublyLinkedList<int> dll;

	DoublyLinkedListTest() {
	}
};

TEST_F(DoublyLinkedListTest, unshiftShiftOneElement) {
	dll.unshift(3);
	EXPECT_EQ(dll.length(), 1);
	EXPECT_EQ(dll.pop(), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, pushPopOneElement) {
	dll.push(3);
	EXPECT_EQ(dll.length(), 1);
	EXPECT_EQ(dll.pop(), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, unshiftShiftMuchElement) {
	dll.unshift(3);
	dll.unshift(15);
	dll.unshift(42);
	dll.unshift(1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.shift(), 1908);
	EXPECT_EQ(dll.shift(), 42);
	EXPECT_EQ(dll.shift(), 15);
	EXPECT_EQ(dll.shift(), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, pushPopMuchElement) {
	dll.push(3);
	dll.push(15);
	dll.push(42);
	dll.push(1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.pop(), 1908);
	EXPECT_EQ(dll.pop(), 42);
	EXPECT_EQ(dll.pop(), 15);
	EXPECT_EQ(dll.pop(), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, unshiftPopMuchElement) {
	dll.unshift(3);
	dll.unshift(15);
	dll.unshift(42);
	dll.unshift(1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.pop(), 3);
	EXPECT_EQ(dll.pop(), 15);
	EXPECT_EQ(dll.pop(), 42);
	EXPECT_EQ(dll.pop(), 1908);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, pushShiftMuchElement) {
	dll.push(3);
	dll.push(15);
	dll.push(42);
	dll.push(1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.shift(), 3);
	EXPECT_EQ(dll.shift(), 15);
	EXPECT_EQ(dll.shift(), 42);
	EXPECT_EQ(dll.shift(), 1908);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, removeFromPosition) {
	dll.push(3);
	dll.push(15);
	dll.push(42);
	dll.push(1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.remove(1), 15);
	EXPECT_EQ(dll.remove(2), 1908);
	EXPECT_EQ(dll.remove(1), 42);
	EXPECT_EQ(dll.remove(0), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, insertToPosition) {
	dll.insert(0, 3);
	dll.insert(1, 15);
	dll.insert(1, 42);
	dll.insert(2, 1908);
	EXPECT_EQ(dll.length(), 4);
	EXPECT_EQ(dll.pop(), 15);
	EXPECT_EQ(dll.pop(), 1908);
	EXPECT_EQ(dll.pop(), 42);
	EXPECT_EQ(dll.pop(), 3);
	EXPECT_EQ(dll.length(), 0);
}

TEST_F(DoublyLinkedListTest, iterateForward) {
	int list[4] = { 3, 15, 42, 1908 };
	for (int i = 0; i < 4; ++i) {
		dll.push(list[i]);
	}
	EXPECT_EQ(dll.length(), 4);
	int i = 0;
	for (DoublyLinkedList<int>::iterator it = dll.begin(); it != dll.end();
			++it) {
		EXPECT_EQ(*it, list[i++]);
	}
}

TEST_F(DoublyLinkedListTest, iterateBackward) {
	int list[4] = { 3, 15, 42, 1908 };
	for (int i = 0; i < 4; ++i) {
		dll.unshift(list[i]);
	}
	EXPECT_EQ(dll.length(), 4);
	int i = 0;
	for (DoublyLinkedList<int>::iterator it = dll.rbegin(); it != dll.rend();
			--it) {
		EXPECT_EQ(*it, list[i++]);
	}
}
