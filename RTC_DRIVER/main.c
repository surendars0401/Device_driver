#include <stdio.h>
#include "rtc_driver.h"

int main() {
    rtc_time_t current_time = {
        .seconds = 0,
        .minutes = 30,
        .hours = 14,
        .day = 1,
        .month = 1,
        .year = 2024,
        .weekday = 1
    };

    if (rtc_init() != 0) {
        printf("Failed to initialize RTC\n");
        return -1;
    }

    if (rtc_set_time(&current_time) != 0) {
        printf("Failed to set time\n");
        return -1;
    }

    rtc_time_t read_time;
    if (rtc_get_time(&read_time) != 0) {
        printf("Failed to read time\n");
        return -1;
    }

    rtc_time_t alarm_time = current_time;
    alarm_time.minutes += 5;
    if (alarm_time.minutes >= 60) {
        alarm_time.minutes -= 60;
        alarm_time.hours++;
    }

    if (rtc_set_alarm(&alarm_time) != 0) {
        printf("Failed to set alarm\n");
        return -1;
    }

    rtc_enable_alarm();

    if (rtc_check_alarm()) {
        printf("Alarm triggered!\n");
    }

    return 0;
}
