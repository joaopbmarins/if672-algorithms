#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct{
    int **matrix;
    int numEdge;
    int *Mark;
    int numNode;
}Graph;

void setMark(Graph *g, int v, int state){
    g->Mark[v] = state;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

Graph *create_graph(const int n){   
    Graph *g = new Graph;
    g->numNode = n;
    g->Mark = new int[n]();
    g->matrix = new int*[n];
    for(int i=0;i<n;i++){
        g->matrix[i] = new int[n]();
    }
    g->numEdge = 0;
    return g;
}

int first(Graph *g, int v){
    for(int i=0;i<g->numNode;i++){
        if(g->matrix[v][i] != 0)
            return i;
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

int weight(Graph *g, int i, int j){
    return g->matrix[i][j];
}

void Floyd(Graph *g, int **dist){
    for(int i=0;i<g->numNode;i++){
        for(int j=0;j<g->numNode;j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else if(weight(g, i,j) != 0){
                dist[i][j] = weight(g,i,j);
            }
            else{
                dist[i][j] = INFINITY;
            }
        }
    }
    for(int k=0;k<g->numNode;k++){
        for(int i=0;i<g->numNode;i++){
            for(int j=0;j<g->numNode;j++){
                if(dist[i][k] != INFINITY && dist[k][j] != INFINITY && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){

    return 0;
}