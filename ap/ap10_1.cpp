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
    cout << v << " ";
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

void BFS(Graph *g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, VISITED);
    while(q.size() > 0){
        int v = q.front();
        q.pop();
        //preVisit
        cout << v << " ";
        int w = first(g, v);
        while(w < g->numNode){
            if(getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next(g, v, w);
        }
        //posVisit
    }  
}

void graphTraverse(Graph *g, const bool &bfs){
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }
    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            if(bfs)
                BFS(g, v);
            else
                DFS(g, v);
        }
    }
}

void graphTraverse(Graph *g, const bool &bfs, int start){
    for(int v = 0; v < g->numNode; v++){
        setMark(g, v, UNVISITED);
    }

    if(bfs)
        BFS(g, start);
    else
        DFS(g, start);

    for(int v = 0; v < g->numNode; v++){
        if(getMark(g, v) == UNVISITED){
            if(bfs)
                BFS(g, v);
            else
                DFS(g, v);
        }
    }
}

void toposort(Graph *g, int v, stack<int> &s){
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < g->numNode){
        if(getMark(g,w) == UNVISITED){
            toposort(g,w,s);
        }
        w = next(g,v,w);
    }
    s.push(v);
}

int main(){

    int n, q;
    cin >> n >> q;

    Graph *g = create_graph(n);

    while(q>0){
        string comando;
        cin >> comando;
        if(comando == "add"){
            int i,j;
            cin >> i >> j;
            setEdge(g, i, j, 1);
            setEdge(g, j, i, 1);
        }
        else if(comando == "BFS"){
            int v;
            cin >> v;
            graphTraverse(g, true, v);
            cout << endl;
        }
        else if(comando == "DFS"){
            int v;
            cin >> v;
            graphTraverse(g, false, v);
            cout << endl;
        }
        q--;
    }
/* //Topological Sort
    for(int i=0;i<n;i++){
        setMark(g,i,UNVISITED);
    }
    stack<int> s;
    toposort(g, 0, s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
*/

    return 0;
}