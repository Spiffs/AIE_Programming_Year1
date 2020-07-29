using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            float QA(float x)
            {
                float result = x * x + 2 * x - 7;
                return result;
            }

            double QB(float a, float b, float c)
            {
                float x = (b * b) - 4 * a * c;
                double result = Math.Sqrt(x);
                if (result < 0)
                {
                    return 0;
                }
                else return result;
            }

            float QC(float s, float e, float t)
            {
                float result = s + t * (e - s);
                return result;
            }

            float QD(float x1, float y1, float x2, float y2)
            {
                double x = Math.Pow(x2 - x1)
            }


        }
    }
}
