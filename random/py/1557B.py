t=int(input())
for u in range(t):
    n,k=map(int,input().split())
    v=list(map(int,input().split()))
    cnt=1
    p=[]
    for i in range(n):
        p.append((v[i],i))
    p.sort(key=lambda x: x[0])
    for i in range(n-1):
        if p[i][1]+1!=p[i+1][1]:
            cnt+=1
    # 6 3 4 5 7
    # 3 4 5 7 6
    if cnt<=k:
        print("Yes")
    else:
        print("No")
            