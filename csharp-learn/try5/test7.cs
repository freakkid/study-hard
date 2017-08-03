using System;

public delegate void StringListEvent(IStringList sender);
public interface IStringList
{
    // 方法
    void Add(String s);
    int Count {get; }
    event StringListEvent Changed;
    String this[int index] { get; set; }
}
