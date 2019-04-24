def gcd(x, y):
    while(y):
        x, y = y, x % y
    return x



def main():
    tc = int(input())
    cont = 0
    for k in range(0,tc):
        tmp = list(map(int, input().split()))
        m = tmp[0]
        n = tmp[1]
        v = list(map(int, input().split()))

        z = 1
        while v[z] == v[z-1]:
            z = z+1

        ans = [0] * (n+1)
        sec = gcd(v[z-1],v[z])
        ans[z] = sec
        tmp = sec

        for i in range(z,0,-1):
            ans[i-1] = v[i-1]/tmp
            tmp = ans[i-1]


        for i in range(z,n):
            ans[i+1] = v[i]/sec
            sec = ans[i+1]

        ord = []
        for i in range (0, n+1):
            ord.append(ans[i])

        ord = list(dict.fromkeys(ord))
        ord.sort()

        k = 0
        ind = {}
        for x in ord:
            ind[x] = k
            k = k + 1

        cont = cont + 1;
        print("Case #", cont, ": ", sep = '', end = '')
        for i in ans:
            print(str(chr(65 + ind[i])), sep='', end ='')
        print()

if __name__ == "__main__":
    main()
