


typedef struct Trie {
    struct Trie* child[26];
    bool isEndofWord; 
} Trie;

Trie* trieCreate() {
    Trie* ret = NULL;
    int i = 0;

    ret = (Trie*)calloc(sizeof(Trie), 1);
    for (i = 0; i < 26; i++) {
        ret->child[i] = NULL;
    }
    ret->isEndofWord = false;

    return ret;
}

void trieInsert(Trie* obj, char* word) {
    Trie* cur = NULL; 
    int wordLen = 0, idx = 0, i = 0;

    cur = obj;
    wordLen = strlen(word);

    for (i = 0; i < wordLen; i++) {
        idx = word[i] - 'a';
        if (cur->child[idx] == NULL) {
            cur->child[idx] = trieCreate();
        }
        cur = cur->child[idx];
    }

    cur->isEndofWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* cur = NULL;
    int wordLen = 0, idx = 0, i = 0;

    cur = obj;
    wordLen = strlen(word);
    
    for (i = 0; i < wordLen; i++) {
        idx = word[i] - 'a';
        if (cur->child[idx] == NULL) {
            return false;
        }
        cur = cur->child[idx];
    }

    if (cur->isEndofWord == true) {
        return true;
    } else {
        return false;
    }
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* cur = NULL;
    int prefixLen = 0, idx = 0, i = 0;

    cur = obj;
    prefixLen = strlen(prefix);
    
    for (i = 0; i < prefixLen; i++) {
        idx = prefix[i] - 'a';
        if (cur->child[idx] == NULL) {
            return false;
        }
        cur = cur->child[idx];
    }

    return true;
}

void trieFree(Trie* obj) {
    int i = 0;

    if (obj == NULL) {
        return;
    }

    for (i = 0; i < 26; i++) {
        if (obj->child[i]) {
            trieFree(obj->child[i]);
        }
    }
    
    free(obj);
    obj = NULL;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
