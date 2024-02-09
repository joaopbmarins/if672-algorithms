#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define UNVISITED 0
#define VISITED 1


typedef struct Graph{
    vector<int> *array;
    bool *Mark;
    int *dest;
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
    g->dest = new int[n];
    g->array = new vector<int>[n];
    return g;
}

void setEdge(Graph *g, int i, int j, int wt){
    //g->array[i].push_back({j,wt});
    g->array[i].push_back(j);
    return;
}



void BFS(Graph *g, int start){
    for(int i=0;i<g->numNode;i++) g->dest[i] = -1;
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    g->dest[start] = 0;
    while(q.size() > 0){
        int v = q.front();
        q.pop();
        //preVisit
        for(int w : g->array[v]){
            if(getMark(g, w) == UNVISITED){
                g->dest[w] = g->dest[v] + 1; 
                setMark(g, w, VISITED);
                q.push(w);
            }
        }
        //posVisit
    }  
}

void BFS(Graph *g, int start, int target, int vet[]){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    bool found = false;
    vet[start] = start;
    while(q.size() > 0 && !false){
        int v = q.front();
        q.pop();
        //preVisit
        for(int w : g->array[v]){
            if(getMark(g, w) == UNVISITED){
                if(vet[w] == -1)
                    vet[w] = v;
                if(w == target){
                    found = true;
                    break;
                }
                setMark(g, w, VISITED);
                q.push(w);
            }
        }
        //posVisit
    }  
}


void graphTraverse(Graph *g){
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }
    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            BFS(g, v);
        }
    }
}

void graphTraverse(Graph *g, const bool &bfs, int start){
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }

    BFS(g, start);

    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            BFS(g, v);
        }
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    Graph *g = create_graph(n);

    while (q>0){
        int i,j;
        cin >> i >> j;
        setEdge(g,i,j,1);
        q--;
    }
    

    BFS(g, 2);
    for(int i=0;i<g->numNode;i++){
        cout << g->dest[i] << " ";
    }
    cout << endl;
   
    
    

   /*
   int vet[n];
   for(int i=0;i<n;i++) vet[i] = -1;
   int start, target;
   cin >> start >> target;
    BFS(g, start, target, vet);  
    
    for(int i : vet)
        cout << i << " ";
    cout << endl;
    vector<int> f;
    
    for(int i=target, j=0;i!= start && j<g->numNode;j++){
        f.push_back(vet[i]);
        i = vet[i];
    }

    for(int i = f.size()-1; i>=0;i--)
        cout << f[i] << " ";
    cout << endl;
   */
    
    



    return 0;
}