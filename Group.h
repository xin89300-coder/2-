#ifndef _GROUP_H_
#define _GROUP_H_
#include "StudentVector.h"
#include "Student.h"
#include <cstddef>
#include<iostream>
using namespace std;
class Group {
    StudentVector obj;
    size_t count;
    int* decisions;
    size_t playCount;
public:
    Group(int s, size_t c);
    void GroupDecision(int w);
  friend ostream&operator<<(ostream&os,const Group&gro);
    Group* Split();
  Group& operator+=( Group&gro);
    ~Group();    
};
#endif
