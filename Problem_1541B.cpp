#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(unsigned long long *arr, int len)
{
  unsigned long long pairs = 0;
  for (int i = 0; i < len; i++)
  {
    // cout << endl
    //      << arr[i] << ": ";
    int mutliplier = 1;
    unsigned long long product = arr[i] * mutliplier;
    long long j = product - (i + 1) - 1;
    while (j < len)
    {
      // cout << arr[i] << "x" << mutliplier << ", ";
      if (j > i && arr[j] == mutliplier)
      {
        pairs++;
        // cout << i + 1 << "+" << j + 1 << "=" << arr[i] << "x" << arr[j] << endl;
      }

      mutliplier++;
      product = arr[i] * mutliplier;
      j = product - (i + 1) - 1;
    }
    // cout << endl;
  }
  return pairs;
}

int main()
{
  // input from file
  // std::ifstream in("input.txt");
  // std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
  // std::cin.rdbuf(in.rdbuf());

  int testCasesCount;
  cin >> testCasesCount;
  while (testCasesCount--)
  {
    int len;
    cin >> len;
    unsigned long long arr[len];
    for (int i = 0; i < len; i++)
      cin >> arr[i];

    unsigned long long pairs = solve(arr, len);
    cout << pairs << endl;
  }
}
