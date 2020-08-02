/*
xuhui gong 1718128
 */
package mygarden;

import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import javax.imageio.ImageIO;

/**
 *
 * @author Mac
 */
public class FileUtils {
    
    
     private static String path ;
     private static String xString ;
     private static int x ;
     private static String yString;
     private static int y ;
     private static String orderOfFlowerbed;
    
    
     private static ArrayList<String> readMyFlowersText = new ArrayList<String>();
     
     
     public static BufferedImage loadImage(String imagePath){
        BufferedImage image = null;
        try {
            image = ImageIO.read(new File(imagePath));
            
        } catch (IOException e) {
            System.out.println("Problem loading image: "+imagePath);
            e.printStackTrace();
        }
        return image;
    }
    
    public static ArrayList<String> getFileNames(String dirPath){
        ArrayList<String> names = new ArrayList<String>();
        File dir = new File(dirPath);
        if(dir.isDirectory()){
            for(File f: dir.listFiles()){
                names.add(f.getPath());
            }
        }
        return names;
    }
    
   
    
    public static void readZooFromFile(){
        Path filePath = Paths.get("flower.txt");
        if(!Files.exists(filePath)){
            System.out.println("There is no file to read from.");
        }
        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            String line = null;
            while ((line = reader.readLine()) != null) {
               // System.out.println(line);
                if(line.startsWith("ImageDisplay")){
                    imageFromString(line);
                    Flowerbed.recoveryFile();
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
    
    
    
    private static void imageFromString(String line){
        String[] str = line.split("\\,");
          path = str[1];
          xString = str[2];
          x=Integer.parseInt(xString);
          yString = str[3];
          y=Integer.parseInt(yString);
          orderOfFlowerbed = str[4];
        
    }

    public static int getX() {
        return x;
    }

    public static int getY() {
        return y;
    }

    public static String getPath() {
        return path;
    }

    public static String getOrderOfFlowerbed() {
        return orderOfFlowerbed;
    }
    
    
}
