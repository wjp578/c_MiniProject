#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TXT_NAME "English Plan.txt"

int main()
{
    FILE* file=fopen(TXT_NAME,"w");
    printf("请输入计划完成天数：");
    int day;
    scanf("%d",&day);
    srand((unsigned int)time(NULL));

    int *days=(int*)malloc(4*day);
    int i=0;
    for(;;)
    {
        int d=rand()%day+1;
        int j=0;
        for(j=-1;j<i;j++)
        {
            if(days[j+1]==d)
                break;
            if(days[j+1]!=d)
            {
                if(j+1==i)
                {
                    days[i]=d;
                    i++;
                    break;
                }
            }
        }
        if(i==day)
            break;
    }

    for(i=0;i<day;i++)
    {
        fprintf(file,"day%d\tpage%d\n",i+1,days[i]);
    }

    free(days);
    days=NULL;

    fclose(file);
    file=NULL;
    return 0;
}
