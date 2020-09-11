# has_include

`__has_include`的C++98簡化版，目前支持C++11的新加頭文件檢測，C++14以上已有`__cpp_lib_*`宏，推薦使用標準檢測方式，在`__has_include`已定義的環境下優先使用`__has_include`。

```C++
#include <string>
#include <has_include.hpp>

#if __HAS_INCLUDE(tuple)
#include <tuple>
using std::tuple;
using std::make_tuple;
#else
#include <boost/tuple.hpp>
using boost::tuple;
using std::make_tuple;
#endif // __HAS_INCLUDE(tuple)

int main()
{
    tuple<std::string, int> t = make_tuple("Tom", 18);
    return 0;
}
```
