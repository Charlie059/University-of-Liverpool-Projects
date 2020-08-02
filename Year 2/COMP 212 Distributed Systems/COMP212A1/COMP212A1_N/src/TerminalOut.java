import java.io.FileNotFoundException;
import java.io.PrintStream;

public class TerminalOut {
      public TerminalOut(){
            try {
                PrintStream print=new PrintStream("./testResult.txt"); //Write the file
                System.setOut(print);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
}
