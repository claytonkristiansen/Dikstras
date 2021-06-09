#include <vector>
#include <map>

using std::vector;
using std::map;

//#define ID unsigned int

template<typename ID>
struct Edge
{
    ID VertId;
    unsigned int Weight;
    Edge(ID id, unsigned int weight)
    {
        VertId = id;
        Weight = weight;
    }
};

template<typename ID>
class Vertex
{
    ID m_id;
    vector<Edge<ID>> m_edgeList;
    unsigned int m_distance = UINT32_MAX;

public:

    Vertex(ID id, vector<Edge<ID>> eList)
    {
        m_id = id;
        m_edgeList = eList;
    }    

    ID GetID() const {return m_id;}
    void SetID(ID id) {m_id = id;}  

    unsigned int GetDistance() const {return m_distance;}
    void SetDistance(unsigned int distance) {m_distance = distance;}

    unsigned int GetWeight(ID vID) const
    {
        return this->m_weightMap.at(vID);
    }

    vector<Edge<ID>> GetEdgeList()
    {
        return m_edgeList;
    }
};