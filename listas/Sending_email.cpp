#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define INF INT_MAX
#define endl "\n"

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
    g->array[j].push_back({i,wt});
    return;
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
            
        }while(!(getMark(g, get<2>(heapTop)) == UNVISITED));
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

    int c;
    cin >> c;
    for(int i=0;i<c;i++){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        Graph *g = create_graph(n);
        for(int j=0;j<m;j++){
            int a,b,c;
            cin >> a >> b >> c;
            setEdge(g, a, b, c);
        }
        
        Dijkstra(g, s);
        cout << "Case #" << i + 1 << ": ";
        if(g->dist[t] == INF){
            cout << "unreachable\n";
        }
        else{
            cout << g->dist[t] << endl;
        }
    }

    return 0;
}