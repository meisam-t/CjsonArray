#include <cjson/cJSON.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	//{“serial_number”: “3", “id”: “402", “data”: [“93", “88”, “99", “64”, “81", “f4”, “80", “4d”]} // Json data 
	char *cjsondata = "{\"serial_number\":\"3\",\"id\":\"402\",\"data\":[\"93\",\"88\",\"99\",\"64\",\"81\",\"f4\",\"80\",\"4d\"]}"; // Cjson Data conversion
	cJSON *DATA = NULL;
	cJSON *iterator = NULL;
	

	// Parsing cjson data
	cJSON *root = cJSON_Parse(cjsondata);  
	if (!cJSON_IsObject(root)) {
		return EXIT_FAILURE;
	}
		/// reading the serial number 
	//SN = cJSON_GetObjectItem(root, "serial_number");
	char *SerNo = cJSON_GetObjectItem(root, "serial_number")->valuestring;
	printf(" ---- serial number is : %s ", SerNo);
	puts("\n");
	///
	/// reading the id 
	
	//ID = cJSON_GetObjectItem(root, "id");
	char *ID = cJSON_GetObjectItem(root, "id")->valuestring;
	printf(" ---- ID is : %s ", ID);
	puts("\n");
	
	/// 
	DATA = cJSON_GetObjectItem(root, "data");
	if (!cJSON_IsArray(DATA)) {
		cJSON_Delete(root);
		return EXIT_FAILURE;
	}

	// iterate over array data[]
	printf("Data:\n");
	int i = 0;
	char s[30] = "\0";
	char *scpy;
	scpy = malloc( 32 * sizeof(char*) );
	cJSON_ArrayForEach(iterator, DATA) {
		if (cJSON_IsString(iterator)) {
			printf("%s ", iterator->valuestring);
			//strcpy(s, iterator->valuestring);
			//strcpy(scpy[i],iterator->valuestring);
			strcat(s,iterator->valuestring);
			sprintf(scpy,"%s",s);
			i++;
		} else {
			printf("Data is not valid, ");
		}

	}
	puts("\n\n");
	//strncat(val,iterator->valuestring,10);

	 /* sizeof("") accounts for '\0' at the end */
   
   printf("String is : %s \n and \n scpy :%s \n", s, scpy);
 
	puts("-------------------");
	puts(s);
	puts(scpy);
		 
	puts("-------------------");
	
	char *out = cJSON_Print(root);
	puts("000000 ");
	puts(out);
	cJSON_Delete(root);
}

