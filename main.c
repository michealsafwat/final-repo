#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Team Members : Khaled Khalifa - Mostafa Gamal - Micheal Safwat

struct student
{

    char name[50];
    int ID;
    int db[3];
    int score;
};
struct student a[];
int xarr;      // input from user to select whether to create students with random data or enter the data from keybaord
char yarr;     // input from user to select where to insert
int posarr;     // holds the index to insert to
int Narr;          //Number of students
clock_t ss;   //  holds the time of execution at a certain moment
struct student *ptr, *first;

void insert_begin();
void input_data();
void insert();
void insert_last();

// array functions
// function to insert data at the beginning of the array
void insert_begin()
{
    struct student s;           // this structure will hold the data that the user will input
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase one on the number of students then allocate memory slots for the new number of students pointed at by first
    Narr++;
    first = (struct student *)realloc(first, Narr * sizeof(struct student));
   // shift each element in the array to the right and add the new inserted student at the beginning of the array
    for (int i = Narr; i > 0; i--)
        *(first + i) = *(first + i - 1);
    *first = s;
    ss = clock() - ss;      // calculate the total time in ticks of the insertion process
}

// function that inserts data at any position in the array
void insert()
{
    printf("Enter position of insertion: ");
    scanf("%d", &posarr);
    struct student s;
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase the number of students by one then allocate memory for the new number of students
    Narr++;
    first = (struct student *)realloc(first, Narr * sizeof(struct student));
    // shift the elements after the required position
    for (int i = Narr - 1; i > 0; i--)
    {
        if (i == posarr)
            break;
        first[i] = first[i - 1];
    }
    first[posarr] = s;     // insert at the required position after shifting the other elements
    ss = clock() - ss;        // calculate the total time in ticks of the insertion process
}

// function to insert data at last position of the array
void insert_last()
{

    struct student s;       // this structure will hold the data that the user will input
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase the number of students by one then allocate memory for the new number of students
    Narr++;
    first = (struct student *)realloc(first, Narr * sizeof(struct student));
    *(first + Narr - 1) = s;           // insert the student's data at the last position
    ss = clock() - ss;              // calculate the total time in ticks of the insertion process
}

// displays the students of the array
void disp(struct student *p)
{
    for (int i = 0; i < Narr; i++)
    {
        printf("\nID is %d\n", p->ID);
        printf("score is %d\n", p->score);
        printf("name is %s\n", p->name);
        printf("DB is %d %d %d\n", p->db[0], p->db[1], p->db[2]);
        p++;
    }
}

// function that takes input from the user to indicate whether to create many nodes with trash data or the user wants to input the students' data manually
void input_data()
{
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d", &xarr);
    printf("\nEnter the number of students: ");
    scanf("%d", &Narr);
    ptr = (struct student *)calloc(Narr, sizeof(struct student));      //allocate N number of slots to hold students data
    first = ptr;
    if (xll == 1)     // if the user wants to enter the students' data manually
    {
        for (int i = 0; i < Narr; i++)
        {
            printf("Enter the student name:");
            getchar();
            scanf("%50[^\n]s", ptr->name);
            getchar();
            printf("\nEnter the ID of student:");
            scanf("%d", &ptr->ID);
            printf("\nEnter the student score:");
            scanf("%d", &ptr->score);
            printf("\nEnter the student date of birth(day/month/year):");
            scanf("%d%d%d", &ptr->db[0], &ptr->db[1], &ptr->db[2]);
            ptr++;
        }
    }

    else                // if user wants to insert many students without inputting data manually
    {
        //insert a students with trash data to an array pointed to by ptr
        struct student s;
        for (int i = 0; i < Narr; i++)
        {
            *ptr = s;
            ptr++;
        }
    }

    // ask the user for the position of insertion
    printf("To insert a student at the first position press 0\n");
    printf("To insert a student at the last position press 1 \n");
    printf("To insert a student at any index position press 2 \n");
    getchar();
    scanf("%d", &yarr);
    if (yarr == 0)
        insert_begin();
    else if (yarr == 1)
        insert_last();
    else if (yarr == 2)
        insert();
}


void menu()
{
    char m;
printf("To use a linked list press 1:\n");
printf("To use an array press 2:\n");

scanf("%d", &m);
if (m==1){

    input_datall();
    createll();
    Display_LL(head);
    printf("\nTime taken by the operation: %.12lf sec\n", (double)sec / CLOCKS_PER_SEC);    // calculates time in seconds
    printf("Size taken is %ld\n",sizeof(struct student)*(Nll+1)+16+8*(Nll+1));       // calculates size taken  which is the size of each node plus head and tail pointers
}
else{



    input_data();
    disp(first);
    printf("\nTime taken by the operation: %.12lf sec\n", (double)ss / CLOCKS_PER_SEC);           // calculates time of insertion in seconds
    printf("Size taken is %ld bytes\n",sizeof(struct student)*Narr);  // calculates the size taken by the array
}
}


int main()
{
    printf("********WELCOME********\n");
    menu();
    return 0;
}
