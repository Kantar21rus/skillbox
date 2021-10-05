#include <iostream>
#include <map>
#include <string>

bool itsAnagram(std::string str1, std::string str2)
{
    std::map<char, int> string1;
    std::map<char, int> string2;

    for (char i='a'; i <= 'z'; ++i)
    {
        int count = 0;
        for (int j=0; j < str1.length(); ++j)
        {
            if (str1[j] == i)
                ++count;
        }
        string1.insert(std::pair<char, int>(i, count));
    }
    for (char i='a'; i <= 'z'; ++i)
    {
        int count = 0;
        for (int j=0; j < str2.length(); ++j)
        {
            if (str2[j] == i)
                ++count;
        }
        string2.insert(std::pair<char, int>(i, count));
    }
    std::map<char, int>::iterator itr1 = string1.begin();
    std::map<char, int>::iterator itr2 = string2.begin();
    for (int i=0; i < ('z'-'a'+1); ++i)
    {
        if (itr1->second != itr2->second)
            return false;
        ++itr1;
        ++itr2;
    }
  return true;
}

int main()
{
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    if (itsAnagram(str1, str2))
        std::cout << "It's anagram\n";
    else 
        std::cout << "It's NOT anagram\n";
}
