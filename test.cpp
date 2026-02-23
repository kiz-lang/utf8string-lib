import std;
import utf8;

int main() {
    // 测试 UTF8Char
    utf8::UTF8Char ch1(U'你');
    utf8::UTF8Char ch2('A');

    std::println("ch1: {}, 字节数: {}", ch1.to_string(), ch1.bytesize());
    std::println("ch2: {}, is_alpha: {}", ch2.to_string(), ch2.is_alpha());
    std::println("ch2 大写: {}", ch2.to_upper().to_string());

    // 测试 UTF8String
    utf8::UTF8String s(u8"Hello 你好世界 123");
    std::println("\n原串: {}", s);
    std::println("字符数: {}", s.size());
    std::println("字节数: {}", s.bytesize());

    // 子串、大小写、trim
    auto sub = s.substr(6, 2);
    std::println("substr(6,2): {}", sub);
    std::println("转大写: {}", s.to_upper());
    std::println("转小写: {}", s.to_lower());

    utf8::UTF8String s_space("  abc 你好  ");
    std::println("trim 前: '{}'", s_space);
    std::println("trim 后: '{}'", s_space.trim());

    // 遍历
    std::println("\n遍历:");
    for (const auto& c : s) {
        std::print("{} ", c);
    }
    std::println();
}