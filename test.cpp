#include <gtest/gtest.h>
#include "core.hpp"

// 示例测试 1: 测试 ASCII 字符
TEST(UTF8CharTest, AsciiCharacter) {
    utf8::UTF8Char ch('A');
    EXPECT_EQ(ch.bytesize(), 1);
    EXPECT_EQ(ch.to_cod_point(), 0x41);
    EXPECT_TRUE(ch.is_alpha());
    EXPECT_FALSE(ch.is_digit());
}

// 示例测试 2: 测试中文字符 (UTF-8 3字节)
TEST(UTF8CharTest, ChineseCharacter) {
    // "好" 的 UTF-8 编码是 E5 A5 BD
    const char* buf = "\xE5\xA5\xBD";
    utf8::UTF8Char ch(buf, 3);
    EXPECT_EQ(ch.bytesize(), 3);
    EXPECT_EQ(ch.to_cod_point(), 0x597D); // "好" 的 Unicode
    EXPECT_TRUE(ch.is_alpha()); // 你的 is_alpha 包含了 CJK
}

// 示例测试 3: 测试字符串拼接
TEST(UTF8StringTest, Concatenation) {
    utf8::UTF8String s1("Hello");
    utf8::UTF8String s2(" World");
    utf8::UTF8String s3 = s1 + s2;
    EXPECT_EQ(s3.to_string(), "Hello World");
    EXPECT_EQ(s3.size(), 11); // 字符数
}