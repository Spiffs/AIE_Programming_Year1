using System;

namespace Loops
{
    class Program
    {
        static void Main()
        {
            int playerhealth = 100;
        // Initial player health
            int enemyhits = 5;
        // Amount of total enemy hits and repeats in the loop
            int initialhits = enemyhits;
            // Notes the total enemy hits 
            int enemydamage = 10;

            Console.WriteLine(playerhealth);
        
            while (enemyhits > 0)   // Repeats "enemyhits" times 
        {
                enemyhits--;        // Each time the loop is played it takes 1 away from "enemyhits' leaving it repeating by the set amount of times 
                playerhealth -= enemydamage;
                Console.WriteLine("Health: " + playerhealth);
        }

            Console.WriteLine("The enemy landed " + initialhits + " htis of " + enemydamage + " health each!");
            Console.WriteLine("Leaving your health at " + playerhealth);
            Console.ReadKey();

        }
    }
}
