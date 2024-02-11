#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1

typedef struct Graph{
    list<int> *array;
    int *Arestas_Chegando;
    vector<int> toposort;
    int numEdge;
    int numNode;
}Graph;

Graph *create_graph(int n){
    Graph *g = new Graph;
    g->numNode = n;
    g->numEdge = 0;
    g->Arestas_Chegando = new int[n]();
    g->array = new list<int>[n];
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    g->array[i].push_back(j);
    g->Arestas_Chegando[j]++;
    g->numEdge++;
    return;
}

bool temCiclo = false;
void BFS(Graph *g){
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> heap_q;

    for(int i=0;i<g->numNode;i++){
        if(g->Arestas_Chegando[i] == 0)
            heap_q.push(i);
    }

    while(heap_q.size() > 0){
        int v = heap_q.top();
        heap_q.pop();
        g->toposort.push_back(v);
        count++;
        //preVisit
        for(int w : g->array[v]){
            g->Arestas_Chegando[w]--;
            if(g->Arestas_Chegando[w] == 0){    
                heap_q.push(w);
            }
        }
        //posVisit
    }
    if(count != g->numNode)
        temCiclo = true;
    
}


int main(){

    int n,m;
    cin >> n >> m;
    Graph *g = create_graph(n);
    while(m>0){
        int i,j;
        cin >> i >> j;
        i--;
        j--;
        setEdge(g, i, j, 1);
        m--;
    }
    BFS(g);
    if(!temCiclo){
        for(int i=0;i<n;i++){
            cout << g->toposort[i] +1 << " ";
        }
    }
    else{
        cout << "Sandro fails." << endl;
    }
    cout << endl;

    return 0;
}