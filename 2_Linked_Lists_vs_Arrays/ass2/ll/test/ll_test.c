#include <string.h>

#include "linkedlist.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
  // This is run after EACH test
}

void test_add_first(void)
{
	ITEM *list = NULL;
	int ret = 0;
	ret = add_first(&list, 1);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->value, 1);
	ret = add_first(&list, 2);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->next->value, 1);
	TEST_ASSERT_EQUAL(list->value, 2);
	clean(list);
}

void test_add_last(void)
{
	ITEM *list = NULL;
	int ret = 0;
	ret = add_last(&list, 4);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->value, 4);
	ret = add_last(&list, 2);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->next->value, 2);
	TEST_ASSERT_EQUAL(list->value, 4);
	
	clean(list);
}


void test_add_after(void)
{
	ITEM *list = NULL;
	int ret = 0;
	add_first(&list, 4);
	add_first(&list, 3);
	add_first(&list, 7);
	
	ret = add_after(list, list->next, 8);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(8,list->next->next->value);
	
	ret = add_after(list, list->next, 1);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(8,list->next->next->next->value);
	
	clean(list);
}

void test_rem_first(void)
{
	ITEM *list = NULL;
	int ret = 0;
	add_first(&list, 4);
	add_first(&list, 3);
	add_first(&list, 7);
	TEST_ASSERT_EQUAL(7, list->value);
	ret = rem_first(&list);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(3, list->value);
	clean(list);
}

void test_rem_last(void)
{
	ITEM *list = NULL;
	int ret = 0;
	ret = rem_last(&list);
	TEST_ASSERT_EQUAL(-1,ret);
	ret = add_first(&list, 4);
	ret = add_first(&list, 2);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->value, 2);
	ret = rem_last(&list);
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(list->value, 2);
	clean(list);
}

void test_rem_after(void)
{
	ITEM *list = NULL;
	int ret = 0;
	add_first(&list, 4);
	add_first(&list, 3);
	add_first(&list, 7);
	add_first(&list, 14);
	TEST_ASSERT_EQUAL(14, list->value);
	//remove item(3) after second item(7)
	ret = rem_after(list, list->next); 
	TEST_ASSERT_EQUAL(0,ret);
	TEST_ASSERT_EQUAL(4, list->next->next->value);
	clean(list);
}


int main (int argc, char * argv[])
{
    UnityBegin();

    /* Put your UTs here */
    MY_RUN_TEST(test_add_first);
	MY_RUN_TEST(test_add_last);
	MY_RUN_TEST(test_add_after);
	MY_RUN_TEST(test_rem_first);
	MY_RUN_TEST(test_rem_last);
	MY_RUN_TEST(test_rem_after);
	
    return UnityEnd();
}
