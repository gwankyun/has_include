#ifdef _WIN32
#  define _CRT_SECURE_NO_WARNINGS
#endif // _WIN32
#include <iostream>
#include <fstream>
#include <string>
#include <has_include.hpp>

#if HAS_INCLUDE(tuple)
#  include <tuple>
#  define TUPLE std::tuple
#  define MAKE_TUPLE std::make_tuple
#else
#  include <boost/tuple/tuple.hpp>
#  define TUPLE boost::tuple
#  define MAKE_TUPLE boost::make_tuple
#endif

#if HAS_INCLUDE(optional)
#  pragma message("has <optional>")
#endif

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    std::cout << "hello" << std::endl;
    TUPLE<int, std::string> tpl(MAKE_TUPLE<int, std::string>(18, "Tom"));
    return 0;
}
