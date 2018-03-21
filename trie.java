//208. Implement Trie (Prefix Tree)
//DescriptionHintsSubmissionsDiscussSolution
//Implement a trie with insert, search, and startsWith methods.
// https://leetcode.com/problems/implement-trie-prefix-tree/description/
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.


class Trie {
    class TrieNode {
    char c;
    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    boolean isLeaf;
 
    public TrieNode() {}
 
    public TrieNode(char c){
        this.c = c;
    }
}
  
      private TrieNode root;
    /** Initialize your data structure here. */
    public Trie() {
       root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
           HashMap<Character, TrieNode> children = root.children;
        // iterate over the word
        for(int i = 0 ; i < word.length() ; i ++ )
        {
            char c = word.charAt(i);
            TrieNode t ;
       //  see if Trie node exists 
            if(children.containsKey(c))
            {
                t = children.get(c);
               
            }
      //  if not create and add the node
        else
           {
              t = new TrieNode();
            children.put(c,t);
           }
             children = t.children;
            
            if(i == word.length() - 1 )
            {
                t.isLeaf = true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
         TrieNode t = searchNode(word);
 
        if(t != null && t.isLeaf) 
            return true;
        else
            return false;
    }
    
     public TrieNode searchNode(String str){
        Map<Character, TrieNode> children = root.children; 
        TrieNode t = null;
        for(int i=0; i<str.length(); i++){
            char c = str.charAt(i);
            if(children.containsKey(c)){
                t = children.get(c);
                children = t.children;
            }else{
                return null;
            }
        }
 
        return t;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
       if(searchNode(prefix) == null) // understand null 
            return false;
        else
            return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
