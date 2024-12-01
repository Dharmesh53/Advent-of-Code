#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void solver(unordered_map<int, int> &map, vector<int> &nums) {
  int ans = 0;

  for (auto &x : nums) {
    int count = map[x];
    x = x * count;
    ans += x;
  }

  cout << ans << "\n";
}

pair<int, int> getTwoNumber(string &str) {
  int i = 0;
  int num = 0;
  pair<int, int> nums;

  while (i < str.length()) {
    if (str[i] != ' ') {
      num = num * 10 + (str[i] - '0');
    } else {
      if (!nums.first) {
        nums.first = num;
      }
      num = 0;
    }
    i++;
  }

  nums.second = num;

  return nums;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <input filename>" << endl;
    return 1;
  }

  ifstream file(argv[1]);

  string line;
  unordered_map<int, int> map;
  vector<int> vt;

  while (getline(file, line)) {
    pair<int, int> nums = getTwoNumber(line);
    vt.push_back(nums.first);
    map[nums.second]++;
  }

  solver(map, vt);

  file.close();

  return 0;
}
