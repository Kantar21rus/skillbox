#include <iostream>

class Toy
{
    std::string name;

    public:

    Toy(std::string i_name) : name(i_name) {}
    Toy() : Toy("Uknown") {}

    std::string getName() { return name;}

};

class shared_support
{
    int count[100];
    public:
    shared_support()
    {
        std::cout << "sp constructor\n";
        for (int i=0; i<100; ++i)
            count[i] = -1;
    }
    friend class shared_ptr_toy;
};

class shared_ptr_toy
{
    int* count;
    Toy* toyPtr;

    public:

    int id = 0;
    shared_ptr_toy(Toy* i_Toy, shared_support* i_sp) : toyPtr(i_Toy)
    {
        std::cout << "ptr constructor1\n";
        bool circle = true;
        while(circle)
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
        {
            ++i_sp->count[id];
            count = &(i_sp->count[id]);
        }
    }

    shared_ptr_toy(shared_ptr_toy& i_spt)
    {
        std::cout << "ptr constructor2\n";
        ++(*i_spt.count);
        count = i_spt.count;
        toyPtr = i_spt.toyPtr;
    }

    shared_ptr_toy() {}
    
    int getCount() {return *count;}

    ~shared_ptr_toy()
    {
        std::cout << "ptr destructor\n";
        if (*count > 1) 
            --(*count);
        else
        {
            delete toyPtr;
            *count = 0;
            count = nullptr;
        }
    }

};
/*
shared_ptr_toy make_shared(Toy * i_Toy)
{
    shared_ptr_toy tmp(i_Toy);
    return tmp;
}
*/

int main()
{
    shared_support* spClass = new shared_support;
    Toy* mToy = new Toy("Ball");
    Toy* mToy2 = new Toy("Bone");

    shared_ptr_toy sptr1(mToy, spClass);
    shared_ptr_toy sptr2(sptr1);
    shared_ptr_toy sptr3(sptr1);
    shared_ptr_toy sptr4(sptr1);
    shared_ptr_toy sptr5(sptr1);
    shared_ptr_toy sptr6(mToy2, spClass);
    std::cout << "Name: " << mToy->getName() << " id " << sptr1.id  << " count: " << sptr1.getCount() << " " << sptr2.getCount() << "\n";
    std::cout << "Name: " << mToy2->getName() << " id " << sptr6.id  << " count: " << sptr6.getCount() << "\n";

}
