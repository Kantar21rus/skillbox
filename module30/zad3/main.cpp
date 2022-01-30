#include <iostream>
#include <cpr/cpr.h>
#include <vector>

struct request 
{
    char full_body[200] = {0};
    char arguments[180] = {0};
    char buffer[50] = {0};
    std::string type;
    int pos_req = 0;
    int pos_arg = 0;
    int count_arg = 0;
};

void addString(char* str, int &pos, std::string add)
{
    int j=0;
    for(int i = pos + add.length(); pos < i; ++pos)
    {
        str[pos] = add[j];
        j++;
    }
}

void addArguments(char* body, char* arg, int &pos_req, int pos_arg)
{
    for(int i=0; i < pos_arg; ++i)
    {
        body[pos_req++] = arg[i];
    }
}

void showString(char* req, int pos)
{
    for (int i=0; i<pos; ++i)
    {
        std::cout << req[i];
    }
    std::cout << "\n";
}

void parcingArguments(std::vector<cpr::Pair> &pairs, char* arguments, int pos_arg, int count_arg)
{
    std::string arg = "";
    std::string value = "";
    int pos=0;
    for(int i=0; i<count_arg; ++i)
    {
        arg = "";
        value = "";
        while(arguments[pos] != '=')
        {
            arg += arguments[pos++];
        }
        ++pos;
        while(arguments[pos] != '&')
        {
           value += arguments[pos++]; 
        }
        ++pos;
        pairs.push_back({arg, value});
    }
}

int main()
{
    bool run = true;
    cpr::Response r;
    request req;
    std::string input = "http://httpbin.org/";
    std::string support = "";
    addString(req.full_body, req.pos_req, input);
    while (run)
    {
        std::cout << "Insert type request or arguments\n";
        std::cin >> input;
        if (input == "get")
        {
            run = false;
            req.type = input;
            input = input + "?";
            addString(req.full_body, req.pos_req, input);
            showString(req.full_body, req.pos_req);
            addArguments(req.full_body, req.arguments, req.pos_req, req.pos_arg);
            showString(req.full_body, req.pos_req);
            r = cpr::Get(cpr::Url(req.full_body));

        }
        else if (input == "post")
        {
            run = false;
            req.type = input;
            addString(req.full_body, req.pos_req, input);
            showString(req.full_body, req.pos_req);
            std::vector<cpr::Pair> pairs;
            parcingArguments(pairs, req.arguments, req.pos_arg, req.count_arg);
            //pairs.push_back({"arg1", "val1"});
            //pairs.push_back({"arg2", "val2"});
            cpr::Payload payload = cpr::Payload(pairs.begin(), pairs.end());
            
            r = cpr::Post(cpr::Url(req.full_body),payload);
        }
        else
        {
            input =input + "=";
            addString(req.arguments, req.pos_arg, input);
            std::cout << "Insert value:\n";
            std::cin >> input;
            input = input + "&";
            addString(req.arguments, req.pos_arg, input);
            showString(req.arguments, req.pos_arg);
            req.count_arg++;
        }
    }
    std::cout << r.text << "\n";
}
