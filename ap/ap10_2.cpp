#include <iostream>
#include <list>
using namespace std;
#define UNVISITED 0
#define VISTED 1

typedef struct Edge{
    int index;
    int weight;
}Edge;

typedef struct Graph{
    list<Edge> *array;
    bool *Mark;
    int numEdge;
    int numNode;
}Graph;

void setMark(Graph *g, int v, bool state){
    g->Mark[v] = state;
}

bool getMark(Graph *g, int v){
    return g->Mark[v];
}

Graph *create_graph(int n){
    Graph *g = new Graph;
    g->numNode = n;
    g->numEdge = 0;
    g->Mark = new bool[n]();
    g->array = new list<Edge>[n];
    return g;
}

int first(Graph *g, int v){
     for(auto i : g->array[v]){
        if(i.index != v){
            return i.index;
        }
     }
    return g->numNode;
}

int next(Graph *g, int v, int w){
    for(int i=w+1; i<g->numNode;i++){
        if(g->matrix[v][i] != 0)
            return i;
    }
    return g->numNode;
}

void setEdge(Graph *g, int i, int j, int wt){
    if(wt == 0)
        return;//error
    for(auto k : g->array[i]){
        if(k.index != j)
    }
}

void delEdge(Graph *g, int i, int j){
    if(g->matrix[i][j] != 0)
        g->numEdge--;
    g->matrix[i][j] = 0;
    return;
}


int main(){


    return 0;
}