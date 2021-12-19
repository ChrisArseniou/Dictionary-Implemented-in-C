/*programma pou elegxei an mia leksh yparxei sto leksiko.Ean den yparxei emfanizei tis 2 kontinoteres se ayth*/

#include <stdio.h>
#include<ctype.h>
#include <string.h>
#define SIZE 30

int main(int argc, char *argv[]){

	char user_str[SIZE],read_str[SIZE],close1_str[SIZE],close2_str[SIZE],word1_str[SIZE],word2_str[SIZE]; /*user to vazeis esi, to read einai to dictionary*/
	char user_str_size[20],end_of_dictionary_str[]="EndOfDictionary";/*dhlwnw to EndOfDictionary se string */
	int result,result_end=1,distance_c=0,i,j,m, distance_1, distance_2,word_counter=0,d1,d2;
	
	printf("Word to check: ");
	/*vrisko to megethos se sxesh me to SIZE pou exoume kanei define*//*me ta dyo if sygkinw tis dyo lekseis leksikografika*/
	
	sprintf(user_str_size, "%%%ds", SIZE-1);
	scanf(user_str_size, user_str);

	printf("\n#\n");
	
	while(1){
			
		word_counter++;
			
		scanf(user_str_size, read_str);
		/*sygkrinei to sting pou diavase me to EndOfDictionary kai me thn leksh pou thelei na tsekarh*/
		result = strcmp(read_str,user_str);
		result_end = strcmp(read_str , end_of_dictionary_str);
		/*an diavastei h leksh stamataei to programma kai typwnei thn katalhlh ekfrash*/
		if(result == 0){
			printf("\nDistance:  0, Word: %s\n", read_str);
			printf("\n#\n");
			printf("\"%s\" is in the dictionary.\n", user_str);
			return(0);
		}
		
		/*An o xrisths grapsei EndOfDictionary tote stamata h anagnwsh*/
		if(result_end == 0){
			break;
		}
		/*me tis duo entoles if psaxno na vrw to megalytero string oson afora to mhkos*/  
		if(strlen(user_str) >= strlen(read_str)){
			j = strlen(user_str); 
			m = strlen(read_str);
		}
			
		if(strlen(read_str) > strlen(user_str)){
			j = strlen(read_str);
			m = strlen(user_str);
		}
		/*to counter stamata mexri na perasei apo kathe stoixeio toy megalyterou string*/
		/*ypologizw thn apostash metaksi toy string poy theloume na checkaroume kai toy string poy diavasame sthn synexeia*/
		for(i=0;i<j;i++){
				
			if(user_str[i] == '\0' && tolower(read_str[i]) != '\0' && i < strlen(user_str) && i < strlen(read_str)){
				distance_c++;
			}
			
			if(tolower(user_str[i]) != '\0' && read_str[i] == '\0' && i < strlen(user_str) && i < strlen(read_str)){
				distance_c++;
			}
			
			if(user_str[i] == '\0' && read_str[i] == '\0' && i < strlen(user_str) && i < strlen(read_str)){
				break;
			}
			
			if(tolower(user_str[i]) != tolower(read_str[i]) && i < strlen(user_str) && i < strlen(read_str)){
				distance_c++;
			}
		
			if( i >= m ){
				distance_c++;
			}
		}
		/*an h apostsh einai mhden tote vrikame thn leksh*/
		if(distance_c != 0){
			printf("\nDistance: %2d, Word: %s\n", distance_c , read_str);
		}
		/*apothikevw tis dyo prvtes lekseis poy edwsa*/
		if(word_counter == 1){
			distance_1 = distance_c;
			strcpy(close1_str,read_str);
		}
			
		if(word_counter == 2){
			distance_2 = distance_c;
			strcpy(close2_str,read_str);
		}
		/*krataei panta tis dyo lekseis me to mikrotero distance */
		if(word_counter != 1 && word_counter != 2 && distance_c < distance_1){
			if(distance_1 <= distance_2 ){
				distance_2 = distance_1;
				strcpy(close2_str,close1_str);
			}
			distance_1 = distance_c;
			strcpy(close1_str,read_str);
		}
		else {
			if(word_counter != 1 && word_counter != 2 && distance_c < distance_2){
				distance_2 = distance_c;
				strcpy(close2_str,read_str);
			}
		}
		/*an to distance einai 0 tote vrikame thn leksh poy psaxname*/
		if(distance_c == 0){
			printf("\nDistance: %2d, Word: %s\n", distance_c , read_str);
			printf("\n#\n");
			printf("\"%s\" is in the dictionary.\n", user_str);
			return(0);
		}
		/*mhdenismos ths apostashs sto telos ths kathe loopas*/
		distance_c = 0;
	}
		
	printf("\n#\n");
	printf("\"%s\" is not in the dictionary.\n", user_str);
	printf("Suggestions:\n");

	/*an to word_counter einai 2 simainei oti diavasthke mono mia leksh mazi me to EndOfDictionary ,  thn opoia typvnoyme*/
	if(word_counter == 2){
		strcpy(word1_str,close1_str);
		printf("\"%s\", %d\n" , word1_str,distance_1);
	}
	
	/* sygkinw tis lekseis leksikografika kai typwnw to apotelesma*/ 
	if(word_counter >= 3){
		if(strcmp(close1_str, close2_str) > 0){
			strcpy(word1_str, close2_str);
			d1 = distance_2;
			strcpy(word2_str, close1_str);
			d2 = distance_1;
		}
		else{
			strcpy(word1_str, close1_str);
			d1 = distance_1;
			strcpy(word2_str, close2_str);
			d2 = distance_2;
		}
		printf("\"%s\", %d\n", word1_str, d1);
		printf("\"%s\", %d", word2_str, d2);
		printf("\n");
	}
	return(0);
}
