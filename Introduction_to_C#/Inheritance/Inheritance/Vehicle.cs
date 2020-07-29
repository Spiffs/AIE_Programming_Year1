using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{


    public class Vehicle
    {
        public string name;
        public int wheels;
        public int doors;
        public int seats;
        public int maxspeed;
        public int lights;
        public string description;



        public Vehicle() //Default
        { }


        public Vehicle(string a_name, string a_description,
        int a_wheels, int a_doors, int a_seats, int a_maxspeed, int a_lights)
        {
            a_name = name;
            a_wheels = wheels;
            a_doors = doors;
            a_seats = seats;
            a_maxspeed = maxspeed;
            a_lights = lights;
            a_description = description;

        }
        //    Car Car1 = new Car();
        //    Motorbike Motorbike1 = new Motorbike();
        //    Train Train1 = new Train();
        //    Plane Plane1 = new Plane();
        //    Boat Boat1 = new Boat();

        //    Print();

        //}

        //public void Print()
        //{
        //    Console.WriteLine(Car1.name);

        public void PrintCar() //Prints the operations for Car 
        {
            Car Car1 = new Car(); //Creates a copy of the class Car nameed Car1, which adopts the default valued defined in Car.cs

            //Recieving info from Car must now be done by Car1!!
            Console.WriteLine("Name:                " + Car1.name); //Car1.name : Car1 refering to the class copy, connected to .name which refers to the function in the class
            Console.WriteLine("Number of Wheels:    " + Car1.wheels);
            Console.WriteLine("Number of Doors:     " + Car1.doors);
            Console.WriteLine("Number of Seats:     " + Car1.wheels);
            Console.WriteLine("Max Speed:           " + Car1.maxspeed);
            Console.WriteLine("Number of Lights:    " + Car1.lights);
            Console.WriteLine("Description:         " + Car1.description);


        }

    }

    public class SpecialVehicle
    {


        public string name, description, material;
        public int wheels, doors, seats, maxspeed, lights;

        public SpecialVehicle()
        { }

        public SpecialVehicle(string a_name, string a_description, string a_material,
        int a_wheels, int a_doors, int a_seats, int a_maxspeed, int a_lights)
        {
            a_name = name;
            a_wheels = wheels;
            a_doors = doors;
            a_seats = seats;
            a_maxspeed = maxspeed;
            a_lights = lights;
            a_description = description;
            a_material = material;
        }

        public void PrintTrain()
        {
            Train Train1 = new Train(); //Creates a copy of the class Train nameed Train1, which adopts the default valued defined in Train.cs

            //Recieving info from Car must now be done by Car1!!
            Console.WriteLine("Name:                " + Train1.name); //Train1.name : Train1 refering to the class copy, connected to .name which refers to the function in the class
            Console.WriteLine("Number of Wheels:    " + Train1.wheels);
            Console.WriteLine("Number of Doors:     " + Train1.doors);
            Console.WriteLine("Number of Seats:     " + Train1.wheels);
            Console.WriteLine("Max Speed:           " + Train1.maxspeed);
            Console.WriteLine("Number of Lights:    " + Train1.lights);
            Console.WriteLine("Description:         " + Train1.description);
            Console.WriteLine("Material:            " + Train1.material);  
        }

        public void PrintPlane()
        {
            Plane Plane1 = new Plane(); //Creates a copy of the class Train nameed Train1, which adopts the default valued defined in Train.cs

            //Recieving info from Car must now be done by Car1!!
            Console.WriteLine("Name:                " + Plane1.name); //Train1.name : Train1 refering to the class copy, connected to .name which refers to the function in the class
            Console.WriteLine("Number of Wheels:    " + Plane1.wheels);
            Console.WriteLine("Number of Doors:     " + Plane1.doors);
            Console.WriteLine("Number of Seats:     " + Plane1.wheels);
            Console.WriteLine("Max Speed:           " + Plane1.maxspeed);
            Console.WriteLine("Number of Lights:    " + Plane1.lights);
            Console.WriteLine("Description:         " + Plane1.description);
            Console.WriteLine("Material:            " + Plane1.material);
        }
    }
    
}
