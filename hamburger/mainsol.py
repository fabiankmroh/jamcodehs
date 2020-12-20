N,K = input().split()
N = int(N)
K = int(K)
S = list(input())
j = 0
ans = 0
for i in range(N):
	if(S[i]=='H'):
		continue
	else:
		for j in range(max(j,i-K),min(N,i+K+1)):
			if(S[j]=='P'):
				continue
			else:
				ans = ans+1
				j = j+1
				break
print(ans)