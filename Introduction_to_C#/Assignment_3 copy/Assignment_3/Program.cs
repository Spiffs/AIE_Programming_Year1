using System;
using System.IO;
using System.Linq;

namespace Assignment_3
{
    class Program
    {
        public static int playerorstore = 0;

        public static int Wallet;

        public static string walletpath = @"D:\Programming_Year1\Introduction_to_C#\Assignment_3\Assignment_3\Wallet.txt";

        public static string playerpath = @"D:\Programming_Year1\Introduction_to_C#\Assignment_3\Assignment_3\Player.txt";

        public static string storepath = @"D:\Programming_Year1\Introduction_to_C#\Assignment_3\Assignment_3\Store.txt";

        public static Newitem[] Items;
        //Initialising the Player inventory array
        public static GenericItem[] Player;

        //Initialising the Store stock array 
        public static GenericItem[] Store;

        //Secondary 
        public static int[] WA = new int[8];


        //The main function fetches all array values from the .txt files. This includes the Store and Player inventories and the Wallet balance
        public static void Main()
        {
            //_________________________________________________________
            //FIX: converting array to hold class values 
            //Assignemnt_2 for original
            //_________________________________________________________

            //Defining Player inventory array values
            Player = new GenericItem[8];

            //MM yes, arrays inside arrays, yum (Solution for inaccessible values)
            Player[0] = new Weapon("Sword", 1, 40, WA[0] = 50);
            Player[1] = new Weapon("Bow", 10, 80, WA[1] = 10);
            Player[2] = new Weapon("Arrow", 10, 120, WA[2] = 40);
            Player[3] = new Weapon("Axe", 10, 180, WA[3] = 70);

            Player[4] = new Armor("Helmet", 1, 40, WA[4] = 10);
            Player[5] = new Armor("Chestplate", 10, WA[5] = 80, 40);
            Player[6] = new Armor("Leggings", 1, 120, WA[6] = 20);
            Player[7] = new Armor("Boots", 10, 180, WA[7] = 10);


            //Defining Store stock array values
            Store = new GenericItem[8];

            Store[0] = new Weapon("Sword", 10, 50, 50);
            Store[1] = new Weapon("Bow", 10, 100, 10);
            Store[2] = new Weapon("Arrow", 10, 150, 40);
            Store[3] = new Weapon("Axe", 10, 200, 70);

            Store[4] = new Armor("Helmet", 10, 50, 10);
            Store[5] = new Armor("Chestplate", 10, 100, 40);
            Store[6] = new Armor("Leggings", 10, 150, 20);
            Store[7] = new Armor("Boots", 10, 200, 10);

            //__________________________________________________________________________________________
            //Fetching all array values from textfile saves

            Items = new Newitem[50];

            try
            {
                Wallet = Convert.ToInt32(File.ReadAllText(walletpath));
            }
            catch
            {
                Wallet = 1000;
            }

            for (int i = 0; i < 8; i++)
            {
                Player[i].quantity = Convert.ToInt32(File.ReadLines(playerpath).Skip(i).Take(1).First());
            }

            for (int i = 0; i < 8; i++)
            {
                Store[i].quantity = Convert.ToInt32(File.ReadLines(storepath).Skip(i).Take(1).First());
            }

            //__________________________________________________________________________________________


            //Console.WriteLine(Program.Store[0].name + Program.Store[0].Quantity + Program.Store[2].cost);

            Menu_.Menu();
            Console.ReadKey();
            Console.Clear();

            ////Sort command: BROKEN in **
            //Array.Sort(*Store*, StringComparer.InvariantCulture);

            ////Print command (sorted)
            //for (int i = 0; i < Store.Length; i++)
            //{
            //    Console.WriteLine(Program.Store[i]);
            //}

            //Console.ReadKey();

            //________________________________________________________________________________________________



        }


        //lil load function purely for looks 
        static void Loadyboi()
        {
            for (int i = 0; i < 1; i++)
            {
                int a = 25;
                Console.Clear();
                Console.WriteLine("Loading -- \\");
                System.Threading.Thread.Sleep(a);
                Console.Clear();
                Console.WriteLine("Loading -- |");
                System.Threading.Thread.Sleep(a);
                Console.Clear();
                Console.WriteLine("Loading -- /");
                System.Threading.Thread.Sleep(a);
                Console.Clear();
                Console.WriteLine("Loading -- -");
                System.Threading.Thread.Sleep(a);
            }
        }


        //Saves quantities and Wallet Balance to corrosponding .txt files
        public static void Save()
        {
            //_________________________________________________________________________________________________________
            //Write to file code:

            StreamWriter playerwriter;
            playerwriter = new StreamWriter(playerpath);

            for (int i = 0; i < 8; i++)
            {
                playerwriter.WriteLine(Player[i].quantity.ToString());
            }

            StreamWriter storewriter;
            storewriter = new StreamWriter(storepath);

            for (int i = 0; i < 8; i++)
            {
                storewriter.WriteLine(Store[i].quantity.ToString());
            }

            playerwriter.Close();
            storewriter.Close();

            StreamWriter walletwriter;
            walletwriter = new StreamWriter(walletpath);

            walletwriter.WriteLine(Wallet);

            walletwriter.Close();

            Menu_.Menu();

            //__________________________________________________________________________________________________________
        }

        //__________________________________________________________________________________________________________________________________________end of main class



        


    }
}
