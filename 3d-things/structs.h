#ifndef STRUCTS
#define STRUCTS

#include <vector>

struct Vertex {
    float x;
    float y;
    float z;
    float w;
};

struct Colortype {
    float red;
    float green;
    float blue;    
};

struct box {
    std::vector<Vertex> point = std::vector<Vertex>(4);
    Colortype color;
};

#endif