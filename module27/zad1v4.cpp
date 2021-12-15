#include <iostream>
#include <vector>

class Branch
{
    Branch* parent = nullptr;
    Branch* thisBranch = this;
    std::string elfName = "None";

    public:

    std::vector<Branch*> children;

    void setParent(Branch* in_parent)
    {
        parent = in_parent;
    }

    void setChildren()
    {
        Branch* newBranch = new Branch;
        newBranch->setParent(this);
        newBranch->setName();
        children.push_back(newBranch);
    }

    void setName()
    {
        std::cout << "Insert elf's Name\n";
        std::cin >> elfName;
    }

    void getName()
    {
        std::cout << elfName << "\n";
    }

    void getChildren()
    {
        for (int i=0; i<children.size(); ++i)
        {
            children[i]->getName();       
        }
    }
};

int main()
{
    int countChildren = 0;
    Branch* three = new Branch;
    three->setChildren();
    countChildren++;
    three->setChildren();
    countChildren++;
    three->setChildren();
    countChildren++;
    for (int i=0 ; i < countChildren; ++i)
    {
        three->children[i]->setChildren();
    }
    std::cout << "Children in three\n";
    three->getChildren();
    std::cout << "Children in children\n";
    for (int i=0 ; i < countChildren; ++i)
    {
        three->children[i]->getChildren();
    }
}
