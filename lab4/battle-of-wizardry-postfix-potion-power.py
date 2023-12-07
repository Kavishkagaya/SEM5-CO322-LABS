cases = int(input())

for i in range(cases):
    stack = []
    postfix = input().split()
    for j in postfix:
        if(j <= '9' and j >= '0'):
            stack.append(int(j))
        else:
            a = stack.pop()
            b = stack.pop()
            if(j == '+'):
                stack.append(a+b)
            elif(j == '-'):
                stack.append(b-a)
            elif(j == '*'):
                stack.append(a*b)
            elif(j == '/'):
                stack.append(b//a)

    print(stack.pop())