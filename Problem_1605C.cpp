#include <bits/stdc++.h>

using namespace std;

bool isValid(int freq[])
{
  return (freq[0] > freq[1] and freq[0] > freq[2]);
}
int getMinLen(string str, int strLength)
{
  int minimum = INT_MAX;

  int left = 0, right = strLength - 1;

  // skip leading b's and c's
  while (left < strLength and str[left] != 'a')
  {
    left++;
  }
  if (left == strLength - 1)
    return -1;

  // skip trailing b's and c's
  while (right >= left and str[right] != 'a')
  {
    right--;
  }
  if (left == right)
    return -1;

  // brute force
  for (int i = left; i <= right; i++)
  {
    int freq[3] = {0}; // frequencies of elements
    freq[str[i] - 'a']++;
    for (int j = i + 1; j < i + 7 and j <= right; j++)
    {
      freq[str[j] - 'a']++;
      if (isValid(freq))
      {
        minimum = min(minimum, j - i + 1);
      }
    }
  }

  if (minimum == INT_MAX)
    return -1;
  return minimum;
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

    cout << getMinLen(str, strLength) << endl;

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
