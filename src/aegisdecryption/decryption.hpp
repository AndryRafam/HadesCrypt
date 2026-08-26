#ifndef DECRYPTION_HPP
#define DECRYPTION_HPP

#include "../core/aegis.hpp"

class Decryption final : public Aegis {
    public:
        Decryption() {}
        bool decryptionMode();
        ~Decryption() override {}
};

#endif
