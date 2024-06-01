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

void create_good_shift_table(int* good_shift_table,int* pos_table,char* search_str);
void create_good_shift_table_special(int* good_shift_table,int* pos_table,char* search_str);
void count_pattern_number(char content[44049][150],char * search_str,int num_lines);
void find_match_in_line(char* line,char* search_str,int *shifts,int *num_matches);

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
    printf("Welcome to the Boyre Moore program for string search\nPlease enter a Pattern to search: ");
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

    count_pattern_number(content,search_str,num_lines);

    timespec_get( &now2, TIME_UTC );
	now_2 = ((long int) now2.tv_sec) * 1000 + ((long int) now2.tv_nsec)/1000000;

	diff = now_2 - now_1;  //difference stores the time taken to run the program
    printf("Execution Time = %ld ms\n",diff);
    return 0;
}

void count_pattern_number(char content[44049][150],char * search_str,int num_lines)
{
    int num_matches = 0;
    int shifts =0;

    for(int i=0;i<num_lines;i++)
    {
        find_match_in_line(content[i],search_str,&shifts,&num_matches);
    }

    printf("Pattern Count: %d\n",num_matches);
    printf("Shifts Count: %d\n",shifts);
}

void find_match_in_line(char* line,char* search_str,int *shifts,int* num_matches)
{
    int s = 0;
    int j;
    int len = strlen(search_str);
    int t_len = strlen(line);

    int pos_table[len+1];
    int good_shift_table[len+1];

    for(int i=0;i<len+1;i++)
    {
        good_shift_table[i] = 0;
    }

    create_good_shift_table(good_shift_table,pos_table,search_str);
    create_good_shift_table_special(good_shift_table,pos_table,search_str);

    while(s <= t_len-len)
    {
        j = len -1;
        while(j>=0 && search_str[j] == line[s+j])
        {
            j--;
        }
        if(j<0)
        {
            *num_matches = *num_matches+1;
            s += good_shift_table[0];
            *shifts = *shifts + 1;
        }
        else
        {
            s += good_shift_table[j+1];
            *shifts = *shifts + 1;
        }
    }
}

void create_good_shift_table_special(int* good_shift_table,int* pos_table,char* search_str)
{
    int i,j;
    int len = strlen(search_str);
    j = pos_table[0];
    for(i=0;i<=len;i++)
    {
        if(good_shift_table[i] == 0)
        {
            good_shift_table[i] = j;
        }
        if(i == j)
        {
            j = pos_table[j];
        }
    }
}

void create_good_shift_table(int* good_shift_table,int* pos_table,char* search_str)
{
    
    int len = strlen(search_str);
    int i = len;
    int j = len +1;

    pos_table[i] = j;
    while(i>0)
    {
        while(j<=len && search_str[i-1] != search_str[j-1])
        {
            if(good_shift_table[j] == 0)
            {
                good_shift_table[j] = j-1;
            }
            j = pos_table[j];
        }
        i--;
        j--;
        pos_table[i] = j;
    }
}
