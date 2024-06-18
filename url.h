#ifndef URL_H
#define URL_H
#include <string>
#include <fstream>
#include <iostream>
#include "HTTPRequest.hpp"

class url {
    public:
	    url(std::string urlString, std::string filename);
        void displayFile(int maxLines = -1);
    private:
        std::string filename;
        std::string urlString;
};

#endif