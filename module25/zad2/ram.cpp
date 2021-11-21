#pragma once

void write(int *rambuf, int *wrbuf)
{
    for (int i=0; i<8; ++i)
    {
        *(rambuf+i) = *(wrbuf+i);
    }
}

void read(int *rambuf, int *rdbuf)
{
    for (int i=0; i<8; ++i)
    {
        *(rdbuf+i) = *(rambuf+i);
    }
}
