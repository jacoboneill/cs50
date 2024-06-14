# Cryptography

## Encryption
The scrambling of plaintext data to ciphertext algorithmically generated using a key.

## Decryption
The descrambling of ciphertext back to it's original plaintext using a key.

## Caesar Cipher
It is done by adding a value to a letter, where the letter wraps around at z.

E.g. if the key is 5 and the message is "well", then:
> Rember that the ASCII code for 'z' is 122.
- w = 119, 119 + 5 = 124, wraparound = 98 = b
- e = 101, 101 + 5 = 106, 106 = j
- l = 108, 108 + 5 = 113, 113 = q
- l = 108, 108 + 5 = 113, 113 = q

Therefore, the ciphertext is "bjqq"
