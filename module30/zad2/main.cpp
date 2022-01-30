#include <iostream>
#include <cpr/cpr.h>

std::string parcing(std::string &text)
{
    int pos = 0;
    std::string str = "";
    while (true)
    {
        if (text[pos] == '<' && text[pos+1] == 'h' && text[pos+2] == '1' && text[pos+3] == '>') 
        {
            pos = pos+4;
            while ( !(text[pos] == '<' && text[pos+1] == '/' && text[pos+2] == 'h' && 
                    text[pos+3] == '1' && text[pos+4] == '>'))
            {
                str += text[pos];
                pos++;
            } 
            return str;
        }
        pos++;
    }
}

int main()
{
    cpr::Response r;
    std::string comand;
    r = cpr::Get(cpr::Url("http://httpbin.org/html"),
            cpr::Header({{"Accept", "text/html"}}));
    
    std::string output = parcing(r.text);
    std::cout << output << "\n";
}
