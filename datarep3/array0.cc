#include "hexdump.hh"
#include <ctime>

int main() {
    int a[4]; // sizeof(int) = 4 bytes

    a[0] = 61; // 0x3d
    a[1] = 62; // 0x3e
    a[2] = 63; // 0x3f
    a[3] = 64; // 0x40

    hexdump_object(a);
}

// Prints: 7fff18c00060  3d 00 00 00 3e 00 00 00  3f 00 00 00 40 00 00 00  |=...>...?...@...|
// Address stays in the general 7fff... range
// Seems like 4 bytes per array element (each digit in hex is represented with 4 bits)