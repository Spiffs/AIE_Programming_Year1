using System;

namespace Assignment_3
{
    class Prints
    {
        //Print Player inventory function
        public static void PrintPlayer()
        {
            string s;

            Console.WriteLine();

            for (int i = 0; i < 8; i++)
            {
                if (Program.Player[i].name == "Leggings")
                {
                    s = " ";
                }
                else if (Program.Player[i].name == "Boots")
                {
                    s = " ";
                }
                else if (Program.Player[i].quantity > 1)
                {
                    s = "s";
                }
                else
                {
                    s = " ";
                }

                Console.WriteLine(Program.Player[i].quantity + " " + Program.Player[i].name + s);
            }
        }

        //Print Store inventory function 
        public static void PrintStore()
        {
            string s;

            Console.WriteLine();

            for (int i = 0; i < 8; i++)
            {
                if (Program.Store[i].name == "Leggings")
                {
                    s = " ";
                }
                else if (Program.Store[i].name == "Boots")
                {
                    s = " ";
                }
                else if (Program.Store[i].quantity > 1)
                {
                    s = "s";
                }
                else
                {
                    s = " ";
                }

                Console.WriteLine(Program.Store[i].quantity + " " + Program.Store[i].name + s);
            }
        }


        //Prints the Newitem arrays (Used by the Delete function
        public static void PrintNewItems()
        {
            for (int i = 0; i < Program.newitemlength; i++)
            {
                Console.WriteLine((i + 1) + ". " + Program.PlayerExtraItems[i].name);
            }
        }


        //Prints the Players Newitem inventory array
        public static void PrintPlayerNew()
        {
            for (int i = 0; i < Program.newitemlength; i++)
            {
                Console.WriteLine((Program.PlayerExtraItems[i].quantity + " " + Program.PlayerExtraItems[i].name));
            }
        }


        //Prints the Stores Newitem inventory array 
        public static void PrintStoreNew()
        {
            for (int i = 0; i < Program.newitemlength; i++)
            {
                Console.WriteLine((Program.StoreExtraItems[i].quantity + " " + Program.StoreExtraItems[i].name));
            }
        }


        //Menu result which displays the Wallet Balance 
        public static void DisplayWallet()
        {
            Console.Clear();
            Console.WriteLine("You have $" + Program.Wallet + " to your name.");
            Console.ReadKey();

            Menu_.Menu();
        }
    }
}



