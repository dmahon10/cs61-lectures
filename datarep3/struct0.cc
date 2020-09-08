#include "hexdump.hh"
#include <ctime>

struct example {
    int x; // sizeof(int) == 4
    int y; // alignof(int) == 4
    int z;
    int w;
};

// Expecting size of above struct to be 4*4 = 16 bytes
// No padding because they all have same alignment and 
// because the alignment of a struct is equal to the 
// alignment of its largest member. 

int main() {
    example e;

    e.x = 61;
    e.y = 62;
    e.z = 63;
    e.w = 64;

    hexdump_object(e);
}

// In structs members are laid out in order of delaration -- which order in memory, increasing or decreasing?
// Will the members be printed in contiguous memory?

// Prints: 7ffe3c6b6600  3d 00 00 00 3e 00 00 00  3f 00 00 00 40 00 00 00  |=...>...?...@...|
// Address changes but stays in same general 7ff... region
// Each element is 4 bytes as expected -- whole struct is 16 bytes
