#include "hexdump.hh"
#include <ctime>

struct example {
    int x; // size == align == 4
    int y; 
    char z; // size == align == 1
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

// Expected: 7ff... 3d 00 00 00 3e 00 00 00  3f 40
// Printed: 7ffc059e85e8  3d 00 00 00 3e 00 00 00  3f 40 40 00              |=...>...?@@.|

// First 10 bytes are as expected, 11th and 12th bytes are unexpected... 
// I suspect alignment might dictate where the struct ends as well
// Ie if alignment is 4, then it takes up a multiple of 4 bytes

