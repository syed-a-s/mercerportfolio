#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits.h>
using namespace std;
#include "graph.h"
#include "HashTable.h"

const string notFound = "ZZZ";
const int maxVertices = 50;

struct VertexInfo {
    string vertex;
    bool isMarked = false;
    int totalDist = INT_MAX;
    string prevVertex;
};

int BuildGraph(Graph<string> &initialGraph, string filename, HashTable<string> &initialHash, vector<string> &orderedVertices);
void BuildStruct(VertexInfo vertices[], vector<string> vertex, int totalVertices);
void AlterStruct(VertexInfo vertices[], int index, string vertex, bool isMarked, int totalDist, string prevVertex);
void PrintVertices(vector<string> vertices);
void IsValidInput(HashTable<string> &vertices, string &userInput);
int FindIndex(VertexInfo vertices[], string currentVertex, int totalVertices);
void PrintFormatted(string a, string b, string c);
string FindNearestVertex(Graph<string> graph, Queue<string> graphQ, string currentVertex);
int TotalDist(Graph<string> graph, VertexInfo vertices[], string currentVertex, int totalVertices);

void PrintStruct(VertexInfo vertices[], int totalVertices);

int main(int argc, char *argv[]) {
    Graph<string> myGraph;
    Queue<string> myGraphQ, weightQ;
    HashTable<string> vertexHash(notFound, maxVertices);
    vector<string> vertexVector;
    string currentVertex;
    int totalVertices;
    int currentIndex, nextIndex;

    totalVertices = BuildGraph(myGraph, argv[1], vertexHash, vertexVector);
    VertexInfo myVertexInfo[totalVertices];
    BuildStruct(myVertexInfo, vertexVector, totalVertices);

    cout << "\033[2J\033[1;1H";
    //cout << "Dijkstra's Algorithm" << endl;
    cout << "A Weighted Graph Has Been Built For These " << totalVertices << " Cities" << endl;
    PrintVertices(vertexVector);
    cout << "Please Input Your Starting Vertex : ";
    IsValidInput(vertexHash, currentVertex);

    // step 1
    currentIndex = FindIndex(myVertexInfo, currentVertex, totalVertices);
    AlterStruct(myVertexInfo, currentIndex, myVertexInfo[currentIndex].vertex, true, 0, "N/A");
    PrintFormatted(myVertexInfo[currentIndex].vertex, to_string(myVertexInfo[currentIndex].totalDist), myVertexInfo[currentIndex].prevVertex);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    myGraph.GetToVertices(currentVertex, myGraphQ);
    while(!myGraphQ.isEmpty()) {
        nextIndex = FindIndex(myVertexInfo, myGraphQ.getFront(), totalVertices);

        if(myVertexInfo[nextIndex].totalDist > TotalDist(myGraph, myVertexInfo, myGraphQ.getFront(), totalVertices))
            myVertexInfo[nextIndex].totalDist = TotalDist(myGraph, myVertexInfo, myGraphQ.getFront(), totalVertices);

        myVertexInfo[nextIndex].prevVertex = currentVertex;

        myGraphQ.dequeue();
    }

    myGraph.GetToVertices(currentVertex, myGraphQ);
    currentVertex = FindNearestVertex(myGraph, myGraphQ, currentVertex);
    currentIndex = FindIndex(myVertexInfo, currentVertex, totalVertices);
    myVertexInfo[currentIndex].isMarked = true;

    PrintFormatted(myVertexInfo[currentIndex].vertex, to_string(myVertexInfo[currentIndex].totalDist), myVertexInfo[currentIndex].prevVertex);
    ///////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}

int BuildGraph(Graph<string> &initialGraph, string filename, HashTable<string> &initialHash, vector<string> &orderedVertices) {
    ifstream infile;
    infile.open(filename);
    string origin, destination, line;
    int weight = 0, totalVertices = 0;

    while(getline(infile, line)) {
        stringstream ss(line);
        getline(ss, origin, ';');
        getline(ss, destination, ';');
        ss >> weight;

        if(initialHash.find(origin) == notFound) {
            initialGraph.AddVertex(origin);
            initialHash.insert(origin);
            orderedVertices.push_back(origin);
            totalVertices++;
        }

        if(initialHash.find(destination) == notFound) {
            initialGraph.AddVertex(destination);
            initialHash.insert(destination);
            orderedVertices.push_back(destination);
            totalVertices++;
        }

        initialGraph.AddEdge(origin, destination, weight);
    }

    infile.close();

    return totalVertices;
}

void BuildStruct(VertexInfo vertices[], vector<string> vertex, int totalVertices) {
    for(int i = 0; i < totalVertices; i++) {
        vertices[i].vertex = vertex.at(i);
    }
}

void AlterStruct(VertexInfo vertices[], int index, string vertex, bool isMarked, int totalDist, string prevVertex) {
    vertices[index].vertex = vertex;
    vertices[index].isMarked = isMarked;
    vertices[index].totalDist = totalDist;
    vertices[index].prevVertex = prevVertex;
}

void PrintVertices(vector<string> vertices) {
    sort(vertices.begin(), vertices.end());

    for(int i = 0; i < vertices.size(); i++) {
        cout << "\t\t" << vertices.at(i);
        if(i % 3 == 0)
            cout << endl;
    }
}

void IsValidInput(HashTable<string> &vertices, string &userInput) {
    cin >> userInput;
    while(vertices.find(userInput) == notFound) {
        cout << "Invalid Input. Please Try Again : ";
        cin >> userInput;
    }
}

int FindIndex(VertexInfo vertices[], string currentVertex, int totalVertices) {
    int i = 0;
    for(i; i < totalVertices; i++) {
        if(vertices[i].vertex == currentVertex) 
            break;
    }
    return i;
}

void PrintFormatted(string a, string b, string c) {
    cout << "\t\t" << a << "\t\t" << b << "\t\t" << c << endl;
}

string FindNearestVertex(Graph<string> graph, Queue<string> graphQ, string currentVertex) {
    int minWeight = INT_MAX;
    int currentWeight = -1;
    string nextNearestVertex;

    while(!graphQ.isEmpty()) {
        currentWeight = graph.WeightIs(currentVertex, graphQ.getFront());
        if (minWeight > currentWeight) {
            nextNearestVertex = graphQ.getFront();
            minWeight = currentWeight;
        }
        graphQ.dequeue();
    }

    return nextNearestVertex;
}

// TO DO : check why WeightIs function returns 0
int TotalDist(Graph<string> graph, VertexInfo vertices[], string currentVertex, int totalVertices) {
    int totalDist = 0, index = 0;

    PrintStruct(vertices, totalVertices);

    index = FindIndex(vertices, currentVertex, totalVertices);
    while((vertices[index].prevVertex != "N/A")) {
        totalDist = totalDist + graph.WeightIs(currentVertex, vertices[index].prevVertex);
        currentVertex = vertices[index].prevVertex;
        index = FindIndex(vertices, currentVertex, totalVertices);
    }
    
    return totalDist;
}

void PrintStruct(VertexInfo vertices[], int totalVertices) {
    for(int i = 0; i < totalVertices; i++) {
        PrintFormatted(vertices[i].vertex, vertices[i].prevVertex, to_string(vertices[i].totalDist)); 
    }
}
