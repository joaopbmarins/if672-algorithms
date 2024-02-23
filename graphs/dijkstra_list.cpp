#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define INF INT_MAX

typedef pair<int,int> pint;
typedef tuple<int,int,int> triplaINT;


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
    return;
}


void Dijkstra(Graph *g, int start, bool outraVersao){
    for(int i=0;i<g->numNode;i++){
        setMark(g, i, UNVISITED);
        g->dist[i] = INF;
    }
    g->dist[start] = 0;

    priority_queue<pint, vector<pint>, greater<pint>> heap;// nessa heap o par é <dist, nó> para nao precisar criar outra função para a comparação

    heap.push({g->dist[start], start});

    while(heap.size()>0){
        pint vpar = heap.top();
        int v = vpar.second; 
        heap.pop();
        if(getMark(g, v) == UNVISITED){
            setMark(g, v, VISITED);
            for(int w=0;w<g->array[v].size();w++){
                int i = g->array[v][w].first;
                int iweight = g->array[v][w].second;
                if(g->dist[i] > g->dist[v] + iweight){
                    g->dist[i] = g->dist[v] + iweight;
                    heap.push({g->dist[i], i});
                }
            }
        }
    }

}


void Dijkstra(Graph *g, int start){
    for(int i=0;i<g->numNode;i++){
        setMark(g, i, UNVISITED);
        g->dist[i] = INF;
    }
    g->dist[start] = 0;

    priority_queue<triplaINT, vector<triplaINT>, greater<triplaINT>> heap;
    heap.push({g->dist[start], start, start});

    for(int i=0;i<g->numNode;i++){
        triplaINT heapTop;
        do{
            if(heap.size() == 0)
                return;
            heapTop = heap.top();
            heap.pop();
            
        }while(!(getMark(g,get<2>(heapTop)) == UNVISITED));
        int v = get<2>(heapTop);
        setMark(g, v, VISITED);
        g->parent[v] = get<1>(heapTop);
        auto wFull = g->array[v].begin();
        while(wFull != g->array[v].end()){
            int w = (*wFull).first;
            if(getMark(g,w) != VISITED && g->dist[w] > g->dist[v] + (*wFull).second){
                g->dist[w] = g->dist[v] + (*wFull).second;
                heap.push({g->dist[w], v,w});
            }
            wFull++;
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
        cout << g->dist[i] << " ";
    }
    cout << endl;

    return 0;
}