#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct pd {
    char last_name[10];
    char name[10];
    char patronymic[10]; 
    char date[10];
    char gender;
    char id[10];  
    int count_children;
    int* id_child;
}people;

void FindOfBornInDate(struct pd people[], short count, char mas[]) {
    //har dateOfBorn[10];
    printf("Введите дату рождения в формате dd/mm/yy слитно\n");
    //fgets(dateOfBorn, sizeof(dateOfBorn), stdin);
    short len = strlen(mas);
    mas[len-1] = '\0';
    //mas[9] = '\0';
    printf("В этот день родились:\n");
    for (size_t i = 0; i < count; i++) {
        if (strcmp(people[i].date, mas) == 0) {
            printf("%s %s %s\n",people[i].last_name, people[i].name, people[i].patronymic); 
        }
    }
}

void FindParents(struct pd people[], short count, char id_children[]) {
	int temp = 0;
	short len = strlen(id_children);
    printf("%s", id_children);

    id_children[len-1] = '\0';
    
	for(int i = 0; i < count;i++) {
		if (strcmp(people[i].id, id_children) == 0) {
			temp = i;
			//printf("TEMP = %d\n\n", temp);
			//break;
		}
	}

    printf("Его родители:\n");
    for (size_t i = 0;i < count;i++) {
        for (size_t j = 0;j < people[i].count_children ;j++) {
            if (people[i].id_child[j] == temp){
                printf("%s %s %s\t%s\n", people[i].last_name, people[i].name, people[i].patronymic,people[i].id);
            }
        }
    }
}

char* ReturnFindParents(struct pd people[], short count, char id_children[]) {
	int temp = 0;
    //printf("{%d}", kek);
	//short len = strlen(id_children);
    //printf("%s ", id_children);
    //id_children[len-1] = '\0';
    
	for(int i = 0; i < count;i++) {
		if (strcmp(people[i].id, id_children) == 0) {
			temp = i;
		}
	}

    for (size_t i = 0;i < count;i++) {
        for (size_t j = 0;j < people[i].count_children ;j++) {
            if (people[i].id_child[j] == temp){
                return ReturnFindParents(people,count,people[i].id);
            }

        }
    }

    return id_children;
}

int* AllParents(struct pd people[], short count, char id_man[]) {
    //short len = strlen(id_man);
    //id_man[len-1] = '\0';
    short temp = 0;
    for (size_t i = 0; i < count; i++) {
        if (strcmp(people[i].id, id_man) == 0) {
            temp = i;
            break;
        }
    }

    int* arr = NULL;
    int index = 0;
    for (size_t i = 0; i < count; i++) {
        for (size_t j = 0; j < people[temp].count_children; j++) {
            for (size_t k = 0; k < people[i].count_children; k++) {
                if (people[temp].id_child[j] == people[i].id_child[k]) {
                    index++;
                    arr = realloc(arr, index * sizeof(int));
                    arr[index] = i;
                    arr[0] = index;
                    //printf("%s ", people[i].id);
                    break;
                }
            }
        }
    }
    //printf("[%d]", index);
    //printf("все у кого общие дети:\n");
    //for (size_t i = 0; i < index; i++) {
       //printf("%s\n", people[arr[i]].name);
    //}
    return arr;
}

void FindAllNamesakes(struct pd people[], short count) {
    //printf("%s", ReturnFindParents(people,count,people[3].id));
    //char* test;
    printf("=>%s}\n", ReturnFindParents(people,count,people[5].id));
    for (int i = 0;i < count;i++)
        for (int j = 0;j < count;j++) {
            if (strcmp(people[i].last_name, people[j].last_name) == 0 && i!=j) {
                int* arr_i = AllParents(people, count, ReturnFindParents(people,count,people[i].id));
                int* arr_j = AllParents(people, count, ReturnFindParents(people,count,people[j].id));
                //int length = _msize(arr) / sizeof(int);
                //printf("%d", length);
                int num = 0;
                for (int k = 1;k <= arr_i[0];k++)
                    for (int k1 = 1;k1 <= arr_j[0];k1++)
                        if (arr_i[k] == arr_j[k1]) {
                            num++;
                            break;
                        }
                if (num == 0) {
                    printf("[%s %s <> %s %s]\n",people[i].last_name,people[i].name,people[j].last_name,people[j].name);
                    break;
                }
            }

            /*if (strcmp(people[i].last_name, people[j].last_name) == 0 && i!=j) {
                if (strcmp(ReturnFindParents(people,count,people[i].id), ReturnFindParents(people,count,people[j].id)) != 0) {
                    printf("%s %s %s %s\n", people[i].last_name, people[i].name, people[i].patronymic, people[i].id);            //printf("%s\n",ReturnFindParents(people,count,people[i].id));
                    break;
                }
                //printf("%d",i);
            }*/
            //printf("%s ",ReturnFindParents(people,count,people[1].id));

        }
}

void FindWoman(struct pd people[], short count, char id_man[]) {
    //getchar();
        //printf("%s",id_man);
    short len = strlen(id_man);
    id_man[len-1] = '\0';
    //printf("%s",id_man);
    short temp = -1;
    for(size_t i = 0;i < count;i++)
        if (strcmp(people[i].id, id_man) == 0 && people[i].gender == 'M') {
            temp = i;
            //printf("%hu",temp);
        }


    printf("Женщины имеющие общих детей:\n");
    if (temp != -1)
    for (size_t i = 0;i < count;i++) {
        for (size_t j = 0;j < people[temp].count_children;j++) {
            //int num = 0;
            for (size_t k = 0;k < people[i].count_children;k++) {
                if (people[temp].id_child[j] == people[i].id_child[k]
                && people[i].gender == 'F'){
                    printf("%s %s %s\n",people[i].last_name, people[i].name, people[i].patronymic); 
                }
            }

        }
    }
}

void FillStructArray(struct pd people[], short count) {
    for (size_t i = 0; i < count; i++) {
        printf("Введите фамилию для %ld человека:\n", i);
        scanf("%s", people[i].last_name);

        printf("Введите имя для %ld человека:\n", i);
        scanf("%s", people[i].name);

        printf("Введите отчество для %ld человека:\n", i);
        scanf("%s", people[i].patronymic);

        printf("Введите дату рождения для %ld человека (dd/mm/yy):\n", i);
        scanf("%s", people[i].date);

        printf("Введите пол для %ld человека (M/F):\n", i);
        scanf(" %c\n", &people[i].gender);

        printf("Введите id для %ld человека:\n", i);
        //scanf("%s", &people[i].id);
        //getchar();
        //char id_man[10];
		fgets(people[i].id, sizeof(people[i].id), stdin);
		int len = 0; len = strlen(people[i].id);
		people[i].id[len-1] = '\0';
        printf("Введите кол-во детей для %ld человека:\n", i);
        unsigned int childrens = 0;
        scanf("%u", &childrens);
        //getchar(); 
		people[i].count_children = childrens;
		people[i].id_child = (int*)malloc(sizeof(int) * people[i].count_children);
        //if (people[i].count_children > 0 && childrens <= people[i].count_children) {
            for (size_t k = 0; k < people[i].count_children; k++) {
                printf("Введите id %ld ребенка для %ld человека:\n", k, i);
                scanf("%d", &people[i].id_child[k]);
            }
        //}
        
        
    }
}

void PrintStructArray(struct pd people[],short count) {
    for (size_t i = 0; i < count; i++) {
        printf("========\n");
        printf("num: %ld\n", i);
        printf("ФИО: %s %s %s\n", people[i].last_name, people[i].name, people[i].patronymic);
        printf("Дата рождения: %s\n", people[i].date);
        printf("Пол: %c\n", people[i].gender);
        printf("ID: %s\n", people[i].id);
        printf("ID детей: ");
        for (size_t k = 0; k < people[i].count_children; k++) {
            printf("%hu ", people[i].id_child[k]);
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
		fgets(people[i].last_name, 10, fp);
		fgets(people[i].name, 10, fp);
		fgets(people[i].patronymic, 10, fp);
		fgets(&people[i].gender, 1, fp);
		fgets(people[i].id, 10, fp);
		for(size_t j = 0;j < people[i].count_children;j++) {
			//fscanf("%d",people[i].id_child[j]);
			
		}
		/*fscanf(fp, "%s %s %s %s %s %hu %hu %hu %hu %hu", 
                people[i].last_name, people[i].name, 
                people[i].patronymic, people[i].date, 
                &people[i].gender, &people[i].id, 
                &people[i].id_child[0], &people[i].id_child[1], 
                &people[i].id_child[2], &people[i].id_child[3]);
		}*/
	}
    /*for (size_t i = 0;i < count;i++) {
        fscanf(fp, "%s %s %s %s %c %s %d", 
                people[i].last_name, people[i].name, 
                people[i].patronymic, people[i].date, 
                &people[i].gender, people[i].id, &people[i].count_children);
                for( size_t j = 0;j < 1;j++)
					fscanf(fp, "%d",&people[i].id_child[j]);
                //&people[i].id_child[0], &people[i].id_child[1], 
                //&people[i].id_child[2], &people[i].id_child[3]);
    }
    fclose(fp);*/
}

void ZeroFillStuct(struct pd people[], short count) {
    for (size_t i = 0; i < count; i++) {
        memset(&people[i], 0, sizeof(struct pd));
    }
}

int main() {
    printf("===Дата рождения===\n");
    char mas1[10];
    fgets(mas1, sizeof(mas1), stdin);
    //printf("%s",mas1);
    printf("===Введите ребенка===\n");
    
    char id_children[10];
    fgets(id_children, sizeof(id_children), stdin);

    printf("Введите номер удостоверения личности мужчины\n");

    char id_man[10];
    fgets(id_man, sizeof(id_man), stdin);
    


    printf("Введите кол-во человек\n");
    short count = 0;
	//int id_children = 0;
    scanf("%hd",&count);
    struct pd people[count];  
    printf("%d",count);
    
    //ZeroFillStuct(people, count);
    FillStructArray(people, count);
    PrintStructArray(people, count);
    
    printf("==Др==\n");
    //char mas[10];
    //getchar(); 
    //fgets(mas, sizeof(mas), stdin);
	FindOfBornInDate(people, count, mas1);
    FindParents(people, count, id_children);
    printf("==Однофамильцы==\n");
    FindAllNamesakes(people, count);
    printf("===Поиск женщин===\n");
    FindWoman(people, count, id_man);
    //printf("Введите номер удостоверения личности ребенка\n");

    //scanf("%d", &id_children);
	//FindParents(people, count, id_children);
        //printf("\nВыберете действие:\n1) Поиск по дате\n2) Поиск родителей\n");
        //printf("3) Найти всех однофамильцев\n4) Поиск женщин с общ. детьми\n");
        //printf("5) Заполнить структуры вручную.\n6) Вывести структуры\n");
        //printf("7) Чтение из файла.\n");
    //short select = 0; 
    /*do {


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
                //ReadPeopleFromFile("people.txt", people, count);
                break;
        }
    } while (select != 0);*/
 
}
