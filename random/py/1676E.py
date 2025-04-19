t=int(input())
for u in range(t):
    n,q=map(int,input().split())
    v=list(map(int,input().split()))
    init_sum=0
    v.sort(reverse=True)
    ans=[]
    psum=[]
    psum.append(v[0])
    for i in range(1,n):
        psum.append(v[i]+psum[i-1])
    for i in range(q):
        a=int(input())
        # a를 채우기 위해 최소 몇 개의 사탕을 먹어야 하는지?
        L=1
        R=n
        min_num=n+1
        while L<=R:
            mid=int((L+R)/2)
            if mid==0:
                break
            sum=psum[mid-1]
            if sum>=a:
                min_num=min(min_num,mid)
                R=mid-1
            else:
                L=mid+1
        if min_num<=n:
            ans.append(min_num)
        else:
            ans.append(-1)
    for i in range(len(ans)):
        print(ans[i])
            