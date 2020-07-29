using System;

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
            //Print command
            Prints.PrintStore();
            Prints.PrintStoreNew();

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
            else //I know its not needed but putting empty else statements in places like this just helps keep me sane :)
            { }

            //Quantity input 
            Console.WriteLine("Quantity?");
            Console.WriteLine();

            int Quantity = Tests.IntInput();

            int ItemTotal = (Program.Store[resultNumber].cost * Quantity);

            Console.Clear();

            //Confirmation page (differs from default and extra items)
            if (!Program.newitem)
            {
                Console.WriteLine(Program.Store[resultNumber].name + " will cost you $" + ItemTotal);
            }
            else if (Program.newitem)
            {
                Console.WriteLine(Program.StoreExtraItems[resultNumber].name + " will cost you $" + (Program.StoreExtraItems[resultNumber].cost * Quantity));
            }
            Console.ReadKey();

            //Sending information to return tests for amount in wallet and stock
            bool a_WalletTest = Tests.WalletTest(ItemTotal, Program.Wallet);

            bool Stocktest = Tests.StoreStockTest(resultNumber, Quantity);

            if (!a_WalletTest)
            {
                Console.Clear();
                Console.WriteLine("Sorry, you only have $" + Program.Wallet);
                Console.ReadKey();
            }
            else if (!Stocktest)
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

                //Empty stock messages (differ for default and extra items
                if (!Program.newitem)
                {
                    Console.WriteLine("The store only has " + Program.Store[resultNumber].quantity + " " + 
                                                              Program.Store[resultNumber].name + s);
                }
                else if (Program.newitem)
                {
                    Console.WriteLine("The store only has " + Program.StoreExtraItems[resultNumber].quantity + " " + 
                                                              Program.StoreExtraItems[resultNumber].name);
                }
                Console.ReadKey();
            }

            //Successful tests transfers the quantities and wallet balance
            else
            {
                Console.WriteLine();
                Console.WriteLine("Accept? (Y / N)");
                Console.WriteLine();
                string accept = Console.ReadLine().ToUpper();

                //Default Items
                if (!Program.newitem)
                {
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
                //Extra Items
                else if (Program.newitem)
                {
                    if (accept == "Y" || accept == "Y ")
                    {
                        temp = Quantity;
                        Program.PlayerExtraItems[resultNumber].quantity += temp;
                        Program.StoreExtraItems[resultNumber].quantity -= temp;
                        Program.Wallet -= Program.StoreExtraItems[resultNumber].cost * Quantity;

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
