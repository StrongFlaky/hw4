#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    bool duplicate = find(s);
    if(!duplicate){
        rbt.insert(s);
    }

}

void RedBlackTreeSet::remove(const string & s) {
    for(auto check = rbt.begin(); check != rbt.end(); check++){
        if(*check == s){
            rbt.erase(check);
            return;
        }
    }
}

bool RedBlackTreeSet::find(const string & s) {
    for(auto check = rbt.begin(); check != rbt.end(); check++){
        if(*check == s){
            return true;
        }
    }
    return false;
}
