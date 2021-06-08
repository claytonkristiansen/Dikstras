#include <queue>
#include "Graph.h"

//Updates the distance value of toV if needed
void Relax(Vertex fromV, Vertex toV)
{
    unsigned int newDist = fromV.GetWeight(toV.GetID()) + fromV.GetDistance();
    if(newDist < toV.GetDistance())
    {
        toV.SetDistance(newDist);
    }
}

//You can ignore this.
//This is just custom comparison logic to allow the priority_queue to work with Vertex objects 
class VertexCompare
{
public:
    bool operator()(const Vertex& lhs, const Vertex& rhs) const
    {
        if(lhs.GetDistance() < rhs.GetDistance())
        {
            return true;
        }
        else return false;
    }
}

//Takes the graph and a starting vertex as parameters
ID* Dikstras(Graph graph, ID startV)
{
    //ID array declared on the stack, needs to be deleted later
    ID* parentArr = new ID[graph.GetSize()];

    //Just treat this like a minimum priority queue for Vertex objects
    //No need to worry about the template at this time
    std::priority_queue<Vertex, vector<Vertex>> mpq;    



    return parentArr;
}



int main()
{
    std::ifstream inputFile("graph1.txt");
    Graph graph(inputFile);
    Dikstras(graph);
    return 0;
}