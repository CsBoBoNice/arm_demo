#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

const std::string LOCAL_LOG = "LocalLog";

void SetSpdlog();

int main(int argc, char *argv[])
{
    sleep(10); // 秒

    SetSpdlog();
    auto loger = spdlog::default_logger();
    if (loger == nullptr)
    {
        std::cout << "arm_demo error loger null" << std::endl;
    }
    else
    {
        std::cout << "arm_demo success loger" << std::endl;
    }

    loger->info(" ");
    loger->info("***************************************************************************************");
    loger->info("arm_demo start!");
    loger->info("***************************************************************************************");


    while (1)
    {

        sleep(5); // 秒
    }

    exit(EXIT_SUCCESS);
}

/**
 * @brief 日志库配置
 */
void SetSpdlog()
{

    //<1.创建多个sink
    auto sink1 = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto sink2 = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("/home/pi/log/arm_demo/log.txt", 1024 * 1024 * 10, 3);
    std::vector<spdlog::sink_ptr> sinks = {sink1, sink2};

    //<2.创建使用多个sink的单个logger，logger会把内容输出到不同位置，此处是控制台以及log.txt
    auto logger = std::make_shared<spdlog::logger>(LOCAL_LOG, sinks.begin(), sinks.end());

    // 将logger设置为默认的日志记录器
    spdlog::set_default_logger(logger);

    // spdlog::rotating_logger_mt(LOCAL_LOG, "./log.txt", 1024 * 1024 * 1, 3);
    // auto loger = spdlog::get(LOCAL_LOG);
    // if (loger)
    // {
    //     cout << "error loger null" << endl;
    //     return 0;
    // }
    // loger->set_pattern("[%D:%H:%M:%S.%e] [%l] %v");
    // loger->set_error_handler([](const std::string &msg)
    //                          { std::cerr << "my err handler: " << msg << std::endl; });
    // loger->set_level(spdlog::level::info);
    // loger->flush_on(spdlog::level::info);

    sink1->set_pattern("[%D:%H:%M:%S.%e] [%l] %v");
    sink1->set_level(spdlog::level::debug);

    sink2->set_pattern("[%D:%H:%M:%S.%e] [%l] %v");
    sink2->set_level(spdlog::level::info);

    auto loger = spdlog::default_logger();
    if (loger == nullptr)
    {
        std::cout << "main error loger null" << std::endl;
        return;
    }
    else
    {
        std::cout << "main success loger" << std::endl;
    }
    loger->set_pattern("[%D:%H:%M:%S.%e] [%l] %v");
    loger->flush_on(spdlog::level::info);
}
