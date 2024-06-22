#include "url.h"
#include "sstream"

url::url(std::string urlString, std::string filename):urlString(urlString), filename(filename)
{
    try{
        //make http request and write result to file
        http::Request request{urlString};
        const auto response = request.send("GET");
        std::ofstream file(filename);
        file << std::string{response.body.begin(), response.body.end()} << '\n';
        file.close();
    } catch(const std::exception &e){
        std::cerr << "Request failed, error: " << e.what() << "\n";
    }
}

void url::displayFile(int maxLines){
    try{
        //read file line by line and to stringstream
        std::stringstream ss;
        std::ifstream file(filename);
        std::string line;
        int count = 0;
        while (std::getline(file, line) && (count < maxLines || maxLines == -1)){
            ss << line << std::endl;
            count++;
        }
        file.close();
        std::cout << ss.str() << std::endl;
    } catch(const std::exception &e){
        std::cerr << "Request failed, error: " << e.what() << "\n";
    }
}