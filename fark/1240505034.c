#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini tutacak struct
struct DateTime {
    int year, month, day, hour, minute, second;
};

// Zaman� temsil etmek i�in union
union EpochTime {
    time_t epoch;
};

// Kullan�c�n�n girdi�i tarihi epoch zamana �eviren fonksiyon
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = dt.year - 1900;
    timeStruct.tm_mon = dt.month - 1;
    timeStruct.tm_mday = dt.day;
    timeStruct.tm_hour = dt.hour;
    timeStruct.tm_min = dt.minute;
    timeStruct.tm_sec = dt.second;
    return mktime(&timeStruct);
}

int main() {
    struct DateTime dt1, dt2;
    union EpochTime e1, e2;
    
    // Kullan�c�dan ilk tarih bilgisini alma
    printf("Birinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);
    
    // Kullan�c�dan ikinci tarih bilgisini alma
    printf("Ikinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);
    
    // Epoch zamanlar�na �evirme
    e1.epoch = convertToEpoch(dt1);
    e2.epoch = convertToEpoch(dt2);
    
    // Zaman fark�n� hesaplama
    double diff = difftime(e2.epoch, e1.epoch);
    
    // Sonu�lar� ekrana yazd�rma
    printf("Epoch zamanlar: \n");
    printf("Ilk tarih Epoch: %ld\n", (long)e1.epoch);
    printf("Ikinci tarih Epoch: %ld\n", (long)e2.epoch);
    printf("Iki tarih arasindaki fark: %.0f saniye\n", diff);
    
    // Epoch zaman�n� a��klama
    printf("\nEpoch (Unix zamani), 1 Ocak 1970 00:00:00 UTC zamanina dayali olarak saniye cinsinden hesaplanan bir zamandir.\n");
    
    return 0;
}

