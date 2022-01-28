#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double x, y, r;
  Solution(double radius, double x_center, double y_center)
  {
    x = x_center;
    y = y_center;
    r = radius;
  }

  vector<double> randPoint()
  {
    double randNum = (double)rand() / RAND_MAX;
    randNum = sqrt(randNum);
    double randRadi = randNum * r;

    randNum = (double)rand() / RAND_MAX;
    double randAngle = randNum * 360;
    return {x + (randRadi * cos(randAngle)), y + (randRadi * sin(randAngle))};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */