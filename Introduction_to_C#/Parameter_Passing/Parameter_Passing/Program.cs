using System;

namespace Parameter_Passing
{
    
        public class IntHolder //IntHolder can be named anything
            {
                public int i;
            }
    class Program 
    {
        static void Foo(IntHolder x) 
            { 
                x = new IntHolder(); 
            }
    static void Main(string[] args) 
            {
                IntHolder y = new IntHolder(); 
                y.i = 5; //1 int holder with the value of 5 in it 
                
                Foo(y); //Recalls the function Foo!!! <---
                
                Console.WriteLine(y.i); 
            }
        //static void Foo(IntHolder x) - does not transfer or carry values 
        //therefore;
        //Foo(y) - will not recall the new value of x 
    }
}