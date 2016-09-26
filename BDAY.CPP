    #include <stdio.h>
    #include <string.h>
    int main()
    {
	int i, j, n1, n2, c = 0;
	char a1[50];
    	scanf("%d", &n1);

    	
    	for(i = 0; i < n1; i++)
    	scanf("%s", a1[i]);
     
    	scanf("%d", &n2);
     
	int r[50], s[50];
	char a2[50];

	for(i = 0; i < n2; i++) {
	scanf("%d%d%s", &r[i], &s[i], a2[i]);
	}


		for(j = 0; j < n2; j++) {
			for(i = r[j]; i <= s[j]; i++)  {
				if(a2[j] == a1[i])
				c = c + 1;
				printf("%d", c);
			}
			c = 0;
	}




    }