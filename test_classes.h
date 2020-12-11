#include <string>

class Test_Class {
public:
    Test_Class() {}
    Test_Class(int test_int, 
             int test_int2)
            : test_int(test_int)
            , test_int2(test_int2)
        {}
    // Test_Class(const std::string &test_string, 
    //      int test_int)
    //     : test_string(test_string)
    //     , test_int(test_int)
    // {}

    ~Test_Class() noexcept {}

    std::string test_string;
    int test_int;
    int test_int2;
};