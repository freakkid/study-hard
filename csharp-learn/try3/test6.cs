using System;

abstract class A
{
    int y;

    public virtual int X
    {
        get {return 0;}
    }
    
    public virtual int Y
    {
        get {return y;}
        set {y=value;}
    }

    public abstract int z {get; set;}
}

class B: A
{
    int z;
    // base 引用父类属性
    public override int X
    {
        get {return base.X + 1;}
    }

    // 覆盖类A的虚属性
    public override int Y
    {
        set {base.Y = value < 0 ? 0: value;}
    }

    public abstract int z 
    {
        get {return z;}
        set {z=value;}
}