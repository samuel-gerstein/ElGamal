#include "ElGamal.h"

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

string decimalToBinary(int n) {
    string result = "";
    while (n > 0) {
        result = to_string(n % 2) + result;
        n /= 2;
    }
    cout << result << endl;
    return result;
}

int repeated_square_and_multiply(int a, int k, int m)
{
    int b = 1;
    string k_binary = decimalToBinary(k);
    if (k_binary[(k_binary.length()-1)] == '1')
    {
        b = a;
    }
    for (int i = 1; i < k_binary.length(); i++) {
        a = (a * a) % m;
        if (k_binary[(k_binary.length()-i-1)] == '1') {
            b = (b * a) % m;
        }
    }
    return b;
}

//Constructor
client::client(int message, int p, int alpha) {
    plaintext = message;
    prime = p;
    generator = alpha;
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

