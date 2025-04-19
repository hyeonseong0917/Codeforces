t=int(input())
for i in range(t):
    n=int(input())
    v=[]
    for j in range(n):
        s=input()
        v.append(s)
    # for j in range(n):
    #     print(v[j])
    # 각 string v[i]에 대해 v[i]=v[j]+v[k]를 만족하는 j,k가 있는지?
    ans=""
    m={}
    for j in range(n):
        if v[j] in m:
            m[v[j]]+=1
        else:
            m[v[j]]=1
    for j in range(n):
        cur_str=v[j]
        # cur_str을 만들 수 있는 경우의 수 있는지??
        flag=0
        for k in range(1,len(cur_str)):
            fst_str=cur_str[:k]
            sed_str=cur_str[k:]
            # fst_str과 sed_str 둘 다 있을경우
            if fst_str in m and sed_str in m:
                flag=1
                break
        if flag:
            ans+='1'
        else:
            ans+='0'
    print(ans)