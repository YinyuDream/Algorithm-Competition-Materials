def Is_Palindrome(str_num):
    if str_num==str_num[::-1]:
        return True
    return False
def Base_change(num,base):
    remain=""
    while num>0:
        remain+=str(num%base) if num%base<10 else chr(ord("A")+num%base-10)
        num//=base
    return remain[::-1]
def main():
    base=eval(input())
    for i in range(1,301):
        if Is_Palindrome(Base_change(i**2,base))==True:
            print(Base_change(i,base),Base_change(i**2,base))
main()