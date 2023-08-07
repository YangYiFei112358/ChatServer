cmake_minimum_required(VERSION 3.0)
project(main)

# 配置编译选项
# -o -g
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置头文件搜索路径
# include_directories()
# 配置库文件搜索路径
# link_directories()


# 设置需要编译的源文件列表
set(SRC_LIST ./muduo_server.cpp)
# aux_source_directory(. SRC_LIST) # 定义变量，存储当前目录下的所有源文件

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 表示需要编译哪些源文件
add_executable(server ${SRC_LIST})
# 表示需要链接这三个库
target_link_libraries(server muduo_net muduo_base pthread)