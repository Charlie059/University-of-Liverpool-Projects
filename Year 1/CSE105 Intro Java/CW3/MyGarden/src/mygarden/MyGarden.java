/*
xuhui gong 1718128
 */
package mygarden;
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author Mac
 */
public class MyGarden {

    public static JFrame myWindow;
    
       
    public static void main(String[] args) {
        
        myWindow = new JFrame("My Garden");

        myWindow.setVisible(true);
        myWindow.getContentPane().setBackground(new Color(139, 69, 19));
        
        
        myWindow.setSize(1200, 1000);
        myWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
        
        FileUtils.readZooFromFile();

        
        //不能光移除，还要移除文件
       // myWindow.remove(Flower.myFlowers.get(1));
       // myWindow.remove(Flower.myFlowers.get(0));
        UserInterface.showMenu();
        
        myWindow.dispose();
       
    }
    
  /*  public static void removeFlowerbed (int removePart){
        
        if (removePart == 1) {
            
            
             Flowerbed.restoreOrder();
              Flowerbed.readOrder();
             
             for (int i = 0; i < Flowerbed.getFirstOrder(); i++) {
                 int a = Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder()+Flowerbed.getFourthOrder();
            myWindow.remove(Flower.myFlowers.get(0));
            Flower.myFlowers.remove(0);
            Flower.myFlowersText.remove(Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder()+Flowerbed.getFourthOrder());
          
            myWindow.repaint();}
               Flowerbed.restoreOrder();
            Flowerbed.readOrder();
            
        }
        else if (removePart == 2) {
            Flowerbed.restoreOrder();
            Flowerbed.readOrder();
            
            for (int i = Flowerbed.getFirstOrder(); i<Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder(); i++) {
          
            myWindow.remove(Flower.myFlowers.get(Flowerbed.getFirstOrder()));
            Flower.myFlowers.remove(Flower.myFlowers.get(Flowerbed.getFirstOrder()));
             Flower.myFlowersText.remove(Flowerbed.getFourthOrder()+Flowerbed.getThirdOrder());
          
            myWindow.repaint();
        }
             Flowerbed.restoreOrder();
            Flowerbed.readOrder();
         
        }
        else if (removePart == 3) {
            Flowerbed.restoreOrder();
            Flowerbed.readOrder();
           
            for (int i = Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder(); i<Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder(); i++) {
          
            myWindow.remove(Flower.myFlowers.get(Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()));
            Flower.myFlowers.remove(Flower.myFlowers.get(Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()));
            Flower.myFlowersText.remove(Flowerbed.getFourthOrder());
          
            myWindow.repaint();
        }
            Flowerbed.restoreOrder();
            Flowerbed.readOrder();
        }
        else if (removePart == 4) {
            Flowerbed.restoreOrder();
            Flowerbed.readOrder();
           
            int a = Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder()+Flowerbed.getFourthOrder();
             for (int i = Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder(); i<a; i++) {
             
            myWindow.remove(Flower.myFlowers.get(Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder()));
            Flower.myFlowers.remove(Flowerbed.getFirstOrder()+Flowerbed.getSecondOrder()+Flowerbed.getThirdOrder());
             Flower.myFlowersText.remove(0);
           
            myWindow.repaint();
            
        }
             Flowerbed.restoreOrder();
            Flowerbed.readOrder();
        }
          
    }
   */
  public static void removeAllFlowerbed(){
     myWindow.getContentPane().removeAll();
     myWindow.repaint();
      while (Flower.myFlowersText.size()!=0) {          
          Flower.myFlowersText.remove(0);
      }
            
            
  }
    
   

    public static JFrame getMyWindow() {
        return myWindow;
    }

    
    
}
