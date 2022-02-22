#include <iostream>

class Toy
{
    std::string name;

public:

    Toy(std::string i_name) : name(i_name) {}
    Toy() : Toy("Uknown") {}

    std::string getName() { return name; }

};
/*
class shared_support
{
    int count[100];
public:
    shared_support()
    {
        std::cout << "sp constructor\n";
        for (int i = 0; i < 100; ++i)
            count[i] = -1;
    }
    friend class shared_ptr_toy;
};
*/
class shared_ptr_toy
{
    int tmp = 1;
    int* count;
    Toy* toyPtr;

public:

    int id = 0;
    shared_ptr_toy(Toy* i_Toy) : toyPtr(i_Toy)
    {
        std::cout << "ptr constructor1\n";
        /*
        bool circle = true;
        while (circle)
        {
            if (i_sp->count[id] != -1)
                ++id;
            else
                circle = false;
        }
        if (i_sp->count[id] == -1)
        {
            i_sp->count[id] = 1;
            count = &(i_sp->count[id]);
        }
        else
        */
        count = &tmp;
    }

    shared_ptr_toy(shared_ptr_toy& i_spt)
    {
        std::cout << "ptr constructor2\n";
        ++(*i_spt.count);
        id = i_spt.id;
        count = i_spt.count;
        toyPtr = i_spt.toyPtr;
    }

    shared_ptr_toy() { count = nullptr; toyPtr = nullptr; }

    shared_ptr_toy& operator=(shared_ptr_toy& i_spt)
    {
        if (count != nullptr)
        {
            (*count)--;
            if (*count == 0)
                delete toyPtr;
        }
        count = i_spt.count;
        (*count)++;
        toyPtr = i_spt.toyPtr;
        id = i_spt.id;
        return *this;
    }

    void decrimentCount() { (*count)--; }
    int getCount() { return *count; }
    std::string getName() { return toyPtr->getName(); }

    ~shared_ptr_toy()
    {
        std::cout << toyPtr->getName() << " ptr destructor\n";
        if (*count > 1)
            --(*count);
        else
        {
            delete toyPtr;
            toyPtr = nullptr;
            *count = 0;
            count = nullptr;
        }
    }

};

shared_ptr_toy& make_shared(Toy* i_Toy)
{
    shared_ptr_toy* tmp = new shared_ptr_toy(i_Toy);
    tmp->decrimentCount();
    return *tmp;
}


int main()
{
//    shared_support* spClass = new shared_support;
    Toy* mToy = new Toy("Ball");
    Toy* mToy2 = new Toy("Bone");
    Toy* mToy3 = new Toy("Ball");

    shared_ptr_toy sptr1(mToy);
    shared_ptr_toy sptr2(sptr1);
    shared_ptr_toy sptr3(sptr1);
    shared_ptr_toy sptr4(sptr1);
    shared_ptr_toy sptr5(sptr1);
    shared_ptr_toy sptr6(mToy2);
    shared_ptr_toy sptr7(sptr6);
    shared_ptr_toy sptr8;
    sptr8 = make_shared(mToy3);
    std::cout << "Name: " << sptr1.getName() << " id " << sptr1.id << " count: " << sptr1.getCount() << "\n";
    std::cout << "Name: " << sptr6.getName() << " id " << sptr6.id << " count: " << sptr6.getCount() << "\n";
    std::cout << "Name: " << sptr7.getName() << " id " << sptr7.id << " count: " << sptr7.getCount() << "\n";
    std::cout << "Name: " << sptr8.getName() << " id " << sptr8.id << " count: " << sptr8.getCount() << "\n";
    sptr6 = sptr1;
    std::cout << "Name: " << sptr1.getName() << " id " << sptr1.id << " count: " << sptr1.getCount() << "\n";
    std::cout << "Name: " << sptr6.getName() << " id " << sptr6.id << " count: " << sptr6.getCount() << "\n";
    std::cout << "Name: " << sptr7.getName() << " id " << sptr7.id << " count: " << sptr7.getCount() << "\n";
    std::cout << "Name: " << sptr8.getName() << " id " << sptr8.id << " count: " << sptr8.getCount() << "\n";
}
