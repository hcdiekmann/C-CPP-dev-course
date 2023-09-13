#include "mystack.h"
#include "gtest/gtest.h"
 
class stackMetaTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
	  
  }
 
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(stackMetaTest,created_stack_is_empty){
	int num1;
    stackMeta *teststack = new stackMeta(sizeof(int));
	EXPECT_EQ(-1,teststack->pop(&num1));
	delete teststack;
}

TEST_F(stackMetaTest,push_pop){
	int num1 = 3;
	int num2 = 8;
	int num3 = 4;
    stackMeta *teststack = new stackMeta(sizeof(int));
    EXPECT_EQ(0,teststack->push(&num1));
    EXPECT_EQ(0,teststack->push(&num2));
	EXPECT_EQ(0,teststack->pop(&num1));
	EXPECT_EQ(8,num1);
	EXPECT_EQ(0,teststack->push(&num3));
	delete teststack;
}

TEST_F(stackMetaTest,pop_empty_stack){
	int num1 = 3;
    stackMeta *teststack = new stackMeta(sizeof(int));
    EXPECT_EQ(0,teststack->push(&num1));
	EXPECT_EQ(0,teststack->pop(&num1));
	EXPECT_EQ(3,num1);
	EXPECT_EQ(-1,teststack->pop(&num1));
	delete teststack;
}

TEST_F(stackMetaTest,numelem){
	int num1 = 3;
	int num2 = 8;
    stackMeta *teststack = new stackMeta(sizeof(int));
    EXPECT_EQ(0,teststack->nofelem());
    EXPECT_EQ(0,teststack->push(&num1));
    EXPECT_EQ(1,teststack->nofelem());
    EXPECT_EQ(0,teststack->push(&num2));
    EXPECT_EQ(2,teststack->nofelem());
	EXPECT_EQ(0,teststack->pop(&num1));
	EXPECT_EQ(1,teststack->nofelem());
	delete teststack;
}
