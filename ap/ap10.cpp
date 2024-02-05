#include <iostream>

typedef struct{
    int **matrix;
    int numEdge;
    int *Mark;
    int n;
}Graph;

void setMark(Graph *g, int v, int state){
    g->Mark[v] = state;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

Graph *create_graph(const int n){   
    Graph *g = new Graph;
    g->n = n;
    g->Mark = new int[n]();
    g->matrix = new int*[n];
    for(int i=0;i<n;i++){
        g->matrix[i] = new int[n]();
    }
    g->numEdge = 0;
    return g;
}

int first(Graph *g, int v){
    for(int i=0;i<g->n;i++){
        if(g->matrix[v][i] != 0)
            return i;
    }
    return g->n;
}

int next(Graph *g, int v, int w){
    for(int i=w+1; i<g->n;i++){
        if(g->matrix[v][i] != 0)
            return i;
    }
    return g->n;
}

void setEdge(Graph *g, int i, int j, int wt){
    if(wt == 0)
        return;//error
    if(g->matrix[i][j] == 0)
        g->numEdge++;
    g->matrix[i][j] = wt;
    return;
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