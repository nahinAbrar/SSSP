/* Asm Nahin
 * Single Source Shortest Path Using Topological Sorting
 * 15 January 2021
*/
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[50];
vector<int>parent(50);
vector<int>distancE(50);

list<int> topoOrder;
bool visited[50];
int cost[50][50];

void dfs(int source){
    visited[source] = 1;
    for(int i=0; i< graph[source].size(); i++)
    {
        int next = graph[source][i].first;
        if(visited[next] == 0)
            dfs(next);
    }
    topoOrder.push_front(source);

}

void topLogicalSort(int node){
    for(int i=1; i<=node; i++){
        if(visited[i] ==0)
            dfs(i);
    }
}

void initialize(int source, int node){
    for(int i=0; i<=node; i++)
    {
        distancE[i] = INT32_MAX;
        parent[i] = INT32_MIN;
    }
    distancE[source] = 0;

}

void relax(int src, int des, int wei){
    if(distancE[des] > distancE[src] + wei){
        distancE[des] = distancE[src] + wei;
        parent[des] = src;
    }
}

void SSSP(int source, int nodes){
    int i;
    topLogicalSort(nodes);
    cout << "Topological Order: "<<endl;
/*    for(auto it=topoOrder.begin(); it!=topoOrder.end(); it++)
        cout << (*it) << " ";*/
    for(int & it : topoOrder)
        cout << it << " ";

    cout << endl;


    initialize(source,nodes);
    while (!topoOrder.empty()){
        int u,size;
        u = topoOrder.front();
        topoOrder.pop_front();
        size = graph[u].size();
        for(i=0; i<size; i++)
        {
            relax(u,graph[u][i].first,graph[u][i].second);
            //Debug purpose
            /*cout << graph[u][i].first << "\t" << graph[u][i].second << endl << endl;*/
        }

    }
}

int main()
{
    int i,nodes, edges, src, des, weight, sourceNode;


    cout << "Enter Nodes: ";
    cin >> nodes;
    cout << "Enter Edges: ";
    cin >> edges;

    for(i=0; i<edges; i++)
    {
        cin >> src >> des >> weight;
        graph[src].push_back(make_pair(des,weight));

    }

    cout << "Enter Starting Source: ";
    cin >> sourceNode;

    SSSP(sourceNode,nodes);



    for(i=1; i<=nodes;i++)
    {
        cout << distancE[i] << " ";
    }
    return 21;
}


// Sample output check
/*Input
 * Nodes : 6, Edges : 7
1 2 2
2 3 3
3 4 6
1 5 1
5 3 2
5 6 4
6 1 1*/


/*Output
 * src node 1
1 2 2
1 5 1
1 3 3
1 4 6
1 6 5*/
