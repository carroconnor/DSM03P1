#include "helpers.h"

void helpers::resetStream(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

int helpers::inputInt(std::string prompt, int min, int max){
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
        helpers::resetStream();
        std::cin >> result;
    }

    return result;
}

std::string helpers::trim(const std::string &str,
                            const std::string &whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}