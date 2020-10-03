#include <iostream>
#include <gtest/gtest.h>
#include <string>

using namespace std;

// 参数化之前的方案

// Returns true iff n is a prime number.
bool IsPrime(int n)
{
    // Trivial case 1: small numbers
    if (n <= 1) return false;

    // Trivial case 2: even numbers
    if (n % 2 == 0) return n == 2;

    // Now, we have that n is odd and n >= 3.

    // Try to divide n by every odd number i, starting from 3
    for (int i = 3; ; i += 2) {
        // We only have to try i up to the squre root of n
        if (i > n/i) break;

        // Now, we have i <= n/i < n.
        // If n is divisible by i, n is not prime.
        if (n % i == 0) return false;
    }
    // n has no integer factor in the range (1, n), and thus is prime.
    return true;
}

TEST(IsPrimeTest, HandleTrueReturn)
{
    EXPECT_TRUE(IsPrime(3));  //这里复制了5个检查点
    EXPECT_TRUE(IsPrime(5));
    EXPECT_TRUE(IsPrime(11));
    EXPECT_TRUE(IsPrime(23));
    EXPECT_TRUE(IsPrime(17));
}

// 参数化方案
class IsPrimeParamTest : public::testing::TestWithParam<int>
{

};

// 使用 TEST_P 这个宏， 第一个参数传上面定义的参数类
TEST_P(IsPrimeParamTest, HandleTrueReturn)
{
    int n =  GetParam();  //然后这里直接调用GetParam即可，那它怎么知道要传递的值的范围呢？ 
    EXPECT_TRUE(IsPrime(n));
}

// 所以再定义一个宏，单独告诉它范围；
// 第一个参数是测试案例的前缀，可以任意取。
// 第二个参数是测试案例的名称，需要和之前定义的参数化的类的名称相同，如：IsPrimeParamTest
// 第三个参数是可以理解为参数生成器，上面的例子使用test::Values表示使用括号内的参数。Google提供了一系列的参数生成的函数：
INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));
