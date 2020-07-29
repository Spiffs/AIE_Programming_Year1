using System;

namespace Assignment_3
{
    class Tests
    {
        //Searches and returns the items name, Quantity and cost to the player
        //Searches either the players inventory or the stores stock
        public static void Search(GenericItem[] sub)
        {
            string youornah = " ";

            if (Program.playerorstore == 1)
            {
                youornah = "You have ";
            }
            else if (Program.playerorstore == 2)
            {
                youornah = "The store has ";
            }

            Console.Clear();
            Console.WriteLine("Search item or press Enter to exit "); //random search text i entered
            Console.WriteLine(0);
            
            for (int i = 0; i < 8; i++)
            {
                Console.WriteLine(Program.Player[i].name);
            }

            for (int i = 0; i < Program.newitemlength; i++)
            {
                Console.WriteLine(Program.PlayerExtraItems[i].name);
            }

            string searchQuery = Console.ReadLine().ToUpper(); //fetch user input

            //Adding an s onto the item name for gramatical correctness
            string s;

            int ResultNumber = SearchInt(searchQuery);

            if (ResultNumber >= 0)
            {
                if (sub[ResultNumber].name == "Leggings")
                {
                    s = " ";
                }
                else if (sub[ResultNumber].name == "Boots")
                {
                    s = " ";
                }
                else if (sub[ResultNumber].quantity > 1)
                {
                    s = "s ";
                }
                else
                {
                    s = " ";
                }

                //string DP is used to print different lines for the Weapon and Armour classes 
                //(DP stands for Damage or Protection which is the respective additional inteval for each custom class 
                string DP = "";

                if (!Program.newitem)
                {
                    if (ResultNumber < 4)
                    {
                        DP = " and deals " + Program.WA[ResultNumber] + " damage.";
                    }
                    else
                    {
                        DP = " and has a " + Program.WA[ResultNumber] + " protection score.";
                    }
                }

                Console.Clear();

                if (sub == Program.Player)
                {
                    if (!Program.newitem)
                    {
                        Console.WriteLine(youornah + sub[ResultNumber].quantity + " " + sub[ResultNumber].name +
                                          s + "which cost $" + sub[ResultNumber].cost + " each" + DP);
                    }
                    else if(Program.newitem)
                    {
                        Console.WriteLine(youornah + Program.PlayerExtraItems[ResultNumber].quantity + " " +
                                          Program.PlayerExtraItems[ResultNumber].name + " which cost $" + 
                                          Program.PlayerExtraItems[ResultNumber].cost + " each.");
                    }
                }
                else if (sub == Program.Store)
                {
                    if (!Program.newitem)
                    {
                        Console.WriteLine(youornah + sub[ResultNumber].quantity + " " + sub[ResultNumber].name +
                                          s + "which cost $" + sub[ResultNumber].cost + " each" + DP);
                    }
                    else if (Program.newitem)
                    {
                        Console.WriteLine(youornah + Program.StoreExtraItems[ResultNumber].quantity + " " +
                                          Program.StoreExtraItems[ResultNumber].name + " which cost $" +
                                          Program.StoreExtraItems[ResultNumber].cost + " each.");
                    }
                }
                Console.ReadKey();
            }
            else //Keep-me-sane line 
            { }
        }


        //Search int tests for values in the array and returns if the input matches a result, if not it will fail and return to the menu 
        public static int SearchInt(string SearchItem) //Generic search function jay helped me perfect //*Changes have been made*
        {

            if (SearchItem == "SWORDS" || SearchItem == "BOWS" || SearchItem == "ARROWS" || SearchItem == "AXES" || SearchItem == "HELMETS" || SearchItem == "CHESTPLATES")
            {
                SearchItem = SearchItem.Remove(SearchItem.Length - 1, 1);
            }
            for (int i = 0; i < Program.Store.Length; i++)  //searched through the array values
            {
                if (Program.Store[i].name.ToString().ToUpper() == SearchItem)
                {
                    Program.newitem = false;
                    return i;
                }
            }
            for (int i = 0; i < Program.newitemlength; i++)
            {
                if (Program.StoreExtraItems[i].name.ToString().ToUpper() == SearchItem)
                {
                    Program.newitem = true;
                    return i;
                }
            }
            return -1;
        }

        //Searches the Newitem arrays to match an int with
        public static int SearchNewItems(int input)
        {
            for (int i = 0; i < Program.newitemlength; i++)
            {
                if ((Program.PlayerExtraItems[i].arrayvalue) == input)
                {
                    return i;
                }

            }
            return -1;
        }

        //Menu result which searches the Store or Player inventory for items and send results to the search function
        public static void SearchMenu()
        {
            Console.Clear();
            Console.WriteLine("Search: ");
            Console.WriteLine();
            Console.WriteLine("1. Inventory ");
            Console.WriteLine("2. Store ");
            Program.playerorstore = IntInput();

            if (Program.playerorstore == 1)
            {
                Search(Program.Player);
            }
            else if (Program.playerorstore == 2)
            {
                Search(Program.Store);
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Invalid input");
                Console.ReadKey();
                Menu_.Menu();
            }
            Menu_.Menu();
        }


        //Breakpoint test for converting string inputs to ints
        public static int IntInput()
        {
            bool clear = false;
            int a = 0;

            //NOTE: to use while loops instead of for loops when making breaking infinate loops :)
            while (!clear)
            {
                try
                {
                    a = Convert.ToInt32(Console.ReadLine());
                    clear = true;
                    return a;
                }
                catch
                {
                    Console.Clear();
                    Console.WriteLine("Invalid input");
                    Console.ReadKey();
                    Menu_.Menu();
                }
            }
            return a;
        }


        //Testing to see if the player has enough stock for the requested sell Quantity
        public static bool PlayerStockTest(int i, int RequestQuantity)
        {
            if (!Program.newitem)
            {
                if (Program.Player[i].quantity < RequestQuantity)
                {
                    return false;
                }
            }
            if (Program.newitem)
            {
                if (Program.PlayerExtraItems[i].quantity < RequestQuantity)
                {
                    return false;
                }
            }
            return true;
        }


        //Testing to see if the store has enough stock for the requested buy Quantity
        public static bool StoreStockTest(int i, int RequestQuantity)
        {
            if (!Program.newitem)
            {
                if (Program.Store[i].quantity < RequestQuantity)
                {
                    return false;
                }
            }
            if (Program.newitem)
            {
                if (Program.StoreExtraItems[i].quantity < RequestQuantity)
                {
                    return false;
                }
            }
            return true;
        }

        //Tests for enough player balance before a purchase
        public static bool WalletTest(int TotalItemCost, int Wallet)
        {
            if (TotalItemCost > Wallet)
            {
                return false;
            }
            else return true;
        }
    }
}
