#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<unordered_map>

const std::unordered_map<std::string, int> mp = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

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

