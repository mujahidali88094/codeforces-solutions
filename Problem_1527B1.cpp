#include <bits/stdc++.h>

using namespace std;

int main()
{
  // input from file
  std::ifstream in("input.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
  std::cin.rdbuf(in.rdbuf());

  int testCasesCount;
  cin >> testCasesCount;
  while (testCasesCount--)
  {
    int strLength;
    cin >> strLength;
    string str;
    cin >> str;

    int zeros = 0;
    for (int i = 0; i < strLength; i++)
    {
      if (str[i] == '0')
        zeros++;
    }

    if (zeros == 1 || zeros % 2 == 0)
    {
      cout << "BOB" << endl;
    }
    else
    {
      cout << "ALICE" << endl;
    }
  }
}
/*
SOLUTION EXPLANATION:
-----------------------

1) if there is one zero (obviously at middle), bob wins.
2) if there are even zeros:
  i) alice makes a 0 as 1
  ii) bob makes string palindrome
  ...
  n-1) if there is one 0, it will be bob's turn and he will reverse the string
  n) alice has to make last 0 as 1
  Result:
  bob wins as alice has to make last pay 1 extra dollar.

3) if there are odd zeros:
  i) alice makes middle 0 as 1
  ...
  gameplay will continue as scenerio 2 but alice and bob will interchange their roles
  Hence, alice wins.

*/
