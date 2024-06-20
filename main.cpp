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
    stack<url> optionsList;
    stack<url> fwdStack = stack<url>();
    stack<url> backStack = stack<url>();
    std::stringstream ss;
    url currentUrl;
    int menuOption = 1;
    int count = 0;
    std::ifstream navFile("navigation.txt");
    std::string lineStr;

    while(std::getline(navFile, lineStr)){
        std::istringstream ss(lineStr);
        std::string urlStr, fileNameStr;

        ss >> urlStr >> fileNameStr;
        url newUrl = url(urlStr, fileNameStr);
        optionsList.push(newUrl);
    }

    while(true){
        std::cout << "What would you like to do? " << std::endl;
        std::vector<int> menuOptions;        
        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    if(!optionsList.isEmptyStack()){
                        ss << std::to_string(menuOption) << " Navigate to a new URL\n";
                        menuOptions.push_back(0);
                        menuOption++;
                    }
                    break;
                case 1:
                    if(!backStack.isEmptyStack() && !backStack.isFullStack()){
                        ss << std::to_string(menuOption) << " Go Back to the previous URL\n";
                        menuOptions.push_back(1);
                        menuOption++;
                    }
                    break;
                case 2:
                    if(!fwdStack.isEmptyStack() && !fwdStack.isFullStack()){
                        ss << std::to_string(menuOption) << " Go Forward to the next URL\n";
                        menuOptions.push_back(2);
                        menuOption++;
                    }
                    break;
                case 3:
                    ss << std::to_string(menuOption) << " Exit Browser\n";
                    menuOptions.push_back(3);
                    menuOption++;
                    break;
            }
        }
        std::cout << ss.str() << std::endl;
        ss.str(std::string());
        int userAnswer = menuOptions.at(inputInt("", 1, menuOption) - 1);
        menuOption = 1;
        switch (userAnswer)
        {
            case 0:
                //go to nav
                if(count > 0){
                    backStack.push(currentUrl);
                }
                if(!fwdStack.isEmptyStack()){
                    fwdStack.initializeStack();
                }
                currentUrl = optionsList.top();
                currentUrl.displayFile();
                optionsList.pop();
                break;
            case 1:
                //go back
                fwdStack.push(currentUrl);
                currentUrl = backStack.top();
                backStack.pop();
                currentUrl.displayFile();
                break;
            case 2:
                //go forward
                backStack.push(currentUrl);
                currentUrl = fwdStack.top();
                fwdStack.pop();
                currentUrl.displayFile();
                break;
            case 3:
                return 0;
        }
        count++;
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