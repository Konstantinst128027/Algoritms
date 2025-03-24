import base64
import random
import string
import subprocess

def generate_random_data(length):
    """Генерация случайных данных."""
    return ''.join(random.choice(string.ascii_letters + string.digits) for i in range(length)).encode()

def test_encoding(input_data):
    """
    Тестирует только кодировщик:
    1. Кодирует данные
    2. Проверяет, правильно ли закодированы данные
    Возвращает tuple: (успех_проверки, закодированные_данные)
    """
    # Кодирование данных
    process = subprocess.Popen(
        ["./main", "-e"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    encoded, encoder_stderr = process.communicate(input=input_data)
    encoded = encoded.strip()

    # Проверка ошибок кодировщика
    if encoder_stderr:
        print("Encoder error:", encoder_stderr.decode().strip())
        return (False, None)

    # Проверка корректности кодирования
    encoded_reference = base64.a85encode(input_data)
    if encoded != encoded_reference:
        print("Encoder output does not match base64.a85encode!")
        return (False, None)

    print("Encoding test passed!")
    return (True, encoded)

def test_decoding(encoded_data, original_data):
    """
    Тестирует только декодировщик:
    1. Раскодирует данные
    2. Проверяет, правильно ли раскодированы данные
    """
    # Декодирование данных
    process = subprocess.Popen(
        ["./main", "-d"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    decoded, decoder_stderr = process.communicate(input=encoded_data)
    decoded = decoded.strip()

    # Проверка ошибок декодировщика
    if decoder_stderr:
        print(decoder_stderr.decode().strip())
        print(f"Error code: {process.returncode}")
        return False

    # Проверка корректности декодирования
    if decoded != original_data:
        print("Decoded data does not match original data!")
        return False

    print("Decoding test passed!")
    return True
