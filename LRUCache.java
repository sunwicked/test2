class LRUCacheEntry{
    int key ;
    int value;
    LRUCacheEntry next = null;
    LRUCacheEntry prev = null;
}
public class LRUCache {
    Map<Integer,LRUCacheEntry> _mapping;
    List<LRUCacheEntry> _freeEntries; 
    LRUCacheEntry head,tail;
    LRUCacheEntry [] entries ;
    
    
    public LRUCache(int capacity) {
         _mapping = new HashMap<>();

        _freeEntries  = new ArrayList<>();
        entries = new LRUCacheEntry[capacity];
        for(int i =0;i<capacity;++i){
            entries[i] = new LRUCacheEntry();
            _freeEntries.add(entries[i]);
        }
        head = new LRUCacheEntry();
        tail = new LRUCacheEntry();
        head.next = tail;
        head.prev = null;
        tail.prev = head;
        tail.next = null;
    }
    
    public int get(int key) {
        LRUCacheEntry node = _mapping.get(key);
        if(node!=null){
            detachNode(node);
            attachNode(node);
            return node.value;
        }
        return -1;
        
    }
    
    public void put(int key, int value) {
        LRUCacheEntry node = _mapping.get(key);
        if(node!=null){
            detachNode(node);
            node.value = value;
            attachNode(node);
            return;
        }
        if(_freeEntries.isEmpty()){
            node = tail.prev;
            _mapping.remove(node.key);
            node.key = key;
            node.value = value;
            detachNode(node);
            attachNode(node);
            _mapping.put(key,node);

        }
        else{
            
             node = _freeEntries.get(_freeEntries.size()- 1);
            _freeEntries.remove(_freeEntries.size() - 1);
            node.key = key;
            node.value = value;
           
            _mapping.put(key,node);
            attachNode(node);
        }
    }
    public void detachNode(LRUCacheEntry node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    public void attachNode(LRUCacheEntry node){
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        node.prev = head;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
