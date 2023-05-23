#include "WeddingGuest.h"
//#include <iostream> // for dump() cerr

//void WeddingGuest::dump() const{
//    Node *p;
//    p = head;
//    while (p != nullptr) {
//       std:: cerr << p->fName << " " << p->lName << " " << p->val << std::endl;
//        p = p->next;
//    }
//}

WeddingGuest::WeddingGuest(){
    head = nullptr;
    tail = nullptr;
}

WeddingGuest::~WeddingGuest(){
    Node *p;
    p = head;
    while (p!=nullptr){
        Node *n = p->next;
        delete p;
        p = n;
    }
}

WeddingGuest::WeddingGuest(const WeddingGuest& src){
    head = nullptr;
    Node *p = head;
    if (src.guestCount() == 0){
        head = nullptr;
        tail = nullptr;
        return;
    }
    else {
    for (int i = 0; i < src.guestCount(); i++){
        Node *n = new Node;
        if (i==0){
            head = n;
            n->prev = nullptr;
        }
        else {
            p->next = n;
            n->prev = p;
        }
        std::string first;
        std::string last;
        GuestType value;
        src.verifyGuestOnTheList (i, first, last, value);
        n->fName = first;
        n->lName = last;
        n->val = value;
        n->next = nullptr;
        p = n;
        if (i == guestCount() -1)
            tail = n;
    }
}
}

const WeddingGuest& WeddingGuest::operator=(const WeddingGuest& src){
    if (&src == this)
        return *this;
    
    Node *p;
    p = head;
    while (p!=nullptr){
        Node *n = p->next;
        delete p;
        p = n;
    }
    
    head = nullptr;
    Node *p2 = head;
    if (src.guestCount() == 0){
        head = nullptr;
        tail = nullptr;
        return *this;
    }
    else {
    for (int i = 0; i < src.guestCount(); i++){
        Node *n = new Node;
        if (i==0){
            head = n;
            n->prev = nullptr;
        }
        else {
            p2->next = n;
            n->prev = p2;
        }
        std::string first;
        std::string last;
        GuestType value;
        src.verifyGuestOnTheList (i, first, last, value);
        n->fName = first;
        n->lName = last;
        n->val = value;
        n->next = nullptr;
        p2 = n;
        if (i == guestCount() -1)
            tail = n;
    }
}
    return *this;
}

bool WeddingGuest::noGuests() const {
    if (head == nullptr)
        return true;
    return false;
}
   
int WeddingGuest::guestCount() const{
    Node *p;
    p = head;
    int count = 0;
    while (p!=nullptr){
        count ++;
        p = p->next;
    }
    return count;
}
   
bool WeddingGuest::inviteGuest(const std::string& firstName, const std::string&
                               lastName, const GuestType& value){
    if (head == nullptr){
        // add to front
        Node *p;
        p = new Node;
        p->fName = firstName;
        p->lName = lastName;
        p->val = value;
        p->next = head;
        p->prev = nullptr;
        head = p;
        tail = p;
    }
    
    else if ( lastName < head->lName ||
             ( (lastName == head->lName) && (firstName < head->fName))){
        //add to front
        Node *p;
        p = new Node;
        p->fName = firstName;
        p->lName = lastName;
        p->val = value;
        p->next = head;
        p->prev = nullptr;
        head->prev = p;
        head = p;
    }
    
    else if ( lastName > tail->lName ||
             (lastName == tail->lName && firstName > tail->fName ) ){
        // add to end
        Node *p = new Node;
        p->fName = firstName;
        p->lName = lastName;
        p->val = value;
        tail->next = p;
        p-> next = nullptr;
        p->prev = tail;
        tail = p;
    }
    
    else {
        // add to middle
        Node *p = head;
        while (p->next != nullptr){
            if (p->fName == firstName && p->lName == lastName){
                return false;
            }
            if (p->next->lName >lastName ||
                 ((p->next->lName == lastName) && (p->next->fName > firstName))){
                     break;
                 }
            p = p->next;
        }
        if (p->fName == firstName && p->lName == lastName){
            return false;
        }
        Node *latest = new Node;
        latest->fName = firstName;
        latest->lName = lastName;
        latest->val = value;
        latest->next = p->next;
        latest->prev = p;
        p->next = latest;
        latest->next->prev = latest;
    }
    return true;
}

   
bool WeddingGuest::alterGuest(const std::string& firstName, const std::string&
                              lastName, const GuestType & value){
    Node *p;
    p = head;
    while (p != nullptr) {
        if (p->fName == firstName &&  p->lName == lastName){
            p->val = value;
            return true;
        }
        p = p->next;
    }
    return false;
}
   
    bool WeddingGuest::inviteOrAlter(const std::string& firstName, const
                                     std::string& lastName, const GuestType& value){
        alterGuest(firstName, lastName, value);
        inviteGuest(firstName, lastName, value);
        return true;
    }
   
    bool WeddingGuest::crossGuestOff(const std::string& firstName, const
                                     std::string& lastName){
        Node *p;
        p = head;
        while (p!=nullptr){
            if (p->lName + p->fName == lastName +firstName){
                if (p != head && p != tail){
                    p->prev->next = p->next;
                    p->next->prev = p-> prev;
                } else if (p == head && p == tail){
                    head = nullptr;
                    tail = nullptr;
                } else if (p == head){
                    head = p->next;
                    p->next->prev = nullptr;
                } else if (p == tail) {
                    tail = p->prev;
                    p->prev->next = nullptr;
                }
                delete p;
                return true;
            }
            p = p->next;
        }
        return false;
    }
   
   
    bool WeddingGuest::invitedToTheWedding(const std::string& firstName, const
                                           std::string& lastName) const{
        Node *p = head;
        while (p != nullptr){
            if (p->fName == firstName && p->lName == lastName){
                return true;}
                p = p->next;
        }
        return false;
    }
   
    bool WeddingGuest::matchInvitedGuest(const std::string& firstName, const
                           std::string& lastName, GuestType& value) const{
        Node *p = head;
        while (p != nullptr){
            if (p->fName == firstName && p->lName == lastName){
                value = p->val;
                return true;}
                p = p->next;
        }
        return false;
    }
   
    bool WeddingGuest::verifyGuestOnTheList(int i, std::string& firstName,
                              std::string& lastName, GuestType & value) const{
        if (i < 0 || i > guestCount() -1 || guestCount() == 0){
            return false;
        }
        Node *p = head;
        for (int count = 0; count <guestCount(); count++){
            if (count == i){
                firstName = p->fName;
                lastName = p->lName;
                value = p-> val;
                return true;
            }
            p = p->next;
        }
        return true;
    }

void WeddingGuest::swapWeddingGuests(WeddingGuest& other){
    WeddingGuest temp = other;
    other = *this;
    *this = temp;
}

bool joinGuests(const WeddingGuest & odOne,
 const WeddingGuest & odTwo,
                WeddingGuest & odJoined){
    WeddingGuest odOneTemp = odOne;
    WeddingGuest odTwoTemp = odTwo;
    int flag = 0;
    odJoined = odOne;
    for (int i = 0; i < odTwoTemp.guestCount(); i++){
        std::string first;
        std::string last;
        GuestType value;
        odTwoTemp.verifyGuestOnTheList (i, first, last, value);
        if (odJoined.invitedToTheWedding(first, last)) {
            GuestType valueJoin;
            odJoined.matchInvitedGuest (first, last, valueJoin);
            if (value!=valueJoin){
                odJoined.crossGuestOff(first, last);
                flag = 1;
            }
        }
        else {
            odJoined.inviteGuest(first, last, value);
        }
    }
            if (flag == 1)
            return false;
            
            return true;
}

void attestGuests (const std::string& fsearch,
 const std::string& lsearch,
 const WeddingGuest& odOne,
                   WeddingGuest& odResult){
    WeddingGuest odOneTemp = odOne;
    odResult = odOne;
    int num = odOneTemp.guestCount();
    if (fsearch == "*" && lsearch == "*" )
        return;
    for (int i = 0; i< num; i++){
        std::string first;
        std::string last;
        GuestType value;
        odOneTemp.verifyGuestOnTheList (i, first, last, value);
        if (fsearch != "*" && lsearch != "*"){
            if (first==fsearch && last==lsearch){
                continue;
            } else {
            odResult.crossGuestOff(first, last);
            }
        }
       else if (lsearch == "*" && fsearch!= "*"){
           if (first==fsearch){
               continue;
           } else {
           odResult.crossGuestOff(first, last);
           }
        }
       else if (fsearch == "*" && lsearch != "*"){
           if (last==lsearch){
               continue;
           } else {
           odResult.crossGuestOff(first, last);
           }
        }
    }
}
