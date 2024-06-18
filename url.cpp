#include "url.h"

url::url(std::string urlString, std::string filename):urlString(urlString), filename(filename)
{
    try{
        http::Request request{"http:://test.com/test"};

        const auto response = request.send("GET");
        std::cout << std::string{response.body.begin(), response.body.end()} << '\n';
        std::ofstream
        file(filename);
        file << std::string{response.body.begin(), response.body.end()} << '\n';
    } catch(const std::exception &e){
        std::cerr << "Request failed, error: " << e.what() << "\n";
    }
};

void url::displayFile(int maxLines = -1){
    std::ifstream
    file(filename);
    std::string line;
    int count = 0;
    while (std::getline(file, line) && (count < maxLines || maxLines == -1)){
        std::cout << line << std::endl;
        count++;
    }
}