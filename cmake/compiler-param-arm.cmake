# 设置当前的系统环境
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm64)

# 设置运行时目标文件（exe、dll）的输出位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR})

# 设置存档目标文件（lib、a）的输出位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${CMAKE_SYSTEM_PROCESSOR})


# 设置工具链目录
#SET(TOOLCHAIN_DIR  /home/cs/pi_tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu)

# 设置gcc和g++变量
SET(CMAKE_C_COMPILER aarch64-linux-gnu-gcc-9)
SET(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++-9)



