class MyHashMap {
public:
    int BUCKET;
    vector<list<pair<int,int>>>table;
    
    MyHashMap(){
        BUCKET=1000;
        table.resize(BUCKET);
    }
    
    int hash(int key){
        return key%BUCKET;
    }
    
    
    list<pair<int,int>> :: iterator  search(int key){
        int i=hash(key);
        list<pair<int,int>>:: iterator  itr=table[i].begin(); 
        while (itr !=table[i].end()){
            if(itr->first==key){
                return itr;
            }
            itr++;
        }
        return itr;
    }
    
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        table[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>> ::iterator itr=search(key);
        if(itr==table[i].end()){
            return -1;
        }else{
            return itr->second;
        }
    }
    
    void remove(int key) {
        int i=hash(key);
        list<pair<int,int>>:: iterator itr=search(key);
        if(itr!=table[i].end()){
            table[i].erase(itr);
        }
    }
};