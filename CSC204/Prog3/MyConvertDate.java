// Name : Syed Saadat
// Title : ConvertDate (Project 3)

import java.util.*;

public class MyConvertDate
{
      public static void main (String[] args)
      {  
        // All the Variables 
        
        String day, year, month, date; // The String Date
        int J;                             // The century
        int K;                             // Year within century
        int m;                             // Month
        int date2;                         // Day in month 
        int h;                             // The variable for the day in the week
        int year2;
        
        // Getting Initial value
        
        Scanner scan = new Scanner(System.in);
        System.out.print("\nEnter date to be converted (month day, year) : ");
        date = scan.nextLine();
        
        // Pulling off year, date, and month
        
        year = date.substring(date.length() - 4, date.length());
        year2 = Integer.parseInt(year);
        
        int endIndex = date.indexOf(",");
        int startIndex = date.lastIndexOf(" ", endIndex);
        day = date.substring(startIndex + 1, endIndex);
        date2 = Integer.parseInt(day);
        
        month = date.substring(0, date.indexOf(" "));
        month = month.trim();

        // Converting month to a number 
        
        m = -1;
        
        if(month.equalsIgnoreCase("january")){
           
            m = 1;
                
        } else if(month.equalsIgnoreCase("february")){
            
            m = 2;                                          

        } else if(month.equalsIgnoreCase("march")){
            
            m = 3;
         
        } else if(month.equalsIgnoreCase("april")){
        
            m = 4;
        
        } else if(month.equalsIgnoreCase("may")){
            
            m = 5;

        } else if(month.equalsIgnoreCase("june")){
            
            m = 6;
        
        } else if(month.equalsIgnoreCase("july")){
            
            m = 7;

        } else if(month.equalsIgnoreCase("august")){
            
            m = 8;

        } else if(month.equalsIgnoreCase("september")){
            
            m = 9;
            
        } else if(month.equalsIgnoreCase("october")){
            
            m = 10;
        
        } else if(month.equalsIgnoreCase("november")){
            
            m = 11;

        } else if(month.equalsIgnoreCase("december")){
            
            m = 12;
        }

    
        // Finding J & K
        
        J = year2 / 100;
        K = year2 % 100;
        
        // Calculating the day of the week
        
        if( m == 1){
            m = 13;
            K--;
            if(K == -1){
                 K = 99;
                 J--;}
         } else if(m == 2){
             m = 14;
             K--; 
             if(K == -1){
                 K = 99;
                 J--;}
         }
         
         h = -1;
         h = ((date2 + (((m + 1) * 26) / 10) + K + (K / 4) + (J / 4)) + (5 * J)) % 7;
        
        // Assigning Number to Day of Week
        
        String dayInWeek = " ";
        if(h == 0){
          dayInWeek = "Saturday";
        } else if(h == 1){
          dayInWeek = "Sunday";
        } else if(h == 2){
          dayInWeek = "Monday";
        } else if(h == 3){
          dayInWeek = "Tuesday";
        } else if(h == 4){
          dayInWeek = "Wednesday";
        } else if(h == 5){
          dayInWeek = "Thursday";
        } else if(h == 6){
          dayInWeek = "Friday";
        } 
        
        // Printing Results
        
        System.out.println("\nConverted Date: " + dayInWeek + ", " + month.substring(0,1).toUpperCase() + 
        month.substring(1) + " " + date2 +", " + year2 + "\n");

      }
}
        
        