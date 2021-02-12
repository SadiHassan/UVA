# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 09:59:54 2021

@author: MH9130
"""

import math
def inlt():
    return(list(map(int,input().split())))

def line2int(line):
    return(list(map(int,line.split())))

def solve(line):
    p = float(line[0])
    a = float(line[1])
    b = float(line[2])
    c = float(line[3])
    d = float(line[4])
    n = int(line[5])
    max_so_far = float(-1)
    ans = float(0)
    for k in range(1, n + 1):
        price = p * (math.sin(a * k + b) + math.cos(c * k + d) + 2)
        #print(price)
        ans = max(ans, max_so_far - price)
        max_so_far = max(price, max_so_far)
    if ans <= 0:
        print("0.00\n")
    else:
        print("%.8lf\n"%ans)

def solve_11078(scores):
    max_so_far = -1550001
    ans = -1550001
    max_so_far = max(max_so_far, scores[0])
    for i in range(1, len(scores)):
        ans = max(ans, max_so_far - scores[i])
        max_so_far = max(max_so_far, scores[i])
    print(ans)

def solve_11687(N_int):  
    loop = 0
    cur = N_int
    prev = -1    
    while True:
        if cur == prev:
            return loop
        prev = cur
        prev_str = str(prev)
        cur = len(prev_str)
        loop += 1
    return

def solve_11687_rec(s, c):
    l = len(s)
    if str(l) == s:
        return c
    return solve_11687_rec(str(l), c + 1)

def main():
    '''
    f = open("in.txt", "r")
    for line in f:
        line = line2int(line)
        solve(line)
    '''
    
    '''
    line = inlt()
    solve(line)
    '''
    
    '''
    T = int(input())
    while T > 0:
        T -= 1
        N = int(input())
        scores = []
        for i in range(N):
            sc = int(input())
            scores.append(sc)
        solve_11078(scores)
    '''
    '''
    for i in range(1, 105):
        s = ""
        for j in range(i):
            s += '9'
        ans = solve_11687(int(s))
        print(i, ans)
    '''
    '''
    solve_11687(9)
    solve_11687(99)
    solve_11687(999)
    solve_11687(9999)
    solve_11687(99999)
    solve_11687(999999)
    solve_11687(9999999)
    solve_11687(99999999)
    solve_11687(999999999)
    solve_11687(9999999999)
    '''
    while True:
        try:
            N = int(input())
            price = inlt()
            
            target = int(input())
            input()
        except EOFError:
            break
        
        price = sorted(price)
        #print(price)
        low = 0
        high = N - 1
        ans_low = 0
        ans_high = 0
        while low < high and high >= 0 and low < N:
            if price[low] + price[high] == target:
                ans_low = low
                ans_high = high
                #print("found: ",price[low], price[high])
                if low < N - 1:
                    while price[low] == price[low + 1]:
                        low += 1
                        if low >= N - 1:
                            break
                        ans_low = low
                if high > 1:
                    while price[high] == price[high - 1]:
                        high -= 1
                        if high <= 0:
                            break
                        ans_high = high
                if low + 1 == high:
                    break
                    
                low += 1
                high -= 1
                        
            elif price[low] + price[high] < target:
                low += 1
            else:
                high -= 1
            
        print("Peter should buy books whose prices are %d and %d."%(price[ans_low], price[ans_high]))
        print("")
main()
