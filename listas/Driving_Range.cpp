#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define INF INT_MAX
#define endl "\n"

typedef pair<int,int> pint;
typedef pair<int,pair<int,int>> superPair;


typedef struct Graph{
    vector<pint> *array;//par é <nó, peso>
    bool *Mark;
    int *dist;
    int *parent;
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
    g->array = new vector<pint>[n];
    g->dist = new int[n];
    g->parent = new int[n];
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    g->array[i].push_back({j,wt});
    g->array[j].push_back({i,wt});
    return;
}

void Prim(Graph *g, int start){
    for(int i=0;i<g->numNode;i++){
        setMark(g, i, UNVISITED);
        g->dist[i] = INF;
    }
    g->dist[start] = 0;

    priority_queue<superPair, vector<superPair>, greater<superPair>> heap;
    heap.push({g->dist[start], {start, start}});

    for(int i=0;i<g->numNode;i++){
        superPair heapTop;
        do{
            if(heap.size() == 0)
                return;
            heapTop = heap.top();
            heap.pop();
            
        }while(!(getMark(g,heapTop.second.second) == UNVISITED));
        int v = heapTop.second.second;
        setMark(g, v, VISITED);
        g->parent[v] = heapTop.second.first;
        auto wFull = g->array[v].begin();
        while(wFull != g->array[v].end()){
            int w = (*wFull).first;
            if(getMark(g,w) != VISITED && g->dist[w] > (*wFull).second){
                g->dist[w] = (*wFull).second;
                heap.push({g->dist[w], {v,w}});
            }
            wFull++;
        }
        
    }

}

int main(){

    int n,m;
    bool controle = true;
    cin >> n >> m;
    while(controle){
        Graph *g = create_graph(n);
        for(int i=0;i<m;i++){
            int a, b, wt;
            cin >> a >> b >> wt;
            setEdge(g, a, b, wt);
        }
        Prim(g,0);
        int highest = -1;

        for(int i=0;i<g->numNode;i++){
            if(g->dist[i] > highest && g->dist[i] != 0)
                highest = g->dist[i];
        }
        if(highest == INF)
            cout << "IMPOSSIBLE";
        else
            cout << highest;
        cout << endl;

        cin >> n >> m;
        if(n == 0 & m == 0) controle = false;
    }

    return 0;
}