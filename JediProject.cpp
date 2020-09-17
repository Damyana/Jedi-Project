#include <iostream>
#include <string>

using namespace std;

enum RankJedi { Default1,Youngling, Padawan, JediService, JediKnight, JediMaster, GrandMaster };
enum RankStormtrooper { Default2, OfficerCadet, Lieutenant, Captain, Major, Colonel, Commander };

class Planet
{
private:
	string name;
	string planetSystem;
	string republic;
public:
	Planet() {}
	Planet(string _name, string _planetSystem, string _republic)
	{
		this->name = _name;
		this->planetSystem = _planetSystem;
		this->republic = _republic;
	}
	Planet(const Planet& other)
	{
		this->name = other.name;
		this->planetSystem = other.planetSystem;
		this->republic = other.republic;
	}
	Planet& operator=(const Planet& src)
	{
		if (this != &src)
		{
			this->name = src.name;
			this->planetSystem = src.planetSystem;
			this->republic = src.republic;
		}
		return*this;
	}

	~Planet() {};

	//SET
	void setNameP(string _name)
	{
		this->name = _name;
	}
	void setplanetSystem(string _planetSystem)
	{
		this->planetSystem = _planetSystem;
	}
	void setRepublic(string _republic)
	{
		this->republic = _republic;
	}

	//GET
	string getNameP()const
	{
		return this->name;
	}
	string getplanetSystem()const
	{
		return this->planetSystem;
	}
	string getRepublic()const
	{
		return this->republic;
	}

	void Display()
	{
		cout << "--->Planet" << endl;
		cout << endl;

		cout << "Name of Planet: " << name << endl;
		cout << "PlanetSystem: " << planetSystem << endl;
		cout << "Republic: " << republic << endl;
	}

	friend ostream& operator<<(ostream& output, const Planet& P) {
		output << "Name of Planet: " << P.name << " PlanetSystem: " << P.planetSystem << " Republic: " << P.republic;
		return output;
	}

	friend istream& operator>>(istream& input, Planet& P) {
		input >> P.name >> P.planetSystem >> P.republic;
		return input;
	}
};

class Jedi
{
private:
	string name;
	RankJedi rank;
	double midichlorian;
	Planet planet;
	string spicies;
	string militaryRank;
public:
	Jedi()
	{
		planet = Planet();
		RankJedi rank = Default1;
		midichlorian = 0.0;
	}
	Jedi(string _name, RankJedi _rank, double _midichlorian, Planet _planet, string _spicies, string _militaryRank)
	{
		this->name = _name;
		this->rank = _rank;
		this->midichlorian = _midichlorian;
		this->planet = _planet;
		this->spicies = _spicies;
		this->militaryRank = _militaryRank;
	}
	Jedi(const Jedi& other)
	{
		this->name = other.name;
		this->rank = other.rank;
		this->midichlorian = other.midichlorian;
		this->planet = other.planet;
		this->spicies = other.spicies;
		this->militaryRank = other.militaryRank;
	}
	Jedi& operator=(const Jedi& src)
	{
		if (this != &src)
		{
			this->name = src.name;
			this->rank = src.rank;
			this->midichlorian = src.midichlorian;
			this->planet = src.planet;
			this->spicies = src.spicies;
			this->militaryRank = src.militaryRank;
		}
		return*this;
	}

	~Jedi() {};

	//SET
	void setNameJ(string _name)
	{
		this->name = _name;
	}

	void setRank(RankJedi _rank)
	{
		this->rank = _rank;
	}

	void setMidichlorian(double _midichlorian)
	{
		this->midichlorian = _midichlorian;
	}

	void setPlanet(Planet _planet)
	{
		this->planet = _planet;
	}

	void setSpicies(string _spicies)
	{
		this->spicies = _spicies;
	}

	void setMilitaryRank(string _militaryRank)
	{
		this->militaryRank = _militaryRank;
	}

	//GET
	string getNameJ()const
	{
		return this->name;
	}

	RankJedi getRank()const
	{
		return this->rank;
	}

	double getMidichlorian()const
	{
		return this->midichlorian;
	}

	Planet getPlanet()const
	{
		return this->planet;
	}

	string getSpicies()const
	{
		return this->spicies;
	}

	string getMilitaryRank()const
	{
		return this->militaryRank;
	}


	void Display()
	{
		cout << "--->Jedi" << endl;
		cout << endl;

		cout << "Name of Jedi: " << name << endl;

		switch (rank)
		{
		case Youngling:
			cout << "Youngling" << endl;
			break;
		case Padawan:
			cout << "Padawan" << endl;
			break;
		case JediService:
			cout << "JediService" << endl;
			break;
		case JediKnight:
			cout << "JediKnight" << endl;
			break;
		case JediMaster:
			cout << "JediMaster" << endl;
			break;
		case GrandMaster:
			cout << "GrandMaster" << endl;
			break;
		}

		cout << "Midichlorian: " << midichlorian << endl;
		cout << "Planet: " << planet << endl;
		cout << "Spicies: " << spicies << endl;
		cout << "Military Rank: " << militaryRank << endl;

	}

	friend ostream& operator<<(ostream& output, const Jedi& J) {
		output << "Name: " << J.name << endl;
		output << "Rank: ";
		switch (J.rank)
		{
		case Youngling:
			output << "Youngling" << endl;
			break;
		case Padawan:
			output << "Padawan" << endl;
			break;
		case JediService:
			output << "JediService" << endl;
			break;
		case JediKnight:
			output << "JediKnight" << endl;
			break;
		case JediMaster:
			output << "JediMaster" << endl;
			break;
		case GrandMaster:
			output << "GrandMaster" << endl;
			break;
		}
		output << "Midichlorian: " << J.midichlorian << endl;
		output << "Planet: " << J.planet << endl;
		output << "Spicies: " << J.spicies << endl;
		output << "Military Rank:" << J.militaryRank << endl;
		return output;
	}

	friend istream& operator>>(istream& input, Jedi& J) {
		input >> J.name >> J.midichlorian >> J.planet >> J.spicies >> J.militaryRank;
		return input;
	}

};

class Stormtrooper
{
private:
	string id;
	RankStormtrooper rank;
	string type;
	Planet planet;
public:
	Stormtrooper()
	{
		planet = Planet();
		RankStormtrooper rank = Default2;
	}
	Stormtrooper(string _id, RankStormtrooper _rank, string _type, Planet _planet)
	{
		this->id = _id;
		this->rank = _rank;
		this->type = _type;
		this->planet = _planet;
	}
	Stormtrooper(const Stormtrooper& other)
	{
		this->id = other.id;
		this->rank = other.rank;
		this->type = other.type;
		this->planet = other.planet;
	}
	Stormtrooper& operator=(const Stormtrooper& src)
	{
		if (this != &src)
		{
			this->id = src.id;
			this->rank = src.rank;
			this->type = src.type;
			this->planet = src.planet;
		}
		return*this;
	}

	~Stormtrooper() {};

	//SET
	void setID(string _id)
	{
		this->id = _id;
	}
	void setRank(RankStormtrooper _rank)
	{
		this->rank = _rank;
	}
	void setMidichlorian(string _type)
	{
		this->type = _type;
	}
	void setPlanet(Planet _planet)
	{
		this->planet = _planet;
	}

	//GET
	string getID()const
	{
		return this->id;
	}
	RankStormtrooper getRank()const
	{
		return this->rank;
	}
	string getType()const
	{
		return this->type;
	}
	Planet getPlanet()const
	{
		return this->planet;
	}

	void Display()
	{
		cout << "--->Stormtrooper" << endl;
		cout << endl;
		cout << "ID: " << id << endl;
		switch (rank)
		{
		case OfficerCadet:
			cout << "OfficerCadet" << endl;
			break;
		case Lieutenant:
			cout << "Lieutenant" << endl;
			break;
		case Captain:
			cout << "Captain" << endl;
			break;
		case Major:
			cout << "Major" << endl;
			break;
		case Colonel:
			cout << "Colonel" << endl;
			break;
		case Commander:
			cout << "Commander" << endl;
			break;
		}
		cout << "Type: " << type << endl;
		cout << "Planet: " << planet << endl;


	}

	friend ostream& operator<<(ostream& output, const Stormtrooper& S) {
		output << "ID: " << S.id << endl;
		output << "Rank: ";
		switch (S.rank)
		{
		case OfficerCadet:
			output << "OfficerCadet" << endl;
			break;
		case Lieutenant:
			output << "Lieutenant" << endl;
			break;
		case Captain:
			output << "Captain" << endl;
			break;
		case Major:
			output << "Major" << endl;
			break;
		case Colonel:
			output << "Colonel" << endl;
			break;
		case Commander:
			output << "Commander" << endl;
			break;
		}
		output << "Type: " << S.type << endl;
		output << "Planet: " << S.planet << endl;

		return output;
	}

	friend istream& operator>>(istream& input, Stormtrooper& S) {
		input >> S.id >> S.type >> S.planet;
		return input;
	}
};

class JediTemple
{
private:
	Jedi* jedi;
	int size = 0;
	int beds = 100;
public:
	JediTemple ()
	{
		jedi = new Jedi[beds];
		size = 0;
	}
	JediTemple(const JediTemple& jt)
	{
		for (int i = 0; i < beds; i++)
		this->jedi[i] = jt.jedi[i];
		size = jt.size;
	}
	JediTemple& operator=(const JediTemple& jt)
	{
		if (this != &jt)
		{
			delete[] jedi;
			size = 0;
			for (int i = 0; i < beds; i++)this->jedi[i] = jt.jedi[i];
			size = jt.size;
		}
		return *this;
	}
	~JediTemple() { delete[] jedi; }

	void buildNewWing()
	{
		beds *= 2;
		Jedi* moreJedi = new Jedi[beds];
		for (int i = 0; i < beds / 2; i++)
		{
			moreJedi[i] = jedi[i];
		};
		delete[] jedi;
		for (int i = 0; i < beds; i++) { jedi[i] = moreJedi[i]; }
	}

	void AddJedi(Jedi j)
	{
		if (size == beds)buildNewWing();
		jedi[size] = j;
		size++;
	}

	void DeleteJedi(string name)
	{
		bool flag = true;
		for (size_t i = 0; i < this->size; i++)
		{
			if (name == jedi[i].getNameJ())
			{
				flag = false;
				for (size_t j = i; j < (this->size - 1); j++)
				{
					this->jedi[j] = this->jedi[j + 1];
				}
				size--;
				break;
			}
		}

		for (size_t i = 0; i < this->size; i++)
		{
			jedi[i].Display();
			cout << endl;
		}

		if (flag)
			cout << "No Jedi with name: " << name << endl;
	}

	int CountJedi()const
	{
		return size;
	}

	void Display()
	{
		cout << "---------------------------JediTemple-----------------------------" << endl;
		cout << "Your Jedis: " << endl;
		for (int i = 0; i < this->size; i++)
		{
			jedi[i].Display();
			cout << endl;
		}
	}

	friend ostream& operator<<(ostream& output, const JediTemple& JD) {
		output << "Jedi: " << endl;
		for (int i = 0; i < JD.size; i++)
		{
			output << JD.jedi[i];
		}
		return output;
	}
};

class Army
{
private:
	Stormtrooper* troops;
	int size = 0;
	int beds = 100;
public:
	Army()
	{
		troops = new Stormtrooper[beds];
		size = 0;
	}
	Army(const Army& a)
	{
		for (int i = 0; i < beds; i++)
			this->troops[i] = a.troops[i];
		size = a.size;
	}
	Army& operator=(const Army& a)
	{
		if (this != &a)
		{
			delete[] troops;
			size = 0;
			for (int i = 0; i < beds; i++)this->troops[i] = a.troops[i];
			size = a.size;
		}
		return *this;
	}
	~Army() { delete[] troops; }

	void buildNewWing()
	{
		beds *= 2;
		Stormtrooper* moreSt = new Stormtrooper[beds];
		for (int i = 0; i < beds / 2; i++)
		{
			moreSt[i] = troops[i];
		};
		delete[] troops;
		for (int i = 0; i < beds; i++) { troops[i] = moreSt[i]; }
	}

	void AddStormtroop(Stormtrooper s)
	{
		if (size == beds)buildNewWing();
		troops[size] = s;
		size++;
	}

	void DeleteStormtroop(string ID)
	{
		bool flag = true;
		for (size_t i = 0; i < this->size; i++)
		{
			if (ID == troops[i].getID())
			{
				flag = false;
				for (size_t j = i; j < (this->size - 1); j++)
				{
					this->troops[j] = this->troops[j + 1];
				}
				size--;
				break;
			}
		}

		for (size_t i = 0; i < this->size; i++)
		{
			troops[i].Display();
			cout << endl;
		}

		if (flag)
			cout << "No Stormtrooper with ID: " << ID << endl;
	}

	int CountStormtroopers()const
	{
		return size;
	}

	void Display()
	{
		cout << "---------------------------ARMY-----------------------------" << endl;
		cout << "Your Stormtroopers: " << endl;
		for (int i = 0; i < this->size; i++)
		{
			troops[i].Display();
			cout << endl;
		}
	}

	friend ostream& operator<<(ostream& output, const Army& A) {
		output << "Stormtroopers: " << endl;
		for (int i = 0; i < A.size; i++)
		{
			output << A.troops[i];
		}
		return output;
	}
};

class Galaxy
{
private:
	string nameGalaxy;
	Planet* planets;
	int size = 0;
	int beds = 100;
public:
	Galaxy()
	{
		planets = new Planet[beds];
		size = 0;
	}
	Galaxy(string _nameGalaxy)
	{
		this->nameGalaxy = _nameGalaxy;
	}
	Galaxy(const Galaxy& g)
	{
		for (int i = 0; i < beds; i++)
			this->planets[i] = g.planets[i];
		size = g.size;
	}
	Galaxy& operator=(const Galaxy& gs)
	{
		if (this != &gs)
		{
			delete[] planets;
			size = 0;
			for (int i = 0; i < beds; i++)this->planets[i] = gs.planets[i];
			size = gs.size;
		}
		return *this;
	}
	~Galaxy() { delete[] planets; }

	void buildNewWing()
	{
		beds *= 2;
		Planet* morePlanet = new Planet[beds];
		for (int i = 0; i < beds / 2; i++)
		{
			morePlanet[i] = planets[i];
		};
		delete[] planets;
		for (int i = 0; i < beds; i++) { planets[i] = morePlanet[i]; }
	}

	void AddPlanet(Planet p)
	{
		if (size == beds)buildNewWing();
		planets[size] = p;
		size++;
	}

	void DeletePlanet(string name)
	{
		bool flag = true;
		for (size_t i = 0; i < this->size; i++)
		{
			if (name == planets[i].getNameP())
			{
				flag = false;
				for (size_t j = i; j < (this->size - 1); j++)
				{
					this->planets[j] = this->planets[j + 1];
				}
				size--;
				break;
			}
		}

		for (size_t i = 0; i < this->size; i++)
		{
			planets[i].Display();
			cout << endl;
		}

		if (flag)
			cout << "No Planet with name: " << name << endl;
	}

	int CountPlanets()const
	{
		return size;
	}

	void Display()
	{
		cout << "---------------------------GALAXY-----------------------------" << endl;
		cout << "Your Planets: " << endl;
		for (int i = 0; i < this->size; i++)
		{
			planets[i].Display();
			cout << endl;
		}
	}

	friend ostream& operator<<(ostream& output, const Galaxy& G) {
		output << "Planets: " << endl;
		for (int i = 0; i < G.size; i++)
		{
			output << G.planets[i];
		}
		return output;
	}

};

class GalacticRepublic
{
private:
	string nameRepublic;
	JediTemple jediTemple;
	Army army;
	Galaxy galaxy;
public:
	GalacticRepublic()
	{
		jediTemple = JediTemple();
		army = Army();
		galaxy = Galaxy();
	}
	GalacticRepublic(string _nameRepublic, JediTemple _jediTemple, Army _army, Galaxy _galaxy)
	{
		this->nameRepublic = _nameRepublic;
		this->jediTemple = _jediTemple;
		this->army = _army;
		this->galaxy = _galaxy;
	}
	GalacticRepublic(const GalacticRepublic& other)
	{
		this->nameRepublic = other.nameRepublic;
		this->jediTemple = other.jediTemple;
		this->army = other.army;
		this->galaxy = other.galaxy;
	}
	GalacticRepublic& operator=(const GalacticRepublic& src)
	{
		if (this != &src)
		{
			this->nameRepublic = src.nameRepublic;
			this->jediTemple = src.jediTemple;
			this->army = src.army;
			this->galaxy = src.galaxy;
		}
		return*this;
	}

	//SET
	void setNameRepublic(string _nameRepublic)
	{
		this->nameRepublic = _nameRepublic;
	}
	//GET
	string getNameRepublic()const
	{
		return this->nameRepublic;
	}

	void Display()
	{
		cout << "---------------------------Galactic Republic-----------------------------" << endl;
		cout << "Name of Republic: " << nameRepublic << endl;
		jediTemple.Display();
		army.Display();
		galaxy.Display();
	}

};

int main()
{
	//PLANETS
	Planet p1("Durka", "Dita", "Demi");
	//p1.Display();

	//JEDIS
	Jedi j1("Niki", Youngling , 59.5, p1, "meche", "Major");
	//j1.Display();

	//STORMTROOPERS
	Stormtrooper s1("123", OfficerCadet, "XXX", p1);
	Stormtrooper s2("111", Captain, "ZZZ", p1);
	//s1.Display();

	////JEDITEMPLE - add jedis
	JediTemple t1;
	t1.AddJedi(j1);
	//t1.DeleteJedi("Niki");
	//t1.Display();
	cout << "Count Jedi: " << t1.CountJedi() << endl;

	//MY ARMY - add stormtroopers
	Army a1;
	a1.AddStormtroop(s1);
	a1.AddStormtroop(s2);
	//a1.DeleteStormtroop("123");
	/*a1.Display();*/
	cout << "Count Stormtroops: " << a1.CountStormtroopers() << endl;

	//Galaxies - add planets
	Galaxy g1;
	g1.AddPlanet(p1);
	//g1.DeletePlanet("Durka");
	//g1.Display();
	cout << "Count Planets: " << g1.CountPlanets() << endl;

	//GalacticRepublic
	GalacticRepublic rep("Bebe", t1, a1, g1);
	rep.Display();

}