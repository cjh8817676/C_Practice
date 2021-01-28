#include <stdio.h>
#include<stdlib.h>

struct employee    /*define structure type*/
{
    char name[12]; /*name*/
    int no;        /*code number*/
};

struct team
{
    struct employee manager;  /*structure within structure*/
    struct employee member;   /*structure within structure*/
};

struct team inform;

