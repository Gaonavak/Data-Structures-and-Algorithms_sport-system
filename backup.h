#ifndef BACKUP_C
#define BACKUP_C
#include "List.h"
#include <stdbool.h>

void writeEvent2Bak(List_project p);
List_project restoreEvent();
void writeAthlete2Bak(List_people p);
List_people restoreAthlete();
bool hasEventBaK();
bool hasAthleteBak();
int getEventLen(List_project p);
int getAthleteLen(List_people p);
bool hasBak();
void  restoreGrade(List_people human,List_grade *mark,List_project event);

#endif