using System;

namespace Functions
{
    class Program
    {
        static int playerHealth = 100;
        static int monsterDamage = 30;
        static void MonsterEnchounter()
        {
            Console.WriteLine("A vicious monster appears!");
            Console.ReadKey();
        }
        static void Start()
        {
            Console.WriteLine("My game has begun!");
            Console.ReadKey();
            MonsterEnchounter();
            MonsterAttacks(monsterDamage * 2);
            MonsterAttacks(monsterDamage);
            MonsterAttacks(monsterDamage * 3);

            monsterDamage = 5;
        }

        static void MonsterAttacks(int damage)
        {
            int combo = 0;
            combo += 1;
            playerHealth -= damage;
            Console.WriteLine("The Monster attacks you for " + damage + " points of damage. You have " + playerHealth + " health left");
            Console.ReadKey();
        }
        static void Main()
        {
            Start();
        }
    }
}
