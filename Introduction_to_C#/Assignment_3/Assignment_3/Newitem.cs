using System;
using System.IO;
using System.Linq;

namespace Assignment_3
{
    //New item class used to create the Newitem arrays
    public class Newitem
    {
        public int arrayvalue;
        public string name;
        public int quantity;
        public int cost;


        public Newitem()
        { }

        public Newitem(int a_arrayvalue, string a_name, int a_quantity, int a_cost)
        {
            arrayvalue = a_arrayvalue;
            name = a_name;
            quantity = a_quantity;
            cost = a_cost;
        }

    }

    //for read and write to and from text files for use in arrays https://stackoverflow.com/questions/20153546/im-trying-to-fill-my-listclass-from-a-text-file-using-c\

    //Super user command which allows a user to add items
    class Superuser_
    {
        public static void Superuser()
        {
            //Beggins by asking for the items information which is stored in strings 
            Console.Clear();

            Console.WriteLine("Create a new item");
            Console.WriteLine();
            Console.WriteLine("Item name:");
            string nameinput = Console.ReadLine();

            Console.Clear();

            Console.WriteLine("Player Quantity: ");
            int playerquantity = Tests.IntInput();

            Console.Clear();

            Console.WriteLine("Store quantity: ");
            int storequantity = Tests.IntInput();

            Console.Clear();

            Console.WriteLine("Item buy value: ");
            int storecostinput = Tests.IntInput();

            Console.Clear();

            Console.WriteLine("Item sell value: ");
            int playercostinput = Tests.IntInput();

            //Increasing the size of the array to store the new item
            ++Program.newitemlength;

            //The Players Newitem array is resized and given new information
            Program.PlayerExtraItems = new Newitem[Program.newitemlength];

            try
            {
                for (int i = 0; i < Program.newitemlength; i++)
                {
                    Program.PlayerExtraItems[i] = new Newitem(0, "null", 0, 0);
                }
            }
            catch { }

            using (StreamReader reader = File.OpenText(Program.playernewitempath))
            {
                reader.ReadLine();
                string line;
                for (int i = 0; i < (Program.newitemlength - 1); i++)
                {
                    line = reader.ReadLine();
                    if (line == null)
                    {
                        break;
                    }
                    Program.PlayerExtraItems[i].arrayvalue = int.Parse(reader.ReadLine());
                    Program.PlayerExtraItems[i].name = reader.ReadLine();
                    Program.PlayerExtraItems[i].quantity = int.Parse(reader.ReadLine());
                    Program.PlayerExtraItems[i].cost = int.Parse(reader.ReadLine());
                }
                reader.Close();
            }

            Program.PlayerExtraItems[Program.newitemlength - 1].arrayvalue = (Program.newitemlength);
            Program.PlayerExtraItems[Program.newitemlength - 1].name = nameinput;
            Program.PlayerExtraItems[Program.newitemlength - 1].quantity = playerquantity;
            Program.PlayerExtraItems[Program.newitemlength - 1].cost = playercostinput;


            //The Store Newitem array is resized and given new information
            Program.StoreExtraItems = new Newitem[Program.newitemlength];

            try
            {
                for (int i = 0; i < Program.newitemlength; i++)
                {
                    Program.StoreExtraItems[i] = new Newitem(0, "null", 0, 0);
                }
            }
            catch { }

            using (StreamReader reader = File.OpenText(Program.storenewitempath))
            {
                string line;

                for (int i = 0; i < (Program.newitemlength - 1); i++)
                {
                    line = reader.ReadLine();
                    if (line == null)
                    {
                        break;
                    }
                    Program.StoreExtraItems[i].arrayvalue = int.Parse(reader.ReadLine());
                    Program.StoreExtraItems[i].name = reader.ReadLine();
                    Program.StoreExtraItems[i].quantity = int.Parse(reader.ReadLine());
                    Program.StoreExtraItems[i].cost = int.Parse(reader.ReadLine());
                }
                reader.Close();
            }

            Program.StoreExtraItems[Program.newitemlength - 1].arrayvalue = (Program.newitemlength);
            Program.StoreExtraItems[Program.newitemlength - 1].name = nameinput;
            Program.StoreExtraItems[Program.newitemlength - 1].quantity = storequantity;
            Program.StoreExtraItems[Program.newitemlength - 1].cost = storecostinput;

            //The save function is used to reset certain values and avoid errors in the application
            Program.Save();
            Console.Clear();
            Console.WriteLine("Success!");
            Console.ReadKey();
            Menu_.Menu();
        }
    }

    
    class DeleteItem
    {
        //Item deletion function (Note: only deletes items created by the super user)
        public static void Delete()
        {
            Console.Clear();
            
            //First tests for items to delete 
            if (Program.newitemlength < 1)
            {
                Console.WriteLine("There are no added items");
                Console.ReadLine();
                Menu_.Menu();
            }

            Console.WriteLine("Delete Item: ");
            Console.WriteLine();

            Prints.PrintNewItems();

            int input = Tests.SearchNewItems(Tests.IntInput());

            //Tests for invalid inputs
            if (input < 0)
            {
                Console.Clear();
                Console.WriteLine("Invalid input ");
                Console.ReadKey();
                Delete();
            }

            Console.Clear();
            Console.WriteLine("Accept? (Y / N)");
            Console.WriteLine();
            string accept = Console.ReadLine().ToUpper();

            //Waits for confirmation then deletes the item and resizes the array 
            if (accept == "Y" || accept == "Y ")
            {
                Console.Clear();

                Program.PlayerExtraItems = Program.PlayerExtraItems.Where(w => w != Program.PlayerExtraItems[input]).ToArray();
                Program.StoreExtraItems = Program.StoreExtraItems.Where(w => w != Program.StoreExtraItems[input]).ToArray();

                Program.newitemlength--;

                //Again the arrays are resaved to texdt documents to avoid errors
                Program.Save();
                Console.Clear();
                Console.WriteLine("Success!");
                Console.ReadKey();

            }
            else if (accept == "N" || accept == "N ")
            {
                Console.Clear();
                Console.WriteLine("All g bro x");
                Console.ReadKey();
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Invalid input ");
                Console.ReadKey();
                Delete();
            }


            Program.Main();
        }
    }
}
