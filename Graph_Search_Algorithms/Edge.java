/**
 * Created by marc on 04/04/2017.
 */
public class Edge {
    public Node a,b;
    //direction is always a -> b
    public double weight;

    public Edge (Node from, Node to, double w) {
        a = from;
        b = to;
        weight = w;
    }
}
