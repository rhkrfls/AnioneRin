using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Monster : Unit
    {
        public Monster()
        {
            hp = 20;
            walk_speed = 1.0f;
            damage = 10.0f;

            is_walk = false;
            is_jump = false;
            is_attack = false;
        }

        ~Monster()
        {

        }

        
    }
}
