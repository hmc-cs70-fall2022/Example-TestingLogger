#include <iostream>
#include <string>
#include <sstream>
#include <cs70/testinglogger.hpp>

// This example test will pass                                                     
bool test1() {
    TestingLogger log("test 1");

    constexpr int MAX = 4;
    int result = 3;   // imagine this result came from some more complex code      
    affirm(result < MAX);

    return log.summarize();
}

// This example test will fail we our loop goes around one time too many           
bool test2() {
    TestingLogger log("test 2");
    
    constexpr int MAX = 4;
    for (size_t i = 0; i <= 4; ++i) {
        affirm(i < MAX);
    }
    
    return log.summarize();
}

// This example test will pass because 1 + 1 = 2                                   
bool test3() {
    TestingLogger log("test 3");

    affirm_expected(1 + 1, 2);

    return log.summarize();
}

// This example test will fail                                                     
bool test4() {
    TestingLogger log("test 4");
    
    for (int i = 0; i < 3; ++i) {
        int val = i * i;  // imagine we were *supposed* to have computed i + i     
        affirm_expected(val, 2*i);
    }
    
    return log.summarize();
}

// This example tests printed output
bool test5() {
    TestingLogger log("test 5");
    std::stringstream ss;

    ss << "Hello World! " << 42;
    affirm_expected(ss.str(), "Hello World! 42");

    return log.summarize();
}

int main() {
    TestingLogger log("all tests");
    test1();
    test2();
    test3();
    test4();
    test5();

    if (log.summarize(true)) {
        return 0;  // success
    } else {
        return 1;  // failure
    }
}
