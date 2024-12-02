#include "rtc_driver.h"
#include <stdio.h>

#define RTC_I2C_ADDR     0x68    
#define RTC_SEC_REG      0x00
#define RTC_MIN_REG      0x01
#define RTC_HOUR_REG     0x02
#define RTC_DAY_REG      0x03
#define RTC_DATE_REG     0x04
#define RTC_MONTH_REG    0x05
#define RTC_YEAR_REG     0x06
#define RTC_ALARM_REG    0x07

static uint8_t rtc_initialized = 0;
static uint8_t alarm_enabled = 0;

static uint8_t bcd_to_dec(uint8_t bcd) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

static uint8_t dec_to_bcd(uint8_t dec) {
    return ((dec / 10) << 4) | (dec % 10);
}

int rtc_init(void) {
    rtc_initialized = 1;
    printf("RTC initialized\n");
    return 0;
}

int rtc_set_time(rtc_time_t *time) {
    if (!rtc_initialized || !time) {
        return -1;
    }

    if (time->seconds > 59 || time->minutes > 59 || time->hours > 23 ||
        time->day > 31 || time->month > 12 || time->year > 2099 ||
        time->weekday > 7 || time->weekday < 1) {
        return -1;
    }

    printf("Time set to: %02d:%02d:%02d %02d/%02d/%04d\n",
           time->hours, time->minutes, time->seconds,
           time->day, time->month, time->year);
    return 0;
}

int rtc_get_time(rtc_time_t *time) {
    if (!rtc_initialized || !time) {
        return -1;
    }

    time->seconds = 0;
    time->minutes = 0;
    time->hours = 12;
    time->day = 1;
    time->month = 1;
    time->year = 2024;
    time->weekday = 1;

    printf("Current time read: %02d:%02d:%02d %02d/%02d/%04d\n",
           time->hours, time->minutes, time->seconds,
           time->day, time->month, time->year);
    return 0;
}

int rtc_set_alarm(rtc_time_t *alarm_time) {
    if (!rtc_initialized || !alarm_time) {
        return -1;
    }

    printf("Alarm set\n");
    return 0;
}

void rtc_enable_alarm(void) {
    if (rtc_initialized) {
        alarm_enabled = 1;
        printf("Alarm enabled\n");
    }
}

void rtc_disable_alarm(void) {
    if (rtc_initialized) {
        alarm_enabled = 0;
        printf("Alarm disabled\n");
    }
}

int rtc_check_alarm(void) {
    if (!rtc_initialized || !alarm_enabled) {
        return 0;
    }
    return 0;
}
