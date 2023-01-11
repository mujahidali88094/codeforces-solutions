#include <bits/stdc++.h>

using namespace std;

/*
  Solution Explanation:
  ----------------------

  arr[j] - arr[i] = j - i
  implies arr[j] - j = arr[i] - i
  means the pairs of interest are those who satisfy above equation

  get unique differences and count occurences of each of them

  for each unique difference
  since pair should follow the condition i < j
  the result will be (count-1)+(count-2)+...+1

  add up for all the unique differences

*/

class FrequencyCounter
{
public:
  unordered_map<int, int> dictionary;
  void addOrUpdate(int n)
  {
    auto iterator = dictionary.find(n);
    if (iterator != dictionary.end())
    {
      iterator->second = iterator->second + 1;
    }
    else
    {
      dictionary.insert(make_pair(n, 1));
    }
  }
};
unsigned long long sumUpto(int n)
{
  unsigned long long answer;
  if (n % 2 == 0)
    answer = (unsigned long long)(n / 2) * (n + 1);
  else
    answer = (unsigned long long)((n + 1) / 2) * n;
  return answer;
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
    int arrayLength;
    cin >> arrayLength;
    int array[arrayLength];
    FrequencyCounter freqCounter;
    for (int i = 0; i < arrayLength; i++)
    {
      cin >> array[i];
      int differenceWithIndex = array[i] - i;
      freqCounter.addOrUpdate(differenceWithIndex);
    }

    unsigned long long answer = 0;
    for (auto it : freqCounter.dictionary)
    {
      int freq = it.second;
      answer += sumUpto(freq - 1);
    }
    cout << answer << endl;
  }
}