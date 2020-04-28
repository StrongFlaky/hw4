#include "Set.h"
#include <iostream>

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    return linked.size();
}

void LinkedListSet::insert(string s) {
    bool duplicate = find(s);
    if(!duplicate){
        linked.push_back(s);
    }
}

void LinkedListSet::remove(const string & s) {
    bool check = find(s);
    if(check){
        linked.remove(s);
    }

    /*for(auto begin = linked.begin(); begin != linked.end(); begin++){
        if(*begin == s){
           linked.erase(begin);
           return;
        }
    }*/
    
}

bool LinkedListSet::find(const string & s) {
    for(auto begin = linked.begin(); begin != linked.end(); begin++){
        if(*begin == s){
           return true;
        }
    }
    return false;
}
