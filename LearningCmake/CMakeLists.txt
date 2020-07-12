# cmake 最低版本需求
cmake_minimum_required(VERSION 3.16)

# 工程名称
project(LearningCmake)

set(CMAKE_CXX_STANDARD 11)

# message输入一些日志信息，在一些模式下能够终止程序构建
message(STATUS ${PROJECT_NAME})
message(STATUS ${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_BINARY_DIR})

# 设置有关版本号的两个变量，版本号 1.0
# 这两个变量将会在后面的操作中被插入到源代码中
set (Tutorial_VERSION_MAJOR 1)   #设置Tutorial_VERSION_MAJOR变量的值为1
set (Tutorial_VERSION_MINOR 0)

# 一些常用内置变量
# PROJECT_SOURCE_DIR 、 CMAKE_SOURCE_DIR         工程顶层目录。
# CMAKE_BINARY_DIR 、 PROJECT_BINARY_DIR         工程编译发生的目录
# CMAKE_CURRENT_SOURCE_DIR                       当前处理的 CMakeLists.txt 所在的路径
# CMAKE_CURRRENT_BINARY_DIR	                    如果是 in-source 编译,它跟 CMAKE_CURRENT_SOURCE_DIR 一致,如果是 out-of-source 编译,他指的是 target 编译目录。
# EXECUTABLE_OUTPUT_PATH、LIBRARY_OUTPUT_PATH    最终目标文件存放的路径。
# PROJECT_NAME                                  通过 PROJECT 指令定义的项目名称。

# does this system provide the log and exp functions?
# 使用include()命令来加载.cmake (一个module) ，也可以提供自己的模块，并在CMAKE_MODULE_PATH变量中指定它们的位置。
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# 提供一个选项：是否使用提供的数学函数？   CMake GUI 中将会显示一个 ON 的默认值，用户可以按需更改。
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 检查并设置相关变量
#if (Check_Function)
#    include(CheckFunctionExists)    # 这是哪里定义的宏？
#    check_function_exists(log HAVE_LOG)  # 也就说HAVE_LOG和HAVE_EXP的值是系统赋值的，系统去检查当前平台是否包含这两个函数
#    check_function_exists(exp HAVE_EXP)
#endif (Check_Function)


# 以 TutorialConfig.h.in 为模版
# 以上设置的变量将会影响此处的处理
# 替换相关变量并输出到 TutorialConfig.h
configure_file (
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"  #上面的变量赋的值传递到这个文件中，
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"     #然后生成这个头文件
)

# 将构建目录添加到 include 的搜索路径中以便找到 TutorialConfig.h 文件
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?   根据上面的配置判断是否需要做下面的动作
if (USE_MYMATH)

    # include MathFunctions 路径，以便可以引用到这个目录下的头文件
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")

    # ADD_SUBDIRECTORY(NAME) 添加一个文件夹进行编译，该文件夹下的 CMakeLists.txt 负责编译该文件夹下的源码. NAME是相对于调用add_subdirectory的CMakeListst.txt的相对路径．
    add_subdirectory (MathFunctions)

    #如果需要用自己的库函数，就更改内置变量的值，否则就用内置变量本身自己的值
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 编译源码生成目标
set(SOURCE_FILES main.cxx)
add_executable(LearningCmake ${SOURCE_FILES})

# 添加链接库 ，使用内置变量的值 (注意：这一步一定要放在add_executable的后面，否则会报错LearningCmake还未build，gcc的流程是先编译，最后才连接)
target_link_libraries (LearningCmake ${EXTRA_LIBS})

# 安装可执行文件和配置文件，代表安装到本地 (用于实际执行测试)
# TARGETS包含六种形式：ARCHIVE, LIBRARY, RUNTIME, OBJECTS, FRAMEWORK, BUNDLE。注意Mathfunction安装的是LIBRARY，而根目录下的可执行文件是RUNTIME类型。
# FILE 将给定的文件复制到指定目录。如果没有给定权限参数，则由该表单安装的文件默认为OWNER_WRITE、OWNER_READ、GROUP_READ和WORLD_READ。
# TARGETS和FILE可指定为相对目录和绝对目录。
# DESTINATION在这里是一个相对路径，取默认值。在unix系统中指向 /usr/local
# 也可以通过设置CMAKE_INSTALL_PREFIX这个变量来设置安装的路径，那么安装位置不指向/usr/local，而指向你所指定的目录。
install (TARGETS LearningCmake DESTINATION bin)    # /usr/local/bin/
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)                      # /usr/local/include

# 添加测试
enable_testing ()

# 验证应用程序是否正常运行，没有发生崩溃，并且返回值是0。这是CTest测试的基本形式
add_test (TutorialRuns LearningCmake 25)

# 使用PASS_REGULAR_EXPRESSION测试属性来验证测试的输出是否包含特定的字符串
add_test (TutorialComp25 LearningCmake 25)
set_tests_properties (TutorialComp25
        PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5"
        )

# does it handle negative numbers
add_test (TutorialNegative LearningCmake -25)
set_tests_properties (TutorialNegative
        PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0"
        )

# does it handle small numbers
add_test (TutorialSmall LearningCmake 0.0001)
set_tests_properties (TutorialSmall
        PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01"
        )

# does the usage message work?
add_test (TutorialUsage LearningCmake)
set_tests_properties (TutorialUsage
        PROPERTIES
        PASS_REGULAR_EXPRESSION "Usage:.*number"
        )

# 添加一个宏来简化 add_test 复杂的流程
macro (do_test arg result)
    add_test (TutorialComp${arg} LearningCmake ${arg})
    set_tests_properties (TutorialComp${arg}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result}
            )
endmacro ()

# 使用上面定义的宏
do_test (25 "25 is 5")
do_test (-25 "-25 is 0")
do_test (0.0001 "0.0001 is 0.01")

# 使用 CPack 来创建 （平台相关）的安装程序，目的是在各种平台上提供二进制和源代码分发
include (InstallRequiredSystemLibraries)   # InstallRequiredSystemLibraries该模块包含有这个项目在当前平台所需的任何运行时库
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)  # 使用你设置的这些变量和其他系统属性来配置安装程序