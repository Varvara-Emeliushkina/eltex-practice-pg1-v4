#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int main() {
    FILE *f = fopen("phonebook.dat", "rb");
    if (!f) {
        printf("Файл не найден\n");
        return 1;
    }
    
    int count;
    unsigned int nextUid;
    
    fread(&count, sizeof(int), 1, f);
    fread(&nextUid, sizeof(unsigned int), 1, f);
    
    printf("Контактов: %d, nextUid: %d\n\n", count, nextUid);
    
    for (int i = 0; i < count; i++) {
        Contact c;
        fread(&c, sizeof(Contact), 1, f);
        
        printf(" Контакт %d \n", i+1);
        printf("UID: %u\n", c.uid);
        printf("Имя: %s\n", c.firstName);
        printf("Фамилия: %s\n", c.lastName);
        printf("Место работы: %s\n", c.workplace);
        printf("Должность: %s\n", c.position);
        
        printf("Телефоны: ");
        for (int j = 0; j < c.phoneCount; j++) {
            printf("%s ", c.phones[j]);
        }
        printf("\n");
        
        printf("Emails: ");
        for (int j = 0; j < c.emailCount; j++) {
            printf("%s ", c.emails[j]);
        }
        printf("\n");
        
        printf("Соцсети:\n");
        for (int j = 0; j < c.socialCount; j++) {
            printf("  %s: %s\n", c.socials[j].platform, c.socials[j].profile);
        }
        printf("\n");
    }
    
    fclose(f);
    return 0;
}