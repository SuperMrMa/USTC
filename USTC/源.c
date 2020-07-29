#include<stdio.h>
#include<string.h>
int main() {
	long long int ip[3];
	while (scanf_s("%d.%d.%d.%d", &ip[0], ip[1], ip[2], ip[3]) != EOF) {
		int flag = 1;
		for (int i = 0; i < 4; i++) {
			if (ip[i] > 255 || ip[i] < 0)
			{
				printf_s("NO\n");
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			printf_s("YES\n");
	}
	return 0;
}