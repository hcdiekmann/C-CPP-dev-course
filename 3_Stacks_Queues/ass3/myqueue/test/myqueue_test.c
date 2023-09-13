#include <string.h>
#include <stdio.h>
#include "mystack.h"
#include "myqueue.h"
#include "unity.h"
#include "testrunner.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_queue_create_delete(void)
{
	QueueMeta_t *testQueue = myqueue_create(8);
	TEST_ASSERT_NOT_NULL(testQueue);
	myqueue_delete(testQueue);
}

void test_enqueue_dequeue(void)
{
	QueueMeta_t *testQueue = myqueue_create(sizeof(int));
	int num1 = 3;
	int num2 = 12;
	myqueue_enqueue(testQueue, &num1);
	myqueue_enqueue(testQueue, &num2);
	myqueue_dequeue(testQueue, &num2);
	TEST_ASSERT_EQUAL_INT(3, num1);
	TEST_ASSERT_EQUAL_INT(3, num2);
	myqueue_dequeue(testQueue, &num1);
	TEST_ASSERT_EQUAL_INT(12, num1);
	myqueue_delete(testQueue);
}


int main () {
	UnityBegin();
	MY_RUN_TEST(test_queue_create_delete);
	MY_RUN_TEST(test_enqueue_dequeue);
	return UnityEnd();
}
