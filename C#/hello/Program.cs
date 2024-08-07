using System.Threading;
using System;
using System.Threading;
// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");
(double, int) t1 = (4.5, 3);
Console.WriteLine($"Tuple with elements {t1.Item1} and {t1.Item2}.");
int[] arr = new int[] { 1, 2, 3, 4, 5 };
Console.WriteLine($"Array with elements {arr}");

var thr = new Thread
(
    n =>
    {
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine($"In child thread: {n}");
        }
    
    Thread.Sleep(5000); //静态方法，暂停当前线程1000ms。注：Thread.Sleep(0)会导致线程立即放弃当前的时间片，自动将CPU移交给其他线程。
    Thread.Yield(); //与Sleep(0)类似，但是它只会把执行交给同一处理器上的其他线程。即Yield是主动让出CPU，如果有其他就绪线程就执行其他线程，如果没有则继续当前线程
    }
){IsBackground = true};
thr.Start(999);
for (int i = 0; i < 1000; i++)
{
Console.WriteLine("In main thread: 888");
}
thr.Join();
thr.Join(1000); //设置超时，参数用毫秒或TimeSpan。返回bool类型：等待的线程结束了，就返回true，超时了返回false。


partial class Program
{
    private static int counter = 0;
    private static readonly object lockObject = new object();

    static void Main(string[] args)
    {
        Thread thread1 = new Thread(IncrementCounter);
        Thread thread2 = new Thread(IncrementCounter);

        thread1.Start();
        thread2.Start();

        thread1.Join();
        thread2.Join();

        Console.WriteLine($"Final counter value: {counter}");
    }

    private static void IncrementCounter()
    {
        for (int i = 0; i < 100000; i++)
        {
            lock (lockObject)
            {
                // Critical section that modifies the shared resource.
                counter++;
            }
            // Other non-critical section code can go here.
        }
    }
}