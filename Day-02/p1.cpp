#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> &vt) {
  for (auto num : vt) {
    cout << num << " ";
  }
  cout << "\n";
}

auto isIncreasing = [](int a, int b) -> bool { return a < b; };

auto isDecreasing = [](int a, int b) -> bool { return a > b; };

auto isEqual = [](int a, int b) -> bool { return a == b; };

auto inRange = [](int a, int b) -> bool {
  int diff = abs(a - b);
  return diff >= 1 && diff <= 3;
};

bool isSafe(vector<int> &nums) {
  if (nums.size() == 1)
    return true;

  if (isEqual(nums[0], nums[1]) || !inRange(nums[0], nums[1])) {
    return false;
  }

  bool isArrayIncreasing = nums[0] < nums[1];

  for (int i = 2; i < nums.size(); i++) {
    if (!inRange(nums[i], nums[i - 1])) {
      return false;
    }

    if ((nums[i] == nums[i - 1]) ||
        (isDecreasing(nums[i - 1], nums[i]) && isArrayIncreasing) ||
        (isIncreasing(nums[i - 1], nums[i]) && !isArrayIncreasing)) {
      return false;
    }
  }

  print(nums);

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
