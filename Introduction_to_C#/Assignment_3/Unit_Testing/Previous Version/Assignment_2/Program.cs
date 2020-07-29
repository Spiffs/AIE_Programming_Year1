using System;

namespace Assignment_2
{
    class Program
    {
        public string temp;
        static void Main()
        { 
            //FIX: jay changed the string to static in order to properly call it in the main function 
            //Assignment_1 for original

            string[] Playerinventory = new string[8]
            {
                //Weapons
                "Sword"         ,
                "Bow"           ,
                "Arrow"         ,
                "Axe"           ,
                
                //Armour
                "Helmet"        ,
                "Chestplate"    ,
                "Leggings"      ,
                "Boots"

            }; //array featuring different items 

            Console.WriteLine("Search: "); //random search text i entered
            string searchQuery = Console.ReadLine().ToUpper(); //fetch user input

            int resultNumber = Search(Playerinventory, searchQuery);
            
            if (resultNumber >=0)
            {
                Console.WriteLine(Playerinventory[resultNumber]);
            }
            else
            {
                Console.WriteLine("Error");
            }
            
            //searchQuery = user input, is sent as the second value for the search function 
            //inputs and returns array values in relation to user input and player inventory

            
            Console.ReadKey();

            Array.Sort(Playerinventory, StringComparer.InvariantCulture);

            for (int i = 0; i <= Playerinventory.Length; i++)
            {
                Console.WriteLine(Playerinventory[i]);
            }

        }

        public static int Search(string[] array, string searchItem) //generic search function jay helped me perfect
        {
            for (int i = array.Length - 1; i >= 0; i--)  //searched through the array values
            {
                if (array[i].ToUpper() == searchItem.ToUpper())
                {
                    return i;
                }
            }
            return -1;
        }



    }
}


    
    
    

