//
//  courseNodes.hpp
//  csdp250pp1+
//
//  Created by Chris Turnbull on 3/26/24.
//

#ifndef courseNodes_hpp
#define courseNodes_hpp

#include <string>

using namespace std;

class CourseNode {
public:
    string code;
    int creditHours;
    char grade;
    CourseNode* next;

    CourseNode(string code, int creditHours, char grade);
};

#endif /* courseNodes_hpp */
