using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment_3
{
    class Menu_
    {
        //Menu function writes each option of the menu then waits for user input
        public static void Menu()
        {
            MenuClass[] MenuItems = new MenuClass[7];

            MenuItems[0] = new MenuClass(1, "View inventory");
            MenuItems[1] = new MenuClass(2, "Store");
            MenuItems[2] = new MenuClass(3, "Buy");
            MenuItems[3] = new MenuClass(4, "Sell");
            MenuItems[4] = new MenuClass(5, "Search");
            MenuItems[5] = new MenuClass(6, "Bank");
            MenuItems[6] = new MenuClass(7, "Save");

            Console.Clear();

            Console.WriteLine("Menu:");
            Console.WriteLine();

            for (int i = 0; i < 7; i++)
            {
                Console.WriteLine(MenuItems[i].selection + ". " + MenuItems[i].selectionname);
            }

            Console.WriteLine();

            int MenuResult = Tests.IntInput();


            //Userimnput options 
            if (MenuResult == 1)
            {
                Console.Clear();
                Console.WriteLine("You have: ");
                Prints.PrintPlayer();
                Console.ReadKey();
                Menu();
            }
            else if (MenuResult == 2)
            {
                Console.Clear();
                Console.WriteLine("In the store we have: ");
                Prints.PrintStore();
                Console.ReadKey();
                Menu();
            }
            else if (MenuResult == 3)
            {
                Buy_.Buy();
            }
            else if (MenuResult == 4)
            {
                Sell_.Sell();
            }
            else if (MenuResult == 5)
            {
                Tests.SearchMenu();
            }
            else if (MenuResult == 6)
            {
                Prints.DisplayWallet();
            }
            else if (MenuResult == 7)
            {
                Program.Save();
            }
            else if (MenuResult == 69) //Secret code to increase wallet balance by 1000
            {
                Program.Wallet += 1000;
                Menu();
            }
            else if (MenuResult == 88224646)
            {
                Superuser_.Superuser();
            }
        }
    }

    //MenuClass class to easily create a user friendly array input system (potentially useless but eh)
    public class MenuClass
    {
        public int selection;
        public string selectionname;

        public MenuClass()
        { }

        public MenuClass(int a_selection, string a_selectionname)
        {
            selection = a_selection;
            selectionname = a_selectionname;
        }
    }
}
