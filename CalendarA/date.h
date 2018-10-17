#ifndef DATE_H
#define DATE_H
#define <stdio.h>
#define "year.h"
#define "month.h"
#define "day.h"
#define "hour.h"
#define "meeting.h"

class Date{
public:
    //CTOR
    Date(const Year& year, const Month& month, const Day& day, const Hour& hour, const size_t minute);
    //DTOR
    Date();
    //copy CTOR - need? don't want to copy days...
    //mem func
    int addMeeting(const Meeting& meeting);
    int removeMeeting(const Meeting& meeting);
    //static func
    static void printMeetingsList();

private:
    //data mem
    const Year year;
    const Month month;
    const Day day;
    const Hour hour;
    const size_t minute;
    Meeting ** meetingsList;
    //assignment op
    Date& operator=(const Date& date);
};

#endif // DATE_H
