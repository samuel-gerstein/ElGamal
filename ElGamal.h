#ifndef ELGAMAL_H
#define ELGAMAL_H
#include <iostream>
#include <cmath>
class client {
    public:
        client(int message, int p, int alpha);
        void generateKeys();
        void encrypt();
        void decrypt();
        int send_cipher();
        int get_public_key();
    private:
        int plaintext;  // plaintext to be encrypted or found via encryption
        int ciphertext; // ciphertext to be sent or found via decryption
        int private_key;
        int public_key;
        int generator;
        int prime;
};
#endif // ELGAMAL_H