using System;

namespace Magnitude_and_Normalisation
{
    class Program
    {
        public float x = 1;
        public float y = 1;
        public float z = 1;

        public float MadnitudeSqr()
        {
            return (x * x + y * y + z * z);
        }

        public float Distance(Vector3 other)
        {
            float diffX = x - other.x;
            float diffY = y - other.y;
            float diffZ = z - other.z;
        }

        static void Main(string[] args)
        {
            float radius = 10;
            Vector3 toTarget;

            if (toTarget.MagnitudeSqr() <= (radius * radius))
            {
                // within range
            }
        }
    }
}
