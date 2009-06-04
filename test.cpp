#include "TsdbSource.h"
#include <iostream>

int main(int argc, char** argv)
{
    RTTsdbSource src("ccp_rtf_gbp.bin");
    RTKnot k;
    k = src.getValue();
    std::cout << k.toString() << std::endl;
    k = src.getValue();
    std::cout << k.toString() << std::endl;
    src.readAll();
return 1;
}