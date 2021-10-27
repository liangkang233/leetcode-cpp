# !/usr/bin/env python3
# coding: utf-8
from random import *
from string import *

# str.join(sequence)  以str为间隔内容连接字符串列表sequence内每一个元素
# ['1' for i in range(L)]、[i*i for i in range(L)]  利用迭代器生成列表

def create_element0(lines, a = 4, b = 7):
    elements = []
    for i in range(lines):
        # ascii_lowercase在string中定义，为所有小写字符的列表
        # choice(seq): 返回列表、元组或字符串seq的随机项str。（可重复）
        L = randint(a, b)
        s =''.join([choice(ascii_lowercase) for i in range(L)])
        p = randint(0, len(s)) 
        element = s[:p] + choice(ascii_uppercase) + s[p:] + '\n'
        elements.append(element)
    return elements

def create_element1(lines):
    elements = []
    for i in range(lines):
        # sample: 不重复的取列表中i个元素，并返回这些元素组成的列表
        # 不可像choice中列表添加for in，因为其返回的是列表
        # 要生成m个不重复i元素列表得在外面加循环
        username = ''.join(sample(ascii_letters + digits, 5))
        password = randint(10000,99999)
        element= str(username) + "," + str(password) + '\n'
        elements.append(element)
    return elements

def create_element2(lines):
    elements = []
    allNum = list(range(-10000, 10000))
    NumLen = len(allNum)    
    #在allNum中抽取Len个不重复数字,最后依照题意排序，旋转。共lines组
    for i in range(lines):  
        s = []
        num = randint(1, 256)
        for j in range(num) :
            index = randint(j, NumLen - 1)
            s.append(allNum[index])
            # 把用过的元素到前面,以防再次选中
            allNum[index], allNum[i] = allNum[i], allNum[index]
        # 模拟target是否存在，有1/36的几率必定不存在
        suiji = randint(0,35)
        if suiji == 35:
            target = 10001
        else :
            target = s[randint(0, num-1)]
        #排序取出的不重复数组并旋转
        s.sort()
        k = randint(0, num-1)
        if k != 0 :
            s = list(reversed(s[0:k])) + list(reversed(s[k:num]))
            s.reverse()
        element = ' '.join([str(s[i]) for i in range(num)]) + '\n'
        elements.append(element)
        elements.append(str(target) + '\n')
        print(f"i = {i},\t k = {k}, \ttarget = {target}")
    return elements

if __name__ == '__main__':
    elements = create_element2(100)
    with open("./date.txt", 'w', encoding='UTF-8') as file:
        file.writelines(elements)