#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void creatArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int *)malloc(tSize * sizeof(int));
}
void setVal(struct myArray *a)
{
    int i, n;
    for (i = 0; i < (*a).used_size; i++)
    {
        printf("Enter the value at index %d: ", i);
        scanf("%d", &n);
        (*a).ptr[i] = n;
    }
}
void show(struct myArray *a)
{
    int i;
    for (i = 0; i < (*a).used_size; i++)
    {
        printf("%d ", (*a).ptr[i]);
    }
    printf("\n");
}
int main()
{
    struct myArray marks;
    creatArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);

    printf("Hello World!\n");
    return 0;
}