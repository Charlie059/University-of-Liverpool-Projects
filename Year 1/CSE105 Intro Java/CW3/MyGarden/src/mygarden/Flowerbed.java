/*
xuhui gong 1718128
 */
package mygarden;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

/**
 *
 * @author Mac
 */
public class Flowerbed {
    
    private  String imagePath1;
    private  String imagePath2;
    private  int X;
    private  int Y;
    private  int width ;// Set up each flower is 25 * 25
    private  int height ;
    private  int type = 1 ;
    private  static int order;
    private  static int firstOrder=0 ;
    private  static int secondOrder=0 ;
    private  static int thirdOrder=0;
    private  static int fourthOrder=0 ;

    
   
    public Flowerbed(String path1,String path2,int x,int y,int width ,int height){
        this.X = x;
        this.Y = y;
        this.imagePath1 = path1;
        this.imagePath2 = path2;
        this.width = width;
        this.height= height;
    }
    public void addFlowerbed(){
       
       Flower.readFirstLineFromFile();
        for (int i = 0; i < height; i+=25) {
            
            for (int j = 0; j < width; j+=25) {
            Flower flower = new Flower(imagePath1, X+j, Y+i);
            flower.addFlower();
            flower.addFlowertoFile();
        }
            
        }
        
    }
    
     public void addFlowerbedForVerticalMix(){
       
       Flower.readFirstLineFromFile();
        for (int i = 0; i < height; i+=25) {
            
            for (int j = 0; j < width; j+=50) {
            int k =25;
            Flower flower1 = new Flower(imagePath1, X+j, Y+i);
            flower1.addFlower();
            flower1.addFlowertoFile();
            Flower flower2 = new Flower(imagePath2, X+j+k, Y+i);
            flower2.addFlower();
            flower2.addFlowertoFile();
        }
            
        }
       
    }
     
      public void addFlowerbedForHorizontalMix(){
       
       Flower.readFirstLineFromFile();
        for (int i = 0; i < height; i+=25) {
            
            if (isOdd(i)) {
            for (int j = 0; j < width; j+=25) {
            
            Flower flower1 = new Flower(imagePath1, X+j, Y+i);
            flower1.addFlower();
            flower1.addFlowertoFile();
            
            }
            
            
            
            }else{
                for (int j = 0; j < width; j+=25) {
            Flower flower2 = new Flower(imagePath2, X+j, Y+i);
            flower2.addFlower();
            flower2.addFlowertoFile();
                }
            }
          
        
            
        }
       
    }
   
    public static void recoveryFile(){
       
      
            Flower flowerFromFile = new Flower(FileUtils.getPath(), FileUtils.getX(),FileUtils.getY());
            flowerFromFile.addFlower();
            //Flower.myFlowers = 
            writeArraryListOfmyFlowers();
            
        
            
        
        
    }
    
    private static void writeArraryListOfmyFlowers(){
       
        String data = "ImageDisplay";
        data += ",";
        data += FileUtils.getPath();
        data += ",";
        data += String.valueOf(FileUtils.getX());
        data += ",";
        data += String.valueOf(FileUtils.getY());
        data += ",";
        data += String.valueOf(FileUtils.getOrderOfFlowerbed());
        Flower.myFlowersText.add(data);
    }
    
    private boolean isOdd(int a){   
    if(a%2 == 1){   
        return true;   
    }   
    return false;   
}  
   
          
    
      public static void readOrder(){
        Path filePath = Paths.get("flower.txt");
        if(!Files.exists(filePath)){
            System.out.println("There is no file to read from.");
        }
        try (BufferedReader reader = Files.newBufferedReader(filePath)) {
            String line = null;
            while ((line = reader.readLine()) != null) {
               
                if(line.startsWith("ImageDisplay")){
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
      
       private static void imageFromString(String line){
        String[] str = line.split("\\,");
          
          String orderOfFlowerbed = str[4];
          order=Integer.parseInt(orderOfFlowerbed);
          
           if (order == 1) {
               firstOrder++;
           }
           else if (order == 2) {
               secondOrder++;
           }
           else if (order == 3) {
               thirdOrder++;
           }
           else if (order == 4) {
               fourthOrder++;
           }
          
    }

    public static int getFirstOrder() {
        return firstOrder;
    }

    public static int getSecondOrder() {
        return secondOrder;
    }

    public static int getThirdOrder() {
        return thirdOrder;
    }

    public static int getFourthOrder() {
        return fourthOrder;
    }

  
    
       
    public static void restoreOrder(){
            firstOrder=0 ;
            secondOrder=0 ;
            thirdOrder=0;
            fourthOrder=0 ;
            
    }
    
}
