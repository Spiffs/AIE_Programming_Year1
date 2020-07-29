using System;

namespace Operators
{
    class Program
    {
        static void Main()
        {
            bool critical = true;
            bool playerstate = true;
            int playerhealth = 100;

            Console.WriteLine("Health: " + playerhealth);

            if (playerhealth >= 70)     //Test for critical state based of players health
            { 
                critical = true;
            }   
            else
            { 
                critical = false;
            }

            if (critical == true)        //Test for playerhealth depletion based off critical
            {
                playerhealth -= 50; //Successful critical
            }
            else
            {
                playerhealth -= 30; //Unsuccessful critical
            }

            Console.WriteLine("Health: " + playerhealth);

            if (playerhealth >= 70)     //Test for critical based on player health again
            {
                critical = true;
            }
            else if(playerhealth <= 69)
            {
                critical = false;
            }                               //Outcome should turn be false

            
            if (critical == true)        //Test for playerhealth depletion based off critical again 
            {
                playerhealth -= 50;
            }
            else
            {
                playerhealth -= 30;
            }
            
            Console.WriteLine("Health: " + playerhealth);

            if (playerhealth <= 0)
            {
                Console.WriteLine("Game Over!");
                playerstate = false;
            }

            Console.WriteLine("Player State = " + playerstate);     //Should be True because player is still alive
            Console.ReadKey();

        }
    }
}
