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

int main(){
    int c;
    cin >> c;
    for(int a=0;a<c;a++){
        int n, q;
        cin >> n >> q;
        Graph *g = create_graph(n);

        while (q>0){
            int i,j;
            cin >> i >> j;
            setEdge(g,i,j,1);
            q--;
        }     

        int c2;
        cin >> c2;
        cout << "Caso " << a+1 << endl;
        while(c2>0){
            int vet[n];
            for(int i=0;i<n;i++){vet[i] = -1; setMark(g,i,UNVISITED);}
            int start, target;
            cin >> start >> target;
            BFS(g, start, target, vet);  
            
            if(vet[target] != -1){
                vector<int> f;
                for(int i=target, j=0;i!= start && j<g->numNode;j++){
                    f.push_back(vet[i]);
                    i = vet[i];
                }
                cout << f.size() << endl;
                
            }
            else{
                cout << -1 << endl;
            }
            c2--;
        }    
    }

    return 0;
}