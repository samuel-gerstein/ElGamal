#include <iostream>
#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;

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

class client {
    public:
        client(int msg, int enc_msg, int modulus);
        int generateKeys();
        void encrypt();
        void decrypt();
        int send_cipher();
        int get_public_key();
    private:
        int plaintext;  // plaintext to be encrypted or found via encryption
        int ciphertext; // ciphertext to be sent or found via decryption
        int public_key;
        int modulus;
};

//Constructor
client::client(int msg, int enc_msg, int modulus) {

}


int client::generateKeys() {

    //random large prime number 
    srand(time(0));
    unsigned long long int random = pow(10,30) * rand();
    while (primality(random) != true) {
        random = pow(10, 30) * rand();
    }
    int generator = findPrimitive(random);
    int a = 
    public_key = repeated_square_and_multiply(generator, a, modulus);
    return random, generator, public_key;
}

void client::encrypt() {

}

void client::decrypt() {

}

int client::send_cipher() {

    return 0;
}

int client::get_public_key() {
    return 0;
}


//


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
// adapted from https://www.geeksforgeeks.org/primitive-root-of-a-prime-number-n-modulo-n/
void prime_factorization(unordered_set<int> &s, int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when
    // n is a prime number greater than 2
    if (n > 2)
        s.insert(n);
}
 
// Function to find smallest primitive root of n
int findPrimitive(int n)
{
    unordered_set<int> s;
 
    // Check if n is prime or not
    if (primality(n)==false)
        return -1;
 
    // Find value of Euler Totient function of n
    // Since n is a prime number, the value of Euler
    // Totient function is n-1 as there are n-1
    // relatively prime numbers.
    int phi = n-1;
 
    // Find prime factors of phi and store in a set
    prime_factorization(s, phi);
 
    // Check for every number from 2 to phi
    for (int r=2; r<=phi; r++)
    {
        // Iterate through all prime factors of phi.
        // and check if we found a power with value 1
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
 
            // Check if r^((phi)/primefactors) mod n
            // is 1 or not
            if (repeated_square_and_multiply(r, phi/(*it), n) == 1)
            {
                flag = true;
                break;
            }
         }
 
         // If there was no power with value 1.
         if (flag == false)
           return r;
    }
 
    // If no primitive root found
    return -1;
}

///////
int main()
{
}