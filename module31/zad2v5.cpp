#include <iostream>
#include <vector>
#include <map>

class IGraph {
public:
    virtual ~IGraph() {}
    IGraph() {};
    IGraph(IGraph *_oth) {};
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};

void vectorSort(std::vector<int> &vec, int j) {
    int tmp;
    tmp = vec[j+1];
    vec[j+1] = vec[j];
    vec[j] = tmp;
}

void matrixSort(std::vector<std::vector<int>> &matrix) {
    int vecSize = matrix[0].size();
    int matSize = matrix.size();
    for (int i=0; i < vecSize; ++i) {
        for (int j=1; j < (vecSize-i-1); ++j) {
            int tmp;
            if (matrix[0][j] > matrix[0][j+1]) {
                tmp = matrix[0][j+1];
                matrix[0][j+1] = matrix[0][j];
                matrix[0][j] = tmp;
                for (int k=1; k < matSize; ++k) {
                    vectorSort(matrix[k], j);
                }
            }
        }
    }
    for (int i=0; i < matSize; ++i) {
        for (int j=1; j < (matSize-i-1); ++j) {
            std::vector<int> tmp;
            if (matrix[j] > matrix[j+1]) {
                tmp = matrix[j+1];
                matrix[j+1] = matrix[j];
                matrix[j] = tmp;
            }
        }
    }
}

struct edgeTable {
    int from;
    int to;
};

class MatrixGraph : public IGraph {
    int matrixSize = 0;
    std::vector<int> vertex;
    //MatrixGraph* ptr = nullptr;
    
    public:
    
        std::vector<std::vector<int>> matrix;

        MatrixGraph(int tmp) {};

        MatrixGraph(IGraph* _oth);

        bool searchVertex(int i_search) {
            for (int i=0; i < vertex.size(); ++i) {
                if (i_search == vertex[i]) {
                    return true;
                }
            }
            return false;
        }

        void resizeMatrix(int i_int) {
            matrix.resize(i_int);
            for (int i=0; i < i_int; ++i) {
                matrix[i].resize(i_int);
            }
          //  std::cout << matrix.size() << "\n";
        }
        void showMatrix() {
            for (int i=0; i < matrix.size(); ++i) {
                for (int j=0; j < matrix[0].size(); ++j) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        void addToMatrix(int add) {
            ++matrixSize;
            resizeMatrix(matrixSize);
            matrix.back()[0] = add;
            matrix[0].back() = add;
            vertex.push_back(add);
        }

        int getVectorIndex(int i_search) const {
            for (int i=1; i < matrix.size(); ++i) {
                if (matrix[i][0] == i_search) {
                    return i;
                }
            }
            return -1;
        }

        virtual void AddEdge(int from, int to) {
            std::cout << from << " -> " << to << "\n";
            if (vertex.empty()) {
                vertex.push_back(from);
                vertex.push_back(to);
                matrixSize = 3;
                resizeMatrix(matrixSize);
                matrix[0][0] = 0;
                matrix[1][0] = from;
                matrix[1][1] = 0;
                matrix[1][2] = 1;
                matrix[2][0] = to;
                matrix[2][1] = 0;
                matrix[2][2] = 0;
                matrix[0][1] = from;
                matrix[0][2] = to;
            } else {
                int t1 = searchVertex(from);
                int t2 = searchVertex(to);
                if (t1  and t2) {
                    int i = getVectorIndex(from);
                    if (i == 0) {
                        std::cout << "error in getVectorIndex\n";
                    }
                    int j = getVectorIndex(to);
                    if (j == 0) {
                        std::cout << "error in getVectorIndex\n";
                    }
                    matrix[i][j] = 1;
                } else if (t1  and !t2) {
                    addToMatrix(to);
                    int i = getVectorIndex(from);
                    if (i == 0) {
                        std::cout << "error in getVectorIndex\n";
                    }
                    matrix[i].back() = 1;
                } else if (!t1  and t2) {
                    addToMatrix(from);
                    int j = getVectorIndex(to);
                    if (j == 0) {
                        std::cout << "error in getVectorIndex\n";
                    }
                    matrix.back()[j] = 1;
                } else if (!t1  and !t2) {
                    addToMatrix(from);
                    addToMatrix(to);
                    int i = getVectorIndex(from);
                    if (i == 0) {
                        std::cout << "error in getVectorIndex\n";
                    }
                    matrix[i].back() = 1;
                }
            }
        }

        virtual int VerticesCount() const {
            return vertex.size();
        } // Метод должен считать текущее количество вершин

        void showVertex() {
            std::cout << "vertex: ";
            for (int i=0; i < vertex.size(); ++i) {
                std::cout << vertex[i] << " ";
            }
            std::cout << "\n";
        }

        virtual void GetNextVertices(int i_vertex, std::vector<int> &vertices) const {
            vertices.clear();
            int i = getVectorIndex(i_vertex);
            for (int j=1; j < matrix.size(); ++j) {
                if (matrix[i][j] == 1) {
                    vertices.push_back(matrix[0][j]);
                }
            }
        } // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
        virtual ~MatrixGraph() {}

        virtual void GetPrevVertices(int i_vertex, std::vector<int> &vertices) const {
            vertices.clear();
            int j = getVectorIndex(i_vertex);
            for (int i=1; i < matrix.size(); ++i) {
                if (matrix[i][j] == 1) {
                    vertices.push_back(matrix[i][0]);
                }
            }
        } // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную

        void getEdge(std::vector<edgeTable> &i_table) {
            int count = matrix.size();
            for (int i=1; i < count; ++i) {
                edgeTable tmp;
                tmp.from = matrix[i][0];
                for (int j = 1; j < count; ++j) {
                    if (matrix[i][j] == 1) {
                        tmp.to = matrix[0][j];
                        i_table.push_back(tmp);
                    }
                }
            }
        }
};

class ListGraph : public IGraph {
    struct s_vertex {
        int name;
        std::vector<int> adjacentVertex;
        std::vector<int> prevVertex;
    };


    int getVectorIndex(int i_search) const {
        for (int i=0; i < vertex.size(); ++i) {
            if (vertex[i].name == i_search) {
                return i;
            }
        }
        return -1;
    }
    bool searchVertex(int i_search) {
        for (int i=0; i < vertex.size(); ++i) {
            if (i_search == vertex[i].name) {
                return true;
            }
        }
        return false;
    }
    public:
    std::vector<s_vertex> vertex;

    ListGraph(int i) {};
    ListGraph(IGraph* i_graph);

    virtual ~ListGraph() {};

    virtual void AddEdge(int from, int to) {
        std::cout << from << " -> " << to << "\n";
        if (vertex.empty()) {
            s_vertex tmp1, tmp2;
            tmp1.name = from;
            tmp1.adjacentVertex.push_back(to);
            vertex.push_back(tmp1);
            tmp2.name = to;
            tmp2.prevVertex.push_back(from);
            vertex.push_back(tmp2);
        } else {
            int t1 = searchVertex(from);
            int t2 = searchVertex(to);
            if (t1  and t2) {
                int i = getVectorIndex(from);
                vertex[i].adjacentVertex.push_back(to);
                int j = getVectorIndex(to);
                vertex[j].prevVertex.push_back(from);
            } else if (t1  and !t2) {
                int i = getVectorIndex(from);
                vertex[i].adjacentVertex.push_back(to);
                s_vertex tmp;
                tmp.name = to;
                tmp.prevVertex.push_back(from);
                vertex.push_back(tmp);
            } else if (!t1  and t2) {
                s_vertex tmp;
                tmp.name = from;
                tmp.adjacentVertex.push_back(to);
                vertex.push_back(tmp);
                int j = getVectorIndex(to);
                vertex[j].prevVertex.push_back(from); 
            } else if (!t1  and !t2) {
                s_vertex tmp1, tmp2;
                tmp1.name = from;
                tmp1.adjacentVertex.push_back(to);
                vertex.push_back(tmp1);
                tmp2.name = to;
                tmp2.prevVertex.push_back(from);
                vertex.push_back(tmp2);
            }
        }
    }

    virtual int VerticesCount() const {return vertex.size();}

    virtual void GetNextVertices(int i_vertex, std::vector<int> &vertices) const {
        vertices.clear();
        int j = getVectorIndex(i_vertex);
        vertices = vertex[j].adjacentVertex;
    }
    virtual void GetPrevVertices(int i_vertex, std::vector<int> &vertices) const {
        vertices.clear();
        int j = getVectorIndex(i_vertex);
        vertices = vertex[j].prevVertex;
    }

    void showList() {
        for (int i=0; i < vertex.size(); ++i) {
            std::cout << vertex[i].name << ": ";
            for (int j=0; j <vertex[i].adjacentVertex.size(); ++j) {
                std::cout << vertex[i].adjacentVertex[j] << " ";
            }
            std::cout << "\n";
        }
    }

    void listSort() {
        int size = vertex.size();
        for (int i=0; i < size; ++i) {
            s_vertex tmp;
            for (int j=0; j < size - i - 1; ++j) {
                if (vertex[j].name > vertex[j+1].name) {
                    tmp = vertex[j+1];
                    vertex[j+1] = vertex[j];
                    vertex[j] = tmp;
                }
            }
        }
    }

    void getEdge(std::vector<edgeTable> &i_table) {
        int count = vertex.size();
        for (int i=0; i < count; ++i) {
            edgeTable tmp;
            if (vertex[i].adjacentVertex.empty()) {
                continue;
            }
            tmp.from = vertex[i].name;
            for (int j=0; j < vertex[i].adjacentVertex.size(); ++j) {
                tmp.to = vertex[i].adjacentVertex[j];
                i_table.push_back(tmp);
            }
        }
    }
};

MatrixGraph::MatrixGraph(IGraph* _oth) {
    ListGraph* tmp = (ListGraph*) _oth;
    std::vector<edgeTable> edges;
    tmp->getEdge(edges);
    int count = edges.size();
    for (int i=0; i < count; ++i) {
        this->AddEdge(edges[i].from, edges[i].to);
    }
};

ListGraph::ListGraph(IGraph* _oth) {
    MatrixGraph* tmp = (MatrixGraph*) _oth;
    std::vector<edgeTable> edges;
    tmp->getEdge(edges);
    int count = edges.size();
    for (int i=0; i < count; ++i) {
        this->AddEdge(edges[i].from, edges[i].to);
    }
};

int main() {
    if (true) {
        MatrixGraph mMG(1);
        mMG.AddEdge(1, 3);
        mMG.AddEdge(3, 2);
        mMG.AddEdge(2, 3);
        mMG.AddEdge(3, 4);
        mMG.AddEdge(4, 5);
        mMG.AddEdge(8, 5);
        mMG.AddEdge(6, 7);
        mMG.showVertex();
        std::cout << mMG.VerticesCount() << "\n";

        mMG.showMatrix();
        matrixSort(mMG.matrix);
        std::cout << "------------------------------------\n";
        mMG.showMatrix();
        std::vector<int> vertices;
        mMG.GetNextVertices(3, vertices);
        std::cout << "vertices: ";
        for (int i=0; i < vertices.size(); ++i) {
            std::cout << vertices[i] << " ";
        }
        std::cout << "\n";
        std::vector<int> vertices2;
        mMG.GetPrevVertices(3, vertices2);
        std::cout << "vertices2: ";
        for (int i=0; i < vertices2.size(); ++i) {
            std::cout << vertices2[i] << " ";
        }
        std::cout << "\n";
        ListGraph LG(&mMG);
        LG.showList();
    } else {
        ListGraph LG(1);
        LG.AddEdge(1, 3);
        LG.AddEdge(3, 2);
        LG.AddEdge(2, 3);
        LG.AddEdge(3, 4);
        LG.AddEdge(4, 5);
        LG.AddEdge(8, 5);
        LG.AddEdge(6, 7);
        std::cout << LG.VerticesCount() << "\n";
        LG.showList(); 
        std::cout << "------------------------------------\n";
        LG.listSort();
        LG.showList();
        std::vector<int> vertices;
        LG.GetNextVertices(3, vertices);
        std::cout << "vertices: ";
        for (int i=0; i < vertices.size(); ++i) {
            std::cout << vertices[i] << " ";
        }
        std::cout << "\n";
        std::vector<int> vertices2;
        LG.GetPrevVertices(3, vertices2);
        std::cout << "vertices2: ";
        for (int i=0; i < vertices2.size(); ++i) {
            std::cout << vertices2[i] << " ";
        }
        std::cout << "\n";
        MatrixGraph MG(&LG);
        MG.showMatrix();
    }
}
