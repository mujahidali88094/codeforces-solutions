#include <bits/stdc++.h>

using namespace std;

int findMinIndex(vector<int> &arr)
{
  auto it = min_element(arr.begin(), arr.end());
  return distance(arr.begin(), it);
}
void printArray(vector<int> array)
{
  for (int i = 0; i < array.size(); i++)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
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
    vector<int> array;
    for (int i = 0; i < arrayLength; i++)
    {
      int temp;
      cin >> temp;
      array.push_back(temp);
    }
    sort(array.begin(), array.end());
    // printArray(array);
    vector<int> diff;
    diff.push_back(abs(array[0] - array[array.size() - 1]));
    for (int i = 1; i < array.size(); i++)
    {
      diff.push_back(abs(array[i] - array[i - 1]));
    }
    // printArray(diff);
    int noOfRotationsRequired = findMinIndex(diff);
    // cout << noOfRotationsRequired << endl;
    rotate(array.begin(), array.begin() + noOfRotationsRequired, array.end());
    printArray(array);
    // cout << "----" << endl;
  }
}