//
//  string_algorithm.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#include "string_algorithm.h"
#include <iostream>

String_Algorithm::String_Algorithm(){}

String_Algorithm::~String_Algorithm(){}

char * String_Algorithm::reverse(char *s){
        int count = (int)strlen(s);
        char result_arr[count];
        int left = 0;
        int right = count-1;
        while (right>=0) {
            char right_str = s[right];
            result_arr[left] = right_str;
            right -=1;
            left +=1;
        }
    
        char *result = result_arr;
        return result;
    
}

void reverseString(std::vector<char>& s){
    int left = 0;
    int right = (int)s.size() -1;
    while (right >0) {
        if(right > left){
            char temp_r = s[right];
            char temp_l = s[left];
            s[left] = temp_r;
            s[right] = temp_l;
        }
        left  +=1;
        right -=1;
    }
}


