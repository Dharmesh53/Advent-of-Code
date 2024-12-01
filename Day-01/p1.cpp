#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void solver(priority_queue<int, vector<int>> &first,
            priority_queue<int, vector<int>> &second) {
  int ans = 0;

  while (!first.empty()) {
    int t1 = first.top();
    int t2 = second.top();

    ans += abs(t2 - t1);

    first.pop();
    second.pop();
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
  priority_queue<int, vector<int>> first, second;

  while (file >> line) {
    pair<int, int> nums = getTwoNumber(line);
    first.push(nums.first);
    second.push(nums.second);
  }

  solver(first, second);

  file.close();

  return 0;
}
