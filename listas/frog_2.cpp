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
    int n, k;
    cin >> n >> k;
    vector<int> array;
    array.resize(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        array.at(i) = tmp;
    }

    Graph *g = create_graph(n);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+k && j < n;j++){
            int wt = abs(array.at(i) - array.at(j));
            setEdge(g,i,j, wt);
            //cerr << wt << " ";
        }
        //cerr << endl;
    }

    Dijkstra(g, 0);

    cout << g->dist[n-1] << endl;
    
    

    return 0;
}