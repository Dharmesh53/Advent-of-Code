#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

int findNum(std::string word) {
  int i = 0, j = word.size() - 1;
  int num = 0;

  while(i <= j) {
    if(!(word[i] >= '0' && word[i] <= '9')) i++;
    else if(!(word[j] >= '0' && word[j] <= '9')) j--;
    else {
      num = (word[i] - '0') * 10 + word[j] - '0'; 
      break;
    }
  }

  return num;
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
    int num = findNum(line.c_str());
    ans += num;
  }

  std::cout << ans << std::endl;

  file.close();
  
  return 0;
}



/* 

Handling input file in the main function
Along with string stream

int main(int argc, char* argv[]) {
  std::stringstream ss;

  std::ifstream file("input1.txt");

  ss << file.rdbuf();

  std::string word;

  int ans = 0;

  while(ss >> word) {
    int num = findNum(word);
    ans += num;
  }
  std::cout << ans << std::endl;
  return 0;
}

*/
