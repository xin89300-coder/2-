#include "Group.h"
#include <iostream>
using namespace std;

Group::Group(int s, size_t c):obj() {
    count = c;
    decisions = new int[count];
    playCount = 0;
    for (int i = 0; i < count; i++) {
        obj.Push(s+i);
    }
}
void Group::GroupDecision(int w) {
    int d = 0;
    playCount = 0;
    for (int i = 0; i < count; i++) {
        d = obj[i]->MakeDecision(w);
        if (d == 0) {
            decisions[playCount] = obj[i]->GetID();
            playCount++;
        }
    }
    return;
}

ostream&operator<<(ostream&os,const Group&gro) {
  os << gro.playCount << " play, " << gro.count - gro.playCount << " not play\n";
    os << "    Play ID: ";
    for (int i = 0; i < gro.playCount; i++) {
        os << gro.decisions[i] << " ";
    }
    os << endl;
    return os;
}
Group* Group::Split() {
    if (count < 10) return NULL;
    size_t lc = count/2;
    size_t rc = count - lc;
    Group* temp=new Group(0,0);
    temp->obj.Clear();
    for(int i=0;i<rc;i++){
      temp->obj.Push(obj[lc+i]->GetID());
    }
    for(int i=lc;i<count;i++){
      delete obj[i];
      obj[i]=nullptr;
    }
    count=lc;
    return temp;
}

Group::~Group() {
    delete [] decisions;

}
Group& Group:: operator+=( Group&gro){
  for(int i=0;i<gro.count;i++){
    obj.Push(gro.obj[i]->GetID());
  }
  count+=gro.count;
  for(int i=0;i<gro.count;i++){
    gro.obj[i]=nullptr;
  }
      return *this;
}
  
  
  
