load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
#指定该包对其他包可见
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hello",
    hdrs = ["hello.h"],
    srcs = ["hello.cc"],
)
cc_test(
    name = "hello_test",
    srcs = ["hello_test.cc"],
    deps = [ 
        ":hello",
        "@gtest//:gtest",
        "@gtest//:gtest_main"    
    ],  
)

cc_test(
    name = "hello_test2",
    srcs = ["hello_test2.cc"],
    deps = [ 
        ":hello",
        "@gtest//:gtest",
        "@gtest//:gtest_main"    
    ],  
)