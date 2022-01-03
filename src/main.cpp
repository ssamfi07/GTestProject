#include <iostream>
#include <memory>
#include "./utils/UseEmployees.hpp"
#include "./logger/Logger.hpp"
#include "./handlers/HandleEmployees.hpp"

int main(int argc, char* argv[])
{
    LOG_INFO << "Starting program...";
    std::shared_ptr<HandleEmployees> handler = std::make_shared<HandleEmployees>();
    std::shared_ptr<UseEmployees> app = std::make_shared<UseEmployees>(handler);
    app->operateFile();
    return 0;
}
