#include <stdio.h> 
#include <stdlib.h>

#include <time.h>
#include <string.h>

void calendar(int year, int month, int curday, int curmonth, int curyear) {
	struct tm time = {0};
	time.tm_year = year - 1900;
	time.tm_mon = month - 1;
	time.tm_mday = 1;
	mktime(&time);
	
	printf("Month: %d.%d (Current month: %d.%d)", month, year, curmonth + 1, curyear + 1900); 
    printf("\nMond Tues Wedn Thur Frid Satr Sund\n");

    int day_check = time.tm_wday - 1;
    if(day_check < 0) day_check = 6;

    for(int i = 0; i < day_check; i++) printf("     "); // Filling days which are not from this month.

    while( time.tm_mon == (month - 1) ) {
        int day_check = time.tm_wday - 1;
        if(day_check < 0) day_check = 6;
        
        // Marks the current day if its actually current month and year.
        if(time.tm_mday == curday && time.tm_year == curyear) {
        	if(time.tm_mon == curmonth) printf("[%2d] ", time.tm_mday);
        	else printf("%3d  ", time.tm_mday);        	
		} else {
			printf("%3d  ", time.tm_mday);
		}

        if(day_check == 6) printf("\n");

        time.tm_mday++;
        mktime(&time);
    }
    
    printf("\n");
}

int main() {
	while(1) {
		char msg[11]; 
	    printf("Type the date you want.\nAvailable formats:\n 1. yyyy.mm.dd\n 2. yyyy.mm\n 3. yyyy\n 4. now\nInput: "); 
	    scanf("%s", msg);
	
		printf("\n");
		
		// Adding time right after user choice.
		time_t now = time(NULL); 
	    struct tm* tnow = localtime(&now);
	    	
	    // For calendar.
	    int curday = tnow->tm_mday;
	    int curmonth = tnow->tm_mon;
	    int curyear = tnow->tm_year;
		
	    if(msg[0] == 'n') {
	    	// Shows current time.
	    	printf("Local time and date: %s\n", asctime(tnow));
		} else {
			int day = -1, year = -1, month = -1; 
	        sscanf(msg, "%d.%d.%d", &year, &month, &day); 
	        
	        if(day > -1) {
	        	// Shows the day of the week.
	        	struct tm curtime = {0};
	            curtime.tm_year = year - 1900;
	            curtime.tm_mon = month - 1;
	            curtime.tm_mday = day;
	            mktime(&curtime);
	            
	            char week_day[12];
	            switch(curtime.tm_wday) {
	            	case 1: strcpy(week_day, "Monday");
						break;
	            	case 2: strcpy(week_day, "Tuesday");
						break;
	            	case 3: strcpy(week_day, "Wednesday");
						break;
	            	case 4: strcpy(week_day, "Thursday");
						break;
	            	case 5: strcpy(week_day, "Friday");
						break;
	            	case 6:	strcpy(week_day, "Saturday");
						break;
					default: strcpy(week_day, "Sunday");
						break;
				}
				
	            printf("%d.%d.%d - %s\n\n", day, month, year, week_day);
			} else if(month > -1) {
				// Shows calendar for this month.
				calendar(year, month, curday, curmonth, curyear);
				printf("\n");
			} else {
				// Shows calendar for the whole year.
				for(int i = 1; i < 13; i++) {
					calendar(year, i, curday, curmonth, curyear);
					printf("\n");
				}
			}
		}
	}
}
