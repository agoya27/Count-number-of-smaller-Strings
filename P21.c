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

void count_pattern_number(char content[44049][150],char * search_str,int num_lines);
int find_match_in_line(char* line,char* search_str,int num_matches,int *shifts);

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
    printf("Welcome to the Brute Force program for string search\nPlease enter a Pattern to search: ");
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
        num_matches = find_match_in_line(content[i],search_str,num_matches,&shifts);
    }

    printf("Pattern Count: %d\n",num_matches);
    printf("Shifts Count: %d\n",shifts);
}

int find_match_in_line(char* line,char* search_str,int num_matches,int *shifts)
{
    int str_len = strlen(line);
    int pat_len = strlen(search_str);

    int i;
    for(i=0;i<str_len-pat_len;i++)
    {
        int j = 0;
        for(;j<pat_len;j++)
        {
            if(line[i+j] != search_str[j])
            {
                break;
            }
        }
        if(j == pat_len)
        {
            num_matches++;
        }
    }
    *shifts = *shifts + (str_len - pat_len + 1);
    return num_matches;
}
