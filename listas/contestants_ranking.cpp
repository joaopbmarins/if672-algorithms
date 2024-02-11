#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define VISITED 1
#define endl "\n"

typedef struct Graph{
    map<string, vector<string>> list_a;
    map<string, bool> Mark;
    map<string, int> dist;
    int numEdge;
    int numNode;
}Graph;

void setMark(Graph *g, string v, bool state){
    g->Mark[v] = state;
}

bool getMark(Graph *g, string v){
    return g->Mark[v];
}

Graph *create_graph(int n){
    Graph *g = new Graph;
    g->numNode = n;
    g->numEdge = 0;
    return g;
}

void setEdge(Graph *g, string i, string j){
    g->list_a[i].push_back(j);
    g->numEdge++;
    return;
}


void BFS(Graph *g, string start){
    queue<string> q;
    q.push(start);
    setMark(g, start, VISITED);
    g->dist[start] = 0;
    while(q.size() > 0){
        string v = q.front();
        q.pop();
        //preVisit
        auto aux = g->list_a[v];
        for(int w=0;w<aux.size();w++){
            if(getMark(g, aux[w]) == UNVISITED){
                g->dist[aux[w]] = g->dist[v] + 1; 
                setMark(g, aux[w], VISITED);
                q.push(aux[w]);
            }
        }
        //posVisit
    }  
}

int main(){

    int c;
    cin >> c;
    while(c>0){
        int numTeam, maxNode;
        cin >> numTeam;
        maxNode = numTeam * 3;
        Graph *g = create_graph(maxNode);

        for(int i=0;i<numTeam;i++){
            string fulano, ciclano, beltrano;
            cin >> fulano >> ciclano >> beltrano;

            setEdge(g, fulano, ciclano);
            setEdge(g, fulano, beltrano);

            setEdge(g, ciclano, fulano);
            setEdge(g, ciclano, beltrano);
            
            setEdge(g, beltrano, fulano);
            setEdge(g, beltrano, ciclano);

            g->dist[fulano] = -1;
            g->dist[ciclano] = -1;
            g->dist[beltrano] = -1;
        }
        cout << g->list_a.size() << endl;
        //nao mexa

        BFS(g, "Ahmad");

        map<int, vector<string>> flip_dist;
        for(auto i = g->dist.begin(); i != g->dist.end();i++){
            flip_dist[(*i).second].push_back((*i).first);
        }
        
        for(int i=0;i<g->list_a.size();i++){
            for(int j=0;j<flip_dist[i].size();j++){
                cout << flip_dist[i][j] << " " << i << endl;
            }
        }

        for(int i=0;i<flip_dist[-1].size();i++){
            cout << flip_dist[-1][i] << " undefined" << endl;
        }
        


        c--;
    }

    return 0;
}