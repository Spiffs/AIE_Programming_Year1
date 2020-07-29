using System;

namespace Arrays
{
    class Program
    {
        //static void Main(string[] args)
        //{
        //    string[] values = new string[4];

        //    for (int i = 0; i < 4; ++i)
        //    {
        //        values[i] = Console.ReadLine();
        //    }

        //    Console.WriteLine();

        //    for (int i = 3; i > -1; --i)
        //    {
        //        Console.WriteLine(values[i]);
        //    }

        //}

        //_______________________________________________________________________________________________________

        //static void Main(string[] args)
        //{
        //    string[] values = new string[4];

        //    for (int i = 0; i < 4; ++i)
        //    {
        //        values[i] = Console.ReadLine();
        //    }

        //    Console.WriteLine();

        //    Array.Sort(values);

        //    for (int i = 3; i > -1; --i)
        //    {
        //        Console.WriteLine(values[i]);
        //    }

        //_________________________________________________________________________________________________________

        static void Main(string[] args)
        {
            int[] values = new int[9] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            int[,] array4 = { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };

            for (int i = 0; i < 4; --i)
            {
                int u = 0;
                Console.WriteLine(array4[i, 0] + " " + array4[i, 1]);

            
            }



        }
    }
}
