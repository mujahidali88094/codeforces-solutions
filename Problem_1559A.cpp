#include <bits/stdc++.h>

using namespace std;

bool arrayHasSameElement(int *arr, int len)
{
  int firstElement = arr[0];
  for (int i = 1; i < len; i++)
    if (arr[i] != firstElement)
      return false;
  return true;
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
    int arrayLength;
    cin >> arrayLength;
    int array[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
      cin >> array[i];
    }

    int start, end;
    start = 0;
    end = arrayLength - 1;
    while (end > start)
    {
      for (int i = start; i <= end; i++)
      {
        array[i] = array[i] & array[end - i];
      }
      if (arrayHasSameElement(array, arrayLength))
        break;
      end = (end - start) / 2;
    }
    cout << array[0] << endl;
  }
}