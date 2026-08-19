n = input()
ans = 0
stack = []
for i in n:
    if i.isdigit():
        stack.append(int(i))
    elif i == '(':
        stack.append(i)
    elif i == '+':
        stack.append(i)
    elif i == ')':
        val = 0
        while stack[-1] != '(':
            t = stack.pop()
            if type(t) == int:
                val+= t
        t = stack.pop()
        val = 2 ** val
        t = stack.pop()
        stack.append(val)
for i in stack:
    if type(i) == int:
        ans+=i
 
print(ans)