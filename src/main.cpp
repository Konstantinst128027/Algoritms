#include <iostream>
#include <vector>
#include <string>
#include "Ascii85.h"

int main(int argc, char* argv[]) {
    bool decodeMode = false;

    // Парсинг аргументов командной строки
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-d") {
            decodeMode = true;
        } else if (arg != "-e") {
            std::cerr << "Usage: ascii85 [-d] [-e]" << std::endl;
            return 1;
        }
    }

    try {
        if (decodeMode) {
            // Режим декодирования
            std::string ascii85Data;
            char ch;
            while (std::cin.get(ch)) {
                ascii85Data += ch;
            }
            std::cout << std::endl;
            auto decodedData = decodeAscii85(ascii85Data);
            std::cout.write(reinterpret_cast<char*>(decodedData.data()), decodedData.size());
            std::cout << std::endl;
        } else {
            // Режим кодирования
            std::vector<unsigned char> data;
            char ch;
            while (std::cin.get(ch)) {
                data.push_back(ch);
            }
            std::cout << std::endl;
            auto encoded = encodeAscii85(data);
            std::cout << encoded << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
