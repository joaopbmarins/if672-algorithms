#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define UNVISITED 0
#define VISITED 1

//typedef pair<int,int> pint;

/*
Grafo em lista de adjacências
DFS, BFS e TopologicalSort

para edges com peso utilizar a estrutura pint
*/

typedef struct Graph{
    vector<int> *array;
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
    g->array = new vector<int>[n];
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    //g->array[i].push_back({j,wt});
    g->array[i].push_back(j);
    return;
}

void DFS(Graph *g, int v, stack<int> &s){//Topological Sort
    //preVisit
    setMark(g, v, VISITED);
    for(int w : g->array[v]){
        if(getMark(g, w) == UNVISITED){
            DFS(g, w, s);
        }
    }
    s.push(v);
    //posVisit
}

void DFS(Graph *g, int v){//DFS com print em cada nó que ele visita
    //preVisit
    cout << v << " ";
    setMark(g, v, VISITED);
    for(int w : g->array[v]){
        if(getMark(g, w) == UNVISITED){
            DFS(g, w);
        }
    }
    //posVisit
}

void BFS(Graph *g, int start){//BFS com print em cada nó que ele visita
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(q.size() > 0){
        int v = q.front();
        q.pop();
        //preVisit
        cout << v << " ";
        for(int w : g->array[v]){
            if(getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
            
                q.push(w);
            }
        }
        //posVisit
    }  
}

void graphTraverse(Graph *g, const bool &bfs){//graphTraverse onde dá pra escolher qual algoritmo vai usar
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }

    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            if(bfs)
                BFS(g, v);
            else
                DFS(g, v);
        }
    }
}

void graphTraverse(Graph *g, const bool &bfs, int start){//graphTraverse onde dá pra escolher qual algoritmo vai usar e por qual nó ele começa 
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }

    if(bfs)
        BFS(g, start);
    else
        DFS(g, start);

    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            if(bfs)
                BFS(g, v);
            else
                DFS(g, v);
        }
    }
}

int main(){

    int n, q;
    cin >> n >> q;

    Graph *g = create_graph(n);

    while(q>0){
        int i, j;
        cin >> i >> j;
        setEdge(g, i, j, 1);
        q--;
    }

    stack<int> s;
    DFS(g, 0, s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}