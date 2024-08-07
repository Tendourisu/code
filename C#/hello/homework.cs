using System;
using System.Diagnostics;

namespace Homework
{
    public class Program
    {
        public static void Main(string[] args) 
        {
            ILongProgressByTime a = new LongProgressByTime();
            new Thread
                (
                    () =>
                    {
                        Console.WriteLine("A Start: "+(a.Start(2000)).ToString());
                        Thread.Sleep(1000);
                        Console.WriteLine("A TrySet0: "+(a.TrySet0()).ToString());
                        Thread.Sleep(500);
                        Console.WriteLine("A Start: "+(a.Start(1000)).ToString() +" Now: "+Environment.TickCount64);
                        Thread.Sleep(500);
                        Console.WriteLine("A Progress: "+(a.GetProgress()).ToString() +" Now: "+Environment.TickCount64);
                        Thread.Sleep(1003);
                        Console.WriteLine("A TrySet0: "+(a.TrySet0()).ToString());
                    }
                ).Start();

            new Thread
                (
                    () =>
                    {
                        Console.WriteLine("B Start: "+(a.Start(2000)).ToString());
                        Thread.Sleep(1500);
                        Console.WriteLine("B Start: " +(a.Start(1000)).ToString() + " Now: " + Environment.TickCount64);
                        Thread.Sleep(500);
                        Console.WriteLine("B Progress: " +(a.GetProgress()).ToString() + " Now: " + Environment.TickCount64);
                    }
                ).Start();
        }
    }

    public interface ILongProgressByTime
    {
        /// <summary>
        /// 尝试加载下一次进度条，needTime指再次加载进度条所需时间，单位毫秒
        /// 如果之前进度条处于就绪态，则将进度开始下一次加载，返回true
        /// 如果之前进度条不处于就绪态，返回false
        /// </summary>
        public bool Start(long needTime);
        /// <summary>
        /// 使未完成的进度条清零并终止变为就绪态，返回值代表是否成功终止
        /// </summary>
        public bool TrySet0();
        /// <summary>
        /// 使进度条强制清零并终止变为就绪态
        /// </summary>
        public void Set0();
        /// <summary>
        ///     ElapsedTime指其中已过去的时间，NeedTime指当前Progress完成所需时间，单位毫秒
        /// </summary>
        public (long ElapsedTime, long NeedTime) GetProgress();
    }

    public class LongProgressByTime : ILongProgressByTime
    {
        private long startTime = -1;
        private long needTime = 0;
        private object lockObj = new object();

        public bool Start(long needTime)
        {
            lock (lockObj)
            {
                if (startTime == -1) // 如果进度条处于就绪态
                {
                    this.needTime = needTime;
                    startTime = Environment.TickCount64; // 设置开始时间
                    return true;
                }
                return false; // 进度条不处于就绪态
            }
        }

        public bool TrySet0()
        {
            lock (lockObj)
            {
                if (startTime != -1 && Environment.TickCount64 - startTime < needTime) // 如果进度条未完成
                {
                    startTime = -1; // 重置为就绪态
                    return true;
                }
                return false; // 进度条已完成或已处于就绪态
            }
        }

        public void Set0()
        {
            lock (lockObj)
            {
                startTime = -1; // 强制重置为就绪态
            }
        }

        public (long ElapsedTime, long NeedTime) GetProgress()
        {
            lock (lockObj)
            {
                if (startTime == -1) // 如果进度条处于就绪态
                {
                    return (0, 0); // 没有进度
                }
                var elapsedTime = Environment.TickCount64 - startTime;
                return (elapsedTime, needTime); // 返回已过去的时间和完成所需时间
            }
        }
    }

/*输出示例（仅供参考）：
 * A Start: False
B Start: True
A TrySet0: True
B Start: True Now: 14536562
A Start: False Now: 14536578
B Progress: (516, 1000) Now: 14537078
A Progress: (516, 1000) Now: 14537078
A TrySet0: False
*/
}