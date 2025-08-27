// See https://aka.ms/new-console-template for more information
using System.Reflection.Emit;

class MyTime
{
    private int hour;
    private int minute;
    private int second;

    public MyTime(int hour, int minute, int second)
    {
        this.hour = validateHour(hour);
        this.minute = validateMinuteOrSecond(minute, nameof(minute));
        this.second = validateMinuteOrSecond(second, nameof(second));
    }

    private int validateHour(int hour)
    {
        if (hour < 0 || hour > 23)
        {
            throw new ArgumentOutOfRangeException(nameof(hour), "Hour must be between 0 and 24");
        }
        return hour;
    }

    private int validateMinuteOrSecond(int num, string paramName)
    {
        if (num < 0 || num > 59)
        {
            throw new ArgumentOutOfRangeException(nameof(paramName), $"{paramName} must be between 0 and 60");
        }
        return num;
    }
    public void SetTime(int hour, int minute, int second)
    {
        this.hour = validateHour(hour);
        this.minute = validateMinuteOrSecond(minute, nameof(minute));
        this.second = validateMinuteOrSecond(second, nameof(second));
    }

    public void SetHour(int hour)
    {
        this.hour = validateHour(hour);
    }

    public void SetMinute(int minute)
    {
        this.minute = validateMinuteOrSecond(minute, nameof(minute));
    }

    public void SetSecond(int second)
    {
        this.second = validateMinuteOrSecond(second, nameof(second));
    }

    public int GetHour()
    {
        return this.hour;
    }

    public int GetMinute()
    {
        return this.minute;
    }

    public int GetSecond()
    {
        return this.second;
    }

    public override string ToString()
    {
        return $"{this.hour:D2}:{this.minute:D2}:{this.second:D2}";
    }

    private void CheckNextHour()
    {
        if (this.hour == 23)
        {
            this.hour = 0;
        }
        else
        {
            this.hour++;
        }
    }
    private void CheckNextMinute()
    {
        if (this.minute == 59)
        {
            this.minute = 0;
            CheckNextHour();
        }
        else
        {
            this.minute++;
        }
    }
    private void CheckPrevioustHour()
    {
        if (this.hour == 0)
        {
            this.hour = 23;
        }
        else
        {
            this.hour--;
        }
    }

    private void CheckPrevioustMinute()
    {
        if (this.minute == 0)
        {
            this.minute = 59;
            CheckPrevioustHour();
        }
        else
        {
            this.minute--;
        }
    }

    public MyTime NextSecond()
    {
        if (this.second == 59)
        {
            this.second = 0;
            CheckNextMinute();
        }
        else
        {
            this.second++;
        }
        return this;
    }

    public string NextMinute()
    {
        CheckNextMinute();

        return "this";
    }

    public MyTime NextHour()
    {
        CheckNextHour();
        return this;
    }
    public MyTime PreviousSecond()
    {
        if (this.second == 0)
        {
            this.second = 59;
            CheckPrevioustMinute();
        }
        else
        {
            this.second--;
        }
        return this;
    }

    public MyTime PreviousMinute()
    {
        CheckPrevioustMinute();
        return this;
    }

    public MyTime PreviousHour()
    {
        CheckPrevioustHour();
        return this;
    }

}

class TestMyTime
{
    static void Main()
    {
        //test creation of the class MyTime
        //test ToString

        MyTime time = new MyTime(9, 32, 0);

        //it should return not null
        //it should return in good formar
        Console.WriteLine(time);


        //test SetTime
        time.SetTime(10, 59, 5);
        //it should show the new time
        Console.WriteLine(time);

        // //test inputing invalid hour
        // time.SetTime(24, 59, 5);
        // //it should show an error of incorrect hour
        // Console.WriteLine(time);

        // //test inputing invalid minute
        // time.SetTime(23, -1, 5);
        // //it should show an error of incorrect hour
        // Console.WriteLine(time);

        // //test inputing invalid second
        // time.SetTime(23, 59, 60);
        // //it should show an error of incorrect hour
        // Console.WriteLine(time);


        // //test SetHour
        // time.SetHour(1);
        // //only hour should change
        // Console.WriteLine(time);

        // //test SetMinute
        // time.SetMinute(14);
        // //only hour should change
        // Console.WriteLine(time);

        // //test SetSecond
        // time.SetSecond(18);
        // //only hour should change
        // Console.WriteLine(time);

        // //test GetHour
        // int hour = time.GetHour();
        // //only extract the hour
        // Console.WriteLine(hour);

        // //test GetMinute
        // int minute = time.GetMinute();
        // //only extract the minute
        // Console.WriteLine(minute);


        // //test GetSecond
        // int second = time.GetSecond();
        // //only extract the second
        // Console.WriteLine(second);

        // //test NextSecond
        // time.NextSecond();
        // //it should show the next time adding one second
        // Console.WriteLine(time);

        //test NextSecond
        time.NextMinute();
        //it should show the next time adding one minute
        Console.WriteLine(time);

        // //test NextHour
        // time.NextHour();
        // //it should show the next time adding one hour
        // Console.WriteLine(time);

        // //test PreviousSecond
        // time.PreviousSecond();
        // //it should show the next time substracting one second
        // Console.WriteLine(time);

        // //test NextSecond
        // time.PreviousMinute();
        // //it should show the next time substracting one minute
        // Console.WriteLine(time);

        // //test NextHour
        // time.PreviousHour();
        // //it should show the next time substracting one hour
        // Console.WriteLine(time);

        // MyTime edgeTime1 = new MyTime(23, 59, 59);
        // MyTime edgeTime2 = new MyTime(23, 59, 59);
        // MyTime edgeTime3 = new MyTime(23, 59, 59);
        // //test all next methods with the last hour, minute and second
        // edgeTime1.NextHour();
        // edgeTime2.NextMinute();
        // edgeTime3.NextSecond();
        // Console.WriteLine(edgeTime1);
        // Console.WriteLine(edgeTime2);
        // Console.WriteLine(edgeTime3);
    }
}
