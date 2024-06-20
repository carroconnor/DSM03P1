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

/* Program name: stack.cpp
* Author: Carr O'Connor
* Date last updated: 6/20/2024
* Purpose: utilize stacks to mimic browser navigation
*/

void codeGradeLoopFix(std::string errLocation);
int inputInt(std::string prompt, std::vector<int> options);
void resetStream();

int main()
{
    stack<url> optionsList;
    stack<url> fwdStack = stack<url>();
    stack<url> backStack = stack<url>();
    std::vector<int> menuOptions;
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

    optionsList.reverse();

    while(true){
        std::cout << "What would you like to do? " << std::endl;  
        menuOptions.clear();      
        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    if(!optionsList.isEmptyStack()){
                        ss << "1. Navigate to a new URL\n";
                        menuOptions.push_back(1);
                        menuOption++;
                    }
                    break;
                case 1:
                    if(!backStack.isEmptyStack() && !backStack.isFullStack()){
                        ss << "2. Go Back to the previous URL\n";
                        menuOptions.push_back(2);
                        menuOption++;
                    }
                    break;
                case 2:
                    if(!fwdStack.isEmptyStack() && !fwdStack.isFullStack()){
                        ss << "3. Go Forward to the next URL\n";
                        menuOptions.push_back(3);
                        menuOption++;
                    }
                    break;
                case 3:
                    ss << "4. Exit Browser\n";
                    menuOptions.push_back(4);
                    menuOption++;
                    break;
            }
        }
        std::cout << ss.str() << std::endl;
        ss.str(std::string());
        int userAnswer = menuOptions.at(inputInt("", menuOptions));
        menuOption = 1;
        switch (userAnswer)
        {
            case 1:
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
            case 2:
                //go back
                fwdStack.push(currentUrl);
                currentUrl = backStack.top();
                backStack.pop();
                currentUrl.displayFile();
                break;
            case 3:
                //go forward
                backStack.push(currentUrl);
                currentUrl = fwdStack.top();
                fwdStack.pop();
                currentUrl.displayFile();
                break;
            case 4:
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
}

int inputInt(std::string prompt, std::vector<int> options){
    int result;

    if(prompt.length() > 0){
        std::cout << prompt << std::endl; 
    }
    std::cin >> result; 

    while(!(std::find(options.begin(), options.end(), result) != options.end())) {
        std::cout << "That is an invalid choice.";
        resetStream();
        std::cin >> result;
    }

    for(int i = 0; i < options.size(); i++){
        if(options.at(i) == result){
            return i;
        }
    }
    
    throw;
}