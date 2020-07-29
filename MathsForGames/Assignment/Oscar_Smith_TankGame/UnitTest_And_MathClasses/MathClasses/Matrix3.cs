using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MathClasses
{
    public class Matrix3
    {
        public float m1, m2, m3, 
                     m4, m5, m6, 
                     m7, m8, m9;

        public Matrix3()
        {
            m1 = 1; m2 = 0; m3 = 0;
            m4 = 0; m5 = 1; m6 = 0;
            m7 = 0; m8 = 0; m9 = 1;
        }

        public Matrix3(float _m1, float _m2, float _m3, 
                       float _m4, float _m5, float _m6, 
                       float _m7, float _m8, float _m9)
        {
            m1 = _m1; m2 = _m2; m3 = _m3;
            m4 = _m4; m5 = _m5; m6 = _m6;
            m7 = _m7; m8 = _m8; m9 = _m9;
        }

        //Set input with exact values
        public void Set(float _m1, float _m2, float _m3, 
                        float _m4, float _m5, float _m6, 
                        float _m7, float _m8, float _m9)
        {
            m1 = _m1; m2 = _m2; m3 = _m3;
            m4 = _m4; m5 = _m5; m6 = _m6;
            m7 = _m7; m8 = _m8; m9 = _m9;
        }

        //Set input with Matrix
        public void Set(Matrix3 m)
        {
            m1 = m.m1; m2 = m.m2; m3 = m.m3;
            m4 = m.m4; m5 = m.m5; m6 = m.m6;
            m7 = m.m7; m8 = m.m8; m9 = m.m9;
        }

        //Adding Matriceis 
        public static Matrix3 operator +(Matrix3 lhs, Matrix3 rhs)
        {
            return new Matrix3(
                lhs.m1 + rhs.m1, lhs.m2 + rhs.m2, lhs.m3 + rhs.m4,
                lhs.m4 + rhs.m4, lhs.m5 + rhs.m5, lhs.m6 + rhs.m6,
                lhs.m7 + rhs.m7, lhs.m8 + rhs.m8, lhs.m9 + rhs.m9);
        }

        //Subtracting Matrices
        public static Matrix3 operator -(Matrix3 lhs, Matrix3 rhs)
        {
            return new Matrix3(
                rhs.m1 - lhs.m1 + rhs.m2 - lhs.m4 + rhs.m3 - lhs.m7,
                rhs.m1 - lhs.m2 + rhs.m2 - lhs.m5 + rhs.m3 - lhs.m8,
                rhs.m1 - lhs.m3 + rhs.m2 - lhs.m6 + rhs.m3 - lhs.m9,

                rhs.m4 - lhs.m1 + rhs.m5 - lhs.m4 + rhs.m6 - lhs.m7,
                rhs.m4 - lhs.m2 + rhs.m5 - lhs.m5 + rhs.m6 - lhs.m8,
                rhs.m4 - lhs.m3 + rhs.m5 - lhs.m6 + rhs.m6 - lhs.m9,

                rhs.m7 - lhs.m1 + rhs.m8 - lhs.m4 + rhs.m9 - lhs.m7,
                rhs.m7 - lhs.m2 + rhs.m8 - lhs.m5 + rhs.m9 - lhs.m8,
                rhs.m7 - lhs.m3 + rhs.m8 - lhs.m6 + rhs.m9 - lhs.m9);
        }

        //Multiplying Matrices
        public static Matrix3 operator *(Matrix3 lhs, Matrix3 rhs)
        {
            return new Matrix3(
                rhs.m1 * lhs.m1 + rhs.m2 * lhs.m4 + rhs.m3 * lhs.m7,
                rhs.m1 * lhs.m2 + rhs.m2 * lhs.m5 + rhs.m3 * lhs.m8,
                rhs.m1 * lhs.m3 + rhs.m2 * lhs.m6 + rhs.m3 * lhs.m9,

                rhs.m4 * lhs.m1 + rhs.m5 * lhs.m4 + rhs.m6 * lhs.m7,
                rhs.m4 * lhs.m2 + rhs.m5 * lhs.m5 + rhs.m6 * lhs.m8,
                rhs.m4 * lhs.m3 + rhs.m5 * lhs.m6 + rhs.m6 * lhs.m9,

                rhs.m7 * lhs.m1 + rhs.m8 * lhs.m4 + rhs.m9 * lhs.m7,
                rhs.m7 * lhs.m2 + rhs.m8 * lhs.m5 + rhs.m9 * lhs.m8,
                rhs.m7 * lhs.m3 + rhs.m8 * lhs.m6 + rhs.m9 * lhs.m9);
        }

        //Set Rotation around the X axis
        public void SetRotateX(double radians)
        {
            Set(1, 0, 0,
                0, (float)Math.Cos(radians), (float)Math.Sin(radians),
                0, (float)-Math.Sin(radians), (float)Math.Cos(radians));
        }

        public void RotateX(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateX(radians);

            Set(this * m);
        }

        //Set Rotation around the Y axis
        public void SetRotateY(double radians)
        {
            Set((float)Math.Cos(radians), 0, (float)-Math.Sin(radians),
                0, 1, 0,
                (float)Math.Sin(radians), 0, (float)Math.Cos(radians));
        }

        public void RotateY(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateY(radians);

            Set(this * m);
        }

        //Set Rotation around the Z axis
        public void SetRotateZ(double radians)
        {
            Set((float)Math.Cos(radians), (float)Math.Sin(radians), 0,
                (float)-Math.Sin(radians), (float)Math.Cos(radians), 0,
                0, 0, 1);
        }

        public void RotateZ(double radians)
        {
            Matrix3 m = new Matrix3();
            m.SetRotateZ(radians);

            Set(this * m);
        }

        //Set Scaling
        public void SetScaled(float x, float y, float z)
        {
            m1 = x; m2 = 0; m3 = 0;
            m4 = 0; m5 = y; m6 = 0;
            m7 = 0; m8 = 0; m9 = z;
        }

        public void Scale(float x, float y, float z)
        {
            Matrix3 m = new Matrix3();
            m.SetScaled(x, y, z);

            Set(this * m);
        }

        //Set Transformation
        public void SetTranslation(float x, float y)
        {
            m7 = x;
            m8 = y;
        }

        public void Translate(float x, float y)
        {
            m7 += x;
            m8 += y;
        }

    }
}