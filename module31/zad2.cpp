#include <iostream>
#include <string>
#include <vector>

enum { bufSize = 20 };

struct s_vertex
{
    int name;
    std::vector<int> adjacentVertex;
    std::vector<int> prevVertex;
};

class IGraph {

    public:

        s_vertex* vertexs;
        int count = 0;

        virtual ~IGraph() {}

        IGraph(s_vertex* i_vertexs, int& i_count) : vertexs(i_vertexs), count(i_count) {};

        IGraph(IGraph *_oth) {
            vertexs = _oth->vertexs;
            count = _oth->count;
        };

        virtual void AddEdge(s_vertex& from, s_vertex& to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро

        virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин

        virtual void GetNextVertices(s_vertex* vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной

        virtual void GetPrevVertices(s_vertex* vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

};

class ListGraph : public IGraph {

    public:

        ListGraph(s_vertex* i_vertexs, int& i_count) : IGraph(i_vertexs, i_count) {};
        ListGraph(IGraph* i_graph) : IGraph(i_graph) {
            for (int i=0; i < count; ++i) {
                for (int j=0; j < count; ++j) {
                    if (vertexs[i].adjacentVertex[j] == 1) {
                        vertexs[i].adjacentVertex[j] = j + 1;
                    }
                    if (vertexs[i].prevVertex[j] == 1) {
                        vertexs[i].prevVertex[j] = j + 1;
                    }
                }
            }
            std::vector<int> tmpVec;
            for (int i=0; i < count; ++i) {
                for (int j=0; j < count; ++j) {
                    if (vertexs[i].adjacentVertex[j] != 0) {
                        tmpVec.push_back(vertexs[i].adjacentVertex[j]);
                    }
                }
                vertexs[i].adjacentVertex = tmpVec;
                tmpVec.clear();
                for (int j=0; j < count; ++j) {
                    if (vertexs[i].prevVertex[j] != 0) {
                        tmpVec.push_back(vertexs[i].prevVertex[j]);
                    }
                }
                vertexs[i].prevVertex = tmpVec;
                tmpVec.clear();
            }
        };

        virtual ~ListGraph() {};

        virtual void AddEdge(s_vertex& from, s_vertex& to) {
            from.adjacentVertex.push_back(to.name);
            to.prevVertex.push_back(from.name);
            
        }

        virtual int VerticesCount() const {return count;}

        virtual void GetNextVertices(s_vertex* vertex, std::vector<int> &vertices) const {
            vertices = vertex->adjacentVertex;
        }
        virtual void GetPrevVertices(s_vertex* vertex, std::vector<int> &vertices) const {
            vertices = vertex->prevVertex;
        }
};

class MatrixGraph : public IGraph {

    public:

        MatrixGraph(s_vertex* i_vertexs, int& i_count) : IGraph(i_vertexs, i_count) {};

        MatrixGraph(IGraph* i_graph) : IGraph(i_graph) {
            for (int i=0; i < count; ++i) {
                std::vector<int> tmpVec(count);
                for (int j=0; j < vertexs[i].adjacentVertex.size(); ++j) {
                    int tmp = vertexs[i].adjacentVertex[j]; 
                    tmpVec[tmp-1] = 1;
                }
                vertexs[i].adjacentVertex = tmpVec;
                tmpVec.clear();
                tmpVec.resize(count);
                for (int j=0; j < vertexs[i].prevVertex.size(); ++j) {
                    int tmp = vertexs[i].prevVertex[j]; 
                    tmpVec[tmp-1] = 1;
                }
                vertexs[i].prevVertex = tmpVec;
                tmpVec.clear();
            }
        };

        virtual void AddEdge(s_vertex& from, s_vertex& to) {
            from.adjacentVertex[to.name - 1] = 1;
            to.prevVertex[from.name - 1] = 1;
        }

        virtual int VerticesCount() const {return count;}

        virtual void GetNextVertices(s_vertex* vertex, std::vector<int> &vertices) const {
            vertices = vertex->adjacentVertex;
        }

        virtual void GetPrevVertices(s_vertex* vertex, std::vector<int> &vertices) const {
            vertices = vertex->prevVertex;
        }
};

int main() {
    
    std::cout << "Insert vertex count:\n";
    int count = 0;
    std::cin >> count;

    s_vertex* vertexs = new s_vertex[count];
    for (int i=0; i < count; ++i) {
        vertexs[i].name = i+1;
        std::cout << vertexs[i].name << " ";
    }
    std::cout << "\n";

    std::string inp = "";
    std::cout << "Choose List graph(insert 'list') or Matrix graph (insert 'matrix'):\n";
    std::cin >> inp;
    if (inp == "matrix") {
        MatrixGraph msG(vertexs, count);
        for (int i=0; i < count; ++i) {
            vertexs[i].adjacentVertex.resize(count);
            vertexs[i].prevVertex.resize(count);
        }
        /*
        msG.AddEdge(vertexs[0], vertexs[2]);
        msG.AddEdge(vertexs[2], vertexs[1]);
        msG.AddEdge(vertexs[2], vertexs[3]);
        msG.AddEdge(vertexs[3], vertexs[4]);
*/
        int from, to;
        for (;;) {
            std::cout << "Add edge ( if done, enter '-1')\ninsert from: ";
            std::cin >> from;
            if ( from == -1) 
                break;
            std::cout << "insert to: ";
            std::cin >> to;
            msG.AddEdge(vertexs[from-1], vertexs[to-1]);
        }

        std::cout << "Adjacent matrix:\n";
        for (int i = 0; i < count; ++i)
            std::cout << "\t" << i+1;
        std::cout << "\n-------------------------------------------\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ":\t";
            msG.GetNextVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << "\t";
            }
            std::cout << "\n";
        }

        std::cout << "Matrix previous vertex:\n";
        for (int i = 0; i < count; ++i)
            std::cout << "\t" << i+1;
        std::cout << "\n-------------------------------------------\n";
        
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ":\t";
            msG.GetPrevVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << "\t";
            }
            std::cout << "\n";
        }

        ListGraph lsG(&msG);


        std::cout << "Adjacent list:\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ": ";
            lsG.GetNextVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "List previous vertex:\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ": ";
            lsG.GetPrevVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << " ";
            }
            std::cout << "\n";
        }

    } else if (inp == "list") {

        ListGraph lsG(vertexs, count);
        /*
        lsG.AddEdge(vertexs[0], vertexs[1]);
        lsG.AddEdge(vertexs[1], vertexs[3]);
        lsG.AddEdge(vertexs[2], vertexs[1]);
        lsG.AddEdge(vertexs[2], vertexs[3]);
        lsG.AddEdge(vertexs[2], vertexs[4]);
        lsG.AddEdge(vertexs[3], vertexs[0]);
        lsG.AddEdge(vertexs[3], vertexs[4]);
        */
       // /*
           int from, to;
           for (;;) {
           std::cout << "Add edge ( if done, enter '-1')\ninsert from: ";
           std::cin >> from;
           if ( from == -1) 
               break;
           std::cout << "insert to: ";
           std::cin >> to;
           lsG.AddEdge(vertexs[from-1], vertexs[to-1]);
           }
         //  */
        std::cout << "Adjacent list:\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ": ";
            lsG.GetNextVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "List previous vertex:\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ": ";
            lsG.GetPrevVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << " ";
            }
            std::cout << "\n";
        }
        
        MatrixGraph msG(&lsG);
        std::cout << "Adjacent matrix:\n";
        for (int i = 0; i < count; ++i)
            std::cout << "\t" << i+1;
        std::cout << "\n-------------------------------------------\n";
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ":\t";
            msG.GetNextVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << "\t";
            }
            std::cout << "\n";
        }

        std::cout << "Matrix previous vertex:\n";
        for (int i = 0; i < count; ++i)
            std::cout << "\t" << i+1;
        std::cout << "\n-------------------------------------------\n";
        
        for (int i =0; i< count; ++i) {
            std::vector<int> vec;
            std::cout << vertexs[i].name << ":\t";
            msG.GetPrevVertices(&vertexs[i], vec);
            for (int j=0; j < vec.size() ; ++j) {
                std::cout << vec[j] << "\t";
            }
            std::cout << "\n";
        }

    } else {
        std::cout << "Wrong type!\n";
    }
}
