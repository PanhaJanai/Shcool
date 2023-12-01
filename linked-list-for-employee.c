#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define clearScreen system("cls");

typedef struct Employee
{
  int id;
  char name[20];
  char phone_num[20];
  char dob[20];
  float salary;
  int status;
} Employee;

typedef struct NodeType 
{
  Employee e;
  struct NodeType *next;
} NodeType;

// Utility functions
int options(char *mode);
Employee input();
void output(NodeType *origin);
int getEmployeesAmount();
NodeType *getNode();

// Functions of the program
NodeType *initializeList();
NodeType *insertNode(NodeType *origin);
NodeType *deleteNode(NodeType *origin);
void modifyNode(NodeType *origin);
void search(NodeType *origin);

void writeToFile(NodeType *e);
Employee *readFromFile();

int main()
{
  NodeType *origin = initializeList();

  int c = 'y';

  while (c == 'y')
  {
    switch (options("default"))
    {
    case 1:
      printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
      printf("| Employee information:                                                                                                         |\n");
      printf("+-------------------------------------------------------------------------------------------------------------------------------+\n");
      output(origin);
      break;
    case 2:
      origin = insertNode(origin);
      writeToFile(origin);
      break;
    case 3:
      modifyNode(origin);
      writeToFile(origin);
      break;
    case 4:
      origin = deleteNode(origin);
      writeToFile(origin);
      break;
    case 5:
      search(origin);
      break;
    case 6:
      printf("There are %i employees\n", getEmployeesAmount());
      break;
    case 0:
      return 0;
    }

    printf("Would you like to continue? (y/n): ");
    
    scanf("%s", &c);
    fflush(stdin);
    
    printf("\n");

    clearScreen
  }

  // getch();
  return 0;
}

int options(char *mode)
{
  int opt = -1;
  if (strcmpi(mode, "default") == 0)
  {
    printf("\
      Choose one of these options:\n\
      ---------------------------------\n\
      0. Exit program\n\
      1. Output employees\n\
      2. Insert employee into linked list\n\
      3. Modify employee existing date\n\
      4. Delete employee from linked list\n\
      5. Search employee\n\
      6. Count employees\n\
      ---------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "insert") == 0)
  {
    printf("\
      choose one of these insertion methods:\n\
      -----------------------------------------\n\
      0. Go back\n\
      1. Insert at the beginning\n\
      2. Insert before employee id\n\
      3. Insert at the end\n\
      ------------------------------------------\n\
      Your option:\
    ");
    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "delete") == 0)
  {
    printf("\
      Choose on of these deletion methods:\n\
      ------------------------------------\n\
      0. Go back\n\
      1. Delete first node (beginning)\n\
      2. Delete by employee id\n\
      3. Delete last node (end)\n\
      ------------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "modify") == 0)
  {
    printf("\
      Choose on of these modify methods:\n\
      ------------------------------------\n\
      0. Back\n\
      1. Modify employee by field\n\
      ------------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "search") == 0)
  {
    printf("\
      Choose on of these search methods:\n\
      ------------------------------------\n\
      0. Back\n\
      1. Search employee\n\
      ------------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "search-field") == 0)
  {
    printf("\
      Choose on of these search methods:\n\
      ------------------------------------\n\
      0. Back\n\
      1. Search employee by ID\n\
      2. Search employee by Name\n\
      3. Search employee by Phone Number\n\
      4. Search employee by Date of Birth\n\
      5. Search employee by Salary\n\
      6. Search employee by Status\n\
      ------------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  } else if (strcmpi(mode, "modify-field") == 0)  
  {
    printf("\
      Choose on of these deletion methods:\n\
      ------------------------------------\n\
      0. Back\n\
      1. Modify employee ID\n\
      2. Modify employee Name\n\
      3. Modify employee Phone Number\n\
      4. Modify employee Date of Birth\n\
      5. Modify employee Salary\n\
      6. Modify employee Status\n\
      ------------------------------------\n\
      Your option:\
    ");

    scanf("%i", &opt);
    clearScreen

  }

  return opt;
}

Employee input()
{
  Employee e;

  fflush(stdin);
  printf("ID: ");
  scanf("%d", &e.id);

  fflush(stdin);
  printf("Name: ");
  gets(e.name);

  fflush(stdin);
  printf("Phone number: ");
  gets(e.phone_num);

  fflush(stdin);
  printf("Date of birth: ");
  gets(e.dob);

  fflush(stdin);
  printf("Salary: ");
  scanf("%f", &e.salary);

  fflush(stdin);
  printf("Status: ");
  scanf("%i", &e.status);

  return e;
}

NodeType *insertNode(NodeType *origin)
{

  int option = options("insert");
  Employee e;
  NodeType *temp;
  NodeType *temp2 = origin;

  switch (option)
  {
  case 0:
    break;
  case 1:
    e = input();

    temp = getNode();
    temp->next = origin;
    temp->e = e;
    origin = temp;

    break;
  case 2:
    int id;
    printf("Employee ID: ");
    fflush(stdin);
    scanf("%i", &id);
    
    while (origin != NULL)
    {
      if (origin->e.id == id)
      {
        temp->next = getNode();
        temp->next->next = origin;
        temp->next->e = input();
        break;
      }
      temp = origin;
      origin = origin->next;
    }
    origin = temp2;
    break;
  case 3:
    temp = origin;
    while (origin->next != NULL)
    {
      origin = origin->next;
    }
    origin->next = getNode();
    origin->next->e = input();
    origin->next->next = NULL; 
    origin = temp2;
    break;
  }

  return origin;
}

NodeType *deleteNode(NodeType *origin)
{
  int option = options("delete");
  NodeType *temp;

  switch (option)
  {
  case 1:
    origin = origin->next;
    break;
  case 2:
    int id;
    printf("Employee ID: ");
    fflush(stdin);
    scanf("%i", &id);

    while (origin != NULL)
    {
      if (origin->e.id == id)
      {
        temp->next = origin->next;
        break;
      }
      temp = origin;
      origin = origin->next;
    }
    origin = temp;

    break;
  case 3:
    temp = origin;
    while (origin->next->next != NULL)
    {
      origin = origin->next;
    }
    origin->next = NULL;
    origin = temp;
    
    break;
  case 0:
    break;
  }

  printf("Node has been deleted!\n");
  return origin;
}

void modifyNode(NodeType *origin)
{
  int option = options("modify");

  switch (option)
  {
  case 1:
    int emp_id;

    printf("What ID is the employee: ");
    fflush(stdin);
    scanf("%i", &emp_id);

    while (origin != NULL)
    {
      if (origin->e.id == emp_id)
      { 
        switch (options("modify-field"))
        {
        case 1:

          int id;
          fflush(stdin);
          printf("Enter new ID: ");
          scanf("%i", &id);

          origin->e.id = id;
          break;

        case 2:

          char name[20];
          printf("Enter new Name: ");
          fflush(stdin);
          gets(origin->e.name);

          break;

        case 3:

          char p_num[20];
          printf("Enter new Phone Number: ");
          fflush(stdin);
          gets(origin->e.phone_num);

          break;

        case 4:

          char dob[20];
          printf("Enter new Date of Birth: ");
          fflush(stdin);
          gets(origin->e.dob);

          break;

        case 5:

          float sa;
          printf("Enter new Salary: ");
          fflush(stdin);
          scanf("%f", &sa);

          origin->e.salary = sa;
          break;

        case 6:

          int s;
          printf("Enter new Status: ");
          fflush(stdin);
          scanf("%s", &s);

          origin->e.status = s;
          break;

        case 0:
          break;
        }
      }
      origin = origin->next;
    }
    break;
  }
}

void search(NodeType *origin)
{
  int option = options("search");
  int emp_id;
  char name[20];
  char p_num[20];
  char dob[20];
  float salary;
  int status;

  switch (option)
  {
  case 1:

    int opt = options("search-field");

    switch (opt)
    {
    case 1:
      printf("Employee ID: ");
      fflush(stdin);
      scanf("%i", &emp_id);

      while (origin != NULL)
      {
        if (origin->e.id == emp_id)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");

      break;
    
    case 2:

      printf("Employee Name: ");
      fflush(stdin);
      scanf("%s", &name);

      while (origin != NULL)
      {
        if (strcmpi(origin->e.name, name) == 0)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");

      break;

    case 3:
      
      printf("Employee Phone Number: ");
      fflush(stdin);
      scanf("%s", &p_num);

      while (origin != NULL)
      {
        if (strcmpi(origin->e.phone_num, p_num) == 0)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");
      break;

    case 4:

      printf("Employee Date of Birth: ");
      fflush(stdin);
      scanf("%s", &dob);

      while (origin != NULL)
      {
        if (strcmpi(origin->e.dob, dob) == 0)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");
      break;

    case 5:

      printf("Employee Salary: ");
      fflush(stdin);
      scanf("%i", &salary);

      while (origin != NULL)
      {
        if (origin->e.salary == salary)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");
      break;

    case 6:

      printf("Employee Status: ");
      fflush(stdin);
      scanf("%i", &status);

      while (origin != NULL)
      {
        if (origin->e.status == status)
        {
          printf("Found!\n");
          return;
        }
        origin = origin->next;
      }
      printf("Not found!\n");
      break;

    case 0:
      break;
    }

  case 0:
    break;
  }
}

void output(NodeType *origin)
{
  while (origin!= NULL)
  // for (int i = 0; i < getEmployeesAmount(); i++)
  {
    printf("ID: %5d  ",  origin->e.id);
    printf("Name: %15s  ",  origin->e.name);
    printf("Phone number: %15s   ",  origin->e.phone_num);
    printf("Date of birth: %15s   ",  origin->e.dob);
    printf("Salary: %10.2f   ",  origin->e.salary);
    printf("Status: %i\n",  origin->e.status);
    origin = origin->next;
  }
}

void writeToFile(NodeType *origin)
{
  Employee *emp;

  FILE *f = fopen("employee.bin", "wb");

  while (origin != NULL)
  {
    emp = &origin->e;
    fwrite(emp, sizeof(Employee), 1, f);
    origin = origin->next;
  }

  fclose(f);
}

Employee *readFromFile()
{

  FILE *f = fopen("employee.bin", "rb");

  int n = getEmployeesAmount();

  if (n == 0)
    return NULL;

  Employee *employees = (Employee*) malloc(n * sizeof(Employee));

  fread(employees, sizeof(Employee), n, f);

  fclose(f);

  return employees;
}

int getEmployeesAmount()
{
  FILE *f = fopen("employee.bin", "rb");

  // Get the byte size of the file
  int n;
  fseek(f, 0L, SEEK_END);
  n = ftell(f);
  rewind(f);

  // Get the amount of objects
  n = n / sizeof(Employee);

  fclose(f);

  return n;
}

NodeType *getNode()
{
  return (NodeType*) malloc(sizeof(NodeType));
}

NodeType *initializeList()
{
  NodeType *origin = getNode();
  origin->e.id = 0;
  strcpy(origin->e.name, "GOD");
  strcpy(origin->e.phone_num, "Not Telling");
  strcpy(origin->e.dob, "Before Universe");
  origin->e.salary = 0;
  origin->e.status = 0;
  origin->next = NULL;

  NodeType *temp = origin;

  // Get all employees from file
  Employee *emp = readFromFile();

  // printf("%i\n", sizeof(NodeType));
  int n = getEmployeesAmount();
  for (int i = 0; i < n; i++)
  {
    // Handle last node of the linked list
    if (i == n - 1)
    {
      temp->e = *(emp + i);
      temp->next = NULL;
      break;
    } else
    {
      temp->next = getNode();
      temp->e = *(emp + i);
      temp = temp->next;
    }
  }

  return origin;
}