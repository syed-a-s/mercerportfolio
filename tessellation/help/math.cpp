// PURPOSE : all math functions needed for project

#include <stdio.h>      
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

struct Vertex {
    float x;
    float y;
};

int totalVertices = 0;
vector<Vertex> myVertices;

float Lerp(float a, float b, float t);
bool DoesIntersect(Vertex a, Vertex b, Vertex c, Vertex d);

void InsertPoint(float x, float y);
void PrintVector(vector<Vertex> vertices);

int main(int argc, char** argv) {
    InsertPoint(50, 100);
    InsertPoint(200, 20);
    InsertPoint(100, 30);
    InsertPoint(20, 300);

    cout << DoesIntersect(myVertices[0], myVertices[1], myVertices[1], myVertices[2]) << endl;
    cout << "finish" << endl;
    PrintVector(myVertices);
    // cout << DoesIntersect(myVertices[0], myVertices[1], myVertices[2], myVertices[3]) << endl;

    return 0;
}

float Lerp(float a, float b, float t) {
    return a + (a - b) * t;
}

bool DoesIntersect(Vertex a, Vertex b, Vertex c, Vertex d) {
    const float tTop = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    const float uTop = (c.y - a.y) * (a.x - b.x) - (c.x - a.x) * (a.y - b.y);
    const float bottom = (d.y - c.y) * (b.x - a.x) - (d.x - c.x) * (b.y - a.y);

    if (bottom > 0.001 || bottom < -0.001) {
        const float t = tTop / bottom;
        const float u = uTop / bottom;
        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
             return true;
        }
    }

    return false;
}


void InsertPoint(float x, float y) {
    if(myVertices.size() > 2) {
        for(int i = 0; i < myVertices.size() - 1; i++) {
	    if((i+1) == (totalVertices - 2)) {
		printf("%f	%f\n", myVertices[i+1].x, myVertices[i+1].y);
		printf("%f	%f\n", myVertices[totalVertices-2].x, myVertices[totalVertices-2].y);
		continue;
	    } 
            if(DoesIntersect(myVertices[i], myVertices[i + 1], myVertices[totalVertices - 2], myVertices[totalVertices - 1])) {
	        return;
	    }
        }
    }

    myVertices.push_back(Vertex());
    myVertices[totalVertices].x = x;
    myVertices[totalVertices].y = y;
    totalVertices++;
}

/*
void InsertPoint(float x, float y) {
	myVertices.push_back(Vertex());
    	myVertices[totalVertices].x = x;
    	myVertices[totalVertices].y = y;		
	totalVertices++;

	if(myVertices.size() > 2) {
		for(int i = 0; i < myVertices.size() - 2; i++) { 
			cout << DoesIntersect(myVertices[i], myVertices[i + 1], myVertices[totalVertices - 2], myVertices[totalVertices - 1]) << endl;
			if(DoesIntersect(myVertices[i], myVertices[i + 1], myVertices[totalVertices - 2], myVertices[totalVertices - 1])) {
				myVertices.pop_back();
				totalVertices--;
			}
		}
	}
}
*/

void PrintVector(vector<Vertex> vertices) {
    for(int i = 0; i < vertices.size(); i++) {
        cout << "\t\t" << vertices[i].x << " " << vertices[i].y << endl;
    }
}
