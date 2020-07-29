using System;
using System.Collections.Generic;
using System.Text;

namespace Inheritance
{
    public class Boat : Vehicle
    {
        public Boat()
        {
            name = "Yamaha";
            wheels = 0;
            doors = 1;
            seats = 4;
            maxspeed = 80;
            lights = 0;
            description = "Propella boi and awl";
        }
    }
}
