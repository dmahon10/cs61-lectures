#include "hexdump.hh"
#include <ctime>

struct example {
    int x; // size = align = 4
    char y; // size = align = 2
    int z; // size = align = 4
    char w; // size = align = 2
};

int main() {
    example e;

    e.x = 61;
    e.y = 62;
    e.z = 63;
    e.w = 64;

    hexdump_object(e);
}

// Expect: 7ff...     3d 00 00 00 3e 00 00 00 3f 00 00 00 40
// Print: 7ffcad236078  3d 00 00 00 3e 00 00 00  3f 00 00 00 40 00 00 00  |=...>...?...@...|

// It would appear that each member of a struct takes on the alignment of the element with the highest alignment,
// in this case int (alignof(int) == 4). 