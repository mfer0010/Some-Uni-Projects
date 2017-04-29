/**
 * Created by marc on 10/04/2017.
 */

import java.util.Comparator;

public class NodeAStarComparator implements Comparator<Node> {
    @Override
    public int compare(Node a, Node b) {
        if (a.f > b.f) {
            return -1;
        } else if (a.f < b.f) {
            return 1;
        } else return 0;
    }
}
