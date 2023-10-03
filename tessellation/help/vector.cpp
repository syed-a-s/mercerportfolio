// PURPOSE : create a dynamic data structure to store an arbritrary num of vertices

#include <vector>
#include <stdio.h>      
#include <stdlib.h>
#include <iostream>
using namespace std;
 
struct Vertex {
    int x;
    int y;
};

int totalVertices = 0;
vector<Vertex> myVertices;          // a vector of structs

void PrintVector(vector<Vertex> vertices) {
    for(int i = 0; i < vertices.size(); i++) {
        cout << "\t\t" << vertices[i].x << " " << vertices[i].y << endl;
    }
}

int main(int argc, char** argv) {

    // simulate random clicking of the mouse on screen
    for (int i = 0; i < 100; i++) {
        myVertices.push_back(Vertex());
        totalVertices++;
        myVertices[i].x = rand() % 500;
        myVertices[i].y = rand() % 500;
    }

    PrintVector(myVertices);
    printf("Total Vertices : %d\n", totalVertices);

    return 0;
}