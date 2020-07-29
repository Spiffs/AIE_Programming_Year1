using System;
using System.IO;
using System.Linq;

namespace Assignment_3
{
    class Program
    {
        //Initialising public ints used by different functions of the application 
        public static int playerorstore = 0;

        public static int Wallet;

        public static string walletpath = @"Wallet.txt";

        public static string playerpath = @"Player.txt";

        public static string storepath = @"Store.txt";

        public static string playernewitempath = @"Playerextraitem.txt";
        public static string storenewitempath = @"Storeextraitem.txt";

        public static int newitemlength = 1;
        public static int newitemlengthfix = 7;
        public static bool newitem = false;

        //Initiating the extra item storage arrays for both the player and store
        public static Newitem[] PlayerExtraItems;
        public static Newitem[] StoreExtraItems;



        //Initialising the Player inventory array
        public static GenericItem[] Player;

        //Initialising the Store stock array 
        public static GenericItem[] Store;

        //Secondary 
        public static int[] WA = new int[8];



        //The main function fetches all array values from the .txt files. This includes the Store and Player inventories and the Wallet balance
        public static void Main()
        {
            Console.WriteLine("Loading...");
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

            using (StreamReader reader = File.OpenText(playernewitempath))
            {
                newitemlength = int.Parse(reader.ReadLine());
                reader.Close();
            }

            PlayerExtraItems = new Newitem[newitemlength];
            StoreExtraItems = new Newitem[newitemlength];

            //Defining default array values and settings as objects 
            try
            {
                for (int i = 0; i < newitemlength + 1; i++)
                {
                    PlayerExtraItems[i] = new Newitem(0, "null", 0, 0);
                }
            }
            catch { }

            //Defining default array values and settings as objects 
            try
            {
                for (int i = 0; i < newitemlength + 1; i++)
                {
                    StoreExtraItems[i] = new Newitem(0, "null", 0, 0);
                }
            }
            catch { }


            //__________________________________________________________________________________________
            //Fetching all array values from textfile saves

            //Fetching wallet amount, if non existant then makes it a default #1000
            try
            {
                Wallet = Convert.ToInt32(File.ReadAllText(walletpath));
            }
            catch
            {
                Wallet = 1000;
            }

            //Fetching Player inventory quantiies
            for (int i = 0; i < 8; i++)
            {
                Player[i].quantity = Convert.ToInt32(File.ReadLines(playerpath).Skip(i).Take(1).First());
            }

            //Fetching Store inventory quantities
            for (int i = 0; i < 8; i++)
            {
                Store[i].quantity = Convert.ToInt32(File.ReadLines(storepath).Skip(i).Take(1).First());
            }

            //Fetching Player extra items information
            using (StreamReader reader = File.OpenText(playernewitempath))
            {
                newitemlength = int.Parse(reader.ReadLine());
                string line;
                for (int i = 0; i < newitemlength; i++)
                {
                    line = reader.ReadLine();
                    if (line == null)
                    {
                        break;
                    }
                    PlayerExtraItems[i].arrayvalue = int.Parse(reader.ReadLine());
                    PlayerExtraItems[i].name = reader.ReadLine();
                    PlayerExtraItems[i].quantity = int.Parse(reader.ReadLine());
                    PlayerExtraItems[i].cost = int.Parse(reader.ReadLine());
                }
                reader.Close();
            }


            //Fetching Store extra items information 
            using (StreamReader reader = File.OpenText(storenewitempath))
            {
                string line;

                for (int i = 0; i < newitemlength; i++)
                {
                    line = reader.ReadLine();
                    if (line == null)
                    {
                        break;
                    }
                    StoreExtraItems[i].arrayvalue = int.Parse(reader.ReadLine());
                    StoreExtraItems[i].name = reader.ReadLine();
                    StoreExtraItems[i].quantity = int.Parse(reader.ReadLine());
                    StoreExtraItems[i].cost = int.Parse(reader.ReadLine());
                }
                reader.Close();
            }

            Menu_.Menu();
            Console.ReadKey();
            Console.Clear();
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

            Console.Clear();
            Console.WriteLine("Saving...");

            //
            StreamWriter playerwriter = new StreamWriter(playerpath); ;
            for (int i = 0; i < 8; i++)
            {
                playerwriter.WriteLine(Player[i].quantity.ToString());
            }

            //
            StreamWriter storewriter = new StreamWriter(storepath); ;
            for (int i = 0; i < 8; i++)
            {
                storewriter.WriteLine(Store[i].quantity.ToString());
            }

            playerwriter.Close();
            storewriter.Close();

            //
            StreamWriter walletwriter = new StreamWriter(walletpath); ;
            walletwriter.WriteLine(Wallet);

            walletwriter.Close();

            int arrayvalue = 1;

            //
            StreamWriter playernewitemwriter = new StreamWriter(playernewitempath);
            playernewitemwriter.WriteLine(newitemlength);
            for (int i = 0; i < newitemlength; i++)
            {
                playernewitemwriter.WriteLine("1");
                playernewitemwriter.WriteLine(arrayvalue);
                playernewitemwriter.WriteLine(PlayerExtraItems[i].name);
                playernewitemwriter.WriteLine(PlayerExtraItems[i].quantity);
                playernewitemwriter.WriteLine(PlayerExtraItems[i].cost);
                arrayvalue++;
            }
            playernewitemwriter.Close();

            arrayvalue = 1;

            //
            StreamWriter storenewitemwriter = new StreamWriter(storenewitempath);
            for (int i = 0; i < newitemlength; i++)
            {
                storenewitemwriter.WriteLine("1");
                storenewitemwriter.WriteLine(arrayvalue);
                storenewitemwriter.WriteLine(StoreExtraItems[i].name);
                storenewitemwriter.WriteLine(StoreExtraItems[i].quantity);
                storenewitemwriter.WriteLine(StoreExtraItems[i].cost);
                arrayvalue++;
            }
            storenewitemwriter.Close();


            //__________________________________________________________________________________________________________
        }

        //Quit function
        public static void Quit()
        {
            //Includes user confirmation
            Console.Clear();
            Console.WriteLine("Quit? (Y / N)");

            string quit = Console.ReadLine().ToUpper();

            if (quit == "Y" || quit == "Y ")
            {
                System.Environment.Exit(0);
            }
            else if (quit == "N" || quit == "N ")
            {
                Menu_.Menu();
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Invalid input");
                Console.ReadKey();
                Menu_.Menu();
            }
        }

        
    }
    //__________________________________________________________________________________________________________________________________________end of main class
}
