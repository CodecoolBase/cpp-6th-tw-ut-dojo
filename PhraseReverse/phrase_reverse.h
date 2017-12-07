#pragma once

#include <string>
class A
{
public:
  int a;
  void foo();
};
namespace phrase_reverse {

std::string reverse(const std::string &);

std::string reverseWords(const std::string &);

std::string reverseWordOrder(const std::string &);

std::string reverseFirstN(const std::string &, const size_t);
}
