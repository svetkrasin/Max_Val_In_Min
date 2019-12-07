#include <stdio.h>
#include <stdlib.h>

int **mas;
int i, j, n, m, b = 0, s = 0;

int main()
{
	printf("\n Enter n, m: \n");
	scanf("%d%d", &n, &m);

	mas = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		mas[i] = (int*)calloc(m,sizeof(int));
	for( i = 0; i < n; i++)
		for (j = 0; j < m; j++){
			printf("arr[%i %i]: ", i, j);
			scanf("%d",&mas[i][j]);
		}

	printf("\n Massiv:\n");
	for (i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			printf("%5d",mas[i][j]);
		printf("\n");
	}
	printf("\n---— END —---\n");

	b = mas[0][0];
	for (i = 0; i < n; i++){
 		for (j = 0; j < m; j++){
			if (j == 0){b = mas[i][j];};
  			if (b > mas[i][j]){b = mas[i][j];}; // ищем минимальный в каждой строке
 		}
 		if (i == 0){s = b;}
 		if (s < b){s = b;} // ищем максимальный из минимальных
	}

	printf("minmax: %d \n", s );
	for (i = 0; i < n; i++)
		free(mas[i]);
	free(mas);
	getchar();
	return 0;
}