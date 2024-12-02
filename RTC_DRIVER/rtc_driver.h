#ifndef RTC_DRIVER_H
#define RTC_DRIVER_H

#include <stdint.h>

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    uint8_t weekday;
} rtc_time_t;

int rtc_init(void);
int rtc_set_time(rtc_time_t *time);
int rtc_get_time(rtc_time_t *time);
int rtc_set_alarm(rtc_time_t *alarm_time);
void rtc_enable_alarm(void);
void rtc_disable_alarm(void);
int rtc_check_alarm(void);

#endif /* RTC_DRIVER_H */
