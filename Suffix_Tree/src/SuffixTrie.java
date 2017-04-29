import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by marc on 05/01/2017.
 */
public class SuffixTrie {
    private TNode root;
    private List <String> keyOfNodes;

    public SuffixTrie() {
        root = new TNode();
        keyOfNodes = new ArrayList<>();
    }

    //insert all possible suffixes into trie
    public void insert (String word) {
        String s, key;
        TNode t;
        //concatenate #
        word = word.concat("#");
        //create a hash-table of all children of root node currently on the trie
        HashMap<String, TNode> children;

        for (int i = word.length()-1; i >= 0; i--) {
            s = word.substring(i);
            //always start adding from root
            children = root.children;

            //this should run only when s = '#'
            if (s.length()==1) {
                if (!children.containsKey(s)) {
                    t = new TNode(s);
                    children.put(s,t);
                } //else do nothing (should never be the case anyway)
            } else {
                for (int x = 0; x < s.length(); x++) {
                    key = s.substring(0,x+1);
                    if (children.containsKey(key)) {
                        t = children.get(key);
                    } else {
                        t = new TNode(key);
                        children.put(key, t);
                    }
                    children = t.children;
                }
            }
        }
    }

    public void show() {
        showTrie(root.children);
    }
    //call the function by calling root node.children, key
    private void showTrie(HashMap<String, TNode> map) {
        //List<TNode> list = new ArrayList<>();
        //Note showing all root first, then children
        if (map.isEmpty()) return;
        //print all values in children hashmap
        for (String name: map.keySet()) {
            System.out.print(name+" ");
        }
        //System.out.println();
        //recursively show all children
        for (String name : map.keySet()) {
            showTrie(map.get(name).children);
        }

    }

    public boolean suffix(String S) {
        int i = 0;
        String subs;
        S = S.concat("#");

        //start searching from the root's children
        HashMap<String, TNode> children = root.children;
        TNode t;

        while (i < S.length()) {
            subs = S.substring(0, i+1);
            if (children.containsKey(subs)) {
                t = children.get(subs);
                children = t.children;
            } else return false;
            i++;
        }
        return true;
    }

    public boolean substring(String S) {
        int i = 0;
        String subs;

        //start searching from the root's children
        HashMap<String, TNode> children = root.children;
        TNode t;

        while (i < S.length()) {
            subs = S.substring(0, i+1);
            if (children.containsKey(subs)) {
                t = children.get(subs);
                children = t.children;
            } else return false;
            i++;
        }
        return true;
    }

    public int count(String S) {
        //if substring is not in trie return 0
        if (!substring(S)) return 0;

        int i = 0;
        //int count = 0;
        String subs;

        HashMap<String, TNode> children = root.children;
        TNode t;

        //loop to go to node where substring ends
        while (i < S.length()) {
            subs = S.substring(0, i+1);
            if (children.containsKey(subs)) {
                t = children.get(subs);
                children = t.children;
            }
            i++;
        }

        //count all children of node
        return countChildren(children);
    }

    private int countChildren(HashMap <String, TNode> map) {
        int toReturn = 1;
        if (!map.isEmpty()) {
            for (String name : map.keySet()) {
                toReturn += countChildren(map.get(name).children);
            }
        }
        return toReturn;
    }

    public String longestRepeat() {
        //clear list
        keyOfNodes.clear();
        //fill list with all substrings that are repeated
        fillPrivateList(root.children);
        //if list is empty return error
        if (keyOfNodes.isEmpty()) return "No Substrings Repeated";
        //return deepest substring
        String toReturn = keyOfNodes.get(0);
        for (String key : keyOfNodes) {
            if (toReturn.length() < key.length()) toReturn = key;
        }
        return toReturn;
    }

    private void fillPrivateList(HashMap<String, TNode> map) {
        if (map.isEmpty()) return;
        //save all the keys of nodes with more than 1 child
        for (String name: map.keySet()) {
            if (map.get(name).children.size() > 1) keyOfNodes.add(name);
        }
        //recursively check children
        for (String name : map.keySet()) {
            fillPrivateList(map.get(name).children);
        }
    }

    public String longestSubstring(String S) {
        //clear list
        keyOfNodes.clear();
        String subs;
        //for all possible Substrings
        for (int i = 0; i < S.length(); i++) {
            for (int j = i+1; j <= S.length(); j++) {
                subs = S.substring(i,j);
                //if subs is a substring in the trie, add it to the list
                if (substring(subs)) keyOfNodes.add(subs);
            }
        }
        //search the list for the longest substring
        if (keyOfNodes.isEmpty()) return "No Substrings Repeated";
        String toReturn = keyOfNodes.get(0);
        for (String key : keyOfNodes) {
            if (toReturn.length() < key.length()) toReturn = key;
        }
        return toReturn;
    }
}


