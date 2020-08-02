/*
xuhui gong 1718128
 */
package mygarden;

import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 *
 * @author Mac
 */


public class Flower extends JPanel{
    
    
    
    public static ArrayList<ImageDisplay> myFlowers = new ArrayList<>();
    public static ArrayList<String> myFlowersText = new ArrayList<String>();
    
    
    private  String imagePath;
    private  int X;
    private  int Y;
    private  int type = 1 ;
    private static int counter = 0;
    public static int counterOfFileSaving = 1;
     private static String path ;
     private static String xString ;
     private static int x ;
     private static String yString;
     private static int y ;
     private static String orderOfFlowerbed;
     private static int order;
   
    
    public Flower(String image, int X, int Y){
        this.imagePath = image;
        this.X = X;
        this.Y = Y;
        
    }
    
    public void addFlower(){
        
    
        addImage(imagePath, X, Y);
        
        
    }
     protected static void addImage(String imagePath, int x, int y){
       
        
        BufferedImage image = FileUtils.loadImage(imagePath);
        ImageDisplay myImage = new ImageDisplay(image, x, y, 25,25);
        myFlowers.add(0,myImage);
        MyGarden.getMyWindow().add(myFlowers.get(0)); 
        
        counter += 1;
        
        MyGarden.getMyWindow().repaint();
    }
      
     public static boolean saveZooToFile(ArrayList<String> toWrite) {
        try (FileWriter fw = new FileWriter("flower.txt", false);
                BufferedWriter bw = new BufferedWriter(fw);
                PrintWriter out = new PrintWriter(bw)) {
                    for(String im: toWrite){
                       out.println(im.toString());
                    }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        
        return true; 
    }
     
     public void addFlowertoFile(){
             String allString = "ImageDisplay,";
             allString += imagePath;
             allString += ",";
             String X = String.valueOf(this.X);
             String Y = String.valueOf(this.Y);
             
            
             
             String counter = String.valueOf((Flower.counterOfFileSaving)+(order));
             allString += X;
             allString += ",";
             allString += Y;
             allString += ",";
             allString += counter;
             myFlowersText.add(0,allString);
           
             
             saveZooToFile(myFlowersText);
         
     }
     
       public static void readFirstLineFromFile(){
        Path filePath = Paths.get("flower.txt");
        if(!Files.exists(filePath)){
            System.out.println("There is no file to read from.");
        }
        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            String line = null ;
           line = reader.readLine();
                //System.out.println(line);
                if (line!=null) {
                imageFromString(line);
            }
                else if (line==null) {
                order = 0;
            }
                    
                    
                
                
            
        } catch (IOException e) {
            System.out.println("Error reading file:" + filePath);
            e.printStackTrace();
        }
    }
     private static void imageFromString(String line){
        String[] str = line.split("\\,");
          path = str[1];
          xString = str[2];
          x=Integer.parseInt(xString);
          yString = str[3];
          y=Integer.parseInt(yString);
          orderOfFlowerbed = str[4];
          order =Integer.parseInt(orderOfFlowerbed);
    }
     
     public static void restoreCounter(){
         counter -= Flowerbed.getFirstOrder();
     }
      
     /*  public static void readZooFromFile(){
        Path filePath = Paths.get("zoo.txt");
        if(!Files.exists(filePath)){
            System.out.println("There is no file to read from.");
        }
        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            String line = null;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
                if(line.startsWith("1")){
                    imageFromString(line);
                }
                else{
                    System.out.println("Bad line in file: "+line);
                }   
            }
        } catch (IOException e) {
            System.out.println("Error reading file:" + filePath);
            e.printStackTrace();
        }
    }
       
       
        private static void imageFromString(String line){//read method
        
    }
      */
      
}
