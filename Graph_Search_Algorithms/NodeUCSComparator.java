/**
 * Created by marc on 05/04/2017.
 */

import java.util.Comparator;

public class NodeUCSComparator implements Comparator<Node> {
    @Override
    public int compare(Node a, Node b) {
        if (a.UCSCost > b.UCSCost) {
            return -1;
        } else if (a.UCSCost < b.UCSCost) {
            return 1;
        } else return 0;
    }
}
