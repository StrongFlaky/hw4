#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    root = new Node();
    numElements = 0;
}

void clear(MultiwayTrieSet::Node* node){
    for(auto check = node->children.begin(); check != node->children.end(); check++){
        if(check->second != nullptr){
            clear(check->second);
        }
    }
    delete node;
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    clear(root);
}


/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    Node* temp = root;
    for(unsigned int i = 0; i < s.length(); i++){
        char current = s[i];
        if(temp->children.find(current) != temp->children.end()){
            temp = temp->children[current];
        }
        else{
            Node* node = new Node();
            temp->children[current] = node;
            temp = temp->children[current];
        }
    }
    if(temp->isWord == false){
        temp->isWord = true;
        numElements ++;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    Node* temp = root;
    for(unsigned int i = 0; i < s.length(); i++){
        char current = s[i];
        if(temp->children.find(current) != temp->children.end()){
             temp = temp->children[current];
        }
        else{
            return;
        }
    }
    if(temp->isWord == true){
        temp->isWord = false;
        numElements -- ;
    }
}

bool MultiwayTrieSet::find(const string & s) {
    Node* temp = root;
    for(unsigned int i = 0; i < s.length(); i++){
        char current = s[i];
        if(temp->children.find(current) == temp->children.end()){
            return false;
        }
        temp = temp->children[current];
    }
    return temp->isWord;
}
