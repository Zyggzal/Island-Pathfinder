#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub){
	if(!str || !sub) {
		return -1;
	}
    	int len1 = mx_strlen(str);
    	int len2 = mx_strlen(sub);

	if(len2 < 1) return 0;
    	int temp, count = 0, count1 = 0;
    	for(int i = 0; i < len1; ){
        	temp = 0; count = 0;
        	while((str[i] == sub[temp]) && str[i] != '\0'){
            		count++; i++; temp++;
        	}	
        	if(count == len2){
            		count1++;
            		count = 0;
        	}
        	else
            	i++;
    	}
    	return count1;
}
