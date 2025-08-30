#include <iostream>
#include <spdlog/spdlog.h>

int main() {
    spdlog::info("Hello, Bazel + Nix + spdlog World!");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");
    
    std::cout << "Regular cout: Hello, Bazel World!" << std::endl;
    return 0;
} 