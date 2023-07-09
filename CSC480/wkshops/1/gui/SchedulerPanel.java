package gui;

import java.awt.Color;
import java.awt.ComponentOrientation;
import java.awt.GridLayout;
import java.text.SimpleDateFormat;
import java.util.*;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.Border;

import data.EventFileAccessor;

public class SchedulerPanel extends JPanel {
    private static JTextArea[][] cells;
	String[] weekdayNames = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    public SchedulerPanel(int month) {

		try {
			SimpleDateFormat formatter = new SimpleDateFormat("M-d-yyyy");

			// accessing data file of events
			// and storing it into a map
			EventFileAccessor fileAccessor = new EventFileAccessor("data/EventsList.csv");
			Map<Date, String> eventList = new HashMap<Date, String>();
			eventList = fileAccessor.getEventList();


			// two parallel arrays will 
			// be used to print out correct events

			// storing dates from file into array of Dates
			Collection<Date> keySet = eventList.keySet();
			Date[] eventDates = keySet.toArray(new Date[0]);

			// storing events from file into array of Events
			Collection<String> values = eventList.values();
			String[] events = values.toArray(new String[0]);

			// print out calendar events to console
			for(int i = 0; i < eventDates.length; i++) {
				System.out.println(events[i] + " ----> " + eventDates[i]);
			}

			// creating layout for the days of the week
			this.setLayout(new GridLayout(7, 7));
			cells = new JTextArea[6][7];
			Border blackline = BorderFactory.createLineBorder(Color.black);
			JLabel weekdayLabel;
			for (String name : weekdayNames) {
				weekdayLabel = new JLabel(name, JLabel.CENTER);
				weekdayLabel.setOpaque(true);
				weekdayLabel.setBackground(new Color(51, 227, 255));
				weekdayLabel.setForeground(Color.RED);
				weekdayLabel.setBorder(blackline);
				this.add(weekdayLabel);
			}    
				  
			JTextArea aCell;
			
			// initialize calendar
			GregorianCalendar calendar = new GregorianCalendar();
			calendar.set(GregorianCalendar.MONTH, month);									// sets the calendar to the month specified by the user
			calendar.set(GregorianCalendar.DAY_OF_MONTH, 1);								// sets the calendar to the first day of the month
			int daysInMonth = calendar.getActualMaximum(GregorianCalendar.DAY_OF_MONTH);	// stores the # of days that are in the user specified month

			int day = 1;
			for (int i=0; i<cells.length; i++) {
				for (int j=0; j<cells[0].length; j++) {
					aCell = new JTextArea(3, 15);
					//aCell.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);;

					String currentDate = FormatDate(calendar);

					// if the days in month left are greater than 0, then there are
					// still more days to print out onto to the panel
					if(daysInMonth > 0) {
						// prints out the numerical day in the correct text area
						aCell.setText(String.valueOf(day));

						// checks if the current date is an event date, if so print out the event
						if(CanLoadEvent(currentDate, eventDates)) {
							aCell.setText(String.valueOf(day) + "\n" + events[FindIndex(eventDates, currentDate)]);
						}

						// increase calendar day 
						// decrease days left in user specifed month
						// set the calendar to the new day
						day++;
						daysInMonth--;
						calendar.set(GregorianCalendar.DAY_OF_MONTH, day);
					}
				
					aCell.setBorder(blackline);
					this.add(aCell);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
        
    }

	// compares the current date to all event dates
	// and returns if the current date has an event 
	private static boolean CanLoadEvent(String currentDate, Date[] eventDates) {
		boolean canLoad = false;
		for(int i = 0; i < eventDates.length; i++) {
			if(currentDate.equals(FormatDate(eventDates[i]))) {
				canLoad = true;
			}
		}
		
		return canLoad;
	}

	// formats GregorianCalendar object into a string
	public static String FormatDate(GregorianCalendar calendar) {
		SimpleDateFormat formatter = new SimpleDateFormat("M-d-yyyy");
		formatter.setCalendar(calendar);

		return formatter.format(calendar.getTime());
	}

	// formats Date object into a string
	public static String FormatDate(Date date) {
		SimpleDateFormat formatter = new SimpleDateFormat("M-d-yyyy");
		return formatter.format(date);
	}

	// finds the index of the event date
	// can be used to find the name of the event because they are parallel arrays
	public static int FindIndex(Date[] date, String currentDate) {
		int index = 0;
		for(int i = 0; i < date.length; i++) {
			if(FormatDate(date[i]).equals(currentDate)) {
				index = i;
				break;
			}
		}
		return index;
	}
}