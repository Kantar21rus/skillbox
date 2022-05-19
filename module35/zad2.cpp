#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>


int main() {
    std::vector<int> intVec = {1, 5, 3, 2, 4, 5, 3, 1, 2};
    auto uptr = [](std::vector<int> vec){
        std::unordered_set<int> unSet;
        auto uptr(std::make_unique<std::vector<int>>()); 
        for (auto itr : vec) {
            unSet.insert(itr);
        }
        for (auto itr : unSet) {
            uptr->push_back(itr);
        }
        return uptr;
    }(intVec);
    for (auto iter = uptr->begin(); iter != uptr->end(); ++iter) {
        std::cout << *iter << "\n";
    }

}
