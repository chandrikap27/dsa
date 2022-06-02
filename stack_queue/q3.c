#include <stdio.h>

#define MAX 10
int queue_1001[MAX];
int front_1001 = -1, rear_1001 = -1;

void insert(void);
int delete (void);
int peek(void);
void display(void);

void main()
{
  int val_1001, option_1001;

  do
  {
    printf("\n***MAIN MENU*");
    printf("\n 1. Insert an element");
    printf("\n 2. Delete an element");
    printf("\n 3. Display the queue");
    printf("\n 4. EXIT");
    printf("\n Enter your option");
    scanf("%d", &option_1001);

    switch (option_1001)
    {

    case 1:

      insert();
      break;

    case 2:

      val_1001 = delete ();

      if (val_1001 != -1)
        printf("\n The deleted element from queue is : %d", val_1001);
      break;

    case 3:

      display();
      break;
    }

  } while (option_1001 != 4);
}

void insert()
{

  int num_1001;
  printf("\n Enter the number to be inserted in queue :");
  scanf("%d", &num_1001);

  if (rear_1001 == (MAX - 1))
    printf("\n Queue overflow");

  else if (front_1001 == -1 && rear_1001 == -1)
  {
    front_1001 = rear_1001 = 0;
    queue_1001[rear_1001] = num_1001;
  }

  else
  {
    rear_1001++;
    queue_1001[rear_1001] = num_1001;
  }
}

int delete ()
{

  int val_1001;
  if (front_1001 == -1 || front_1001 > rear_1001)
  {
    printf("\nQueue underflow");
    return -1;
  }

  else
  {

    val_1001 = queue_1001[front_1001];
    front_1001++;

    if (front_1001 > rear_1001)
      front_1001 = rear_1001 = -1;

    return val_1001;
  }
}

int peek()
{

  if (front_1001 == -1 || front_1001 > rear_1001)
  {
    printf("\nQueue is empty");
    return -1;
  }
  else

    return (queue_1001[front_1001]);
}

void display()
{
  int i_1001;
  if (front_1001 == -1 || front_1001 > rear_1001)
  {
    printf("\nQueue is empty");
  }

  else
  {
    for (i_1001 = front_1001; i_1001 <= rear_1001; i_1001++)
      printf("%d  ", queue_1001[i_1001]);
  }
}