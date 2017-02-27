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
            private string name = "cat";

            public cat(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "I am a " + this.name + " \n";
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
            private string name = "dog";

            public dog(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "I am a " + this.name + " \n";
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
            private string name = "pig";

            public pig(TextBlock w)
            {
                this.word = w;
            }
            public string saying(object sender)
            {
                this.word.Text += "I am a " + this.name + " \n";
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            bool isSpeakAble = true;

            if (isFirstTime)
            {
                words.Text = "";
                c = new cat(words);
                d = new dog(words);
                p = new pig(words);

                isFirstTime = false;
            }

            if (((Button)sender).Name == "OK")
            {
                switch (input.Text)
                {
                    case "dog":
                        Say = new AnimalSaying(d.saying);
                        break;
                    case "cat":
                        Say = new AnimalSaying(c.saying);
                        break;
                    case "pig":
                        Say = new AnimalSaying(p.saying);
                        break;
                    default:
                        isSpeakAble = false;
                        break;
                }
                clear_input();
            }
            else
            {
                Random ran = new Random();
                int n = ran.Next(1, 4);
                switch (n)
                {
                    case 1:
                        Say = new AnimalSaying(d.saying);
                        break;
                    case 2:
                        Say = new AnimalSaying(c.saying);
                        break;
                    case 3:
                        Say = new AnimalSaying(p.saying);
                        break;
                }
            }

            //执行事件
            if (isSpeakAble)
                Say(this);  
        }

        public void clear_input()
        {
            input.Text = "";
        }

    }
}


