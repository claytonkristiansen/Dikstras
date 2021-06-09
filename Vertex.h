#include <vector>

using std::vector;

#define ID unsigned int

class Vertex
{
    ID m_id;
    vector<ID> m_adjacencyList;
    vector<unsigned int> m_weightList;
    unsigned int m_distance = UINT32_MAX;

public:

    Vertex(ID id, vector<ID> aList)
        :m_weightList(aList.size(), 1)
    {
        m_id = id;
        m_adjacencyList = aList;
    }    
    Vertex(ID id, vector<ID> aList, vector<unsigned int> wList)
    {
        m_id = id;
        m_adjacencyList = aList;
        m_weightList = wList;
    }

    ID GetID() const {return m_id;}
    void SetID(ID id) {m_id = id;}  

    unsigned int GetDistance() const {return m_distance;}
    void SetDistance(unsigned int distance) {m_distance = distance;}

    unsigned int GetWeight(ID vertex) const
    {
        if(vertex < m_weightList.size())
        {
            return m_weightList[vertex];
        }
        else return 0;
    }

    vector<ID> GetAdjacencyList()
    {
        return m_adjacencyList;
    }
};