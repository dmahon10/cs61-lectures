#include "hexdump.hh"
#include <ctime>

int main() {
    char a[4]; // sizeof(char) == 1 byte

    a[0] = 61; // 3d
    a[1] = 62; // 3e
    a[2] = 63; // 3f
    a[3] = 64; // 40

    hexdump_object(a);
}

// Prints: 7ffc78538614  3d 3e 3f 40                                       |=>?@|
// Address stays in the general 7fff... range
// Seems like 1 byte per array element (each digit in hex is represented with 4 bits)
    // Make sense seeing as they are chars
