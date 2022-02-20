
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

shared_ptr_toy& make_shared(Toy * i_Toy, shared_support* i_sp)
{
    shared_ptr_toy* tmp = new shared_ptr_toy(i_Toy, i_sp);
    tmp->decrimentCount();
    return *tmp;
}


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
    shared_ptr_toy sptr7(sptr6);
    shared_ptr_toy sptr8;
    sptr8 = make_shared(mToy, spClass);
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
