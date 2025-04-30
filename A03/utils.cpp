#include <float.h>

#include "utils.hpp"

bool isPermutation(int* perm, int count)
{
  bool * idx = new bool [count]();

  for (int i = 0; i < count; i++)
  {
    if (perm[i] >= count || perm[i] < 0)
    {
      delete[] idx;
      return false;
    }
    
    if (idx[perm[i]])
    {
      delete[] idx;
      return false;
    }
    
    idx[perm[i]] = true;
  }

  for (int i = 0; i < count; i++)
  {
    if (!idx[i])
    {
      delete[] idx;
      return false;
    }
  }
  
  delete[] idx;
  return true;
}

bool isSorted(double* data, int dataCount, int* perm)
{
  double last = -DBL_MAX;
  for (int i = 0; i < dataCount; i++)
  {
    if (last > data[perm[i]])
      return false;
    
    last = data[perm[i]];
  }
  return true;
}