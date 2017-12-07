#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "phrase_reverse.h"

void A::foo()
{
  a = 8;
}

namespace {
// use the fact that input streams are delimeted on whitespace
const std::vector<std::string> split(const std::string &s) {
  std::istringstream ss{s};
  return std::move(
      std::vector<std::string>(std::istream_iterator<std::string>{ss},
                               std::istream_iterator<std::string>{}));
}

std::string join(const std::vector<std::string> &words) {
  std::ostringstream ss;
  ss << words.front();
  std::for_each(++words.cbegin(), words.cend(),
                [&ss](const std::string &word) { ss << " " << word; });
  return std::move(ss.str());
}
}

namespace phrase_reverse {

std::string reverse(const std::string &s) {
  std::string res{s};
  std::reverse(res.begin(), res.end());
  return std::move(res);
}

std::string reverseWords(const std::string &s) {
  std::vector<std::string> words;
  for (auto &word : ::split(s)) {
    words.emplace_back(reverse(word));
  }
  return std::move(::join(words));
}

std::string reverseWordOrder(const std::string &s) {
  std::vector<std::string> words{::split(s)};
  std::reverse(words.begin(), words.end());
  return std::move(::join(words));
}

std::string reverseFirstN(const std::string &s, const size_t n) {
  std::ostringstream ss;
  const size_t split_pos = n;
  ss << reverse(s.substr(0, split_pos)) << s.substr(split_pos);
  return std::move(ss.str());
}
}
