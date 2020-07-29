using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{
    public class Motorbike : Vehicle
    {
        public Motorbike()
        {
            name = "Honda";
            wheels = 2;
            doors = 0;
            seats = 1;
            maxspeed = 250;
            lights = 6;
            description = "Honda 250";
        }
    }
}
