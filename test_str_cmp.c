/*####################################################
# File Name: test_str_cmp.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-18 18:12:31
# Last Modified: 2017-05-18 18:19:45
####################################################*/
#include <stdio.h>

#define str3_cmp(m, c0, c1, c2, c3)                                       \
	    *(uint32_t *) m == ((c3 << 24) | (c2 << 16) | (c1 << 8) | c0)

int main(void){
	char ch[4] = {'G', 'E', 'T', ' '};

	printf("ch[3] = %d\n", ch[3]);
	printf("ch[3] << 24 = %d\n", ch[3] << 24);

	printf("ch[2] = %d\n", ch[2]);
	printf("ch[2] << 16 = %d\n", ch[2] << 16);

	printf("ch[1] = %d\n", ch[1]);
	printf("ch[1] << 8 = %d\n", ch[1] << 8);

	printf("ch[0] = %d\n", ch[0]);

	printf("%d\n", ch[3] << 24 | ch[2] << 16 | ch[1] << 8 | ch[0]);

	return 0;
}
