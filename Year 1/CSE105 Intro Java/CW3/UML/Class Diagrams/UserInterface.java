/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mygarden;


import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JFrame;


/**
 *
 * @author Mac
 */
public class UserInterface {
    private static Scanner kb;
    public static ArrayList<String> folowerbedData = new ArrayList<String>();

    private static int counterOfFolowerbedDataArrayList = 0;
    private static int removCounter = 0;
    private static int removeChoice;
    
    
    
    public static void showMenu(){
        
        kb = new Scanner(System.in);
        
        //Flowerbed.recoveryFile();
        System.out.println("-------------------------------");
        System.out.println("Please select:");
        System.out.println("1.\tAdd flowerbed");
        System.out.println("2.\tRemove flowerbed");
  
        System.out.println("3.\tExit and save");
        System.out.println("-------------------------------");
          
        int command =  getRightChoice(3);
        switch(command){ 
            case 1:
                Flowerbed.readOrder();
               // checkFull();
                

                UserInterface a = new UserInterface();
                a.addFlowerbed();
                break;
            case 2:
               
                System.out.println("Removing flowers:");
             //   System.out.println("****Please do not end the program when Removing all flowerbeds****");
              //  System.out.println("****Removing function only support when you add four flowerbeds then you remove****");
              //  Flowerbed.readOrder();
                MyGarden.removeAllFlowerbed();
              //  removeInstruction();//User must remove each different! Solve it!!!
                //应当四个一加，四个一移除
                
                
                Flower.saveZooToFile(Flower.myFlowersText);
        
                showMenu();
                
                break;  
            case 3:
              //   Flowerbed.readOrder();
                
             //   if (checkMoveall()==false) {
            //        showMenu();
            //    }
                System.out.println("Exit and save");
                //now, how are we going to remove an animal
                
                System.exit(0); 
                break;  
                
        }
        
        
        
        
    }
    
     private void addFlowerbed(){
            

        System.out.println("\n-------------------------------");
        System.out.println("Adding flowerbed");
 
        System.out.println("Please select type of flowerbed firstly");
        System.out.println("1. Pure 2. Mix");
        System.out.println("\n-------------------------------");
        
        int type = getRightChoice(2);
        
        if (type == 1) {
             System.out.println("Please select flower:");
             System.out.println("1.Green 2. Red 3.White 4.Yellow 5.Sun flower");
             System.out.println("\n-------------------------------");
             int pathInt1 = getRightChoice(5);
             String path1 = pathIntTransfertoString(pathInt1);
     
             System.out.println("Please input position x of flowerbed:");
             System.out.println("\n-------------------------------");
             int x = DistanceLimiter("x");
             String xString = String.valueOf(x);
             System.out.println("Please input position y of flowerbed:");
             System.out.println("\n-------------------------------");
             int y = DistanceLimiter("y");
             System.out.println("Please input width of flowerbed:");// 100 yishang bu huc bug
             System.out.println("\n-------------------------------");
             int width = DistanceLimiter("x");
             if (width % 25 != 0) {
                 System.out.println("Because of you input is not Integer multiple of 25, the value will carry");
            }
             System.out.println("Please input height of flowerbed:");
             System.out.println("\n-------------------------------");
             int height = DistanceLimiter("y");
             if (height % 25 != 0) {
                 System.out.println("Because of you input is not Integer multiple of 25, the value will carry");
            }
             String yString = String.valueOf(y);
             String typeString = String.valueOf(type);
             String widthString = String.valueOf(width);
             String heightString = String.valueOf(height); 
// Write folowerbedDataArrayList
             //counterOfFolowerbedDataArrayList
             //counterOffolowerbedData
             String allString = typeString;
             allString += ",";
             allString += path1;
             allString += ",";
             allString += xString;
             allString += ",";
             allString += yString;
             allString += ",";
             allString += widthString;
             allString += ",";
             allString += heightString;
  
             folowerbedData.add(counterOfFolowerbedDataArrayList,allString);
             counterOfFolowerbedDataArrayList += 1;
             //restore the counterOffolowerbedData
            
             String path2 = null;

             saveZooToFile(folowerbedData);
             Flowerbed flowerbed = new Flowerbed(path1,path2,x,y, width, height);
             flowerbed.addFlowerbed();
             //MyGarden.getMyWindow().remove(Flower.myFlowers.get(0));
             //MyGarden.getMyWindow().remove(Flower.myFlowers.get(1));
            // Flower flower = new Flower(path, x, y);
            //flower.addFlowers();
             showMenu();
         }
         else if (type == 2) {
             System.out.println("Please select firt of two path of flower image:");
             System.out.println("1.Green 2. Red 3.White 4.Yellow 5.Sun flower");
             System.out.println("\n-------------------------------");
             int pathInt1 = getRightChoice(5);
             String path1 = pathIntTransfertoString(pathInt1);
             System.out.println("Please select second of two path of flower image:");
             System.out.println("1.Green 2. Red 3.White 4.Yellow 5.Sun flower");//Transfer to String of path1
             System.out.println("\n-------------------------------");
             int pathInt2 = getRightChoice(5);
             String path2 = pathIntTransfertoString(pathInt2);
             
           
             
             System.out.println("Please input position x of flowerbed:");
             System.out.println("\n-------------------------------");
             int x = DistanceLimiter("x");
             String xString = String.valueOf(x);
             
             System.out.println("Please input position y of flowerbed:");
             System.out.println("\n-------------------------------");
             int y = DistanceLimiter("y");
             String yString = String.valueOf(y);
             
             System.out.println("Please input width of flowerbed:");
             System.out.println("\n-------------------------------");
             int width = DistanceLimiter("x");
             String widthString = String.valueOf(width);
             System.out.println("Please input height of flowerbed:");
             System.out.println("\n-------------------------------");
             int height = DistanceLimiter("y");
             String heightString = String.valueOf(height);
             System.out.println("Please select horizontal plant or vertical plant");
             System.out.println("Please press 1 for horizontal plant or press 2 for vertical plant");
             System.out.println("\n-------------------------------");
             int mixType = getRightChoice(2);
             
// Write folowerbedDataArrayList
        

             String allString = "2";
             allString += ",";
             allString += path1;
             allString += ",";
             allString += path2;
             allString += ",";
             allString += xString;
             allString += ",";
             allString += yString;
             allString += ",";
             allString += widthString;
             allString += ",";
             allString += heightString;
             

             folowerbedData.add(counterOfFolowerbedDataArrayList,allString);
             counterOfFolowerbedDataArrayList += 1;

             saveZooToFile(folowerbedData);
             Flowerbed flowerbed = new Flowerbed(path1,path2,x,y, width, height);
             
             if (mixType == 1) {
                flowerbed.addFlowerbedForHorizontalMix();
            }
             else if(mixType == 2){
                flowerbed.addFlowerbedForVerticalMix();
             }
             //flowerbed.addFlowerbedForHorizontalMix();
             
             //MyGarden.getMyWindow().remove(Flower.myFlowers.get(0));
             //MyGarden.getMyWindow().remove(Flower.myFlowers.get(1));
            // Flower flower = new Flower(path, x, y);
            //flower.addFlowers();
             showMenu();

             
         }
        
        
        // How do you want the user to choose the image? SEE LECTURE PPT
        
        //OK, when the user has chosen the image, you need to get the x,y,width,height,
        //and then call:
        //Zoo1.addImage(path, imageX, imageY, width, height);
        
        
    }
    
    
    
    
       private static int getIntInput(){
        int input = 0;
        try{
            input = Integer.parseInt(kb.nextLine());
        }
        catch(NumberFormatException e){
            System.out.println("That is not an int; "
                                + "please try again");
            input = getIntInput();
        }
        finally{
            return input;    
        }
    }
       
       
       private static int getRightChoice(int choice){  //检测用户选择输入在范围内
          int input = getIntInput();
          if (choice == 3){
              if ( (input != 1) && (input != 2) && (input != 3)) {
                  System.out.println("Please select 1 or 2 or 3!");
                  showMenu();
              }
              else {return input;}
              
          }
          else if(choice == 2){
              if ( (input != 1) && (input != 2) ) {
                  System.out.println("Please select 1 or 2!");
                  
                  UserInterface choice2 = new UserInterface();
                  choice2.addFlowerbed();
                  
              }
              else {return input;}
              
          }
          else if(choice == 5){
              if ( (input != 1) && (input != 2) && (input != 3) && (input != 4)&& (input != 5)) {
                  System.out.println("Please select 1 or 2 or 3 or 4 or 5!");
                  UserInterface choice2 = new UserInterface();
                  choice2.addFlowerbed();
                  }
              else{return input;}
           }
          else if(choice == 4){
              if ( (input != 1) && (input != 2) && (input != 3) && (input != 4)) {
                  System.out.println("Please select 1 or 2 or 3 or 4!");
                 // removeInstruction();
              }
              else{return input;}
           }
             
               return input;
       }
       
       
        private static int DistanceLimiter(String choice){  //检测用户input输入范围
          int input = getIntInput();
          int xLimiter = 1200;
          int yLimiter = 1000;
            if (choice.equalsIgnoreCase("x")) {
                 if ((xLimiter<input)||(input<=25)){
              System.out.println("Warning, x is out of range, please enter input beyond 25 and less than 1200");
              DistanceLimiter("x");
           }
            }else if (choice.equalsIgnoreCase("y")) {
                 if ((yLimiter<input)||(input<=25)){
              System.out.println("Warning, y is out of range, please enter input beyond 25 and less than 1000");
              DistanceLimiter("y");
            }
                
            }
            
         
         return input;
    
}
        public static boolean saveZooToFile(ArrayList<String> toWrite) {
        try (FileWriter fw = new FileWriter("folowerbedDataArrayList.txt", false);
                BufferedWriter bw = new BufferedWriter(fw);
                PrintWriter out = new PrintWriter(bw)) {
                    for(String im: toWrite){
                        out.println(im.toString());
                    }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        System.out.println("Garden saved to file");
        return true; 
    }
        
        private static String pathIntTransfertoString(int pathInt){
            if (pathInt == 1) {
                String path = "green.png";//1.Green 2. Red 3.White 4.Yellow 5.Sun flower
                return path;
            }
            else if (pathInt == 2) {
                String path = "red.png";
                return path;
            }
            else if (pathInt == 3) {
                String path = "white.png";
                return path;
            }
            else if (pathInt == 4) {
                String path = "yellow.png";
                return path;
            }
            else if (pathInt == 5) {
                String path = "sflower.png";
                return path;
            }
            else {getRightChoice(5);
              
            return null;}
            
            
        }
        
       
   /*     public static void removeInstruction(){
            
            System.out.println("Which part do you want to remove?");
            System.out.println("Please select a quadrant, such as 1, 2, 3, 4");
             removeChoice = getRightChoice(4);
            
            if (removeChoice == 1) {
                 Flowerbed.restoreOrder();
                 Flowerbed.readOrder();
                 if (Flowerbed.getFirstOrder()==0) {
                     System.out.println("There is nothing to remove!");
                     showMenu();
                    
                }else{removCounter++;
                 MyGarden.removeFlowerbed(1);}
                
            }
            else if (removeChoice == 2) {
                  Flowerbed.restoreOrder();
                 Flowerbed.readOrder();
                 if (Flowerbed.getSecondOrder()==0) {
                     System.out.println("There is nothing to remove!");
                     showMenu();
                    
                }else{removCounter++;
                 MyGarden.removeFlowerbed(2);}
            }
            else if (removeChoice == 3) {
                  Flowerbed.restoreOrder();
                 Flowerbed.readOrder();
                 if (Flowerbed.getThirdOrder()==0) {
                     System.out.println("There is nothing to remove!");
                     showMenu();
                    
                }else{removCounter++;
                 MyGarden.removeFlowerbed(3);}
            }
             else if (removeChoice == 4) {
                  Flowerbed.restoreOrder();
                 Flowerbed.readOrder();
                 if (Flowerbed.getFourthOrder()==0) {
                     System.out.println("There is nothing to remove!");
                     showMenu();
                    
                }else{removCounter++;
                 MyGarden.removeFlowerbed(4);}
            }
            
            
        }
        public static void checkFull(){
            Flowerbed.restoreOrder();
            Flowerbed.readOrder();
            if ((Flowerbed.getFirstOrder()!= 0)&&(Flowerbed.getSecondOrder()!= 0)&&(Flowerbed.getThirdOrder()!= 0)&&(Flowerbed.getFourthOrder() != 0)) {
                System.out.print("Maxium Flowerbed is 4, please remove firstly then add flowerbed!");
                showMenu();
            }
           
        
        }
    /*    private static boolean checkMoveall(){
          
            if (removCounter<=4) {
                  if (removCounter%4 ==0) {
                return true;
            }
            else{System.out.println("Please remove all Flowers, then you could add flowerbed or exit!")
                    ;System.out.println("Please do not end program in removing all");
                return false;}
            }
            else{return true;}
          
        }*/
     
         /*  private static boolean checkMoveall(){
                Flowerbed.restoreOrder();
                Flowerbed.readOrder();
               int removCounter_= 0;
               if (Flowerbed.getFirstOrder() == 0) {
                   removCounter_++;
               }
               if (Flowerbed.getSecondOrder()== 0) {
                   removCounter_++;
               }
               if (Flowerbed.getThirdOrder()== 0) {
                   removCounter_++;
               }
               if (Flowerbed.getFourthOrder()== 0) {
                   removCounter_++;
               }
          
           
                  if (removCounter_%4 ==0) {
                return true;
            }
            else{System.out.println("Please remove all Flowers, then you could add flowerbed or exit!")
                    ;System.out.println("Please do not end program in removing all");
                return false;}
            
            
          
        }*/
    }
        
        
