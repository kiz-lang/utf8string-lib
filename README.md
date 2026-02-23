# utf8string-lib
A modern C++23 library for safe, convenient UTF-8 string & character handling.

## Features
- Complete `UTF8Char` & `UTF8String` types
- Full Unicode-aware operations:
  - Character classification (`is_alpha`, `is_digit`, `is_space`, etc.)
  - Case conversion (`to_upper`, `to_lower`)
  - Substring, trim, concatenation, comparison
  - Iteration & index access by **Unicode code points**
- Zero-overhead view-like design
- Clean C++23 module interface
- No external dependencies

## Requirements
- C++23 or later
- Compiler with modules support:
  - GCC 14+
  - Clang 17+
  - MSVC (VS 2022)

## How to Compile & Test
```bash
g++ -std=c++23 -fmodules core.hpp test.cpp -o test
./test
```

## Usage Example
```cpp
import std;
import utf8;

int main() {
    utf8::UTF8String str(u8"Hello 你好 🌍");
    std::println("{}", str);
    std::println("length (code points): {}", str.size());
}
```

## Authors
- **azhz1107cat**
- **Satklomi**

## License
MIT