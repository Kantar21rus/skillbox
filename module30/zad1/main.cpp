#include <iostream>
#include <cpr/cpr.h>


int main()
{
    cpr::Response r;
    std::string comand;
    do 
    { 
        std::cin >> comand;
        if (comand == "get")
        {
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << r.text << "\n";
        }
        else if (comand == "post")
        {
            r = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout << r.text << "\n";
        }
        else if (comand == "put")
        {
            r = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout << r.text << "\n";
        }
        else if (comand == "delete")
        {
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout << r.text << "\n";
        }
        else if (comand == "patch")
        {
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout << r.text << "\n";
        }
    }
    while ( comand != "exit");
}
