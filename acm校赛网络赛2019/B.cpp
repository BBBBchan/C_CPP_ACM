#include <cstdio>
int main(int argc, char const *argv[])
{
	int k, n, m;
	while(scanf("%d %d %d", &k, &n, &m) != EOF){
		if(k == 1){
			if(n == m)
				printf("%d %d %d %d\n", 1,1,1,1);
			else if(n > m)
				printf("%d %d %d %d\n", 3, 3, 0, 0);
			else if(m > n)
				printf("%d %d %d %d\n", 0, 0, 3, 3);
		}
		else if(n > m && n >= k){
			if(n-k > m-1){
				if(m >= k-1)
					printf("%d %d %d %d\n", 3*k, 3, 3*(k-1), 0);
				else if(m < k-1)
					printf("%d %d %d %d\n", 3*k, k-m+2, k-1+2*m, 0);
			}
			else if(n-k == m-1){
				if(m >= k-1)
					printf("%d %d %d %d\n", 3*(k-1)+1, 3, 3*(k-1), 1);
				else if(m < k-1)
					printf("%d %d %d %d\n", 3*(k-1)+1, k-m+2, k-1+2*m, 1);
			}
			else if(n-k < m-1){
				if(m+k >= 3+n){
					if(m >= k-1){
						printf("%d %d %d %d\n", 3*(k-1), 3, 3*(k-1), 3 );
					}
					else if(m < k-1){
						printf("%d %d %d %d\n", 3*(k-1), k-m+2, k-1+2*m, 3);
					}
				}
				else if(m+k < 3+n){
					if(m >= k-1){
						printf("%d %d %d %d\n", 3*(k-1), 3, 3*(k-1), 2);
					}
					else if(m < k-1){
						printf("%d %d %d %d\n", 3*(k-1), k-m+2, k-1+2*m, 2);
					}
				}
			}
		}
		else if(n < m && m >=k ){
			if(m-k > n-1){
				if(n >= k-1){
					printf("%d %d %d %d\n", 3*(k-1), 0, 3*k, 3);
				}
				else if(n < k-1){
					printf("%d %d %d %d\n", k-1+2*m, 0, 3*k, k-m+2);
				}
			}
			else if(m-k == n-1){
				if(n >= k-1){
					printf("%d %d %d %d\n", 3*(k-1), 1, 3*(k-1)+1, 3);
				}
				else if(m < k-1){
					printf("%d %d %d %d\n", k-1+2*m, 1, 3*(k-1)+1, k-m+2);
				}
			}
			else if(m-k < n-1){
				if(n+k >= 3+m){
					if(n >= k-1){
						printf("%d %d %d %d\n", 3*(k-1), 3, 3*(k-1), 3);
					}
					else if(n < k-1){
						printf("%d %d %d %d\n", k-1+2*m, 3, 3*(k-1), k-m+2);
					}
				}
				else if(n +k < 3+m){
					if(n >= k-1){
						printf("%d %d %d %d\n", 3*(k-1), 2, 3*(k-1), 3);
					}
					else if(n < k-1){
						printf("%d %d %d %d\n", k-1+2*m, 2, 3*(k-1), k-m+2);
					}
				}
			}
		}
		else if(n > m && n < k){
			printf("%d %d %d %d\n", 2*n+k-1, 3+k-1-m, 2*m+(k-1), k-n+m);
		}
		else if(n < m && m < k){
			printf("%d %d %d %d\n", 2*m+(k-1), k-n+m, 2*n+k-1, 3+k-1-m);
		}
		else if( n == m){
			if(n < k){
				printf("%d %d %d %d\n", 2*n+k-1, k, 2*n+k-1, k);
			}
			else if(n >= k){
				printf("%d %d %d %d\n", 3*(k-1), k, 3*(k-1), k);
			}
		}
	}
	return 0;
}