using System;
class Program
{
        static void ToRoman(int num)
        {
                if(num ==0)
                {
                        Console.Write("N");
                }
                else if (num >8)
                {
                        for (int i = 1; i < 10-num; i++)
                        {
                                Console.Write("I");
                        }
                Console.Write("X");
                }
                else if (num > 5)
                {
                        Console.Write("V");
                        for (int i= 1; i< num-5; i++)
                        {
                                Console.Write("I");
                        }
                }
                else if (num > 3)
                {
                        if(num == 4)
                        {
                                Console.Write("I");
                        }
                }
                else
                {
                        for (int i= 1; i< num; i++)
                        {
                                Console.Write("I");
                        }
                }
                Console.Write(" ");
        }

        static void Main()
        {
	
		ToRoman(8);
        }
}

