#include "ElGamal.h"


//Constructor
client::client(int message, int p, int alpha) {
    plaintext = message;
    prime = p;
    generator = alpha;
}

bool primality(int n) {
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

void client::generateKeys() {

    //random large prime number 
    srand(time(0));
    unsigned long long int random = pow(10,30) * rand();
    while (primality(random) != true) {
        random = pow(10, 30) * rand();
    }
    
}

void client::encrypt() {

}

void client::decrypt() {

}

int client::send_cipher() {

}

int client::get_public_key() {

}

