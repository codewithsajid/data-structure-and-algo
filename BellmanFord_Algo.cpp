#include<iostream>
using namespace std;

struct Edge_node
{
    int source;
    int destination;
    int weight;
};

void print_Bell(int *dist, int n)
{
    cout<<"Vertex   Distance from Source\n";
    for(int i=0; i<n; i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}

void Bell_algo(Edge_node *input, int V, int E)
{
    int dist[V], par[V];
    for(int i=0; i<V; i++)
    {
        dist[i] = 99999;
        par[i] = 0;
    }
    dist[0] = 0;
    for(int i=1; i<V; i++)
    {
        for(int j=0; j<E; j++)
        {
            if(dist[input[j].source] != 99999 && dist[input[j].destination] > input[j].weight+dist[input[j].source])
                dist[input[j].destination] = input[j].weight+dist[input[j].source];
        }
    }
    for(int j=0; j<E; j++)
    {
        if(dist[input[j].source] != 99999 && dist[input[j].destination] > input[j].weight+dist[input[j].source])
            cout<<"Graph contains negative weight cycle";
    }
    print_Bell(dist, V);
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
    Bell_algo(input, V, E);
    return 0;
}
