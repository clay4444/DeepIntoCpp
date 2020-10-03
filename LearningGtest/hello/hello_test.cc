#include <iostream>
#include <gtest/gtest.h>
#include <string>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

/*
 * 还包装了一系列EXPECT_* 和ASSERT_*的宏，而EXPECT系列和ASSERT系列的区别是：
 * EXPECT_*  失败时，案例继续往下执行。
 * ASSERT_* 失败时，直接在当前函数中返回，当前函数中ASSERT_*后面的语句将不会执行。
 */

// case1
// 官方的对这两个参数的解释为：[TestCaseName，TestName]，而我对这两个参数的定义是：[TestSuiteName，TestCaseName]
TEST(test, c1) {
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(8, add(2, 6));
}

// case2
TEST(test, c2) {
    EXPECT_EQ(-1, sub(1, 2));
}

TEST(test, c3) {
    std::string x = "abc";
    std::string y = "abc";

    for (int i = 0; i < x.size(); ++i){
        // 使用  << 输出自定义消息
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}

/*
 * 事件机制： 
 * 1.全局事件，所有案例执行前后，继承testing::Environment类
 * 2.TestSuite事件，继承testing::Test
 * 3.TestCase事件，挂在每个案例执行前后
 */

// 全局事件
class FooEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        std::cout << "Foo FooEnvironment SetUP" << std::endl;
    }

    virtual void TearDown()
    {
        std::cout << "Foo FooEnvironment TearDown" << std::endl;
    }
};

// TestSuite事件
// class FooTest : public testing::Test
// {
// protected:
//     static void SetUpTestCase(){
//         shared_resource_.assign("abc");
//     }

//     static void TearDownTestCase() {
//         shared_resource_.assign(NULL);
//     }

//     // Some expensive resource shared by all tests.
//     static string shared_resource_;
// };

// // 第一个参数必须是我们上面类的名字，代表一个TestSuite。
// // 也就是说同一个 TestSuite 可以共享资源
// TEST_F(FooTest, Test1)
//  {
//     // you can refer to shared_resource here 
// };

// TEST_F(FooTest, Test2)
//  {
//     // you can refer to shared_resource here 
// };


// 3.TestCase事件，挂在每个案例执行前后
// class FooCalcTest:public testing::Test
// {
// protected:
//     virtual void SetUp()
//     {
//         m_foo.Init();
//     }
//     virtual void TearDown()
//     {
//         m_foo.Finalize();
//     }

//     FooCalc m_foo;
// };

// 第一个参数也要写上面的类，代表在这个ut跑之前运行TestCase事件；
// TEST_F(FooCalcTest, HandleNoneZeroInput)
// {
//     EXPECT_EQ(4, m_foo.Calc(12, 16));
// }

// TEST_F(FooCalcTest, HandleNoneZeroInput_Error)
// {
//     EXPECT_EQ(5, m_foo.Calc(12, 16));
// }

GTEST_API_ int main(int argc, char ** argv) {
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};

