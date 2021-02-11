//
//  string_algorithm.hpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#ifndef string_algorithm_h
#define string_algorithm_h

#include <stdio.h>
#include <vector>
class String_Algorithm{
public:
    String_Algorithm();
    ~String_Algorithm();
    
    //腾讯
    char * reverse(char *s);
    // leetcode
    void reverseString(std::vector<char>& s);
};

#endif /* string_algorithm_hpp */
