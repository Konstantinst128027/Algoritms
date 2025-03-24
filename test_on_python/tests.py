from function_ascii85 import *
def run_tests():
    """Запускает все тесты"""
    print("=== Starting tests ===")
    
    # Тест 1: Кодирование и декодирование короткой строки
    print("\nTest 1: Basic encoding/decoding")
    test_data = b"Hello World"
    encoding_ok, encoded = test_encoding(test_data)
    if encoding_ok:
        test_decoding(encoded, test_data)
    
    # Тест 2: Кодирование и декодирование случайных данных
    print("\nTest 2: Random data encoding/decoding")
    random_data = generate_random_data(100)
    encoding_ok, encoded = test_encoding(random_data)
    if encoding_ok:
        test_decoding(encoded, random_data)
    
    # Тест 3: Декодирование некорректных данных
    print("\nTest 3: Invalid data decoding")
    invalid_data = b"vvv~~~xxxwww"
    original_data = ""
    test_decoding(invalid_data, original_data)
    
    print("\n=== All tests completed ===")
    
run_tests()
