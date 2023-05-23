//
//#include <iostream>
//#include "WeddingGuest.h"
//#include <cassert>
//#include <string>
//using namespace std;
//
//int main() {
//    // default constructor
//   WeddingGuest lal;
//    // For an empty list:
//   assert(lal.guestCount() == 0); // test size
//   assert(lal.noGuests()); // test empty
//   assert(!lal.crossGuestOff("Malik", "Monk")); // nothing to erase
//    //inviteGuest- add to empty list
//    WeddingGuest groomsmen;
//     groomsmen.inviteGuest ("Tony", "Ambrosio", 40);
//     groomsmen.inviteGuest ("Mike", "Wu", 43);
//     groomsmen.inviteGuest ("Robert", "Wells", 44);
//     groomsmen.inviteGuest ("Justin", "Sandobal", 37);
//     groomsmen.inviteGuest ("Nelson", "Villaluz", 38);
//     groomsmen.inviteGuest ("Long", "Le", 41);
//    //guestCount
//    for (int n = 0; n < groomsmen.guestCount(); n
//         ++)
//     {
//     string first;
//     string last;
//     int val;
//     groomsmen.verifyGuestOnTheList (n, first, last, val);  // verifyGuestOnTheList
//     cout << first << " " << last << " " << val << endl;
//     }
//    cout << endl;
//    //inviteGuest
//    groomsmen.inviteGuest ("Tony", "Aebrosio", 40);   // inviteGuest add to beginning
//    groomsmen.inviteGuest ("Jame", "Pu", 43);   // inviteGuest add to middle
//    groomsmen.inviteGuest ("Mike", "Wuu", 43);
//    groomsmen.inviteGuest ("Mike", "Wuu", 44);  // inviteGuest add to end
//
//    groomsmen.dump();
//    cout << groomsmen.noGuests() << endl;
//    cout << groomsmen.guestCount()<< endl;
//    //alterGuest
//    groomsmen.alterGuest("Tony", "Aebrosio", 16);  //alterGuest at beginning
//    groomsmen.alterGuest("Mike", "Wuu", 16);  // alterGuest at end
//    groomsmen.alterGuest("Justin", "Sandobal", 16);  // alterGuest at middle
//    groomsmen.dump();
//
//    cout << endl;
//    //inviteOrAlter- to empty list
//    WeddingGuest groomsmen2;
//     groomsmen2.inviteOrAlter ("Tony", "Ambrosio", 40);
//     groomsmen2.inviteOrAlter ("Mike", "Wu", 43);
//     groomsmen2.inviteOrAlter ("Robert", "Wells", 44);
//     groomsmen2.inviteOrAlter ("Justin", "Sandobal", 37);
//     groomsmen2.inviteOrAlter ("Nelson", "Villaluz", 38);
//     groomsmen2.inviteOrAlter ("Long", "Le", 41);
//
//    groomsmen2.inviteOrAlter ("Tony", "Aebrosio", 40); // inviteOrAlter invite at beginning
//    groomsmen2.inviteOrAlter ("Jame", "Pu", 43); // inviteOrAlter invite at end
//    groomsmen2.inviteOrAlter ("Mike", "Wuu", 43); // inviteOrAlter invite at middle
//
//    groomsmen2.dump();
//    cout << groomsmen2.noGuests() << endl;
//    cout << groomsmen2.guestCount()<< endl;
//
//    groomsmen2.inviteOrAlter("Tony", "Aebrosio", 16); // inviteOrAlter alter at beginning
//    //groomsmen2.inviteOrAlter("Mike", "Wuu", 16);
//    groomsmen2.alterGuest("Mike", "Wuu", 16); // inviteOrAlter alter at beginning
//    groomsmen2.inviteGuest("Mike", "Wuu", 16); // inviteOrAlter alter at beginning
//    groomsmen2.dump();
//    groomsmen2.inviteOrAlter("Justin", "Sandobal", 16);
//
//    cout << endl;
//    groomsmen2.crossGuestOff("Tony", "Aebrosio"); //crossGuestOff at beginning
//    groomsmen2.crossGuestOff("Justin", "Sandobal");//crossGuestOff in middle
//    groomsmen2.crossGuestOff("Mike", "Wuu"); //crossGuestOff at end
//    groomsmen2.dump();
//
//
//    WeddingGuest bridesmaids;
//     bridesmaids.inviteGuest("Serra", "Park", 39.5);
//     bridesmaids.inviteGuest("Saadia", "Parker", 37.5);
//     assert(!bridesmaids.invitedToTheWedding ("",""));
//     bridesmaids.inviteGuest("Patricia", "Kim", 39.0);
//     bridesmaids.inviteGuest("", "", 21.0);
//     bridesmaids.inviteGuest("Kristin", "Livingston", 38.0);
//     assert(bridesmaids.invitedToTheWedding ("", ""));
//     bridesmaids.crossGuestOff("Patricia", "Kim");
//     assert(bridesmaids.guestCount() == 4
//     && bridesmaids.invitedToTheWedding("Serra", "Park")
//     && bridesmaids.invitedToTheWedding ("Saadia", "Parker")
//     && bridesmaids.invitedToTheWedding ("Kristin", "Livingston")
//     && bridesmaids.invitedToTheWedding ("", ""));
//    //copy constructor
//    WeddingGuest groomsmen3;
//     groomsmen3.inviteGuest ("Tony", "Ambrosio", 40);
//     groomsmen3.inviteGuest ("Mike", "Wu", 43);
//     groomsmen3.inviteGuest ("Robert", "Wells", 44);
//     groomsmen3.inviteGuest ("Justin", "Sandobal", 37);
//     groomsmen3.inviteGuest ("Nelson", "Villaluz", 38);
//     groomsmen3.inviteGuest ("Long", "Le", 41);
//
//    WeddingGuest groomsmen4 = groomsmen3; // copy constructor
//    cout << endl;
//    groomsmen4.dump();
//
//    WeddingGuest groomsmen5;
//    WeddingGuest groomsmen6 = groomsmen5;
//    cout << endl;
//    groomsmen4.dump();
//    cout << endl;
//    cout << "end" << endl;
//
//    //odJoined no repeat name
//    WeddingGuest odOne;
//    odOne.inviteGuest("Anthony", "Davis", 3);
//    odOne.inviteGuest("Lebron", "James", 23);
//    odOne.inviteGuest("Malik", "Monk", 11);
//    WeddingGuest odTwo;
//    odTwo.inviteGuest("Lebron", "James", 23);
//    odTwo.inviteGuest("Russell", "Westbrook", 0);
//    WeddingGuest odJoined;
//    joinGuests(odOne, odTwo, odJoined);
//    odJoined.dump();
//    cout << endl;
//
//    //odJoined with repeat name
//    WeddingGuest odOne1;
//    odOne1.inviteGuest("Pete", "Best", 3);
//    odOne1.inviteGuest("John", "Lennon", 1);
//    odOne1.inviteGuest("Paul", "McCartney", 2);
//    WeddingGuest odTwo1;
//    odTwo1.inviteGuest("Pete", "Best", 6);
//    odTwo1.inviteGuest("George", "Harrison", 4);
//    odTwo1.inviteGuest("Ringo", "Starr", 5);
//    WeddingGuest odJoined1;
//    joinGuests(odOne1, odTwo1, odJoined1);
//    odJoined1.dump();
//    cout << endl;
//
//    //attestGuests with only last name *
//    WeddingGuest goBruins;
//    goBruins.inviteGuest("Cobey", "C", 35);
//    goBruins.inviteGuest("Dan", "H", 38);
//    goBruins.inviteGuest("Dan", "V", 44);
//    goBruins.inviteGuest("Dion", "V", 45);
//    WeddingGuest odResult;
//    attestGuests("Dan", "*", goBruins, odResult);
//    odResult.dump();
//    cout << endl;
//
//    // attestGuests with only first name *
//    WeddingGuest kardashians;
//    kardashians.inviteGuest("Caitlyn", "J", 71);
//    kardashians.inviteGuest("Khloe", "K", 37);
//    kardashians.inviteGuest("Kim", "K", 40);
//    kardashians.inviteGuest("Kanye", "W", 44);
//    WeddingGuest result;
//    attestGuests("*", "K", kardashians, result);
//    result.dump();
//    cout << endl;
//    // attestGuests with bpth first and last name *
//    attestGuests("*", "*", kardashians, result);
//    result.dump();
//    cout << endl;
//    // attestGuests with no matches in odOne
//    attestGuests("S", "*", kardashians, result);
//    result.dump();
//    cout << endl;
//    //attestGuests with aliasing
//    attestGuests("*", "K", kardashians, kardashians) ;
//    result.dump();
//    cout << endl;
//
//    return 0;
//}

#include "WeddingGuest.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
void test() {
 WeddingGuest eliteSingles;

 assert(eliteSingles.inviteGuest("Jackie", "S",
 "jackies@elitesingles.com"));
 assert(eliteSingles.inviteGuest("Mark", "P",
 "markp@elitesingles.com"));
 assert(eliteSingles.guestCount() == 2);
 string first, last, e;
 assert(eliteSingles.verifyGuestOnTheList(0, first, last, e)
 && e == "markp@elitesingles.com");
 assert(eliteSingles.verifyGuestOnTheList(1, first, last, e)
 && (first == "Jackie" && e == "jackies@elitesingles.com"));
 return;
}
int main() {
 test();
 cout << "Passed all tests" << endl;
 return 0;
}
