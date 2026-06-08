class MyHashSet {
    int[] set;
    public MyHashSet() {
       set = new int[31251];
       Arrays.fill(set,0);
    }
    
    public void add(int key) {
        int mask = getMask(key);
        set[key/32] |= (1<<mask);
    }
    
    public void remove(int key) {
        if(contains(key))
            set[key/32] ^= (1<<getMask(key));
    }
    
    public boolean contains(int key) {
        return (set[key/32] & (1<<getMask(key))) != 0;
    }

    private int getMask(int key) {
        return key % 32;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */