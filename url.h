#ifndef URL_H
#define URL_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "HTTPRequest.hpp"

class url {
    public:
        url() = default;
	    url(std::string url, std::string fname);
        void displayFile(int maxLines = -1);
    private:
        std::string filename;
        std::string urlString;
};

// url::url(std::string urlString, std::string filename):urlString(urlString), filename(filename)
// {
//     try{
//         http::Request request{urlString};
//         const auto response = request.send("GET");
//         std::ofstream file(filename);
//         file << std::string{response.body.begin(), response.body.end()} << '\n';
//         file.close();
//     } catch(const std::exception &e){
//         std::cerr << "Request failed, error: " << e.what() << "\n";
//     }
// }

// void url::displayFile(int maxLines){
//     try{
//         std::stringstream ss;
//         std::ifstream file(filename);
//         std::string line;
//         int count = 0;
//         while (std::getline(file, line) && (count < maxLines || maxLines == -1)){
//             ss << line << std::endl;
//             count++;
//         }
//         std::cout << ss.str() << std::endl;
//         file.close();
//     } catch(const std::exception &e){
//         std::cerr << "Request failed, error: " << e.what() << "\n";
//     }
// }

#endif