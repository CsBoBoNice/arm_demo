# 设置cmake最低版本
cmake_minimum_required(VERSION 3.10)
# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 项目名称
project(Arm_Demo)

# 设置可执行文件名称
set(ExeName arm_demo)

# 设置.cmake查找的路径
set(CMAKE_MODULE_PATH  ${CMAKE_SOURCE_DIR}/cmake)

# 包含.cmake配置文件
include(compiler-param-arm)

# 打印信息
MESSAGE(STATUS "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "PROJECT_BINARY_DIR=" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "CMAKE_SOURCE_DIR=" ${CMAKE_SOURCE_DIR})
MESSAGE(STATUS "CMAKE_BINARY_DIR=" ${CMAKE_BINARY_DIR})
MESSAGE(STATUS "CMAKE_MODULE_PATH=" ${CMAKE_MODULE_PATH})
MESSAGE(STATUS "CMAKE_SYSTEM_NAME=" ${CMAKE_SYSTEM_NAME})
MESSAGE(STATUS "CMAKE_SYSTEM_PROCESSOR=" ${CMAKE_SYSTEM_PROCESSOR})
MESSAGE(STATUS "CMAKE_C_COMPILER=" ${CMAKE_C_COMPILER})
MESSAGE(STATUS "CMAKE_CXX_COMPILER=" ${CMAKE_CXX_COMPILER})


# 设置是否使用共享库
option(USE_SHARED "use shared libraries?" OFF)

if(USE_SHARED)
    set(LIBRARY_FORM SHARED)
else()
    set(LIBRARY_FORM STATIC)
endif()

# 设置编译优化
if(CMAKE_BUILD_TYPE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread ")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -pthread ")
endif()

# 向生成添加子目录 引用这个目录下的cmake文件
# add_subdirectory(lib/cjson)

# 设置变量
set(MAIN_SRC src/main.cpp)


#设置库路径#################################################################################

# 设置第三方库文件路径
# file(GLOB LIB_libevent ${PROJECT_SOURCE_DIR}/lib/libevent/lib/*.a)

##################################################################################


# 用指定的源文件为项目添加可执行文件 生成可执行文件
add_executable(${ExeName} ${MAIN_SRC})



#指头文件路径#################################################################################

# 指定所有目标的头文件路径
# include_directories(./include)

#指定目标的头文件路径(第三方)
target_include_directories(${ExeName} PUBLIC
                           ${PROJECT_SOURCE_DIR}/lib
                           ${PROJECT_SOURCE_DIR}/lib/spdlog
                           )

# 指定目标的头文件路径
target_include_directories(${ExeName} PUBLIC
                           ${PROJECT_SOURCE_DIR}/src                  
                           )

#为目标链接库#################################################################################

# 为目标链接库
# target_link_libraries(${ExeName} 
#     FTP_LIB
#     Http_Server_LIB
#     Http_Client_LIB
#     Broadcast_Module_LIB
# )

# 为目标链接库(第三方)
# target_link_libraries(${ExeName} 
#     ${LIB_libevent}
#     cjson_LIB
# )

##################################################################################


# RUNTIME 特指可执行目标二进制 ARCHIVE 特指静态库 LIBRARY 特指动态库
INSTALL(TARGETS ${ExeName}
    RUNTIME   DESTINATION bin
    LIBRARY   DESTINATION lib
    ARCHIVE   DESTINATION lib
)
