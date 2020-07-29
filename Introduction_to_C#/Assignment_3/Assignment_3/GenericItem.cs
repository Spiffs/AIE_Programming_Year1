namespace Assignment_3
{
    //Main geneticitem class 
    public class GenericItem
    {
        public string name;
        public int quantity;
        public int cost;


        public GenericItem()
        { }

        public GenericItem(string a_name, int a_quantity, int a_cost)
        {
            name = a_name;
            quantity = a_quantity;
            cost = a_cost;
            //FIX: jay explained the process of a_name addopting the null name of name
            //was previously a_name = name; which would reset a_name to name which is not set which would therefore make a_name equal nothing 
        }

    }

    //Sub class of GenericItem class called Weapon
    public class Weapon : GenericItem
    {
        public int damage;

        //Default
        public Weapon()
        { }

        public Weapon(string a_name, int a_quantity, int a_cost, int a_damage) : base(a_name, a_quantity, a_cost)
        {
            damage = a_damage;
        }

    }

    //Sub class of gebericitem class called Armor 
    public class Armor : GenericItem
    {
        public int protection;

        public Armor()
        { }

        public Armor(string a_name, int a_quantity, int a_cost, int a_protection) : base(a_name, a_quantity, a_cost)
        {
            protection = a_protection;
        }
    }
}
