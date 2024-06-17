#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cctype>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::string;
using std::vector;

typedef struct {
  std::string str;
  int num;
} lookup;

lookup map[18] = {
  { std::string("one"), 1 },
  { std::string("two"), 2 },
  { std::string("three"), 3 },
  { std::string("four"), 4 },
  { std::string("five"), 5 },
  { std::string("six"), 6 },
  { std::string("seven"), 7 },
  { std::string("eight"), 8 },
  { std::string("nine"), 9 },
  { std::string("1"), 1 },
  { std::string("2"), 2 },
  { std::string("3"), 3 },
  { std::string("4"), 4 },
  { std::string("5"), 5 },
  { std::string("6"), 6 },
  { std::string("7"), 7 },
  { std::string("8"), 8 },
  { std::string("9"), 9 }
};

int match(std::string& slice) {
  for (int i = 0; i < 18; i++) {
    if (!map[i].str.compare(slice)) {
      return map[i].num;
    }
  }
  return -1;
}

int solver(std::ifstream& file) {
  std::string line;
  int temp = 0;
  while (std::getline(file, line)) {
    std::string word = std::string(line);
    std::vector<int> foundDigits;

    for (int windowStart = 0; windowStart < word.size(); windowStart++) {
      int windowEnd = windowStart + 1;

      while (windowEnd <= word.size()) {
        std::string window = word.substr(windowStart, windowEnd - windowStart);

        int matchedNum = match(window);
        if (matchedNum != -1) {
          foundDigits.push_back(matchedNum);
          break;
        }
        windowEnd++;
      }
    }

    std::vector<int> finalNums;
    if (foundDigits.size() > 1) {
      finalNums.push_back(foundDigits[0] * 10 + foundDigits[foundDigits.size() - 1]);
    } else if (foundDigits.size() == 1) {
      finalNums.push_back(foundDigits[0] * 10 + foundDigits[0]);
    }

    for (int i = 0; i < finalNums.size(); i++) temp += finalNums[i];
  }

  return temp;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <input filename>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);

  if (!file.is_open()) {
    std::cout << "Failed to open the file" << std::endl;
    return 1;
  }

  auto t1 = high_resolution_clock::now();

  int ans = solver(file);

  file.close();

  std::cout << ans << std::endl;

  auto t2 = high_resolution_clock::now();

  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  std::cout << "Runtime: " << ms_int.count() << "ms" << std::endl;

  return 0;
}

