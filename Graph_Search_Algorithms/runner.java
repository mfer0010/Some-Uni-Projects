/**
 * Created by marc on 17/03/2017.
 */
import java.util.*;


public class runner {
    private static Node ERROR = new Node(-1, false);
    //For IDA*:
    private static double FOUND = -1;
    private static double MAX = Double.MAX_VALUE;
    private static boolean Once = false;


    public static void main (String [] args) {
        int i, j, m, l, numOfEdges = 0;
        double weight;
        Random rnd = new Random();
        rnd.setSeed(System.currentTimeMillis());
        List<Node> nodes = new ArrayList<>();
        List<Integer> excludes = new ArrayList<>();
        Node temp;
        Edge edge;

        //number of nodes:
        int n = rnd.nextInt(3) + 10; //random number between 10 and 12 (inclusive)
        //create Nodes and add them to the list:
        for (i = 0; i < n; i++) {
            temp = new Node (i, false);
            nodes.add(temp);
        }

        //for each node
        for (i = 0; i < n; i++) {
            // generate number of edges for node:
            m = rnd.nextInt(4) + 1; //random number between 1 and 4

            //clear excludes, leaving only the current node
            excludes.clear();
            excludes.add(i);

            System.out.print("Node " + i + " points to: ");
            //for each edge
            for (j = 0; j < m; j++) {
                //choose a random node to point to:
                l = DiscreteRndExclude(rnd,0, 10, excludes);
                if (l != -1) {
                    numOfEdges++;
                    //make sure that node can't be pointed to again by this current node
                    excludes.add(l);
                    //generate a random weight between 0 and 1:
                    weight = rnd.nextDouble();
                    //create edge:
                    edge = new Edge(nodes.get(i), nodes.get(l), weight);
                    //add edge to node:
                    nodes.get(i).edges.add(edge);

                    System.out.print(l + ", ");
                }
            }
            System.out.println();
        }
        System.out.println("Total number of Edges = " + numOfEdges);

        //Search algorithms:
        Node goal;
        //DFS
        System.out.println("DFS");
        DFS(nodes.get(3), nodes.get(0));

        clear_Ancestory(nodes);
        //BFS
        System.out.println("BFS:");

        goal = BFS(nodes.get(3), nodes.get(0));
        if (goal != ERROR) {
            display_Ancestory(goal, nodes.get(3));
        } else {
            System.out.println("No path exists");
        }

        clear_Ancestory(nodes);
        //UCS
        System.out.println("UCS:");
        goal = UCS(nodes.get(3), nodes.get(0));
        if (goal != ERROR) {
            display_Ancestory(goal, nodes.get(3));
        } else {
            System.out.println("No path exists");
        }

        clear_Ancestory(nodes);
       //IDS
        System.out.println("IDS:");
        goal = IDDFS(nodes.get(3), nodes.get(0));
        if (goal != ERROR) {
            display_Ancestory(goal, nodes.get(3));
        } else {
            System.out.println("No path exists");
        }

        clear_Ancestory(nodes);
        //A*
        System.out.println("A*:");
        goal = A_Star(nodes.get(3), nodes.get(0));
        if (goal != ERROR) {
            display_Ancestory(goal, nodes.get(3));
        } else {
            System.out.println("No path exists");
        }

        clear_Ancestory(nodes);
        //IDA*
        double IDAVal;
        System.out.println("IDA*:");
        IDAVal = IDA_Star(nodes.get(3), nodes.get(0));
        if (IDAVal == MAX) {
            System.out.println("No path exists");
        }
    }

    //Function that returns a random number but excludes certain numbers from range
    //Returns -1 for a specific case, which for us is sufficient to just scrap that generated number.
    public static int DiscreteRndExclude (Random rnd, int start, int end, List <Integer> excludes) {
        int rangelen = end - start - excludes.size();
        int random = rnd.nextInt(rangelen) + start;

        for (int i = 0; i < excludes.size(); i++) {
            if (excludes.get(i) == random) {
                random ++;
            }
        }

        //search the loop again, there is a specific instance where a repeated number will still occur.
        //This can only happen when there already is an edge in the list, so we can just scrap the number.
        for (int i = 0; i < excludes.size(); i++) {
            if (excludes.get(i) == random) {
                return -1;
            }
        }

        return random;
    }

    //DFS Algorithm
    //Displays the path from v to goal
    //if path doesn't exist, displays all the connected sub-graph of v
    public static void DFS (Node v, Node goal) {
        v.dfsCost = 0;
        Stack <Node> S = new Stack<>();
        //push into stack
        S.push(v);
        while (!S.isEmpty()) {
            v = S.pop();
            if (v == goal) {
                System.out.println(goal.id);
                System.out.println("Cost of DFS: " + v.dfsCost);
                return;
            }
            //if v has not already been searched
            if (!v.colour) {
                System.out.print(v.id + "->");
                v.colour = true;
                for (Edge e : v.edges) {
                    e.b.dfsCost = v.dfsCost + e.weight;
                    S.push(e.b);
                }
            }
        }
        System.out.println("\nNo Path exists!");
    }

    //BFS Algorithm
    //Returns special ERROR node if no path exists, else returns the goal node
    //but sets the parents of the goal node to the shortest path from root to goal
    public static Node BFS (Node root, Node goal) {
        //S is the list of all searched vertices
        List<Node> S = new ArrayList<>();
        //Queue contains all the vertices that still need to be searched
        Queue<Node> queue = new LinkedList<>();
        Node current;
        boolean inS;

        //set the parent of the root to null
        root.parent = null;
        S.add(root);
        queue.add(root);

        while (!queue.isEmpty()) {
            current = queue.remove();
            if (current == goal) {
                return goal;
            }
            //for each edge of current node
            for (Edge e : current.edges) {
                //if adjacent node is not in S, set inS to false
                inS = false;
                for (Node s : S) {
                    if (e.b == s) {
                        inS = true;
                    }
                }
                //above loop can be simplified by using the colouring technique to improve efficiency

                if (!inS) {
                    S.add(e.b);
                    //by setting the parent we can then traverse the tree to find the shortest path
                    e.b.parent = current;
                    queue.add(e.b);
                }
            }
        }
        //if function wouldn't have returned then no path exists.
        return ERROR;
    }

    //Uniform Cost Search

    public static Node UCS(Node start, Node goal) {
        Node node = start;
        //for displaying
        node.parent = null;
        //initial cost:
        node.UCSCost = 0;
        //for priority queue (See NodeUCSComparator class)
        Comparator<Node> comparator = new NodeUCSComparator();
        PriorityQueue<Node> frontier = new PriorityQueue<>(10, comparator);
        frontier.add(node);
        //for dealing with cycles:
        List <Node> explored = new ArrayList<>();

        int cntr = 0;

        while (cntr < 50) {
            if (frontier.isEmpty()) {
                //No Path exists
                return ERROR;
            }
            node = frontier.poll();
            if (node == goal) {
                return goal;
            }
            explored.add(node);
            //for all adjacent Nodes:
            for (Edge e: node.edges) {
                if ((!(explored.contains(e.b)) && !(frontier.contains(e.b)))) {
                    //if node is not already searched or in frontier
                    e.b.parent = node;
                    //Update cost
                    e.b.UCSCost = node.UCSCost + e.weight;
                    //add to frontier
                    frontier.add(e.b);
                } else if (frontier.contains(e.b) && e.b.UCSCost > (node.UCSCost+e.weight)) {
                    //else if adjacent node is already in a different searched path
                    //but the cost of that path to get to that node > the cost of this
                    //path to get to that node
                    e.b.parent = node;
                    e.b.UCSCost = node.UCSCost + e.weight;
                    node = e.b;
                }
            }
            cntr ++;
        }
        return ERROR;
    }

    //IDS
    public static Node IDDFS(Node start, Node goal) {
        int depth = 0;
        Node found;
        start.parent = null;
        start.colour = true;
        while (depth < 13) {
            found = DLS(start, goal, depth);
            if (found != ERROR) {
                return found;
            }
            depth ++;
        }
        return ERROR;
    }

    public static Node DLS (Node node, Node goal, int depth) {
        Node found;
        node.colour = true;
        if (depth == 0 & node == goal) {
            return node;
        }
        if (depth > 0) {
            for (Edge e : node.edges) {
                if (!e.b.colour) {
                    e.b.parent = node;
                    found = DLS(e.b, goal, depth - 1);
                    if (found != ERROR) {
                        return found;
                    }
                } else {
                    //if node is already searched, continue algorithm normally,
                    //just don't save the parent so that cycle is dealt with
                    found = DLS(e.b, goal, depth - 1);
                    if (found != ERROR) {
                        return found;
                    }
                }
            }
        }
        return ERROR;
    }

    //A* Search:
    //We need a heuristic that is > 0, but less than or equal to
    //the length of the optimal path
    //Thus taking the cost between the current node and the node
    //being examined should suffice as our heuristic value
    //KNOWN BUG: Occasionally A* would return ERROR when a path actually does exist!
    public static Node A_Star(Node start, Node goal) {
        //Create Lists open and closed
        Comparator<Node> comparator = new NodeAStarComparator();
        PriorityQueue<Node> open = new PriorityQueue<>(10, comparator);
        List <Node> closed = new ArrayList<>();
        //set f of first node to 0 and add it to open list
        start.f = 0;
        start.colour = true;
        open.add(start);

        boolean add;

        Node q = new Node(-2, false);
        q.f = 999999999;
        int cntr = 0;
        //while the open list is not empty;
        while (!open.isEmpty() && cntr < 15) {
            //set q to the node with the least f;
            q = open.poll();

            //generate q's successors
            for (Edge e : q.edges) {
                //set their parents to q
                if (!e.b.colour)
                    e.b.parent = q;
                //if successor is the goal, stop
                if (e.b == goal) {
                    return goal;
                }
                //update cost from starting point
                e.b.g = q.g + e.weight;
                //update heuristic
                e.b.h = e.weight;
                //update f
                e.b.f = e.b.g + e.b.h;

                //if a node in the same position as e.b is in the open list
                //and has f < e.b.f, or the node in the same position
                // as e.b is in the closed list and has f < e.b.f, skip e.b
                add = true;
                for (Edge z : q.edges) {
                    if ((open.contains(z.b) && z.b.f < e.b.f) || (closed.contains(z.b) && z.b.f < e.b.f)) {
                        add = false;
                    }
                }
                //else add node to open list
                if (add) {
                    e.b.colour = true;
                    open.add(e.b);
                }
            }
            closed.add(q);
            cntr ++;
        }
        return ERROR;
    }

    //IDA*
    //returns -1 when path is found
    //returns MAX if no Path exists
    //Known Bug: Occasionally IDA* would return MAX when a path exists
    public static double IDA_Star(Node root, Node goal) {
        int cntr = 0;
        double temp;
        double threshold = 0;
        while (cntr < 30) {
            temp = search(root,0, 0,threshold, goal);
            if (temp == FOUND) {
                System.out.println(root.id);
                return FOUND;
            }
            if (temp == MAX)
                return MAX;
            threshold = temp;
            cntr ++;
        }
        return MAX;
    }

    public static double search(Node node, double g, double h, double threshold, Node goal) {
        double f = g+h;
        double temp;
        if (f > threshold)
            return f;
        if (node == goal) {
            return FOUND;
        }
        double min = MAX;
        for (Edge e: node.edges) {
            //depth search recursive call:
            temp = search(e.b, g+e.weight, e.weight, threshold, goal);
            if (temp == FOUND) {
                if (!Once) {
                    System.out.println("Cost of IDA*: " + (g+e.weight));
                    Once = true;
                }
                System.out.print(e.b.id + "<-");
                return FOUND;
            }
            if (temp < min)
                min = temp;
        }
        return min;
    }

    //function that displays from the child all the way to the root of a tree/graph
    public static  void display_Ancestory (Node child, Node goal) {
        double cost = 0;
        int cntr = 0;
        while ((child.parent != null && cntr < 15)) {
            //loop to calculate cost of edge
            for (Edge e: child.parent.edges) {
                if (e.b == child) {
                    cost += e.weight;
                }
            }
            //print child id
            System.out.print(child.id+"<-");
            child = child.parent;
            cntr++;
        }
        System.out.println(goal.id);
        System.out.println("Cost of Algorithm: " + cost);
    }

    public static void clear_Ancestory (List <Node> nodes) {
        for (Node n : nodes) {
            n.parent = null;
            n.colour = false;
        }
    }
}
