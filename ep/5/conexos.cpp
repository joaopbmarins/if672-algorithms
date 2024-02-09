#include <iostream>
#include <list>
using namespace std;
#define endl "\n"

typedef struct Graph{
    list<int> *array;
    int numEdge;
    int numNode;
    bool *mark;
}Graph;

Graph *createGraph(int n){
    Graph *g = new Graph;
    g->mark = new bool[n]();
    g->array = new list<int>[n];
    g->numEdge = 0;
    g->numNode = n;
    return g;
}

void setEdge(Graph *g, int i, int j){
    g->array[i].push_back(j);
}

int teste  = 0;
void DFS(Graph *g, int v){
    //previsit
    g->mark[v] = true;
    for(int w : g->array[v]){
        if(g->mark[w] == false){
            teste++;
            DFS(g, w);
        }
    }
    //posvisit
}

void graphT(Graph *g){
    for(int v=0;v<g->numNode;v++){
        g->mark[v] = false;
    }
    for(int v=0;v<g->numNode;v++){
        if(g->mark[v] == false){
            DFS(g, v);
        }
    }
}



int main(){

    int c;
    cin >> c;
    while(c>0){
        int n, a;
        cin >> n >> a;
        Graph *g = createGraph(n);
        while(a>0){
            int i,j;
            cin >> i >> j;
            setEdge(g, i, j);
            setEdge(g, j, i);
            a--;
        }
        teste  = 0;
        graphT(g);
        cout << n - teste << endl;
        c--;
    }
    return 0;
}