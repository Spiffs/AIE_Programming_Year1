using System;

namespace Inputs_and_Functions
{
 class Program
    {
        static void pressenter()
        {
            Console.WriteLine("Press Enter to Continue");
        }

        static void Main()
        {
            Console.WriteLine("You are approached by a visious Monster!");
            pressenter();
            Console.ReadKey();
        }

        static void firstattack()
        {
            Console.WriteLine("It attacks, 'Y' to attack it back, 'N' to defend.");
        }
    }
        
}
