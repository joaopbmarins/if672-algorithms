#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define UNVISITED 0
#define VISITED 1

typedef struct{
    int **matrix;
    int numEdge;
    int *Mark;
    int numNode;
}Graph;

void setMark(Graph *g, int v, int state){
    g->Mark[v] = state;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

Graph *create_graph(const int n){   
    Graph *g = new Graph;
    g->numNode = n;
    g->Mark = new int[n]();
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

void DFS(Graph *g, int v){
    //preVisit
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < g->numNode){
        if(getMark(g, w) == UNVISITED){
            DFS(g, w);
        }
        w = next(g, v, w);
    }
    //posVisit
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
        int w = first(g, v);
        while(w < g->numNode){
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
            w = next(g, v, w);
        }
        //posVisit
    }  
}

/*
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
*/
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
    /*
    BFS(g, 5);
    for(int i=0;i<g->numNode;i++){
        cout << g->dest[i] << " ";
    }
    cout << endl;
    */
    
    

   
   int vet[n];
   for(int i=0;i<n;i++) vet[i] = -1;
   int start, target;
   cin >> start >> target;
    BFS(g, start, target, vet);  
    
    for(int i : vet)
        cout << i << " ";
    cout << endl;
    if(vet[target] != -1){
        vector<int> f;
        
        for(int i=target, j=0;i!= start && j<g->numNode;j++){
            f.push_back(vet[i]);
            i = vet[i];
        }

        for(int i = f.size()-1; i>=0;i--)
            cout << f[i] << " ";
        cout << endl;
    }

    return 0;
}