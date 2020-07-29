using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment_3
{
    class Sell_
    {
        //Sell function which includes item and quantity searches. Also includes trade code
        public static void Sell()
        {
            Console.Clear();

            int temp;

            Console.WriteLine("Which item would you like to Sell?");
            Console.WriteLine();
            //Print command
            Prints.PrintPlayer();


            Console.WriteLine();

            string buyorsell = Console.ReadLine().ToUpper();

            int resultNumber = Tests.SearchInt(Program.Player, buyorsell);

            Console.Clear();

            if (resultNumber < 0)
            {
                Console.WriteLine("That item does not exist");
                Console.ReadKey();
                Menu_.Menu();
            }
            else
            { }

            //Quantity input 
            Console.WriteLine("Quantity?");
            Console.WriteLine();

            int Quantity = Tests.IntInput();

            int ItemTotal = (Program.Player[resultNumber].cost * Quantity);

            Console.Clear();
            Console.WriteLine(Program.Player[resultNumber].name + " selling for $" + ItemTotal);
            Console.ReadKey();

            bool a_StockTest = Tests.StockTest(Program.Player[resultNumber].quantity, Quantity);

            if (!a_StockTest)
            {
                Console.Clear();
                Console.WriteLine("You do not have enough items to complete that trade.");

                string s = " ";
                if (resultNumber >= 0)
                {
                    if (Program.Player[resultNumber].name == "Leggings")
                    {
                        s = " ";
                    }
                    else if (Program.Player[resultNumber].name == "Boots")
                    {
                        s = " ";
                    }
                    else if (Program.Player[resultNumber].quantity > 1)
                    {
                        s = "s";
                    }
                    else
                    {
                        s = " ";
                    }
                }


                Console.WriteLine("You only have " + Program.Player[resultNumber].quantity + " " + Program.Player[resultNumber].name + s);
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine();
                Console.WriteLine("Accept? (Y / N)");
                Console.WriteLine();
                string accept = Console.ReadLine().ToUpper();
                if (accept == "Y" || accept == "Y ")
                {
                    temp = Quantity;
                    Program.Player[resultNumber].quantity -= temp;
                    Program.Store[resultNumber].quantity += temp;
                    Program.Wallet += Program.Player[resultNumber].cost * Quantity;

                    Console.Clear();
                    Console.WriteLine("Success!");
                    Console.WriteLine("You now have $" + Program.Wallet);
                    Console.ReadKey();

                }
                else if (accept == "N" || accept == "N ")
                {
                    Console.Clear();
                    Console.WriteLine("All g bro x");
                    Console.ReadKey();
                }
            }

            Menu_.Menu();
        }
    }
}
