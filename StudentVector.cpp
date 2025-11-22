#include "StudentVector.h"
#include<iostream>
#include "Student.h"
using namespace std;
StudentVector::StudentVector(){size=10;len=0;p=new Student*[size];}
void StudentVector::Clear(){
  for(size_t i=0;i<len;i++)
    p[i]=nullptr;
  len=0;
}
StudentVector::~StudentVector(){
  for(int i=0;i<len;i++){
    delete p[i];
  }
  delete []p;
}
void StudentVector::Push(int x){
  if(len==size-1){
    size*=2;
    Student**temp=new Student*[size];
    for(int i=0;i<len;i++)temp[i]=p[i];
    delete []p;
    p=temp;
  }
  p[len++]=new Student(x);
}
Student*& StudentVector::operator[](int i)const{
  if(i<0||i>=len){
    static Student*dummy=nullptr;
    return dummy;
  }
  return p[i];
}
  
  
