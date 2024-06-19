#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include "url.h"
#include "stack.h"
#include "helpers.h"

void resetStream();
void codeGradeLoopFix(std::string errLocation);
const int OPTIONS_COUNT = 10;
//void printOptions();

int main()
{
    stack<url> optionsStack = stack<url>(OPTIONS_COUNT);
    stack<url> fwdStack = stack<url>(OPTIONS_COUNT + 50);
    stack<url> backStack = stack<url>(OPTIONS_COUNT + 50);
    std::stringstream ss;
    int menuOption = 1;
    std::ifstream navFile("navigation.txt");
    std::string readStr;
    int count = 0;
    while(std::getline(navFile, readStr) && count < OPTIONS_COUNT){
        while (ss.good()) {
        std::string substr;
        getline(ss, substr, ','); //get substring
        substr = helpers::trim(substr); //trim whitespace
        auto it = strToFiber.find(substr); //check if valid fiber
        if(it != strToFiber.end())
            this->fiber.push_back(it->second); //add to vector
        else
            throw std::invalid_argument("Invalid fiber type: " + it->first);
    }
    }

    while(true){
        std::cout << "What would you like to do?";        
        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    ss << menuOption << " Navigate to a new URL\n";
                    menuOption++;
                    break;
                case 1:
                    if(!backStack.isEmptyStack() && !backStack.isFullStack()){
                        ss << menuOption << " Go Back to the previous URL\n";
                        menuOption++;
                    }
                    break;
                case 2:
                    if(!fwdStack.isEmptyStack() && !fwdStack.isFullStack()){
                        ss << menuOption << " Go Forward to the next URL\n";
                        menuOption++;
                    }
                    break;
                case 3:
                    ss << " Exit Browser\n";
                    menuOption++;
                    break;
            }
        }
        menuOption = 1;
        int userAnswer = helpers::inputInt("", 1, 4);
        switch (userAnswer)
        {
            case 1:
                ss << menuOption << " Navigate to a new URL\n";
                menuOption++;
                break;
            case 2:
                if (!backStack.isEmptyStack() && !backStack.isFullStack())
                {
                    ss << menuOption << " Go Back to the previous URL\n";
                    menuOption++;
                }
                break;
            case 3:
                if (!fwdStack.isEmptyStack() && !fwdStack.isFullStack())
                {
                    ss << menuOption << " Go Forward to the next URL\n";
                    menuOption++;
                }
                break;
            case 4:
                return 0;
        }
    }
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

// void printOptions(stack<url> ){

// }

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