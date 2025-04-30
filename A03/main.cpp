#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

template <typename T>
T * resizeArray(T * arr, int currSize, int newSize)
{
  T * tmp = new T [newSize]();
  memcpy(tmp, arr, std::min(currSize, newSize) * sizeof(T));
  delete[] arr;
  arr = tmp;
  return arr;
}

/* todo:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */
int main(int, char**) 
{
  int size      = 0;
  int cap       = 2;
  double * arr  = new double [cap]();

  while (1)
  {
    double tmp;
    std::cout << "Please input a double: ";
    std::cin >> tmp;
    if (!std::cin.fail())
    {
      std::cin.ignore();
      arr[size++] = tmp;
      if (size >= cap)
      {
        cap *= 2;
        arr = resizeArray(arr, size, cap);
      }
    }
    else
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "\nYou locked in array size " << size << ":\n{";
      for (int i = 0; i < size; i++)
      {
        std::cout << arr[i];
        if (i < size - 1)
        {
          std::cout << ", ";
        }
      }
      std::cout << "}" << std::endl;
      break;
    }
  }
  
  
  arr         = resizeArray(arr, cap, size);
  
  int * perm  = new int [size]();
  int idx     = 0;

  while(idx < size)
  {
    int tmp   =  0;
    std::cout << "Please input an integer (" << idx + 1 << "/" << size << "): ";
    std::cin  >> tmp;
    if (!std::cin.fail())
    {
      std::cin.ignore();
      perm[idx++] = tmp;
    }
    else
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "That was not an integer dumbass!" << std::endl;
      continue;
    }
  }

  if (isPermutation(perm, size))
  {
    if (isSorted(arr, size, perm))
    {
      std::cout << "Input was a sorted permutation!" << std::endl;
    }
    else
    {
      std::cout << "Input was an unsorted permutation!" << std::endl;
    }
  }
  else
  {
    std::cout << "Input was no permutation!" << std::endl;
  }

  delete[] arr;
  delete[] perm;
}
