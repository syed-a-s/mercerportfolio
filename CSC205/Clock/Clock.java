import java.util.*;

public class Clock 

  {
      private int hour;
      private int min;
      private int sec;
      
      // Initializing
      public Clock(int myHrs, int myMin, int mySec)
      { 
          hour = myHrs;
          min = myMin;
          sec = mySec;
      }
      
      // Set to 0
      public Clock()
      {
          hour = 0;
          min = 0;
          sec = 0;
      }
      
      // Reset
      
      public void reset()
      {
          hour = 0;
          min = 0;
          sec = 0;
      }
      
      // Overloaded reset method
      public void reset(int myHrs, int myMin, int mySec)
      {
          hour = myHrs;
          min = myMin;
          sec = mySec;
      }
      
      // Advance clock by one sec
      public void Advance()
      {
          System.out.print("\nAdvancing the time!\n");
          
          sec ++;
          
          // For resetting time if we need to
          
          if( sec > 59 )
          {
            min++;
            sec = 0;    
          }
           
          if ( min > 59 )
          {
            hour++;
            min = 0;
          }
          if ( hour > 23 )
          
            hour = 0;
          
      }
      
      // Method - print out correct format
      
      public String toString()
      {
          String time = "";
          
          if ( hour < 10 )
              time += '0';
              time =+ hour + ":";
          if ( min < 10 )
              time += '0';
              time += min + ":";
          if ( sec < 10 ) 
              time += '0';
              time += sec;
          
          System.out.print("\nThe time is now " + time + "\n");
          
          return time;
          
      }                        
          
   }       
            
      
       
       
      
