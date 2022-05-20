#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
  for(auto element : v)
    out << element << " ";
  return out;
}

int main() {
  auto getUniqueNumbers = [](const std::vector<int>& source)
  {
    auto result = std::make_unique<std::vector<int>>();
    std::unordered_set<int> storage;
    for(auto value : source)
    {
      if(auto [pos, inserted] = storage.insert(value); inserted) {
        result->push_back(value);
      }
    }
    return result;
  };

  auto source = {1,1,11,12,12,17,76,77,77,77,87,78,78,5,5,7,7,8,1};
  std::cout << "Source: " << std::endl << source << std::endl;

  auto listOfUniqueNumbers = getUniqueNumbers(source);
  std::cout << "Unique numbers: " << std::endl << *listOfUniqueNumbers << std::endl;
} 
