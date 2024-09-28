int mx_count_words(const char *str, char c) {
	if(!str) return -1;
    	int counter = 1;
    	int i = 0;
    	while (str[i] == c) {
       		if (str[i] == '\0') {
           		return 0;
		}
     		i++;
    	}
    	while (str[i] != '\0') {
        	if (str[i] == c && str[i+1] != '\0' && str[i+1] != c) {
            		counter++;
        	}
        	i++;
    	}
    	return counter;
}

