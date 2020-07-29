using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment_3
{
    class Buy_
    {
        //Buy function which includes item and quantity searches. Also includes trade code
        public static void Buy()
        {
            Console.Clear();

            int temp;

            Console.WriteLine("Which item would you like to buy?");
            Console.WriteLine();
            //Print command
            Prints.PrintStore();

            string buyorsell = Console.ReadLine().ToUpper();

            int resultNumber = Tests.SearchInt(Program.Store, buyorsell);

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

            int ItemTotal = (Program.Store[resultNumber].cost * Quantity);

            Console.Clear();
            Console.WriteLine(Program.Store[resultNumber].name + " will cost you $" + ItemTotal);
            Console.ReadKey();

            bool a_WalletTest = Tests.WalletTest(ItemTotal, Program.Wallet);

            bool test = Tests.StockTest(Program.Store[resultNumber].quantity, Quantity);

            if (!a_WalletTest)
            {
                Console.Clear();
                Console.WriteLine("Sorry, you only have $" + Program.Wallet);
                Console.ReadKey();
            }
            else if (!test)
            {
                Console.Clear();
                Console.WriteLine("Stock is not available for that item, sorry.");

                string s = "";

                if (resultNumber >= 0)
                {
                    if (Program.Store[resultNumber].name == "Leggings")
                    {
                        s = " ";
                    }
                    else if (Program.Store[resultNumber].name == "Boots")
                    {
                        s = " ";
                    }
                    else if (Program.Store[resultNumber].quantity > 1)
                    {
                        s = "s";
                    }
                    else
                    {
                        s = " ";
                    }
                }

                Console.WriteLine("The store only has " + Program.Store[resultNumber].quantity + " " + Program.Store[resultNumber].name + s);
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
                    Program.Player[resultNumber].quantity += temp;
                    Program.Store[resultNumber].quantity -= temp;
                    Program.Wallet -= Program.Store[resultNumber].cost * Quantity;

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

                    Menu_.Menu(); 
                }
            }

            Menu_.Menu();
        }
    }
}
