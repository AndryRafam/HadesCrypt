// this code generate a password randomly

#include <string>
#include <algorithm> // std::shuffle
#include <random>
#include <chrono>

#include "../core/aegis.hpp"

std::string Aegis::generatePassword(int length) {
    // define the character set for the password
	const std::string charset =
        "abcdefghijklmnopqrstuvwxyz"  // lowercase character
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  // uppercase character
        "0123456789"                  // numbers
        "!@#$%^&*()-_=+[]{}|;:,.<>?"; // special character

    std::string password = "";
    password.reserve(length); // pre-allocate memory for efficiency

    // generate each character of the password
    for (int i = 0; i < length; ++i) {
        // Pick a random index within character set bounds
        uint32_t index = get_rng().GenerateWord32(0, static_cast<CryptoPP::word32>(charset.length() - 1));
        password += charset[index];
    }
    return password;  
}
