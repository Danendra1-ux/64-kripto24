def generate_key(text, key):
    key = list(key)
    if len(key) == len(text):
        return key
    else:
        for i in range(len(text) - len(key)):
            key.append(key[i % len(key)])
    return "".join(key)

def encrypt_vigenere(text, key):
    encrypted_text = []
    for i in range(len(text)):
        if text[i].isalpha():
            shift = ord(key[i].upper()) - ord('A')
            if text[i].isupper():
                encrypted_text.append(chr((ord(text[i]) - ord('A') + shift) % 26 + ord('A')))
            else:
                encrypted_text.append(chr((ord(text[i]) - ord('a') + shift) % 26 + ord('a')))
        else:
            encrypted_text.append(text[i])
    return "".join(encrypted_text)

def decrypt_vigenere(encrypted_text, key):
    decrypted_text = []
    for i in range(len(encrypted_text)):
        if encrypted_text[i].isalpha():
            shift = ord(key[i].upper()) - ord('A')
            if encrypted_text[i].isupper():
                decrypted_text.append(chr((ord(encrypted_text[i]) - ord('A') - shift + 26) % 26 + ord('A')))
            else:
                decrypted_text.append(chr((ord(encrypted_text[i]) - ord('a') - shift + 26) % 26 + ord('a')))
        else:
            decrypted_text.append(encrypted_text[i])
    return "".join(decrypted_text)

if __name__ == "__main__":
    text = input("Masukkan teks: ")
    key = input("Masukkan kunci: ")

    key = generate_key(text, key)

    encrypted_text = encrypt_vigenere(text, key)
    print("Hasil enkripsi:", encrypted_text)

    decrypted_text = decrypt_vigenere(encrypted_text, key)
    print("Hasil dekripsi:", decrypted_text)
