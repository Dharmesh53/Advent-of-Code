#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<int> &nums) {
  if (nums.size() == 1)
    return true;

  bool isIncreasing = nums[0] < nums[1];

  for (int i = 2; i < nums.size(); i++) {
    if ((nums[i] < nums[i - 1] && isIncreasing) ||
        (nums[i] > nums[i - 1] && !isIncreasing)) {
      return false;
    }

    if ((abs(nums[i] - nums[i - 1]) < 1) || (abs(nums[i] - nums[i - 1]) > 3)) {
      return false;
    }
  }

  return true;
}

vector<int> getNumbersFromString(string &line) {
  vector<int> nums;

  int i = 0, num = 0;

  while (i < line.length()) {
    if (line[i] != ' ') {
      num = num * 10 + (line[i] - '0');
    } else {
      nums.push_back(num);
      num = 0;
    }

    i++;
  }

  nums.push_back(num);

  return nums;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Usage:" << argv[0] << " <input filename>" << "\n";
    exit(1);
  }

  ifstream file(argv[1]);

  string line;
  int ans = 0;

  while (getline(file, line)) {
    vector<int> arr = getNumbersFromString(line);
    ans += isSafe(arr);
  }

  cout << ans << "\n";

  return 0;
}
