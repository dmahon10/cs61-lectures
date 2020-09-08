#include "hexdump.hh"
#include <ctime>

struct example {
    char x; // sizeof(char) == 1
    char y; // alignof(char) == 1
    char z;
    char w;
};

int main() {
    example e;

    e.x = 61;
    e.y = 62;
    e.z = 63;
    e.w = 64;

    hexdump_object(e);
}

// Expecting sizeof(e) == 4 bytes

// Prints: 7ffdaa82e760  3d 3e 3f 40                                       |=>?@|

// 4 bytes as expected
// Address changes, but stays near