#include "ElGamal.h"


//Constructor
client::client(int message, int p, int alpha) {
    plaintext = message;
    prime = p;
    generator = alpha;
}


