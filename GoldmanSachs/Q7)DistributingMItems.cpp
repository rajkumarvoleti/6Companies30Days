#include <iostream>
using namespace std;

int main()
{
  int sizeOfCircle, numberOfItems, startingPosition;
  cin >> sizeOfCircle >> numberOfItems >> startingPosition;
  int ans = (numberOfItems % sizeOfCircle) + startingPosition - 1;
  cout << ans << endl;
}