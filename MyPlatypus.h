#pragma once

int rando(int a, int b);

class Platypus {
	float  weight;
	short age; // months
	char name;  // initial
	char gender;
	bool alive; //(ცოცხალია თუ მკვდარი)
	bool mutant;
public:
	Platypus();
	Platypus(float w, short a, char n, char g);
	void setMutant(bool m);
	void setAlive(bool a);
	void setGender(char g);
	void setName(char n);
	void setWeight(float w);
	bool isMutant() const;
	bool isAlive()const;
	char getGender() const;
	char getName() const;
	short getAge() const;
	float getWeight() const;
	void printInfo() const;
	void age_me(short ag);
	void eat();
	Platypus& fight(Platypus& other_platypus);
	void hatch(char n);
};