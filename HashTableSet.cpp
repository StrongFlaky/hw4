#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    return ht.size();
}

void HashTableSet::insert(string s) {
    bool duplicate = find(s);
    if(!duplicate){
        ht.insert(s);
    }
}

void HashTableSet::remove(const string & s) {
    for(auto check = ht.begin(); check != ht.end(); check++){
        if(*check == s){
            ht.erase(check);
            return;
        }
    }
}

bool HashTableSet::find(const string & s) {
    for(auto check = ht.begin(); check != ht.end(); check++){
        if(*check == s){
           return true;
        }
    }
    return false;
}
