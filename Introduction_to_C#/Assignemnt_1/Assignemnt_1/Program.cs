using System;

namespace Assignemnt_1
{
    class Program
    {
        static void Main(string[] args)
        {   //Curvy brackets arent accepting the public string
            //Assignment_2 for fix 
            public string[] Playerinventory = new string[8]
            {
                "Sword"         ,
                "Bow"           ,
                "Arrow"         ,
                "Axe"           ,
                "Helmet"        ,
                "Chestplate"    ,
                "Leggings"      ,
                "Boots"
            };
    
        

        static void Search()    //working search function but could be "leaner"
        {
            bool success = false;
            bool positive = false;

            while (success = false)
            {
                Console.WriteLine("Search: ");
                string search = Console.ReadLine().ToUpper();

                for (int i = Playerinventory - 1; i >= 0; i--)
                {
                    if Playerinventory[i].ToUpper() == search
                    {

                    }
                }
            }
        }
    }
}



