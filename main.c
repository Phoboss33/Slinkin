#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct pd {
    char last_name[10];
    char name[10];
    char patronymic[10]; 
    char date[10];
    char gender;
    unsigned short id;  
    unsigned short id_child[5];
}people;

void FindOfBornInDate(struct pd people[], short count) {
    char dateOfBorn[10];
    printf("Введите дату рождения в формате dd/mm/yy слитно\n");
    fgets(dateOfBorn, sizeof(dateOfBorn), stdin);

    short len = strlen(dateOfBorn);
    dateOfBorn[len-1] = '\0';

    printf("В этот день родились:\n");
    for (size_t i = 0; i < count; i++) {
        if (strcmp(people[i].date, dateOfBorn) == 0) {
            printf("%s %s %s\n",people[i].last_name, people[i].name, people[i].patronymic); 
        }
    }
}

void FindParents(struct pd people[], short count) {
    short id_children = 0;
    printf("Введите номер удостоверения личности ребенка\n");
    scanf("%d", &id_children);

    if (id_children == 0)
        return;

    printf("Его родители:\n");
    for (size_t i = 0;i < count;i++) {
        for (size_t j = 0;j < 5;j++) {
            if (people[i].id_child[j] == id_children){
                printf("%s %s %s\n", people[i].last_name, people[i].name, people[i].patronymic);
            }
        }
    }
}

void FindAllNamesakes(struct pd people[], short count) {
    for (size_t i = 0;i < count;i++) {  
        for (size_t j = 0;j < count;j++) {
            if (strcmp(people[i].last_name,people[j].last_name) == 0 && i != j){
                printf("%s %s %s\n", people[i].last_name, people[i].name, people[i].patronymic);
                break;
            }
        }
    }
}

void FindWoman(struct pd people[], short count) {
    short id_man = 0;
    printf("Введите номер удостоверения личности мужчины\n");
    scanf("%d", &id_man);

    short temp = 0;
    for(size_t i = 0;i < count;i++)
        if (people[i].id == id_man && people[i].gender == 'M')
            temp = i;

    printf("Женщины имеющие общих детей:\n");
    for (size_t i = 0;i < count;i++) {
        for (size_t j = 0;j < 5;j++) {
            for (size_t k = 0;k < 5;k++) {
                if (people[temp].id_child[j] == people[i].id_child[k]
                && people[i].gender == 'F' && people[temp].id_child[j] != 0){
                    printf("%s\n", people[i].name);
                    break;
                }

            }
        }
    }
}

void FillStructArray(struct pd people[], short count) {
    for (size_t i = 0; i < count; i++) {
        printf("Введите фамилию для %d человека:\n", i);
        scanf("%s", people[i].last_name);

        printf("Введите имя для %d человека:\n", i);
        scanf("%s", people[i].name);

        printf("Введите отчество для %d человека:\n", i);
        scanf("%s", people[i].patronymic);

        printf("Введите дату рождения для %d человека (dd/mm/yy):\n", i);
        scanf("%s", people[i].date);

        printf("Введите пол для %d человека (M/F):\n", i);
        scanf(" %c", &people[i].gender);

        printf("Введите id для %d человека:\n", i);
        scanf("%d", &people[i].id);

        printf("Введите кол-во детей для %d человека:\n", i);
        unsigned int childrens = 0;
        scanf("%u", &childrens);
        //getchar(); 

        if (childrens > 0 && childrens <= 5) {
            for (size_t k = 0; k < childrens; k++) {
                printf("Введите id %d ребенка для %d человека:\n", k, i);
                scanf("%d", &people[i].id_child[k]);
            }
        }
    }
}

void PrintStructArray(struct pd people[],short count) {
    for (size_t i = 0; i < count; i++) {
        printf("========\n");
        printf("ФИО: %s %s %s\n", people[i].last_name, people[i].name, people[i].patronymic);
        printf("Дата рождения: %s\n", people[i].date);
        printf("Пол: %c\n", people[i].gender);
        printf("ID: %hu\n", people[i].id);
        printf("ID детей: ");
        for (size_t k = 0; k < 5; k++) {
            if (people[i].id_child[k] != 0) {
                printf("%hu ", people[i].id_child[k]);
            }
        }
        printf("\n");
    }
}

void ReadPeopleFromFile(const char* filename, struct pd* people, short count) {
    FILE *fp;
    fp = fopen("people.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (size_t i = 0;i < count;i++) {
        fscanf(fp, "%s %s %s %s %s %hu %hu %hu %hu %hu", 
                people[i].last_name, people[i].name, 
                people[i].patronymic, people[i].date, 
                &people[i].gender, &people[i].id, 
                &people[i].id_child[0], &people[i].id_child[1], 
                &people[i].id_child[2], &people[i].id_child[3]);
    }
    fclose(fp);
}

void ZeroFillStuct(struct pd people[], short count) {
    for (size_t i = 0; i < count; i++) {
        memset(&people[i], 0, sizeof(struct pd));
    }
}

int main() {
    printf("Введите кол-во человек\n");
    short count = 0;
    scanf("%d",&count);
    struct pd people[count];    
    ZeroFillStuct(people, count);

        printf("\nВыберете действие:\n1) Поиск по дате\n2) Поиск родителей\n");
        printf("3) Найти всех однофамильцев\n4) Поиск женщин с общ. детьми\n");
        printf("5) Заполнить структуры вручную.\n6) Вывести структуры\n");
        printf("7) Чтение из файла.\n");
    short select = 0; 
    do {


        printf("Введите (1-7, или 0 для выхода): ");
        scanf("%hd",&select);

        switch(select) {
            case 1:
                getchar(); 
                FindOfBornInDate(people, count);
                break;
            case 2:
                FindParents(people, count);
                break;
            case 3:
                FindAllNamesakes(people, count);
                break;
            case 4:
                FindWoman(people, count);
                break;
            case 5:
                FillStructArray(people, count);
                break;
            case 6: 
                PrintStructArray(people, count);
                break;
            case 7: 
                ReadPeopleFromFile("people.txt", people, count);
                break;
        }
    } while (select != 0);
 
}