#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define INF 1000000

/*

NÃO FUNCIONA

*/

typedef pair<int,int> pint;

typedef struct{
    int **matrix;
    int numEdge;
    bool *Mark;
    int *Dist;
    int numNode;
}Graph;

void setMark(Graph *g, int v, bool state){
    g->Mark[v] = state;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

Graph *create_graph(const int n){   
    Graph *g = new Graph;
    g->numNode = n;
    g->Mark = new bool[n]();
    g->Dist = new int[n];
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

void Dijkstra(Graph *g, int start){
    for(int i=0;i<g->numNode;i++){
        setMark(g, i, UNVISITED);
        g->Dist[i] = INF;
    }
    g->Dist[start] = 0;

    priority_queue<pint, vector<pint>, greater<pint>> heap;
    heap.push({g->Dist[start], start});

    while(heap.size()>0){
        pint v = heap.top();
        int vindex = v.second;
        heap.pop();
        if(getMark(g, vindex) == UNVISITED){
            setMark(g, vindex, VISITED);
            int w = first(g, vindex);
            while(w<g->numNode){
                if(g->Dist[w] > g->Dist[vindex] + weight(g, vindex, w)){
                    g->Dist[w] = g->Dist[vindex] + weight(g, vindex, w);
                    heap.push({g->Dist[w], w});
                }
                next(g, vindex, w);
            }
        }
    }

    
}

int main(){

    int n,m,v;
    cin >> n >> m >> v;
    Graph *g = create_graph(n);

    while(m>0){
        int i,j, wt;
        cin >> i >> j >> wt;
        setEdge(g, i, j, wt);
        setEdge(g, j, i, wt);
        m--;
    }

    Dijkstra(g, 0);

    for(int i=0;i<g->numNode;i++){
        cout << g->Dist[i] << " ";
    }
    cout << endl;

    return 0;
}