using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Player : Unit
    {
        public bool no_weapon;
        public bool is_pickup_weapon;

        public Player()
        {
            hp = 100; 
            walk_speed = 1.0f;
            damage = 10.0f;

            is_walk = false;
            is_jump = false;
            is_attack = false;

            no_weapon = false;
            is_pickup_weapon = false;
        }

        public Player(string name) : this()
        {
            this.name = name;
        }

        ~Player()
        {

        }

        public override void Run()
        {
            Console.WriteLine("플레이어 달리기");
            base.Run();
        }

        public void Pickup_Weapon()
        {
            Console.WriteLine("플레이어 무기줍기");
        }

        public void Eating(params int[] array)
        {
            for (int i = 0; i < array.Length; i++)
                Console.WriteLine("플레이어 먹기");
        }
    }
}