#include <queue>
#include <iostream>
#include "Graph.h"

#define IDType unsigned int
#define VertexMPQ std::priority_queue<Vertex<ID>*, vector<Vertex<ID>*>, VertexCompare<ID>>

//Updates the distance value of toV if needed
template<typename ID>
void Relax(const Vertex<ID>& fromV, Vertex<ID>& toV, vector<ID>& parentArr)
{
    unsigned int newDist = fromV.GetWeight(toV.GetID()) + fromV.GetDistance();
    if(newDist < toV.GetDistance())
    {
        parentArr[toV.GetID()] = fromV.GetID();
        toV.SetDistance(newDist);
    }
}

//You can ignore this.
//This is just custom comparison logic to allow the priority_queue to work with Vertex objects 
template<typename ID>
class VertexCompare
{
public:
    bool operator()(const Vertex<ID>* lhs, const Vertex<ID>* rhs) const
    {
        if(lhs->GetDistance() > rhs->GetDistance())
        {
            return true;
        }
        else return false;
    }
};

//Must be called on an mpq after a value change
template<typename ID>
void Heapify(VertexMPQ& mpq)
{
    VertexMPQ tempMPQ;
    while(mpq.size() > 0)
    {
        tempMPQ.push(mpq.top());
        mpq.pop();
    }
    mpq = tempMPQ;
}

//Takes the graph and a starting vertex as parameters
template<typename ID>
vector<ID> Dikstras(Graph<ID> graph, ID startV)
{
    //ID array declared on the stack, needs to be deleted later
    vector<ID> parentArr(graph.GetSize(), 0);

    //Just treat this like a minimum priority queue for Vertex objects
    //No need to worry about the template at this time
    VertexMPQ mpq;    
    graph.GetVertex(startV).SetDistance(0);
    for(Vertex<ID>& v : graph.GetVertexVector())
    {
        mpq.push(&v);
    }
    
    while(!mpq.empty())
    {
        Vertex<ID>* currV = mpq.top();
        mpq.pop();
        vector<ID> aList = currV->GetAdjacencyList();
        //The index, i, is kept track of to find the corresponding weight value in a table
        for(int i = 0; i < aList.size(); ++i)   
        {
            Relax<ID>(*currV, graph.GetVertex(aList[i]), parentArr);
        }
        Heapify(mpq);
    }

    return parentArr;
}

template<typename ID>
void PrintArray(vector<ID> arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
    }
}

int main()
{
    std::ifstream inputFile("graph1.txt");
    Graph<IDType> graph(inputFile);
    vector<IDType> parentArray = Dikstras<IDType>(graph, 0);
    PrintArray(parentArray);
    return 0;
}