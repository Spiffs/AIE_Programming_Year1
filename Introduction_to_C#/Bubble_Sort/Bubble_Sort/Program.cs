using System;

namespace Bubble_Sort
{
    class Program
    {
        static int swaps = 0; //Counts swaps made 
        static int j = 1; //Point of which the accending scan stops 
        static int a = 0; //Point of which the descending scan stops 
        static int comparisons = 0; //Counts comparisons made with or without swaps 
       
        //Scans array in order to test for swaps
        static bool Numbibois(int a, int b)
        {
            comparisons++;
            if (a > b)
            {
                swaps++;
                return true;
            }
            else return false;
        }
        //Scans array backwards scanning for opposire swaps (not needed) 
        //static bool Numbiboisbackwards(int a, int b)
        //{
        //    comparisons++;
        //    if (a > b)
        //    {
        //        swaps++;
        //        return true;
        //    }
        //    else return false;
        //}

        static void printArray(int[] array)
        { 
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write("{0},\t", array[i]);
                if (i % 10 == 9)
                {
                    Console.WriteLine();
                }
            }
            Console.WriteLine();
            Console.WriteLine();
        }

        //static void BubbleSort(int[] array)
        //{
        //    if (array.Length <= 1)
        //        return;
        //    bool sorted = false;
        //    while (!sorted)
        //    {
        //        sorted = true;

        //        for (int i = 0; i < array.Length - 1; ++i)
        //        {
        //            if (Numbibois(array[i], array[i + 1]))
        //            {
        //                int tmp = array[i];
        //                array[i] = array[i + 1];
        //                array[i + 1] = tmp;
        //                sorted = false;
        //            }
        //        }
        //    }
        //}

        //static void OptimisedBubbleSort(int[] array)
        //{
        //    if (array.Length <= 1)
        //        return;
        //    bool sorted = false;
        //    while (!sorted)
        //    {
        //        sorted = true;

        //        for (int i = 0; i < array.Length - j; ++i)
        //        {
        //            if (Numbibois(array[i], array[i + 1]))
        //            {
        //                int tmp = array[i];
        //                array[i] = array[i + 1];
        //                array[i + 1] = tmp;
        //                sorted = false;
        //            }
                    
        //        }
        //        j++;
        //    }
        //}

        static void CocktailBubbleSort(int[] array)
        {
            if (array.Length <= 1)
                return;
            bool sorted = false;
            while (!sorted)
            {
                sorted = true;

                for (int i = 0; i < array.Length - j; ++i)
                {
                    if (Numbibois(array[i], array[i + 1]))
                    {
                        int tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                        sorted = false;
                    }

                }
                
                j++;

                Console.WriteLine("J: " + j);
                


                for (int i = array.Length - j; i >= 0 + a; --i)
                {
                    if (Numbibois(array[i], array[i + 1]))
                    {
                        int tmp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = tmp;
                        sorted = false;
                        
                    }
                }
                a++;

                Console.WriteLine("A: " + a);
            }
        }

        static void Main()
        {
            int[] arrayToBeSorted = new int[]
            {
                14,65,63,1,54,
                89,84,9,98,57,
                71,18,21,84,69,
                28,11,83,13,42,
                64,58,78,82,13,
                9,96,14,39,89,
                40,32,51,85,48,
                40,23,15,94,93,
                35,81,1,9,43,
                39,15,17,97,52,
            };

            Console.WriteLine("unsorted");
            printArray(arrayToBeSorted);

            CocktailBubbleSort(arrayToBeSorted);

            Console.WriteLine("\nSorted");
            printArray(arrayToBeSorted);

            Console.WriteLine("Swaps; " + swaps);
            Console.WriteLine("Comparisons: " + comparisons);

            Console.ReadKey();

        }
    }
}
