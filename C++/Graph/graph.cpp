#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v); //directed graph
    // graph[v].push_back(u); //undirected graph
}

void printGraph(vector<int> graph[], int vertex)
{
    for (int i = 0; i < vertex; ++i)
    {
        cout << i;
        for (auto j = 0; j < graph[i].size(); ++j)
            cout << " -> " << graph[i][j];
        cout << endl;
    }
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (!visited[*i])
            {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

void dfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty())
    {
        int v = s.top();
        cout << v << " ";
        s.pop();
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (!visited[*i])
            {
                s.push(*i);
                visited[*i] = true;
            }
        }
    }
}

vector<int> topologicalSortKahnAlgo(vector<int> graph[], int size)
{
    vector<int> result;
    queue<int> q;
    vector<int> indegree(size, 0);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < graph[i].size(); j++)
            indegree[graph[i][j]]++;

    for (int i = 0; i < indegree.size(); i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        result.push_back(v);
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            indegree[*i]--;
            if (indegree[*i] == 0)
                q.push(*i);
        }
    }
    return result;
}

void topologicalDFS(vector<int> graph[], vector<bool> &visited, stack<int> &result, int node)
{
    visited[node] = true;
    for (auto i = graph[node].begin(); i != graph[node].end(); i++)
        if (!visited[*i])
            topologicalDFS(graph, visited, result, *i);

    result.push(node);
}

//to check for cycle using dfs
bool checkCycleDFS(int node, vector<int> graph[], int visited[], int dfsVisited[])
{
    visited[node] = 1;
    dfsVisited[node] = 1;
    for (auto i : graph[node])
    {
        if (!visited[i]){
            if (checkCycleDFS(i, graph, visited, dfsVisited))
                return true;
        }

            else if (dfsVisited[i])
                return true;
    }
    dfsVisited[node] = 0;
    return false;
}

bool isCyclicDFS(int n, vector<int> graph[])
{
    int visited[n], dfsVisited[n];
    memset(visited, 0, sizeof visited);
    memset(dfsVisited, 0, sizeof dfsVisited);

    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (checkCycleDFS(i, graph, visited, dfsVisited))
                return true;

    return false;
}

void transposeGraph(vector<int> graph[], int vertex, vector<int> transpose[])
{
    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < graph[i].size(); j++)
            addEdge(transpose, graph[i][j], i);
}

void reverseDFS(int vertex, vector<bool> &visited, vector<int> transpose[])
{
    cout << vertex << " ";
    visited[vertex] = 1;
    for (auto i : transpose[vertex])
        if (!visited[i])
            reverseDFS(i, visited, transpose);
}

void kosarajuSCC(vector<int> graph[], int vertex)
{
    //topo sort
    vector<bool> visited(vertex, false);
    stack<int> result;
    topologicalDFS(graph, visited, result, 0);
    cout << "topological done..." << endl;

    //transpose graph
    vector<int> transpose[vertex];
    // for(int i = 0;i<vertex;i++)
    transposeGraph(graph, vertex, transpose);
    cout << "transpose done..." << endl;

    //reverse DFS
    while (!result.empty())
    {
        int node = result.top();
        result.pop();
        if (!visited[node])
        {
            cout << "SCC : ";
            reverseDFS(node, visited, transpose);
            cout << endl;
        }
    }
}

int main()
{
    int vertex = 4;
    vector<int> graph[vertex];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    // addEdge(graph, 2, 0);
    // addEdge(graph, 3, 3);
    cout << isCyclicDFS(vertex, graph); //true
    cout<<endl;
    // addEdge(graph, 0, 1);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 2, 0);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 3, 4);
    // dfs(graph, 0);
    // cout << endl;
    // vector<int> transpose[vertex];
    // transposeGraph(graph, vertex, transpose);
    // dfs(transpose, 0);
    // kosarajuSCC(graph,vertex);
    // addEdge(graph, 4, 5);
    // printGraph(graph, vertex);
    // bfs(graph, 0);
    // cout << endl;
    // dfs(graph, 0);
    // vector<int> res = topologicalSortKahnAlgo(graph, vertex);
    // if (res.size() != vertex)
    //     cout << "Not possible" << endl;
    // else
    // {
    //     for (int i : res)
    //         cout << i << " ";
    //     cout << endl;
    // }
    // cout<<endl;
    // vector<bool> visited(6,false);
    // stack<int> result;
    // topologicalDFS(graph,visited,result,0);
    // for(int i=0;i<result.size();i++){
    //     cout<<result.top()<<" ";
    //     result.pop();
    // }
}