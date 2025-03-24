#include <gtest/gtest.h>
#include <sstream>
#include "Ascii85.h"
// с 1 буквой в остатке
TEST(DecodeAscii85_Test, DecodeTest_1) {
    std::istringstream input_1("87cURDZ");
    std::string input;
    char ch;
    while (input_1.get(ch)) {
        input += ch;
    }
    auto output_1 = decodeAscii85(input);
    std::string output;
    for (char ch: output_1) {
        output += ch;
    }
    EXPECT_EQ(output, "Hello");
}
// с 2 буквами в остатке
TEST(DecodeAscii85_Test, DecodeTest_2) {
    std::istringstream input_1("7WN3SDI`");
    std::string input;
    char ch;
    while (input_1.get(ch)) {
        input += ch;
    }
    auto output_1 = decodeAscii85(input);
    std::string output;
    for (char ch: output_1) {
        output += ch;
    }
    EXPECT_EQ(output, "Friend");
}
// с 3 буквами в остатке
TEST(DecodeAscii85_Test, DecodeTest_3) {
    std::istringstream input_1("6=F>4Ch7V");
    std::string input;
    char ch;
    while (input_1.get(ch)) {
        input += ch;
    }
    auto output_1 = decodeAscii85(input);
    std::string output;
    for (char ch: output_1) {
        output += ch;
    }
    EXPECT_EQ(output, "Babbler");
}
// с 4 буквами в остатке
TEST(DecodeAscii85_Test, DecodeTest_4) {
    std::istringstream input_1("9keWVDI[@&");
    std::string input;
    char ch;
    while (input_1.get(ch)) {
        input += ch;
    }
    auto output_1 = decodeAscii85(input);
    std::string output;
    for (char ch: output_1) {
        output += ch;
    }
    EXPECT_EQ(output, "Miranchu");
}
TEST(DecodeAscii85_Test, DecodeTest_5) {
    std::istringstream input_1("z");
    std::string input;
    char ch;
    while (input_1.get(ch)) {
        input += ch;
    }
    auto output_1 = decodeAscii85(input);

    // Ожидаемый результат: 4 нулевых байта
    std::vector<unsigned char> expected_output = {0, 0, 0, 0};

    // Проверяем результат
    EXPECT_EQ(output_1, expected_output);
}

