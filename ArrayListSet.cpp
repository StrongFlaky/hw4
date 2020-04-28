#include "Set.h"

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    return arr.size();
}

void ArrayListSet::insert(string s) {
    bool duplicate = false;
    for(unsigned int i = 0; i < arr.size(); i++){
        if(arr[i] == s){
            duplicate = true;
        }
    }
    if(!duplicate){
        arr.push_back(s);
    }
}

void ArrayListSet::remove(const string & s) {
    bool find = false;
    int mark = 0;
    for(unsigned int i = 0; i < arr.size(); i++){
        if(arr[i] == s){
            find = true;
            mark = i;
        }
    }
    if(find){
           arr.erase(arr.begin()+mark);
    }
}

bool ArrayListSet::find(const string & s) {
    for(unsigned int i = 0; i < arr.size(); i++){
        if(arr[i] == s){
            return true;
        }
    }
    return false;
}
