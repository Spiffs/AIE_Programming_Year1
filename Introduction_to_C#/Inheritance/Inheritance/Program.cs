using System;

namespace Inheritance
{
    public class Program
    { 
        static void Main(string[] args)
        {
            //____________________________________________________

            Console.WriteLine();

            Car Car1 = new Car();

            Car1.PrintCar();
            Console.ReadKey();

            //___________________________________________________
            
            Console.WriteLine();
            Console.WriteLine();

            Train Train1 = new Train();

            Train1.PrintTrain();

            Console.ReadKey();

            //________________________________________________________

            Console.WriteLine();
            Console.WriteLine();

            Plane Plane1 = new Plane();

            Plane1.PrintPlane();

            Console.ReadKey();

        }
    
    }


    
}
