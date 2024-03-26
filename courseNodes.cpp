//
//  courseNodes.cpp
//  csdp250pp1+
//
//  Created by Chris Turnbull on 3/26/24.
//

#include "courseNodes.hpp"
CourseNode::CourseNode(string code, int creditHours, char grade) {
    code = code;
    creditHours = creditHours;
    grade = grade;
    next = nullptr;
}
