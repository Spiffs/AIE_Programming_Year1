using System;

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
            //Print command
            Prints.PrintPlayer();
            Prints.PrintPlayerNew();

            //input command
            string buyorsell = Console.ReadLine().ToUpper();

            int resultNumber = Tests.SearchInt(buyorsell);

            Console.Clear();

            //Non-existant item test
            if (resultNumber < 0)
            {
                Console.WriteLine("That item does not exist");
                Console.ReadKey();
                Menu_.Menu();
            }
            else //Still maintaining sanity thanks to this boi :)
            { }

            //Quantity input 
            Console.WriteLine("Quantity?");
            Console.WriteLine();

            int Quantity = Tests.IntInput();

            int ItemTotal = (Program.Player[resultNumber].cost * Quantity);

            Console.Clear();

            //Confirmation page (differs from default and extra items)
            if (!Program.newitem)
            {
                Console.WriteLine(Program.Player[resultNumber].name + " selling for $" + ItemTotal);
            }
            else if (Program.newitem)
            {
                Console.WriteLine(Program.PlayerExtraItems[resultNumber].name + " selling for $" + (Program.PlayerExtraItems[resultNumber].cost * Quantity));
            }
            Console.ReadKey();

            //Testing player stock based on requested quantity
            bool a_StockTest = Tests.PlayerStockTest(resultNumber, Quantity);

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

                //Empty stock messages (differ for default and extra items)
                if (!Program.newitem)
                {
                    Console.WriteLine("You only have " + Program.Player[resultNumber].quantity + " " + 
                                                         Program.Player[resultNumber].name + s);
                }
                else if (Program.newitem)
                {
                    Console.WriteLine("You only have " + Program.PlayerExtraItems[resultNumber].quantity + " " + 
                                                         Program.PlayerExtraItems[resultNumber].name);
                }
                Console.ReadKey();
            }
            //Confirmation from player
            else
            {
                Console.WriteLine();
                Console.WriteLine("Accept? (Y / N)");
                Console.WriteLine();
                string accept = Console.ReadLine().ToUpper();

                //Rewrites information to complete the trade
                if (!Program.newitem)
                {
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
                //Default and Newitems had to be seperated to avoid array clashes
                else if (Program.newitem)
                {
                    if (accept == "Y" || accept == "Y ")
                    {
                        temp = Quantity;
                        Program.PlayerExtraItems[resultNumber].quantity -= temp;
                        Program.StoreExtraItems[resultNumber].quantity += temp;
                        Program.Wallet += Program.PlayerExtraItems[resultNumber].cost * Quantity;

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
            }
            Menu_.Menu();
        }
    }
}
