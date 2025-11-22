#ifndef STUDENTVECTOR_H
#define STUDENTVECTOR_H
#include<cstddef>
using namespace std;
class Student;
class StudentVector{
  Student** p;
  size_t size;
  size_t len;
 public:
  StudentVector();
  ~StudentVector();
  void Clear();
  void Push(int);
  Student*& operator[](int)const;
  size_t GetLength()const{return len;}
};
#endif
