#include "Ascii85.h"

#include <stdexcept> // обрабатываем ошибку
#include <cstdint> // используем uint32_t
#include <algorithm> // используем reverse

// Функция для кодирования данных в ASCII85
std::string encodeAscii85(std::vector<unsigned char>& data) {
    std::string output;
    size_t i = 0;

    while (i < data.size()) {
        // Собираем 4 байта для кодирования
        uint32_t value = 0;
        int count = 0;

        for (int j = 0; j < 4; j++) {
            if (i < data.size()) {
                value |= static_cast<uint32_t>(data[i]) << (8 * (3 - j));
                i++;
                count++;
            }
        }
        // Кодируем в ASCII85
        if (value == 0 and count == 4) {
            output += 'z'; // Специальный случай для 4 нулевых байтов
        } else {
            std::string ascii85;
            for (int j = 4; j >= 0; j--) {
                ascii85 += '!' + (value % 85);
                value /= 85;
            }
            // Добавляем только необходимое количество символов
            std::reverse(ascii85.begin(), ascii85.end()); // Переворачиваем строку
            
            if (count < 4) {
                ascii85.resize(count + 1); 
            }
            output += ascii85;
        }
    }
    return output;
}

// Функция для декодирования ASCII85
std::vector<unsigned char> decodeAscii85(std::string& input) {
    std::vector<unsigned char> output;
    uint32_t value = 0;
    int count = 0;

    for (char ch : input) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
            // Пропуск пробельных символов
            continue;
        }
        else if (ch == 'z' and count == 0) {
            // Специальный случай: "z" представляет 4 нулевых байта
            output.insert(output.end(), 4, 0);
        } else if (ch >= '!' and ch <= 'u') {
            // Преобразуем символ в значение от 0 до 84
            value = value * 85 + (ch - '!'); // Так как мы переворачиваем значит самый первый самый старший
            count++;

            // Когда накопилось 5 символов, преобразуем в 4 байта
            if (count == 5) {
                for (int i = 3; i >= 0; i--) {
                    output.push_back(static_cast<unsigned char>((value >> (8 * i)) & 0xFF));
                }
                value = 0;
                count = 0;
            }
        } else {
            throw std::runtime_error("Invalid ASCII85 character");
        }
    }
    // Обработка оставшихся символов
    if (count > 0) {
        for (int i = 0; i < 5 - count; i++) {
            value = value * 85 + 84; // Дополняем 'u' (84)
        }
        for (int i = 3; i > 4 - count; i--) {
            output.push_back(static_cast<unsigned char>((value >> (8 * i)) & 0xFF));
        }
    }

    return output;
}

