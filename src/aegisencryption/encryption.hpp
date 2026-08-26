#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include "../core/aegis.hpp"

class Encryption final : public Aegis {
    public:
        Encryption() {}
        bool encryptionMode();
        ~Encryption() override {}
};

#endif
