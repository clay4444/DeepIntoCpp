load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [ 
        "main.cc", 
    ],  
    #依赖hello模块中的hello library.
    deps = [ 
        "//hello:hello", 
    ],  
)