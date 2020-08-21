
Problem Link - https://leetcode.com/problems/design-hashset/

Solution----


class MyHashSet {
public:
    /** Initialize your data structure here. */
    int hashset[1000001];
    MyHashSet() {
        
    }
    
    void add(int key) {
        hashset[key]=1;
    }
    
    void remove(int key) {
            hashset[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {

       if(hashset[key]==1)
           return true ;
        
        return false ; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */