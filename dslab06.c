#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
    int *array;
    int maxCapacity;	 //maxCapacity is allocated at the time of creation of the queue
    int front;			//index of the front item, starts from 0
    int rear;			//index of the rear item, starts from 0
};
//creating a function to count total number of items in a queue
int noOfItems(struct Queue *queue){
	if (queue->rear == -1 && queue->front==-1)
	{
		return 0;
	} else if (queue->rear >= queue->front){
		return (queue->rear - queue->front)+1;
	} else{
		return (((queue->maxCapacity - 1) - queue->front) + 1) + (queue->rear + 1);
	}
}
//creating a function to check whether the queue is empty or not
int isEmpty(struct Queue *queue){
    if(queue->rear == queue->front){
        return 1;
    }
    return 0;
}
//creating a function to check whether the queue is full or not
int isFull(struct Queue *queue){
    if (noOfItems(queue) == queue->maxCapacity){
        return 1;
    }
    return 0;
}
//creating a function to enqueue the elements into the queue
int enQueue(struct Queue *queue, int value){
	if (isFull(queue) == 0){
		if (noOfItems(queue) == 0)
		{
			// queue->front = -1 as the queue is empty
			// we have to make it 0 as now we will insert an item
			queue->front = 0;
		}
		// incrementing the rear circularly
	    queue->rear = (queue->rear +1)%(queue->maxCapacity);
	    // inserting new element at the rear
	    queue->array[queue->rear] = value;
	    printf("Enqueued element: %d\n", value);
	    return 1;
	}
	else{
		printf("\nQueue is full\n");
		return 0;
	}
}
//creating a function to dequeue the elements from the queue
int deQueue(struct Queue *queue){
	if (noOfItems(queue) != 0){
		// copy the front item in a variable (temp)
		int temp = queue->array[queue->front];
		if (queue->front == queue->rear)
		{
			/* the front should never cross the rear
			it means that the queue is going to become empty after this deQueue operation*/
			queue->front = -1;
			queue->rear	 = -1;
		} else{
			queue->front = (queue->front + 1)%(queue->maxCapacity); // operate in circular way
		}
		// return the variable (temp)
		return temp;
	}
	else{
		// return the extreme value of integer if queue is empty
		return INT_MIN;
	}
}
//creating a function to display the details of queue
void printQueueDetails(struct Queue *queue){
	printf("\nmaxCapacity=%d  front=%d  rear=%d \n", queue->maxCapacity, queue->front, queue->rear);
}
//creating a function to display all the elements of queue
void printQueue(struct Queue *queue){
	int count;
	count = queue->front;
	if (noOfItems(queue) != 0)
	{
		do
	    {
	        printf("Array[%d]= %d ", count, queue->array[count]);
	        count = (count + 1) % (queue->maxCapacity);
	    } while (count != (queue->rear + 1) % queue->maxCapacity);
		printf("\n");
	}
}
int main()
{
	int item, value, sizeOfQueue, operation;
	struct Queue queueA;
	printf("\t\t\t\t\n");
	printf("\nEnter the size of the queue\n");
	scanf("%d", &sizeOfQueue);
	/* keeping the maximum capacity of queue as 
	the entered size of queue by the user */
	queueA.maxCapacity = sizeOfQueue; 
	queueA.front=-1;// the queue is empty
	queueA.rear=-1;// the queue is empty
	// dynamically allocating the memory of queue
	queueA.array = (int *)malloc(queueA.maxCapacity*sizeof(int));
	do
    {
    	printf("\nChoose an operation\n");
      	printf("1.Enqueue into the Queue\n");
      	printf("2.Dequeue from the Queue\n");
      	printf("3.Display the details of Queue\n");
      	printf("4.Display the Queue\n");
      	printf("5.Exit\n");
      	scanf("%d", &operation);
      	switch (operation){
      		case 1:
            	printf("\nEnter the value to be enqueued\n");
        		scanf("%d", &item);
        		enQueue(&queueA, item);			// calling enQueue function
        		break;
         	case 2:
            	value = deQueue(&queueA);		// calling deQueue function
            	if (value == INT_MIN)
            	{
                	printf("\nQueue is empty\n");
            	} else{
                	printf("\n%d is removed", value);
            	}
            	break;
         	case 3:
            	printf("\nDetails of the Queue :\n");
            	printQueueDetails(&queueA);		// calling printQueueDetails function
            	printf("\nTotal number of elements in queue = %d \n", noOfItems(&queueA));
            	break;
         	case 4:
            	printf("\nDisplaying the entire queue :\n");
            	printQueue(&queueA);			// calling printQueue function
            	printf("\nTotal number of elements in queue = %d \n", noOfItems(&queueA));
            	break;
         	case 5:
            	printf("\nPress Enter to exit\n");
            	exit(0);
            	break;
            default:
        		printf("\nWrong operation\n");
        		break;
        }
    }
     while (1);
    return 0;
}
