using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathClasses
{
    public class Vector4
    {
        public float x, y, z, w;

        public Vector4()
        {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }

        public Vector4(float _x, float _y, float _z, float _w)
        {
            x = _x;
            y = _y;
            z = _z;
            w = _w;
        }

        //Operators for Vector4 to Vecor4
        public static Vector4 operator +(Vector4 lhs, Vector4 rhs)
        {
            return new Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
        }

        public static Vector4 operator -(Vector4 lhs, Vector4 rhs)
        {
            return new Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
        }

        public static Vector4 operator *(Vector4 lhs, Vector4 rhs)
        {
            return new Vector4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
        }

        public static Vector4 operator /(Vector4 lhs, Vector4 rhs)
        {
            return new Vector4(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
        }

        //Operators for Vector4 to Float 

        public static Vector4 operator *(Vector4 lhs, float rhs)
        {
            return new Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
        }

        //Operators for Floats and Vector4
        public static Vector4 operator *(float lhs, Vector4 rhs)
        {
            return new Vector4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
        }

        //Operator for Vector4 to Vector4 DOT
        public float Dot(Vector4 rhs)
        {
            return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
        }

        //Operator for Vector4 to Vector4 CROSS
        public Vector4 Cross(Vector4 rhs)
        {
            return new Vector4(
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x,
            0);
        }

        //Vector4 Magnitude 
        public float Magnitude()
        {
            return (float)Math.Sqrt(x * x + y * y + z * z + w * w);
        }

        //Normalize
        public void Normalize()
        {
            float m = Magnitude();
            this.x /= m;
            this.y /= m;
            this.z /= m;
            this.w /= m;
        }

        //Operator for Matrix3 to Vector3
        public static Vector4 operator *(Matrix4 lhs, Vector4 rhs)
        {
            return new Vector4(((rhs.x * lhs.m1) + (rhs.y * lhs.m5) + (rhs.z * lhs.m9) + (rhs.w * lhs.m13)),
                               ((rhs.x * lhs.m2) + (rhs.y * lhs.m6) + (rhs.z * lhs.m10) + (rhs.w * lhs.m14)),
                               ((rhs.x * lhs.m3) + (rhs.y * lhs.m7) + (rhs.z * lhs.m11) + (rhs.w * lhs.m15)),
                               ((rhs.x * lhs.m4) + (rhs.y * lhs.m8) + (rhs.z * lhs.m12) + (rhs.w * lhs.m16)));
        }

        

    }
}