#include <iostream>
#include <cstdlib>
#include "World.h"
using namespace std;

World::World(size_t c) {
    count = size = c;
    groups = new Group*[count];
    for (int i = 0; i < count; i++) {
        groups[i] = new Group(30*i, 30);
    }
    weather = new Weather();
}

void World::DoSimulation() {
    for (int j = 0; j < 30; j++) {
        weather->UpdateWeather();
        int wx = weather->GetWeather();
	int r;
	r=rand()%5;
        HandleGroupSplit(r);
	HandleGroupMerge(r);
        cout << "Day " << j+1<< ":\n";
        for (int i = 0; i < count; i++) {
	  if(groups[i]!=nullptr){
            groups[i]->GroupDecision(wx);
            cout << "Groups " << i+1 << ": ";
            cout<<*groups[i];
        }
    }
}
}

World::~World() {
    for (int i = 0; i < count; i++) {
        delete groups[i];
    }
    delete [] groups;
    delete weather;
}
void World:: HandleGroupSplit(int r){
    if(r>1)return;  
    int dice = rand() % count;
    Group* temp = groups[dice]->Split();
    if (temp == NULL) return;

    if (count == size) {
	size *= 2;
        Group** temp = new Group*[size];
	for (size_t i = 0; i < count; i++) temp[i] = groups[i];
	delete [] groups;
	groups = temp;
    }
    groups[count++] = temp;
}
void World:: HandleGroupMerge(int r){
  if(r!=1)return;
  int dice1=rand()%count;
  int dice2=rand()%count;
  if(dice1==dice2)return;  
  *groups[dice1]+=*groups[dice2];
  Group** temp=new Group*[count-1];
  for(int i=0;i<dice2;i++){
    temp[i]=groups[i];
  }
  delete groups[dice2];
  for(int i=dice2+1;i<count;i++){
    temp[i-1]=groups[i];
  }
  delete []groups;
  groups=temp;
  --count;
}
    
    
