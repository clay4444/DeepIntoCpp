# 添加生成表的执行程序的构建
add_executable(MakeTable MakeTable.cxx)
# 添加一个使用上面程序输出代码的命令
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        DEPENDS MakeTable   # mysqrt.cxx 依赖于生成的文件表(Table.h)
)

# 将当前构建目录添加到include路径以发现 Table.h
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# 添加主库
add_library(MathFunctions mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# 安装头文件和静态库到本地 (用于实际执行测试)
# TARGETS包含六种形式：ARCHIVE, LIBRARY, RUNTIME, OBJECTS, FRAMEWORK, BUNDLE。注意Mathfunction安装的是LIBRARY，而根目录下的可执行文件是RUNTIME类型。
# FILE 将给定的文件复制到指定目录。如果没有给定权限参数，则由该表单安装的文件默认为OWNER_WRITE、OWNER_READ、GROUP_READ和WORLD_READ。
# TARGETS和FILE可指定为相对目录和绝对目录。
# DESTINATION在这里是一个相对路径，取默认值。在unix系统中指向 /usr/local
# 也可以通过设置CMAKE_INSTALL_PREFIX这个变量来设置安装的路径，那么安装位置不指向/usr/local，而指向你所指定的目录。
install (TARGETS MathFunctions DESTINATION bin)     #含义：把MathFunctions这个Library安装到/usr/local目录下的bin文件夹中！   /usr/local/bin/
install (FILES MathFunctions.h DESTINATION include)    # /usr/local/include/