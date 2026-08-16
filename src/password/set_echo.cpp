#include <termios.h>
#include <unistd.h>

# include "../core/aegis.hpp"

void Aegis::setEcho(bool enable) {
    struct termios tty;
    // get the current terminal attributes
    tcgetattr(STDIN_FILENO, &tty);

    if(!enable) {
        // clear the ECHO flag
        tty.c_lflag &= ~ECHO;
    }
    else {
        tty.c_lflag |= ECHO;
    }

    // apply the modified attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
