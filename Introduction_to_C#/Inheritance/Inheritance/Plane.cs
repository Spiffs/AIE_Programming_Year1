using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{
    public class Plane : SpecialVehicle
    {
        public Plane()
        {
            name = "Qantas";
            wheels = 6;
            doors = 10;
            seats = 200;
            maxspeed = 650;
            lights = 10;
            description = "Pwane";
            material = "Steal and foam and stuff idk";
        }
    }

}
