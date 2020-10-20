using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Unit
    {
        public int hp;
        public string name;
        public float walk_speed;
        public float damage;

        public bool is_walk;
        public bool is_jump;
        public bool is_attack;
        public bool is_shield;

        public virtual void Run()
        {
            if (is_walk)
                Console.WriteLine("달리기");
        }

        public virtual void Jump()
        {
            if (is_jump)
                Console.WriteLine("뛰기");
        }

        public virtual void Attack()
        {
            if (is_attack)
                Console.WriteLine("공격하기");
        }

        public virtual void Shield()
        {
            if (is_shield)
                Console.WriteLine("방어하기");
        }

        public virtual void Dead()
        {
            Console.WriteLine("사망");
        }
    }
}
