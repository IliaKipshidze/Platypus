#include <iostream>
#include <ctime>
#include <random>
using namespace std;
#include "MyPlatypus.h"

int rando(int a, int b) { //აგენერირებს რანდომულ რიცხვებს გადმოცემულ ორ რიცხვს შორის
	default_random_engine dom(time(NULL));
	uniform_int_distribution <int> ran(a, b);  
	return ran(dom);
}

bool percentage(int k) {  //როდესაც ვამბობთ რომ რაღაცის შანსი არის 20 პროცენტი ამ შემთხვევაში ჩვენ შეგვიძლია ამ ფუნქციას გადმოვცეთ 20 და თუ მის მიერ
	                     //რენდომულად დაგენერირებული რიცხვი იქნება 20-ზე ნაკლები ან არა, ეს იქნება 20%-იანი ალბათობა
	default_random_engine dr(time(NULL));
	uniform_int_distribution <int> di(0, 99);
	return di(dr) < k;
}

Platypus::Platypus() : weight(0.0), age(0), name('0'), gender('0'), alive(false), mutant(false) {}
Platypus::Platypus(float w, short a, char n, char g) {
		weight = w;
		age = a; //აქ შეგვეძლო ასაკი 0 დაგვეწერა მაგრამ ჩავთვალე რომ ჩვენ უნდა შეგვეძლოს ცოცხალი და გაზრდილი იხვნისკარტას კლასის შექმნაც და ამიტომ არ გავუტოლე 0-ს
		name = n;
		gender = g;
		alive = true;
		mutant = false;
}
void Platypus::setMutant(bool m) {
		if (alive == false)cout << "mkvdari ixvniskarta ver gaxdeba mutanti! " << endl;
		else mutant = m;
}
void Platypus::setAlive(bool a) {
		if ((alive == false) && (a == true))cout << "shen shegidzlia mokla cocxali ixvniskarta magram ver gaacocxleb mkvdars!" << endl;
		else alive = a;   //უფრო რეალობასთან ახლოს რომ იყოს მომხმარებელს არ ვაძლევ მკვდარი იხვნისკარტას გაცოცხლების უფლებას
}
void Platypus::setGender(char g) {
		if (g == 'm' || g == 'f') gender = g; //ეს შემოწმება არის ინფუთის ვალიდაციისთვის
		else cout << "genderma sheidzleba miigos mxolod 'm' an 'f' mnishvneloba" << endl;

}
void Platypus::setName(char n) {
		if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122)) name = n;  //ესეც არის ინფუთის ვალიდაცია, მომხმარებელს არ ვაძლევ ლათინური
		                                                             //სიმბოლოების გარდა სხვა რამის დარქმევის უფლებას
		else cout << "ixvniskartastvis mxolod latinuri asos darqmevaa shesadzlebeli!" << endl;
}
void Platypus::setWeight(float w) {
		if (w <= 0) { //0-ზე ნაკლები წონა არასწორი ინფუთია და შესაბამისად მომხმარებელს არ ვაძლევ მისი შემოყვანის უფლებას
			cout << "wona ver iqneba uaryofiti, scadet misi tavidan shemotana:" << endl;
			float in;   //შემოყავს ახალი წონა
			cin >> in;
			setWeight(in); //და ახალი წონისთვის ვიძახებ ამავე ფუნქციას
		}
		else if (w >= 10) { //მომხმარებელს ვატყობინებ რომ თუ 10-ზე მეტ წონას მიანიჭებს, მისი იხვნისკარტა მოკვდება
			cout << "shegaxsenebt rom tu ixvniskartas amxela wonas mianichebt is mokvdeba! shemoitanet 1 tu gsurt gagrdzeleba da msuqani"
				"ixvniskartas mokvla, tuarada shemoitanet 2 da scadet tavidan:" << endl;
			int i = 0;
			while (i == 0) {
				float in;  //სჰემოყავს არჩევანი, უნდა გაგრძელება თუ არა
				cin >> in;
				if (in == 1) { //თუ გადაწყვეტს რომ მიანიჭოს 10-ზე მეტი და მოკლას, მივანიჭებ, მოვკლავ და აქვე დასრულდება ფუნქცია
					i++;
					weight = w;
					alive = false;
					return;
				}
				else if (in == 2) { //თუ უნდა ახალი წონის შემოყვანა
					i++; //ვზრდი i-ს რომ ვაილ ციკლში აღარ შევიდეს, იმიტომ რომ აღარ მჭირდება
					cout << "shemoitane axali wona: " << endl;
					float in;
					cin >> in;   //შემოვაყვანინებ
					setWeight(in); //და ახალი წონისთვის ვიძახებ ამავე ფუნქციას
				}
				else cout << "unda shemoitanot mxolod 1 an 2:" << endl; //თუ ამ არჩევანშიც არასწორი ინფუთი შემოიყვანა, გამოვუტან ამ შეტყობინებას,
				//არ ვზრდი i-ს, რაც იმას ნიშნავს რომ ვაილ ციკლი ისევ დატრიალდება ანუ თავიდან მოთხოვს არჩევანის შემოყვანას
			}
		}
		else weight = w; //თუ ინფუთ ვალიდაციაში ყველაფერი წესრიგშია პირდაპირ მივანიჭევ ახალ წონას
}
   //მომდევნო 7 ფუნქცია კონსტია რადგან ისინი ჩემი კლასის ველებს არ ცვლიან
bool Platypus::isMutant() const {   
		return mutant;
}
bool Platypus::isAlive()const {
		return alive;
}
char Platypus::getGender() const {
		return gender;
}
char Platypus::getName() const {
		return name;
}
short Platypus::getAge() const {
		return age;
}
float Platypus::getWeight() const {
		return weight;
}
void Platypus::printInfo() const {
	cout << "==================================================" << endl;
		cout << "Information about your Platypus:" << endl;
		if (alive == true) {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Gender: " << gender << endl;
			cout << "weight: " << weight << endl;
			cout << "Mutant: " << boolalpha << mutant << endl;
		}
		else {
			cout << "tqveni ixvniskarta mkvdaria :(" << endl;
		}
	cout << "==================================================" << endl;
}
void Platypus::age_me(short ag) {
		if (alive == true) { //თუ ცოცხალი არ არის ასაკს ვერ შეუცვლის
			age = ag;
			if (percentage(2)) mutant = true; //არის ორი პროცენტი იმისა რომ გახდეს მუტანტი
			if (percentage(weight * 10)) alive = false; //წონაზე 10-ჯერ დიდი პროცენტი არის იმისა რომ მოკვდეს
		}
		else cout << "tqven idzaxebt age_me() funqcias mkvdari ixvniskartastvis romelsac asakis momateba ar sheudzlia!" << endl;
}
void Platypus::eat() {
		if (alive == true) { //თუ ცოცხალი არაა, ვერ შეჭამს
			weight = weight + weight * rando(1, 50) / 1000;  //რენდომულად მოიმატებს რაღაც წონას
		} 
		else cout << "tqven idzaxebt eat() funqcias mkvdari ixvniskartastvis, romelsac chama ar sheudzlia!" << endl;
}

Platypus& Platypus::fight(Platypus& other_platypus) {
		if ((weight / other_platypus.getWeight()) * 50. > rando(1, 100)) return *this;
		return other_platypus; //აბრუნებს გამარჯვებულ პლატიპუსს
}
void Platypus::hatch(char n) {
	if (alive == false) { //პლატიპუსი უნდა იყოს მკვდარი და შემდეგ გამოიჩეკოს (მაგ. უპარამეტრო კონსტრუქტორით შექმნილი), წინააღმდეგ შემთხვევაში ცოცხალი პლატიპუსის გამოჩეკვა არ იქნება აზრობრივი
		alive = true;  //ახალდაბადებული პლატიპუსი უნდა იყოს ცოცხალი
		mutant = false; //არ უნდა იყოს მუტანტი
		age = 0; //ასაკი უნდა ქონდეს 0
		percentage(50) ? gender = 'm' : gender = 'f'; //ერთნაირი ალბათობაა იმისა რომ იყოს მამრი ან მდედრი
		name = n; //სახელი უნდა დაარქვას მომხმარებელმა
		weight = rando(1, 10) / 10;  //წონა რანდომულად
	}
	else cout << "hatch() funqciis gamodzaxeba ar sheidzleba cocxali ixvniskartastvis, radgan is xeltavidan vegar gamoichekeba" << endl;
}
