#include "scopetimer.hpp"

using namespace std;

ScopeTimer::ScopeTimer(const char* name)
{
  this->start_t = clock();
  this->name    = name;
  cout << "Timer '" << name << "' started!" << endl;
}

ScopeTimer::~ScopeTimer()
{
  clock_t end_t = clock();
  cout << "Timer '" << name << "' stopped!" << endl;
  cout << "Runtime: " << ((double)(end_t - start_t) / CLOCKS_PER_SEC) << "s!" << endl;
}