#include <iostream>
#include <spdlog/spdlog.h>
#include <foobar/foobar.h>

int main() {
    spdlog::info("Hello, Bazel + Nix + spdlog World!");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");
    
    // Call the foobar function
    foobar::foobar();
    
    std::cout << "Regular cout: Hello, Bazel World!" << std::endl;
    return 0;
} 