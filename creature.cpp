#include <string>
#include <iostream>
using namespace std;
//Class Declarations
class Creature //Base Class
{
public:
	Creature(string name); //Constructor
	virtual ~Creature();//virtual destructor
	virtual string name() const; //creatures have names.
	virtual bool isMortal() const=0; //pure virtual b/c no default.
	virtual string move() const=0; //pure virtual b/c no default.

private:
	string m_name;
};
class Phoenix : public Creature
{
public:
	Phoenix(string name) :Creature(name) {};  //creates a creature with a name.
	virtual ~Phoenix();//virtual destructor
	virtual bool isMortal() const;  //override the pure virtual isMortal
	virtual string move() const;  //override the pure virtual move
};
class Giant : public Creature
{
public:
	Giant(string name, int weight) :Creature(name), m_weight(weight) {}; //default constructor
	virtual ~Giant();
	virtual bool isMortal() const;
	virtual string move() const;
private:
	int m_weight;
};
class Centaur : public Creature
{
public:
	Centaur(string name) :Creature(name) {};
	virtual ~Centaur(); //destructor
	virtual bool isMortal() const;
	virtual string move() const;
};

void animate(const Creature* c)
{
	cout << c->name() << ", who is ";
	if (c->isMortal())
		cout << "mortal";
	else
		cout << "immortal";
	cout << ", will now " << c->move() << ".\n";
}

int test()
{
	Creature* creatures[4];
	creatures[0] = new Phoenix("Squawkes");
	// Giants have a name and a weight in tons.  Giants under 20 tons
	// walk by tromping; giants weighing at least 20 tons lumber.
	creatures[1] = new Giant("Frawp", 17);
	creatures[2] = new Giant("Gridwulfa", 22);
	creatures[3] = new Centaur("Florence");

	cout << "Here are the creatures." << endl;
	for (int k = 0; k < 4; k++)
		animate(creatures[k]);

	// Clean up the creatures before exiting
	cout << "Cleaning up." << endl;
	for (int k = 0; k < 4; k++)
		delete creatures[k];
	cin.ignore(10000, '\n');
	return 1;
}

//****Creature Definition*******
Creature::Creature(string name) :m_name(name) {};
//Virtual Creature destructor
Creature::~Creature(){}
string Creature::name() const
{
	return m_name;
}

//****Phoenix Definition*******
//virtual destructor
Phoenix::~Phoenix(){
	cout << "Destroying " << name() << " the phoenix."<<endl;
}
bool Phoenix::isMortal() const
{
	return false;
}
string Phoenix::move() const
{
	return "fly";
}

//****Giant Definition*******
Giant::~Giant()
{
	cout << "Destroying " << name() << " the giant."<<endl;
}
bool Giant::isMortal() const
{
	return true;
}
string Giant::move() const
{
	if (m_weight < 20)
		return "tromp";
	else
		return "lumber";
}

//****Centaur Definition*******
Centaur::~Centaur()
{
	cout << "Destroying " << name() << " the centaur."<<endl;
}
bool Centaur::isMortal() const
{
	return true;
}
string Centaur::move() const
{
	return "trot";
}