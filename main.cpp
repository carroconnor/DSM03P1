#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <istream>
#include "url.h"
#include "stack.h"
#include "helpers.h"

void codeGradeLoopFix(std::string errLocation);

int main()
{
    std::vector<url> optionsList;
    stack<url> fwdStack = stack<url>();
    stack<url> backStack = stack<url>();
    std::stringstream ss;
    int menuOption = 1;
    std::ifstream navFile("navigation.txt");
    std::string lineStr;

    while(std::getline(navFile, lineStr)){
        ss << lineStr;
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        url newUrl = url(*begin, *end);
        optionsList.push_back(newUrl);
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
        ss.clear();
        int userAnswer = helpers::inputInt("", 1, menuOption);
        menuOption = 1;
        switch (userAnswer)
        {
            case 1:
                //go to nav
                break;
            case 2:
                //pop stack
                break;
            case 3:
                //push stack
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

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation); // return or throw an exception here to force the program to end or return from the function.
    }
}