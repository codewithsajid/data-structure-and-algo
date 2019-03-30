#include<iostream>
#include<algorithm>
using namespace std;

struct Edge_node
{
    int source;
    int destination;
    int weight;
};

bool compare(Edge_node e1, Edge_node e2)
{
    return e1.weight < e2.weight ;
}

int findParent(int m, int *parent)
{
    if(parent[m]==m)
        return m;
    else
        findParent(parent[m], parent);
}

void Kruskal_algo(Edge_node *input, int V, int E)
{
    sort(input, input + E, compare);
    Edge_node *output = new Edge_node[V-1];
    int *parent = new int[V];
    for(int i=0; i<V; i++)
    {
        parent[i] = i;
    }
    int Count = 0, j=0;
    while(Count != V-1)
    {
        Edge_node CurrentEdge = input[j];
        int sourcepParent = findParent(CurrentEdge.source, parent);
        int destParent = findParent(CurrentEdge.destination, parent);
        if(sourcepParent != destParent)
        {
            output[Count] = CurrentEdge;
            Count++;
            parent[sourcepParent] = destParent;
        }
        j++;
    }
    for(int i=0; i<V-1; i++)
    {
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }
    int Min_Cost = 0;
    cout<<endl<<"The Min Cost of the given graph is :";
    for(int i=0; i<V-1; i++)
        Min_Cost += output[i].weight;
    cout<<Min_Cost;
}

int main()
{
    int V, E;
    cout<<"Enter Number of Vertices and Edges :";
    cin>>V>>E;
    int s, d, w;
    Edge_node *input = new Edge_node[E];
    for(int i=0; i<E; i++)
    {
        cout<<"Enter source and destination of edge and its weight : ";
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }
    Kruskal_algo(input, V, E);
    return 0;
}
