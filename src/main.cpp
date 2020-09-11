#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif // _WIN32
#include <iostream>
#include <fstream>
#include <has_include.hpp>

#if __HAS_INCLUDE(tuple)
#include <tuple>
#endif // __HAS_INCLUDE(tuple)

int main(int argc, char* argv[])
{
    return 0;
}
