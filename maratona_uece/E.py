def entrada():
    return list(map(int, input().split()))

n, m = entrada()
s1, s2 = input().split()
id = s1.find(s2)

if id == -1:
    print('Impossivel')
else:
    final = s1[id: id + len(s2)]
    ans = s1[id+len(s2): len(s1)]
    ans += s1[0: id]
    ans += final
    print(ans)
