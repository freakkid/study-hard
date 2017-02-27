using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

//“空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409 上有介绍

namespace Animal
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private delegate string AnimalSaying(object sender);//声明一个委托
        private event AnimalSaying Say;//委托声明一个事件

        private const string dogName = "dog";
        private const string catName = "cat";
        private const string pigName = "pig";

        private enum animals { dog, cat, pig};

        public MainPage()
        {
            this.InitializeComponent();
        }

        interface Animal
        {
            //方法
            string saying(object sender);
            //属性
            string Name { get; set; }
        }

        class cat : Animal
        {
            TextBlock word;
            private string name = catName;

            public cat(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "Cat: I am a " + this.name + " \n";
                return "";
            }
            public string Name
            {
                get { return name; }
                set { this.name = value; }
            }
        }

        class dog : Animal
        {
            TextBlock word;
            private string name = dogName;

            public dog(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "Dog: I am a " + this.name + " \n";
                return "";
            }
            public string Name
            {
                get { return name; }
                set { this.name = value; }
            }
        }

        class pig : Animal
        {
            TextBlock word;
            private string name = pigName;

            public pig(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "Pig: I am a " + this.name + " \n";
                return "";
            }
            public string Name
            {
                get { return name; }
                set { this.name = value; }
            }
        }


        private cat c;
        private dog d;
        private pig p;
        bool isFirstTime = true;

        private void ifIsFirstTime()
        {
            words.Text = String.Empty;
            c = new cat(words);
            d = new dog(words);
            p = new pig(words);

            isFirstTime = false;
        }

        private void Speak_Click(object sender, RoutedEventArgs e)
        {   
            if (isFirstTime)
            {
                ifIsFirstTime();
            }
                
            Random ran = new Random();
            int n = ran.Next(0, 3);
            switch (n)
            {
                case (int)animals.dog:
                    Say = new AnimalSaying(d.saying);
                    break;
                case (int)animals.cat:
                    Say = new AnimalSaying(c.saying);
                    break;
                case (int)animals.pig:
                    Say = new AnimalSaying(p.saying);
                    break;
            }

            Say(this);
        }

        private void OK_Click(object sender, RoutedEventArgs e)
        {
            if (isFirstTime)
            {
                ifIsFirstTime();
            }

            bool isSpeakAble = true;

            switch (input.Text)
            {
                case dogName:
                    Say = new AnimalSaying(d.saying);
                    break;
                case catName:
                    Say = new AnimalSaying(c.saying);
                    break;
                case pigName:
                    Say = new AnimalSaying(p.saying);
                    break;
                default:
                    isSpeakAble = false;
                    break;
            }

            clear_input();  // 清除textbox的文本

            if (isSpeakAble)
                Say(this);
        }

        private void clear_input()
        {
            input.Text = String.Empty;
        }

    }
}


