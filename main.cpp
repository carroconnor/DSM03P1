#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include "url.h"
#include "stack.h"

void resetStream();
void codeGradeLoopFix(std::string errLocation);

int main()
{
    // try
    // {
    //     // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
    //     http::Request request{"http://test.com/test"};

    //     // send a get request
    //     const auto response = request.send("GET");
    //     std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Request failed, error: " << e.what() << '\n';
    // }
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation); // return or throw an exception here to force the program to end or return from the function.
    }
}