#ifndef STRUCTURE_H
#define STRUCTURE_H

struct Skills {
	string name;
	string property;
	int damage;
};

struct Pokemen {
	string name;
	string property;
	int level = 1;
	int number_of_skills = 0;
	Skills * skill = new Skills [number_of_skills];
};

struct Bag {
	int number_of_pokemen = 0;
	Pokemen * pokemen = new Pokemen [number_of_pokemen];
};

struct User {
	string name;
	int gold = 100;
	Bag bag;
};

#endif