#include "url.h"
#include "sstream"

url::url(std::string urlString, std::string filename):urlString(urlString), filename(filename)
{
    try{
        http::Request request{urlString};
        const auto response = request.send("GET");
        std::ofstream file(filename);
        file << std::string{response.body.begin(), response.body.end()} << '\n';
    } catch(const std::exception &e){
        std::cerr << "Request failed, error: " << e.what() << "\n";
    }
}

void url::displayFile(int maxLines){
    try{
        std::stringstream ss;
        std::ifstream file(filename);
        std::string line;
        int count = 0;
        while (std::getline(file, line) && (count < maxLines || maxLines == -1)){
            ss << line << std::endl;
            count++;
        }
        std::cout << ss.str() << std::endl;
    } catch(const std::exception &e){
        std::cerr << "Request failed, error: " << e.what() << "\n";
    }
}