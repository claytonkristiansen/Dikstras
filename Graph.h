#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Vertex.h"


using std::vector;
using std::string;

class Graph
{
    unsigned int m_size = 0;
    vector<Vertex> m_vertices;

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
                vector<ID> adjList;
                std::stringstream stream(str);
                stream >> vID;
                stream >> comma;
                ID currID;
                while(stream >> currID)
                {
                    stream >> comma;
                    adjList.push_back(currID);
                }
                Vertex currV(vID, adjList);
                m_vertices.push_back(currV);
            }
            m_size = m_vertices.size();
        }
        else if(str == "weighted")
        {
            while(std::getline(inputFile, str))
            {
                ID vID;
                char comma;
                vector<ID> adjList;
                vector<unsigned int> weightList;
                std::stringstream stream(str);
                stream >> vID;
                stream >> comma;
                ID currID;
                unsigned int currWeight;
                while(stream >> currID && stream >> comma && stream >> currWeight)
                {
                    stream >> comma;
                    adjList.push_back(currID);
                    weightList.push_back(currWeight);
                }
                Vertex currV(vID, adjList, weightList);
                m_vertices.push_back(currV);
            }
            m_size = m_vertices.size();
        }
    }

    vector<Vertex>& GetVertexVector()
    {
        return m_vertices;
    }

    Vertex& GetVertex(ID id)
    {
        if(id < m_vertices.size())
        {
            return m_vertices[id];
        }
        return m_vertices[0];
    }
    void AddVertex(Vertex v)
    {
        m_vertices.push_back(v);
        m_size++;
    }

    unsigned int GetSize() const {return m_size;}
};