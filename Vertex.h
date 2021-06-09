#include <vector>
#include <map>

using std::vector;
using std::map;

//#define ID unsigned int

template<typename ID>
class Vertex
{
    ID m_id;
    vector<ID> m_adjacencyList;
    map<ID, unsigned int> m_weightMap;
    unsigned int m_distance = UINT32_MAX;

public:

    Vertex(ID id, vector<ID> aList)
    {
        m_id = id;
        m_adjacencyList = aList;
        for(ID id : m_adjacencyList)
        {
            m_weightMap.insert(id, 1U);
        }
    }    
    Vertex(ID id, vector<ID> aList, map<ID, unsigned int> wList)
    {
        m_id = id;
        m_adjacencyList = aList;
        m_weightMap = wList;
    }

    ID GetID() const {return m_id;}
    void SetID(ID id) {m_id = id;}  

    unsigned int GetDistance() const {return m_distance;}
    void SetDistance(unsigned int distance) {m_distance = distance;}

    unsigned int GetWeight(ID vID) const
    {
        return m_weightMap[vID];
    }

    vector<ID> GetAdjacencyList()
    {
        return m_adjacencyList;
    }
};