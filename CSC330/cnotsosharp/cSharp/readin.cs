//Zaina Khutliwala
//Reading in command line arguments

using System;

public class Readin
{
    static public void Main (string[] args)
    {
        for (int i=0; i<args.Length; i++) {
                            Console.WriteLine(String.Format("Argument {0} is '{1}'", i, args[i])); //prints out command line arguments

        }
    }
}
