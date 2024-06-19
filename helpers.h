#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <limits>

class helpers {
public:
    static void resetStream();
    static int inputInt(std::string prompt = "", int min = 0, int max = 10);
    static std::string trim(const std::string &str, const std::string &whitespace = " ");
    helpers() = delete;
};

#endif