#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include "../core/aegis.hpp"

class Encryption : public Aegis {
    public:
        bool encryptionMode();
};

#endif