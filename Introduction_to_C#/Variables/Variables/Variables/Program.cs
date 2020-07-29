using System;

namespace Variables
{
    class Program
    {
        static void Main()
        {
            string greeting = "Hey family! ";
            string State = "Your current score is: ";
            string gained = "Point Gained!";
            int score = 10;
            int point = 5;
            Console.WriteLine(greeting + State + score);

            score = score + point;
            Console.WriteLine(gained);
            Console.WriteLine(State + score);

            score = score + point;
            Console.WriteLine(gained);
            Console.WriteLine(State + score);

            score = score + point;
            Console.WriteLine(State + score);

            Console.ReadKey();
        }

    }
}