#include <iostream>

using namespace std;
#include "MyPlatypus.h"

int main() {
	Platypus Dead; //ამ პლატიპუსს შექმნის უპარამეტრო კონსტრუქტორი და იგი იქნება მკვდარი;
	Dead.printInfo(); //დაგვიბეჭდავს რომ პლატიპუსი მკვდარია, კონკრეტურლ მონაცემებს (წონა და ა.შ) არ ვაბეჭდინებ რადგან მკვდრისთვის ეს არარელევანტური იქნება
	Dead.age_me(0.4); // დაბეჭდავს რომ მკვდარ პალტიპუსს ასაკს ვერ მოვუმატებთ
	Dead.setAlive(true); //დაბეჭდავს რომ გაცოცხლება არ შეგვიძლია
	Dead.eat(); //დაბეჭდავს რომ მკვდარ პლატიპუსს ვერ ვაჭმევთ
	Platypus newPlat(1.3, 0, 'P', 'm'); //ვქმნით ცოცხალ პლატიპუსს და გადავცემთ მონაცემებს პარამეტრებიანი კონსტრუქტორისთვის
	newPlat.printInfo();
	newPlat.age_me(1);
	newPlat.printInfo();
	newPlat.setName('8');//ეს დაბეჭდავს რომ არასწორი პარამეტრი გადავაწოდეთ
	newPlat.setName('h');
	newPlat.setGender('l'); //ეს დაბეჭდავს რომ არასწორი პარამეტრი გადავაწოდეთ
	newPlat.setGender('f');
	newPlat.setMutant(true);
	newPlat.printInfo();
	newPlat.setMutant(false);
	newPlat.age_me(3);
	newPlat.eat();
	newPlat.printInfo();
	newPlat.setWeight(4);
	newPlat.age_me(5);
	newPlat.printInfo();
	newPlat.setWeight(11); //მოგვცემს გაფრთხილებას რომ პლატიპუსს ვანიჭებთ 10-ზე მეტ წონას და ეს მის სიკვდილს გამოიწვევს
	newPlat.printInfo();
	Platypus MyPlat, Other(3.7, 1, 's', 'm'); //პირველს ვქმნით უპარამეტრო კონსტრუქტორით, მკვდარ პლატიპუსს, და მეორეს პარამეტრებით, უკვე დაბადებულს და ცოტათი წამოზრდილსაც
	MyPlat.hatch('v'); //გამოვჩეკოთ
	MyPlat.age_me(1.5);
	MyPlat.setMutant(true);
	MyPlat.setWeight(2);
	Platypus winer = MyPlat.fight(Other);
	cout << "winner!" << endl;
	winer.printInfo();
	Platypus* loss; // მინდა რომ დავაპოინტერო წაგებული პლატიპუსი, მერე მისი მონაცემები გავზარდო და ისევ ვაჩხუბო, რომ დაჩაგრული არ იყოს :)
	if (winer.getName() == MyPlat.getName()) loss = &Other;
	else loss = &MyPlat;
	loss->setMutant(true);
	loss->setWeight(5);
	loss->eat();
	loss->eat();
	loss->eat();
	loss->age_me(8);
	Platypus nextWiner = winer.fight(*loss);
	cout << "new winner!" << endl;
	nextWiner.printInfo();
}