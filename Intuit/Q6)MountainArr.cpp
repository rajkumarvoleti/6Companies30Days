

class Solution
{
public:
  int findInMountainArray(int target, MountainArray &arr)
  {
    int length = arr.length();
    int start = 0, end = length - 1;

    while (start < end)
    {
      int mid = (start + end) / 2;
      if (arr.get(mid) < arr.get(mid + 1))
        start = mid + 1;
      else
        end = mid - 1;
    }
    int peak = start;

    start = 0;
    end = peak;
    while (start <= end)
    {
      int mid = (start + end) / 2;
      int midVal = arr.get(mid);
      if (midVal == target)
        return mid;
      else if (midVal < target)
        start = mid + 1;
      else
        end = mid - 1;
    }

    start = peak + 1;
    end = length - 1;
    while (start <= end)
    {
      int mid = (start + end) / 2;
      int midVal = arr.get(mid);
      if (midVal == target)
        return mid;
      else if (midVal > target)
        start = mid + 1;
      else
        end = mid - 1;
    }
    return -1;
  }
};