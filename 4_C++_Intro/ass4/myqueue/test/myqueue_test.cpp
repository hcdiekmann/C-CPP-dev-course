#include "myqueue.h"
#include "gtest/gtest.h"
 
class queueMetaTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
	  
  }
 
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(queueMetaTest,dequeue_empty_queue){
	int num1 = 3;
    queueMeta *testqueue = new queueMeta(sizeof(int));
	EXPECT_EQ(-1,testqueue->dequeue(&num1));
	delete testqueue;
}

TEST_F(queueMetaTest,enqueue_dequeue){
	int num1 = 3;
	int num2 = 8;
	int num3 = 4;
    queueMeta *testqueue = new queueMeta(sizeof(int));
    EXPECT_EQ(0,testqueue->enqueue(&num1));
    EXPECT_EQ(0,testqueue->enqueue(&num2));
	EXPECT_EQ(0,testqueue->dequeue(&num2));
	EXPECT_EQ(3,num2);
	EXPECT_EQ(0,testqueue->enqueue(&num3));
	EXPECT_EQ(0,testqueue->dequeue(&num2));
	EXPECT_EQ(8,num2);
	EXPECT_EQ(0,testqueue->dequeue(&num2));
	EXPECT_EQ(4,num2);
	delete testqueue;
}

