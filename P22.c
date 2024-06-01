/*
Name: Anurag Goyal
ID  : 1096870
Date: March 13, 2023
Assignment Number: 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

typedef struct ST {
  int a;
  char b;
}ST;

void create_shift_table(char* search_str,struct ST * shift_table);
void count_pattern_number(char content[44049][150],char * search_str,int num_lines,struct ST * shift_table);
int find_match_in_line(char* line,char* search_str,int num_matches,int *shifts,struct ST * shift_table);

int main()
{
    char f_name[] = "data_A3_Q2.txt";
    char search_str[50];
    long int now_1=0, now_2 =0, diff =0;
	struct timespec now1;
	struct timespec now2;
    char content[44049][150];
    char lines[150];
    int num_lines = 0;
    struct ST shift_table[53];
    printf("Welcome to the Horspool's program for string search\nPlease enter a Pattern to search: ");
    scanf(" %s",search_str);

    FILE* fp = fopen(f_name,"r");
    if(fp == NULL)
    {
        printf("\nFile could not be opened\n");
        return 0;
    }

    while(fgets(lines,sizeof(lines),fp) != NULL)
    {
        for(int i=0;i<strlen(lines);i++)
        {
            content[num_lines][i] = lines[i];
        }
        num_lines++;
    }
    fclose(fp);

    timespec_get( &now1, TIME_UTC );
	now_1 = ((long int) now1.tv_sec) * 1000 + ((long int) now1.tv_nsec)/1000000;

    create_shift_table(search_str,shift_table);
    count_pattern_number(content,search_str,num_lines,shift_table);

    timespec_get( &now2, TIME_UTC );
	now_2 = ((long int) now2.tv_sec) * 1000 + ((long int) now2.tv_nsec)/1000000;

	diff = now_2 - now_1;  //difference stores the time taken to run the program

    printf("Execution Time = %ld ms\n",diff);
    return 0;
}

void count_pattern_number(char content[44049][150],char * search_str,int num_lines,struct ST * shift_table)
{
    int num_matches = 0;
    int shifts =0;

    for(int i=0;i<num_lines;i++)
    {
        num_matches = find_match_in_line(content[i],search_str,num_matches,&shifts,shift_table);
    }

    printf("Pattern Count: %d\n",num_matches);
    printf("Shifts Count: %d\n",shifts);
}

int find_match_in_line(char* line,char* search_str,int num_matches,int *shifts,struct ST * shift_table)
{
    int str_len = strlen(line);
    int pat_len = strlen(search_str);
    int value = 52;

    int i = pat_len-1;
    while(i <= str_len)
    {
        int k = 0;
        while((k <= pat_len-1) && (search_str[pat_len-1-k] == line[i-k]))
        {
            k++;
        }
        if(k == pat_len)
        {
            num_matches++;
            i = i + pat_len;
        }
        else
        {
            for(int j=0;j<52;j++)
            {
                if(shift_table[j].b == line[i])
                {
                    value = j;
                    break;
                }
            }
            i = i + shift_table[value].a;
        }
        *shifts = *shifts + 1;
    }
    return num_matches;
}

void create_shift_table(char* search_str,struct ST * shift_table)
{
    int len = strlen(search_str);
    for(int i=0;i<26;i++)
    {
        shift_table[i].a = len;
        shift_table[i].b = 65+i;
        shift_table[i+26].a = len;
        shift_table[i+26].b = 97+i;
    }
    shift_table[52].a = len;
    int value = 52;

    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<52;j++)
        {
            if(shift_table[j].b == search_str[i])
            {
                value = j;
                break;
            }
        }
        if(value != 52)
        {
            shift_table[value].a = len-1-i;
        }
    }
}