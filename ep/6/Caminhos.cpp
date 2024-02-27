#include <bits/stdc++.h>
#define endl "\n"
#define INF INT_MAX
using namespace std;

typedef pair<int, int> pint;
typedef tuple<int, int, int> tripla;

typedef struct{
    vector<pint> *array;
    int *dist;
    bool *mark;
    int n;
}Graph;

Graph *create_graph(int n){
    Graph *g = new Graph;
    g->dist = new int[n];
    g->n = n;
    g->mark = new bool[n]();
    g->array= new vector<pint>[n];
    return g;
}

void Dijkstra(Graph *g, int start){
    for(int i=0;i<g->n;i++){
        g->dist[i] = INF;
        g->mark[i] = false;
    }

    priority_queue<tripla, vector<tripla>, greater<tripla>> heap;
    heap.push({0,start, start});
    g->dist[start] = 0;

    for(int i=0;i<g->n;i++){
        tripla pv;
        do{
            if(heap.size() == 0) return;
            pv = heap.top();
            heap.pop();

        }while(g->mark[get<2>(pv)]);
        int v = get<2>(pv);
        g->mark[v] = true;
        auto wFull = g->array[v].begin();
        while(wFull != g->array[v].end()){
            if(g->mark[(*wFull).first] != true && g->dist[(*wFull).first] > g->dist[v] + (*wFull).second){
                g->dist[(*wFull).first] = g->dist[v] + (*wFull).second;
                heap.push({g->dist[(*wFull).first], v, (*wFull).first});
            }
            wFull++;
        }
    }
}

int main(){

    int c;
    cin >> c;
    for(int i=0;i<c;i++){
        int n, e;
        cin >> n >> e;
        Graph *g = create_graph(n);
        for(int j=0;j<e;j++){
            int v1,v2,wt;
            cin >> v1 >> v2 >> wt;
            g->array[v1].push_back({v2, wt});
        }
        int start;
        cin >> start;
        Dijkstra(g, start);
        cout << "Caso " << i+1 << endl;
        for(int j=0;j<g->n;j++){
            if(g->dist[j] != INF)
                cout << g->dist[j] << endl;
            else 
                cout << -1 << endl;
        }
    }



    return 0;
}
