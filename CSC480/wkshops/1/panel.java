import gui.SchedulerPanel;
import java.util.*;
import javax.swing.*;

public class panel {
    public static void main(String[] args) {
		String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		int month = -1;

		// ask user for month
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter Numeric Month : ");
		month = scan.nextInt() - 1;

		// initializing JFrame Window
        JFrame schFrame = new JFrame("Monthly Planner for " + months[month]);
		schFrame.add(new SchedulerPanel(month));
		schFrame.pack();
		schFrame.setVisible(true);
		schFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
