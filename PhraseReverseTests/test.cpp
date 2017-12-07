#include "pch.h"
#include <vector>
#include "../PhraseReverse/phrase_reverse.h"

using namespace phrase_reverse;

TEST(PhraseReverse, emptyString) {
  const std::string empty;
  EXPECT_EQ(reverse(empty), empty);
  EXPECT_EQ(reverseWords(empty), empty);
  EXPECT_EQ(reverseWordOrder(empty), empty);
  EXPECT_EQ(reverseFirstN(empty, 0), empty);
}

TEST(PhraseReverse, singleLetter) {
  const std::string a("a");
  EXPECT_EQ(reverse(a), a);
  EXPECT_EQ(reverseWords(a), a);
  EXPECT_EQ(reverseWordOrder(a), a);
  EXPECT_EQ(reverseFirstN(a, 0), a);
  EXPECT_EQ(reverseFirstN(a, 1), a);
  EXPECT_EQ(reverseFirstN(a, 2), a);
  EXPECT_EQ(reverseFirstN(a, a.length() + 1), a);
}

TEST(PhraseReverse, singleWord) {
  const std::string abc("abc");
  const std::string cba("cba");
  EXPECT_EQ(reverse(abc), cba);
  EXPECT_EQ(reverseWords(abc), cba);
  EXPECT_EQ(reverseWordOrder(abc), abc);
  EXPECT_EQ(reverseFirstN(abc, 0), abc);
  EXPECT_EQ(reverseFirstN(abc, 1), abc);
  EXPECT_EQ(reverseFirstN(abc, abc.length() + 4), cba);
}

TEST(PhraseReverse, twoWords) {
  const std::string abcDef("abc def");
  const std::string defAbc("def abc");
  const std::string fedCba("fed cba");
  const std::string cbaFed("cba fed");
  const std::string cbaDef("cba def");
  EXPECT_EQ(reverse(abcDef), fedCba);
  EXPECT_EQ(reverseWords(abcDef), cbaFed);
  EXPECT_EQ(reverseWordOrder(abcDef), defAbc);
  EXPECT_EQ(reverseFirstN(abcDef, 3), cbaDef);
  // EXPECT_EQ(reverseFirstN(abcDef, 4), abc); what should happen?
}