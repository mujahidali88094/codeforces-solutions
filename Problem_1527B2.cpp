#include <bits/stdc++.h>

using namespace std;

int ALICE = 0;
int BOB = 1;
string names[] = {"ALICE", "BOB"};

int getOppositePlayer(int currentPlayer)
{
  return currentPlayer == ALICE ? BOB : ALICE;
}
int getNoOfMovesToMakePalindrome(string &str)
{
  int len = str.length();
  if (len < 2)
    return 0;

  int startOfSecondHalf = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);

  string firstHalf = str.substr(0, len / 2);
  string otherHalf = str.substr(startOfSecondHalf);
  reverse(otherHalf.begin(), otherHalf.end());

  int moves = 0;
  for (int i = 0; i < len / 2; i++)
    if (firstHalf[i] != otherHalf[i])
      moves++;

  return moves;
}
void makePalindrome(string &str)
{
  int len = str.length();
  for (int i = 0, j = len - 1; i < len / 2; i++, j--)
    if (str[i] != str[j])
      if (str[i] == '0')
        str[i] = '1';
      else
        str[j] = '1';
}
bool isPalindrome(string str)
{
  return getNoOfMovesToMakePalindrome(str) == 0;
}
int countZeros(string &str)
{
  int zeros = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '0')
      zeros++;
  }
  return zeros;
}
void playFromPalindrome(int zeros, int turnHolder, int dollarsPaid[])
{
  // cout << "Dollars Paid: " << dollarsPaid[ALICE] << ", " << dollarsPaid[BOB] << endl;

  if (zeros == 0)
    return;
  if (zeros == 1)
  {
    dollarsPaid[turnHolder]++;
    return;
  }
  if (zeros % 2 == 0)
  {
    // when zeros are greater than 2
    dollarsPaid[turnHolder] += ((zeros - 2) / 2);
    dollarsPaid[getOppositePlayer(turnHolder)] += ((zeros - 2) / 2);
    // for last 2 zeros
    dollarsPaid[turnHolder] += 2;
    return;
  }
  dollarsPaid[turnHolder] += 1;
  // str[str.length() / 2 + 1] = '1';
  playFromPalindrome(zeros - 1, getOppositePlayer(turnHolder), dollarsPaid);
  return;
}
void play(string &str, int turnHolder, int dollarsPaid[])
{
  int moves = getNoOfMovesToMakePalindrome(str);
  bool isPalindrome = moves == 0;

  if (isPalindrome)
  {
    playFromPalindrome(countZeros(str), turnHolder, dollarsPaid);
    return;
  }
  // else
  makePalindrome(str);
  int turnHolderMoves = 0, oppositePlayerMoves = 0;
  int remainingZeros = countZeros(str);
  // cout << "RZ:" << remainingZeros << endl;
  if (remainingZeros % 2 == 0 && remainingZeros != 0)
  {
    dollarsPaid[turnHolder] += 1;
    dollarsPaid[getOppositePlayer(turnHolder)] += moves - 1;
    playFromPalindrome(remainingZeros, getOppositePlayer(turnHolder), dollarsPaid);
  }
  else
  {
    dollarsPaid[turnHolder] += 0;
    dollarsPaid[getOppositePlayer(turnHolder)] += moves;
    playFromPalindrome(remainingZeros, turnHolder, dollarsPaid);
  }
  return;
}
void printWinner(int dollarsPaid[])
{
  if (dollarsPaid[ALICE] < dollarsPaid[BOB])
  {
    cout << names[ALICE] << endl;
  }
  else if (dollarsPaid[BOB] < dollarsPaid[ALICE])
  {
    cout << names[BOB] << endl;
  }
  else
  {
    cout << "DRAW" << endl;
  }

  // cout << "Dollars Paid: " << dollarsPaid[ALICE] << ", " << dollarsPaid[BOB] << endl;
  // cout << endl;
}

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

    int dollarsPaid[] = {0, 0};
    play(str, ALICE, dollarsPaid);
    printWinner(dollarsPaid);
  }
}
/*
SOLUTION EXPLANATION :
-----------------------

IF PALINDROME:
--------------
0) if there is no zeros, Alice wins.
1) if there is one zero (obviously at middle), bob wins.
2) if there are even zeros:
  i) alice makes a 0 as 1
  ii) bob makes string palindrome
  ...
  n-1) if there is one 0, it will be bob's turn and he will reverse the string
  n) alice has to make last 0 as 1
  Result:
  bob wins as alice has to pay 2 more dollars than bob.

3) if there are odd zeros:
  i) alice makes middle 0 as 1
  ...
  gameplay will continue as scenerio 2 but alice and bob will interchange their roles
  Hence, alice wins.



IF NOT PALINDROME:
-----------------
until it is a palindrome:

  if remaning zeros in the palindrome favours alice
  alice can just reverse the string and make bob do all the 0s as 1s

  else
  alice will make last 0 as 1 herself, before that she can just reverse

*/
