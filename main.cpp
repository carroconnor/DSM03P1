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
//#include "helpers.h"

void codeGradeLoopFix(std::string errLocation);
int inputInt(std::string prompt, int min, int max);
void resetStream();

int main()
{
    url* currentUrl = nullptr;
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
        int userAnswer = inputInt("", 1, menuOption);
        menuOption = 1;
        switch (userAnswer)
        {
            case 1:
                //go to nav
                if(currentUrl != nullptr){
                    backStack.push(*currentUrl);
                }
                if(!fwdStack.isEmptyStack()){
                    //fwdStack.clear();
                }
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

void resetStream(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

int inputInt(std::string prompt, int min, int max){
    int result;

    if(prompt.length() > 0){
        std::cout << prompt << std::endl; 
    }
    std::cin >> result; 

    while(!std::cin || result < min || result > max){
        if(!std::cin){
            std::cout << "That's not a number." << std::endl;
        }
        std::cout << "Invalid entry. Number must be between " << min << " and " << max << " inclusive. try again." << std::endl; 
        resetStream();
        std::cin >> result;
    }

    return result;
}