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


// creating a structure that represents a node
struct Node
{
    struct student data;
    struct Node *next;
};

// creating and initializing head and tail pointers to Null
struct Node *head = NULL;
struct Node *tail = NULL;


int xll;  // input from user to select whether to create students with random data or enter the data from keybaord
int posll;  // holds the index to insert to
int Nll; //Number of students in the array
struct student *all;  // pointer to an array that holds student's data to put in nodes afterwards
char yll;  // input from user to select where to insert
clock_t sec;//  holds the time of execution at a certain moment


struct student a[];
int xarr;      // input from user to select whether to create students with random data or enter the data from keybaord
char yarr;     // input from user to select where to insert
int posarr;     // holds the index to insert to
int Narr;          //Number of students
clock_t ss;   //  holds the time of execution at a certain moment
struct student *ptr, *first;

void insertll();
void insert_head();
void insert_lastll();
void input_datall();
void createll();
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


// function to insert a node at the first position of the LL which will now be the head node
void insert_head()
{
    struct student s;                   // this structure will hold the data that the user will input
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
    sec = clock();      // calculate the time in ticks at the start of the insertion process

    if(Nll==0){           // if the number of students to create is zero then the inserted node will be the only node in the LL

    // creating a node and whose data will be the data stored from the user in the structure s and this node's next pointer points to NULL
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = NULL;
    head = t;
    sec = clock() - sec;        // calculate the total time in ticks of the insertion process
    }

    // if the number of students to be created is not zero then the inserted node at the beginning will point to the head then it will be the head
    else {
        struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = head;
    head = t;
    sec = clock() - sec;            // calculate the total time in ticks of the insertion process


    }
}


// function that inserts a node at a position in the middle(any index) of the LL
void insertll()
{
    // take data from user
    printf("Enter position of insertion: ");
    scanf("%d", &posll);
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

    sec = clock();              // calculate the time in ticks at the start of the insertion process

    struct Node *t, *p;     // t pointer to create node with and p pointer to traverse to position of insertion
    p = head;               // p will point to first node then moves till it reaches the position
    for (int i = 0; i < posll - 1; i++)
        p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));         // creating a node whose data is the inserted student and its next pointer points at p's next
    t->data = s;
    t->next = p->next;
    p->next = t;                        // now p's next points at t so insertion at the required position is done
    sec = clock() - sec;                // calculate the total time in ticks of the insertion process
}



// function that inserts a node at the end of the LL
void insert_lastll()
{
    // take the data from the user and store it in the structure
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

    sec = clock();          // calculate the time in ticks at the start of the insertion process

    struct Node *t;         // create a node whose data is the inserted student and its next points to NULL
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = NULL;
    tail->next = t;         // tail's next will point to the new created node then tail will point to that node so it's the last one
    tail = t;
    sec = clock() - sec;            // calculate the total time in ticks of the insertion process
}


// function that takes input from the user to indicate whether to create many nodes with trash data or the user wants to input the students' data manually
void input_datall()
{
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d", &xll);
    printf("\nEnter the number of students: ");
    scanf("%d", &Nll);

    all = (struct student *)malloc(Nll * sizeof(struct student));  // pointer that allocates memory for N number of students to hold their data
    if (xll == 1)         // if the user wants to enter the students' data manually
    {
        for (int i = 0; i < Nll; i++)
        {
            printf("\nEnter the student name:");
            getchar();
            scanf("%50[^\n]s", all[i].name);
            getchar();
            printf("\nEnter the ID of student:");
            scanf("%d", &all[i].ID);
            printf("\nEnter the student score:");
            scanf("%d", &all[i].score);
            printf("\nEnter the student date of birth(day/month/year):");
            scanf("%d%d%d", &all[i].db[0], &all[i].db[1], &all[i].db[2]);
        }
    }
    else
        return; // call create() function to start creating students with trash data
}


// function that enables the user to create large number of nodes without the need to enter each student's data manually
void createll()
{
    // creates a node which will be the head node and the tail will point to it as well then create N number of nodes following it
                                                                                                     //and at the end tail points to the last node

    int i;
    struct Node *t;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = *all;
    head->next = NULL;
    tail = head;
    for (i = 1; i < Nll; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = all[i];
        t->next = NULL;
        tail->next = t;    // move tail till reaching the last node
        tail = t;
    }
    // ask the user for the position of insertion
    printf("To insert a student at the first position press 0\n");
    printf("To insert a student at the last position press 1 \n");
    printf("To insert a student at any index position press 2 \n");
    getchar();
    scanf("%c", &yll);
    if (yll == '0')
        insert_head();
    else if (yll == '1')
        insert_lastll();
    else if (yll == '2')
        insertll();
}


// function to display all students' data that exist in the LL by traversing the LL using p pointer
void Display_LL(struct Node *p)
{
    while (p != NULL)
    {
        printf("\nID is %d\n", p->data.ID);
        printf("score is %d\n", p->data.score);
        printf("name is %s\n", p->data.name);
        printf("DB is %d %d %d\n", p->data.db[0], p->data.db[1], p->data.db[2]);
        p = p->next;
    }
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
    printf("Size taken is %ld\n",sizeof(struct student)*(Nll+1)+8*(Nll+1));       // calculates size taken  which is the size of each node plus head and tail pointers
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
