import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by marc on 05/01/2017.
 */
public class runner {
    public static void main (String args[]) {
        //save args in a list
        List<String> arguments = new ArrayList<>();
        for (String s : args) {
            arguments.add(s);
        }

        //check to ensure args were inputted correctly
        if (arguments.isEmpty()) {
            System.err.println("Error, no command line arguments entered. Terminating program");
            return;
        } else if (arguments.size() < 2) {
            System.err.println("Error, too few arguments have been entered. Terminating program");
            return;
        }

        //read file in first line argument
        String word = readFile(arguments.get(0));
        try {
            word.isEmpty();
        } catch (NullPointerException ex) {
            System.err.print("Error, Nothing written in first line of file");
            ex.printStackTrace();
            System.exit(1);
        }

        //create the suffix tree
        SuffixTrie myTrie = new SuffixTrie();
        myTrie.insert(word);

        //do the desired operation
        try {
            if (arguments.get(1).equals("substring()")) {
                System.out.println("Ran substring for " + word + " with parameter " + arguments.get(2) + " and the result is: " + myTrie.substring(arguments.get(2)));
            } else if (arguments.get(1).equals("suffix()")) {
                System.out.println("Ran suffix for " + word + " with parameter " + arguments.get(2) + " and the result is: " + myTrie.suffix(arguments.get(2)));
            } else if (arguments.get(1).equals("count()")) {
                System.out.println("Ran count for " + word + " with parameter " + arguments.get(2) + " and the result is: " + myTrie.count(arguments.get(2)));
            } else if (arguments.get(1).equals("longestRepeat()")) {
                System.out.println("Ran longestRepeat for " + word + " and the result is: " + myTrie.longestRepeat());
            } else if (arguments.get(1).equals("longestSubstring()")) {
                System.out.println("Ran longestSubstring for " + word + " with parameter " + arguments.get(2) + " and the result is: " + myTrie.longestSubstring(arguments.get(2)));
            } else if (arguments.get(1).equals("show()")) {
                myTrie.show();
            }
        } catch (IndexOutOfBoundsException ex) {
            System.err.println("Error, too few arguments have been entered. Terminating program");
            ex.printStackTrace();
        }

       // SuffixTree optimizedTree = new SuffixTree();
        //optimizedTree.insert("hahaa");
        //optimizedTree.show();

    }

    private static String readFile(String nameOfFile) {
        String line = "";
        try {
            BufferedReader reader = new BufferedReader(new FileReader(nameOfFile));
            line = reader.readLine();
            reader.close();
        } catch (FileNotFoundException ex) {
            System.err.println("Error opening file " + nameOfFile);
            ex.printStackTrace();
            System.exit(1);
        } catch (IOException ex) {
            System.err.print("Error in file IO");
            ex.printStackTrace();
            System.exit(1);
        }
        return line;
    }
}
