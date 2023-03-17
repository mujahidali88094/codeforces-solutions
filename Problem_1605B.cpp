#include <bits/stdc++.h>

using namespace std;

void print(vector<int> solution)
{
  if (solution.size() > 0)
    cout << "1" << endl;
  cout << solution.size() << " ";
  for (int i = 0; i < solution.size(); i++)
  {
    cout << solution[i] << " ";
  }
  cout << endl;
}
void solve(string s, int n)
{
  vector<int> solution;
  int left = 0;
  int right = n - 1;
  while (left < right)
  {
    if (s[left] == '1')
    {
      while (s[right] != '0' and right > left)
      {
        right--;
      }
      if (right == left)
      {
        break;
      }
      solution.push_back(left + 1);
      solution.push_back(right + 1);
      left++;
      right--;
    }
    else
    {
      left++;
    }
  }
  sort(solution.begin(), solution.end());
  print(solution);
}
int main()
{
  // input from file
  // std::ifstream in("input.txt");
  // std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
  // std::cin.rdbuf(in.rdbuf());

  int testCasesCount;
  cin >> testCasesCount;
  int i = 1;
  while (i <= testCasesCount)
  {
    int strLength;
    cin >> strLength;
    string str;
    cin >> str;

    solve(str, strLength);

    i++;
  }
}
/*
SOLUTION EXPLANATION:
-----------------------
1) A Valid string will start and end with a if it is Minimum
2) Minimum longest substring will be "abbacca" or "accabba"

So brute force all substrings of length 7

*/
