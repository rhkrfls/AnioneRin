using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Player link = new Player("link");
            Monster goblin = new Monster();

            link.is_attack = true;
            link.Attack();

            link.Eating();
            goblin.is_shield = true;
            goblin.Shield();

            goblin.is_attack = true;
            goblin.Attack();

            link.Dead();
        }
    }

}

