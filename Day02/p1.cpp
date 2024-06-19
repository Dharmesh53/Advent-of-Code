#include<iostream>
#include<fstream>
#include<string>
#include<sstream>


int solver(std::string& line, std::string id) {
  std::stringstream ss(line);
  std::string segment;

  while(std::getline(ss, segment, ';')) {
    std::stringstream segmentStream(segment);
    std::string token;

    while(std::getline(segmentStream, token, ',')) {
      std::stringstream tokenStream(token);
      int number;
      std::string color;

      while(tokenStream >> number >> color) {
        if((color == "green" && number > 13) || (color == "blue" && number > 14) || (color == "red" && number > 12)) {
          return 0;
        }
      }
    }
  }
  return std::stoi(id);
}


int main(int argc, char* argv[]) {

  if(argc != 2) {
    std::cout << "Usage: " << argv[0] << " <input filename>" << std::endl; 
    return 1;
  }

  std::ifstream file(argv[1]);

  std::string line;

  if(!file.is_open()) {
    std::cout << "Failed to open the file" << std::endl;
    return 1;
  }

  int ans = 0;

  while(std::getline(file, line)) {
    size_t colon = line.find(':');
    std::string id = line.substr(5, colon - 5);
    line = line.substr(colon + 1);
    ans += solver(line, id);
  }

    std::cout << ans << std::endl;

  file.close();

  return 0;
}
