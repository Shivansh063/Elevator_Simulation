#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int us_floor, direction,initial_floor=0,initial_person=0;
int elevator_floor=0, max_floor=10,max_person=8;
int destination_floor[8], upper_desfloor[8]={0}, down_desfloor[8]={0};
int person,u=0,v=0;

void User_floor(){
	printf("\nEnter your Current Floor : ");
	scanf("%d", &us_floor);
	printf("Direction in which you want to go : ");
	scanf("%d",&direction);
	elevator_status(us_floor,direction);
	 inside_elevator(elevator_floor,direction,initial_person);
	elevator_path(us_floor,upper_desfloor,down_desfloor,u,v,direction,person);}
void elevator_status(int cur_floor, int cur_direction){
	if((cur_direction == -1 && cur_floor-elevator_floor <= 0 )|| cur_direction == 1 && cur_floor-elevator_floor >= max_floor ){
		printf("\nInvalid Operation");
		User_floor();}
	else{
		printf("\nDoor Closed");
		if(cur_floor - elevator_floor > 0){
			printf("\nMoving in Upward direction");}
 		else{
			printf("\nMoving in Downward direction");}
		printf("\nFloor %d",cur_floor);
		printf("\nDoor Opened");
 		elevator_floor = cur_floor;}}
void inside_elevator(int ele_floor, int dir, int initial_size){
    srand(time(0));
    if(initial_size == 0){
        person = rand() % max_person;
        if(person == 0){
            person=person+1;}
         printf("\n\n%d persons are loading into the lift",person);}
    else{
        person = rand() % (max_person-initial_size+1);
        printf("\n%d persons are loading into the lift",person);}
	int i=0;
	printf("\n");
	for(i=initial_size;i<person+initial_size;i++){
		printf("Enter Destination floor : ");
		scanf("%d",&destination_floor[i]);
		if(destination_floor[i]>=ele_floor){
            upper_desfloor[u]=destination_floor[i];
            u++;}
        else{
            down_desfloor[v]=destination_floor[i];
            v++;}}

    int g=0,h=0;
    for(g=0;g<u-1;g++){
        for(h=g+1;h<u;h++){
    	    if(upper_desfloor[h]>upper_desfloor[g]){
            	int swap = upper_desfloor[g];
            	upper_desfloor[g]= upper_desfloor[h];
            	upper_desfloor[h]=swap; }}}

    for(g=0;g<v-1;g++){
        for(h=g+1;h<v;h++){
    	    if(down_desfloor[h]>down_desfloor[g]){
            	int swap1 = down_desfloor[g];
            	down_desfloor[g]= down_desfloor[h];
            	down_desfloor[h]=swap1; }}}}


 void elevator_path(int current_floor, int upperarray[], int lowerarray[], int size2, int size3, int fin_direction, int initial_size1){
    int l=0,h=0;
    if(fin_direction == 1 && size2!=0){
        for(l=0;l<size2;l++){
            if(upperarray[l]!=max_floor && person!=0){
                elevator_status(upperarray[l],1);}
            else{elevator_status(upperarray[l],-1);}
        person=person-1;
	    destination_floor[l]=0;
	    for(h=l;h<person;h++){
            destination_floor[h]=destination_floor[h+1];}
        if(initial_size1<8){
            inside_elevator(upperarray[l],1,initial_size1);}
	    upperarray[l]=0;
	    for(h=l;h<u;h++){
            destination_floor[h]=destination_floor[h+1];}}
        for(l=size3-1;l>=0;l--){
            elevator_status(lowerarray[l],-1);
            person=person-1;
            if(person<8){
                if(lowerarray[l]!=1 && person !=0){
                    inside_elevator(lowerarray[l],1,person);}
                if(lowerarray[l]==1 && person==0)
                    inside_elevator(lowerarray[l],1,person);
                }}}
    else{
        for(l=size3-1;l>=0;l--){
            elevator_status(lowerarray[l],-1);
            person=person-1;
            if(person<8){
                inside_elevator(lowerarray[l],1,person);}}
        for(l=0;l<size2;l++){
            elevator_status(upperarray[l],1);
            person=person-1;
            if(person<8){
                inside_elevator(upperarray[l],1,person);}
	    destination_floor[l]=0;
	    for(h=l;h<person;h++){
            destination_floor[h]=destination_floor[h+1];}
	    upperarray[l]=0;
	    for(h=l;h<u;h++){
            upperarray[h]=upperarray[h+1];}}}}


int main(){
		printf("Lift initially at Basement");
		printf("\nDoor Closed");
		printf("\n");
		User_floor();
		return 0;
}

