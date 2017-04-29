import java.util.ArrayList;
import java.util.List;

/**
 * Created by marc on 04/04/2017.
 */
public class Node {
    int id;
    Node parent;
    boolean colour;
    double dfsCost;
    double UCSCost;
    double f,g,h;
    public List <Edge> edges;

    public Node (int i, boolean col) {
        id = i;
        colour = col;
        edges = new ArrayList<>();
    }
}
