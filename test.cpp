#include <gtest/gtest.h>

import utf8;

TEST(UTF8CharTest, Ascii) {
  utf8::UTF8Char c{'A'};
  EXPECT_EQ(c.bytesize(), 1);
  EXPECT_EQ(c.to_cod_point(), 'A');
}

TEST(UTF8CharTest, Chinese) {
  const char buf[] = "\xE4\xB8\xAD";
  utf8::UTF8Char c{buf, 3};
  EXPECT_EQ(c.bytesize(), 3);
  EXPECT_EQ(c.to_cod_point(), 0x4E2D);
}

TEST(UTF8StringTest, Basic) {
  utf8::UTF8String s{"Hello UTF8"};
  EXPECT_FALSE(s.empty());
}