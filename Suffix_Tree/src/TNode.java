import java.util.HashMap;

/**
 * Created by marc on 05/01/2017.
 */
public class TNode {
    String data;
    HashMap <String, TNode> children = new HashMap<String, TNode>();
    //boolean leafNode;

    public TNode() {}

    public TNode (String data) {
        this.data = data;
    }
}