#include "immstring.hpp"

// Functions from <cstring> may be used to ease working with 
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>

namespace Util {

// NOTE: Compiler errors related to this constructor provide hints to
//        where else you need to use `const`.
ImmutableString::ImmutableString(const ImmutableString& other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size+1]} 
{
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other.c_str(), m_size + 1, m_data);
}

ImmutableString::ImmutableString(const char* const src) 
        : m_size{(int)strlen(src)},
          m_data{new char [m_size+1]}
{
  std::copy_n(src, m_size + 1, m_data);
}

ImmutableString ImmutableString::concat(const ImmutableString other) const
{
  char * strres = new char [this->size() + other.size() + 2]();
  strcpy(strres, this->c_str());
  strcat(strres, other.c_str());
  return ImmutableString(strres, this->m_size + other.size());
}

ImmutableString::~ImmutableString() {
  delete[] this->m_data;
}

ImmutableString::ImmutableString(char* buf, int len) 
        : m_size{len},
          m_data{buf}
{};

} // Util
