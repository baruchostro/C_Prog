#ifndef MEETING_H
#define MEETING_H
#include "date.h"
#include "contact.h"

class Meeting
{
public:
    //CTOR
    Meeting(const Date& startTime, const Date& endTime, const char * agenda, const Contact& ** invitees, const Contact& initiator);
    //DTOR
    ~Meeting();
    //copy CTOR
    Meeting(const Meeting& meeting);
    //mem func
    int setAgenda(const char * agenda);
    int addInvitee(const Contact& invitee);
    int removeInvitee(const Contact& invitee);
    //static func
    static void printMeeting();

private:
    //data mem
    const Date startTime;
    const Date endTime;
    char * agenda;
    Contact ** invitees;
    const Contact initiator;
    Room location;
    //mem func
    void createFrom(const char * agenda);
    Room findRoom(const Date& startTime, const Date& endTime);
    //assignment op
    Meeting& operator=(const Meeting& meeting);
};

#endif // MEETING_H
