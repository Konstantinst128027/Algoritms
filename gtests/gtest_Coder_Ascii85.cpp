#include <gtest/gtest.h>
#include <sstream>
#include "Ascii85.h"
// с 1 буквой в остатке
TEST(EncodeAscii85_Test, EncodeTest_1) {
    std::istringstream input_1("Hello");
    std::vector <unsigned char> input;
    char ch;
    while (input_1.get(ch)) {
        input.push_back(ch);
    }
    std::string output = encodeAscii85(input);
    EXPECT_EQ(output, "87cURDZ");
}
// с 2 буквами в остатке
TEST(EncodeAscii85_Test, EncodeTest_2) {
    std::istringstream input_1("Friend");
    std::vector <unsigned char> input;
    char ch;
    while (input_1.get(ch)) {
        input.push_back(ch);
    }
    std::string output = encodeAscii85(input);
    EXPECT_EQ(output, "7WN3SDI`");
}
// с 3 буквами в остатке
TEST(EncodeAscii85_Test, EncodeTest_3) {
    std::istringstream input_1("Babbler");
    std::vector <unsigned char> input;
    char ch;
    while (input_1.get(ch)) {
        input.push_back(ch);
    }
    std::string output = encodeAscii85(input);
    EXPECT_EQ(output, "6=F>4Ch7V");
}
// с 4 буквами в остатке
TEST(EncodeAscii85_Test, EncodeTest_4) {
    std::istringstream input_1("Miranchu");
    std::vector <unsigned char> input;
    char ch;
    while (input_1.get(ch)) {
        input.push_back(ch);
    }
    std::string output = encodeAscii85(input);
    EXPECT_EQ(output, "9keWVDI[@&");
}
//  Тест для нулевого вектора
TEST(EncodeAscii85_Test, EncodeTest_5) {
    std::vector <unsigned char> input = {0, 0, 0, 0};
    
    std::string output = encodeAscii85(input);
    EXPECT_EQ(output, "z");
}
