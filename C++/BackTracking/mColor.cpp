#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node,vector<int> color, bool graph[101][101],int v,int col){
    for(int i=0;i<v;i++)
        if(i!=node and graph[i][node]==1 and color[i]==col)
            return false;
    return true;
}

bool solve(int node, vector<int> color,int m,int v,bool graph[101][101]){
    if(node == v)
        return true;
    
    for(int i=1;i<=m;i++)
        if(isSafe(node,color,graph,v,i)){
            color[node] = i;
            if(solve(node+1,color,m,v,graph))
                return true;
            color[node] = 0;
        }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V);
    if(solve(0,color,m,V,graph))
        return true;
    return false;
}

int main(){
    // bool graph
}