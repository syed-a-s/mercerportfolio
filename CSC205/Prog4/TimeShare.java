import java.io.*;
import java.util.*;

public class TimeShare { 

     static int clock, idle, usage, numOfJobs;

     public static void main(String[] args){
    
         Job job = new Job();
		     Queue inputQ = new Queue();
		     Queue outputQ = new Queue();
         Queue jobQ = new Queue();
         Scanner scan = new Scanner(System.in);

         
         System.out.print("Which job file? ");
         String filename = scan.nextLine();
            
         inputJobs("jobs1.dat", inputQ, job);
         processJobs(inputQ, outputQ, jobQ);
         print(outputQ);

     }
	   public static void inputJobs(String inputFile, Queue input, Job job) {
         numOfJobs = 0;
		     try {
		         Scanner in = new Scanner(new File(inputFile));
			       while(in.hasNext()) {
				         Scanner lsc = new Scanner(in.nextLine());
  				       String jobName = lsc.next(); ;
				         int arrivalTime = lsc.nextInt();
				         int runTime = lsc.nextInt();
				         job = new Job(jobName, arrivalTime, runTime);
				         input.enqueue(job);
                 numOfJobs++;
			       }
		     } catch (IOException e) {
					       System.out.println(e.getMessage());
         }
         clock = 1; idle = 0; usage = 0;    
	  }
 
	  public static void processJobs(Queue inputQ, Queue outputQ, Queue jobQ) {
		    // checking with input queue
        boolean all = false;
		    while (!inputQ.isEmpty() && !all ) {
			      Job nextJob = (Job) inputQ.front();
			      if (nextJob.arrivalTime == clock) {
                 jobQ.enqueue(nextJob);
                 inputQ.dequeue();
                // System.out.println(jobQ.front() + "\tmee");
			      }

            if (!jobQ.isEmpty()) {
                Job activeJob = (Job) jobQ.front();
                activeJob = (Job) jobQ.front();
		            if((activeJob.startTime > -1) && (activeJob.runTime == clock - activeJob.startTime)) {
					            activeJob.turnTime = nextJob.arrivalTime - clock;
					            outputQ.enqueue(jobQ.dequeue());
                }

                if((activeJob.arrivalTime <= clock) && (activeJob.startTime == -1)) {                        
					            activeJob.startTime = clock;
					            activeJob.waitTime = activeJob.startTime - activeJob.arrivalTime;
                }
            }
			
			      if (jobQ.isEmpty() && !inputQ.isEmpty()) {
    				  idle++;
			      } else {
				      usage++;
			      }
            clock++;

       }
	  }
 
 	public static void print(Queue outputQ) {
		
		//Queue clone = (Queue) outputQ.clone();
		double totalWait = 0;
		Job job = (Job) outputQ.front();
		
		System.out.println("\nJob Control Analysis : Summary Report" + "\n");
		System.out.println("Job id" + "\t" + "arrival" + "\t" + "start" + "\t" + "run" + "\t" + "wait" + "\t" + "turnaround");
		System.out.println("      " + "\t" + "time   " + "\t" + "time" + "\t" + "time" + "\t" + "time" + "\t" + "time" + "\n");
		
		while(!outputQ.isEmpty()) {
      totalWait += job.waitTime;
			System.out.println(outputQ.front());
			outputQ.dequeue();
		}
		
		System.out.println("\nAverage Wait Time => " + ( totalWait/ numOfJobs));
		System.out.println("\t CPU Usage => " + usage);
		System.out.println("\t CPU Idle => " + idle);
		System.out.println("\t CPU Usage (%) => " + (usage / (usage + idle)) + "\n");
		
	}
}
