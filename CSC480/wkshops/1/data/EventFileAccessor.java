package data;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EventFileAccessor {
      private Map<Date, String> eventList;
      private SimpleDateFormat sdFormat = new SimpleDateFormat("M-d-yyyy");
      private String fileName;

      public EventFileAccessor(String fileName) throws Exception {
            this.fileName = fileName;
            eventList = new HashMap<Date, String>();
            String[] parts;
            Date eventDate;
            String eventText;

            try { 
                  Scanner input = new Scanner(new File(fileName));
                  while (input.hasNextLine()) {
                        parts = input.nextLine().split(",");
                        //System.out.println(parts[0]);
                        eventDate = sdFormat.parse(parts[0]);
                        //System.out.println(eventDate);
                        eventText = parts[1];
                        eventList.put(eventDate, eventText);
                        //System.out.println(eventText + "@" + eventDate);
                  }
            } catch (Exception e) { 
                  e.printStackTrace();
            }
      }

      public Map<Date, String> getEventList() {
            return this.eventList;
      }

      public static void main(String[] args) {
            try { 
                  EventFileAccessor fileAccessor = new EventFileAccessor("data/EventsList.csv");
                  System.out.println("OVER HERE" + fileAccessor.getEventList());
            } catch (Exception e) { 
                  System.out.println("File not found.");
            }
      }
}