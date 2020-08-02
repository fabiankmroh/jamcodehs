#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int n, m;

void check(){
	vector<int> visit(n+1);
	for(int i=1; i<=n; i++){
		
	}
}

int main(){
	scanf("%d %d", &n, &m);
	v.resize(n+1);
	for(int i=1; i<=n; i++){
        v[i] = i;
    }

	while(m--){
		int a, b;
        scanf("%d %d", &a, &b);
		v[a]++; 
        v[b]--;
	}

	check();
	for(int i=1; i<=n; i++) 
        printf("%d ", v[i]);
    
    return 0;
}