#include<iostream>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        isEnd = false;
        for(int i = 0; i <26; i++){
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& word){
    TrieNode* curr = root;
    for( char ch : word){
        int idx = ch - 'a';
        if(curr->children[idx] == nullptr){
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}

bool search(TrieNode* root, const string& word){
    TrieNode* curr = root;
    for(char ch : word){
        int idx = ch - 'a';
        if(curr->children[idx] == nullptr){
            return false;
        }
        curr = curr->children[idx];
    }
    return curr->isEnd;
}

bool startsWith(TrieNode* root, const string& prefix){
    TrieNode* curr = root;
    for (char ch : prefix) {
        int idx = ch - 'a';
        if (curr->children[idx] == nullptr)
            return false;
        curr = curr->children[idx];
    }
    return true;
}

int main() {
    TrieNode* root = new TrieNode();   // constructor initializes root

    insert(root, "dog");
    cout << search(root, "dog") << endl;      // 1 (true)
    cout << search(root, "do") << endl;       // 0 (false)
    cout << startsWith(root, "do") << endl;   // 1 (true)

    insert(root, "do");
    cout << search(root, "do") << endl;       // 1 (true)

    return 0;
}