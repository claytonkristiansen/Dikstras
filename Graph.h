#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Vertex.h"


using std::vector;
using std::string;



template<typename ID>
class Graph
{
    unsigned int m_size = 0;
    vector<Vertex<ID>> m_vertices;

public:

    Graph(std::ifstream& inputFile)
    {
        string str;
        std::getline(inputFile, str);
        if(str == "unweighted")
        {
            while(std::getline(inputFile, str))
            {
                ID vID;
                char comma;
                vector<Edge<ID>> edgeList;
                std::stringstream stream(str);
                stream >> vID;
                stream >> comma;
                ID currID;
                while(stream >> currID)
                {
                    stream >> comma;
                    Edge<ID> e(currID, 1);
                    edgeList.push_back(e);
                }
                Vertex<ID> currV(vID, edgeList);
                AddVertex(currV);
            }
            m_size = m_vertices.size();
        }
        else if(str == "weighted")
        {
            while(std::getline(inputFile, str))
            {
                ID vID;
                char comma;
                vector<Edge<ID>> edgeList;
                std::stringstream stream(str);
                stream >> vID;
                stream >> comma;
                ID currID;
                unsigned int currWeight;
                while(stream >> currID && stream >> comma && stream >> currWeight)
                {
                    stream >> comma;
                    Edge<ID> e(currID, currWeight);
                    edgeList.push_back(e);
                }
                Vertex<ID> currV(vID, edgeList);
                AddVertex(currV);
            }
            m_size = m_vertices.size();
        }
    }

    unsigned int IdToIndex(unsigned int id)
    {
        return id;
    }

    unsigned int IdToIndex(string id)
    {
        return 0;  //TODO: implement string to id functionality
    }

    void AddVertex(Vertex<unsigned int> v)
    {
        m_vertices.push_back(v);
        m_size++;
    }

    void AddVertex(Vertex<string> v)
    {
        m_vertices.push_back(v);    //TODO: implement string add vertex functionality
        m_size++;
    }

    vector<Vertex<ID>>& GetVertexVector()
    {
        return m_vertices;
    }

    Vertex<ID>& GetVertex(ID id)
    {
        unsigned int index = IdToIndex(id);
        if(index < m_vertices.size())
        {
            return m_vertices[index];
        }
        return m_vertices[0];
    }
    

    unsigned int GetSize() const {return m_size;}
};