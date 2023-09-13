#include <string.h>
#include <stdio.h>

#include "mystack.h"
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

void test_create_destroy_mystack(void)
{
	StackMeta_t *testStack1 = mystack_create(sizeof(int));
	StackMeta_t *testStack2 = mystack_create(sizeof(char));
	TEST_ASSERT_NOT_NULL(testStack1);
	TEST_ASSERT_NOT_NULL(testStack2);
	mystack_destroy(testStack1);
	mystack_destroy(testStack2);
	
}

void test_push_mystack(void)
{
	StackMeta_t *testStack = mystack_create(sizeof(char));
	
	char char1 = 'a';
	char char2 = 'b';
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &char1));
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &char2));
	
	mystack_destroy(testStack);
}
	
void test_push_and_pop_mystack(void)
{
	StackMeta_t *testStack = mystack_create(sizeof(int));
	
	int num1 = 10;
	int num2 = 12;
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &num1));
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &num2));
	TEST_ASSERT_EQUAL_INT(10, num1);
	TEST_ASSERT_EQUAL_INT(12, num2);
	
	TEST_ASSERT_EQUAL(0,mystack_pop(testStack, &num1));	
	TEST_ASSERT_EQUAL(0,mystack_pop(testStack, &num2));
	TEST_ASSERT_EQUAL_INT(12, num1);
	TEST_ASSERT_EQUAL_INT(10, num2);
	
	mystack_destroy(testStack);
}

void test_nofelem_mystack(void)
{
	StackMeta_t *testStack = mystack_create(sizeof(int));
	TEST_ASSERT_EQUAL_INT(0, mystack_nofelem(testStack));
	
	int num1 = 10;
	int num2 = 12;
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &num1));
	TEST_ASSERT_EQUAL_INT(1, mystack_nofelem(testStack));
	
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &num2));
	TEST_ASSERT_EQUAL(0,mystack_push(testStack, &num2));
	TEST_ASSERT_EQUAL_INT(3, mystack_nofelem(testStack));
	
	TEST_ASSERT_EQUAL(0,mystack_pop(testStack, &num1));
	TEST_ASSERT_EQUAL_INT(2, mystack_nofelem(testStack));
	
	mystack_destroy(testStack);
}

int main (int argc, char * argv[]) {
	UnityBegin();
	MY_RUN_TEST(test_create_destroy_mystack);
	MY_RUN_TEST(test_push_mystack);
	MY_RUN_TEST(test_push_and_pop_mystack);
	MY_RUN_TEST(test_nofelem_mystack);
	return UnityEnd();
}
