# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project (leetcode)

# 包含子项目。
add_subdirectory ("0001")
add_subdirectory ("0009")

# 添加生成可执行目标
add_executable(longestCommonPrefix "0014/0014.cpp")
add_executable(lengthOfLongestSubstring src/0003.cpp)
add_executable(removeDuplicatesOfArray src/1001.cpp)
