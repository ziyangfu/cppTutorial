#include <iostream>
using namespace std;

 class Mammal   // 哺乳动物
 {
 public:
 void FeedBabyMilk()
 {
 cout << "Mammal: Baby says glug!" << endl;
 }
  };

 class Reptile   // 爬虫类
 {
 public:
 void SpitVenom()  // 喷射毒液
 {
 cout << "Reptile: Shoo enemy! Spits venom!" << endl;
 }
 };

 class Bird
 {
 public:
 void LayEggs()
 {
 cout << "Bird: Laid my eggs, am lighter now!" << endl;
 }
 };

 class Platypus: public Mammal, public Bird, public Reptile
 {
 public:
 void Swim()
 {
 cout << "Platypus: Voila, I can swim!" << endl;
 }
 };

 int main()
 {
 Platypus realFreak;
 realFreak.LayEggs();  // Bird: Laid my eggs, am lighter now!
 realFreak.FeedBabyMilk();  // Mammal: Baby says glug!
realFreak.SpitVenom();  //  Reptile: Shoo enemy! Spits venom!
realFreak.Swim();  // Platypus: Voila, I can swim!
return 0;
 }