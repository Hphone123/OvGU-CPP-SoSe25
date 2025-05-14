#include "Iteration.hpp"
#include "Array.hpp"

template<typename T> class List : public Iterable<T>
{
public:

  virtual void  add   (T item);   = 0;
  virtual T     remove();         = 0;

  virtual T&    operator[](int idx);  //Same as at()
  virtual T&    at(int idx);          // Same as []
};

template <typename T> class ArrayList : public List<T>
{
protected:
  DynamicArray<T> arr;

public:
  ArrayList<T>()
  {
    arr = DynamicArray<T>();
  }

  void add (T item)
  {
    arr.add(item);
  }
};