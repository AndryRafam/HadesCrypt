#ifndef DECRYPTION_HPP
#define DECRYPTION_HPP

#include "../core/aegis.hpp"

class Decryption : public Aegis {
    public:
        bool decryptionMode();
};

#endif