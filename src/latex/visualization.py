# визуализация
import matplotlib.pyplot as plt
import numpy as np
import math

# 1
"""
plt.plot([-1, 2], [-2, 4])
plt.plot([-2, -2.5, -1, -0.5, -2], [1, 2.5, 3, 1.5, 1])
plt.plot([1.5, 3, 3.5, 2, 1.5], [0.5, 1, -0.5, -1, 0.5])
plt.plot([-2.5, -0.5], [2.5, 1.5])
plt.plot([1.5, 3.5], [0.5, -0.5])
plt.plot([-2, -1], [1, 3])
plt.plot([2, 3], [-1,1])
plt.show()
"""
# 2
"""
plt.plot([-1, 1.5], [-3, 4.5])
plt.plot([-2, -0.5, -4, -2], [4, 3.5, 3, 4])
plt.plot([0.99, 0.49, 0.99], [2.99, 1.49, 2.99])
plt.ylabel('2')
plt.show()
"""
# 3
"""
s = m.sqrt(3)/2
plt.plot([s, 0.5, -s, -0.5, s], [0.5, s, -0.5, -s, 0.5])
plt.plot([1, s, -1, -s, 1], [0, -0.5, 0, 0.5, 0])
plt.plot([-1.5, 1.5], [0, 0])
plt.plot([0, 0], [-1.5, 1.5])
plt.show()
"""
# 4
"""
plt.plot([-3, -2, -1, 0, -2, -3], [-1, 1, 1, -1, -2, -1])
plt.plot([0, 2, 3, 2, 1, 0], [1, 2, 1, -1, -1, 1])
plt.plot([-3.5, 3.5], [0, 0])
plt.plot([0, 0], [-2.5, 2.5])
plt.show()
"""
# 5
"""
plt.plot([-1, 2], [-2, 4])
plt.plot([0, 0], [-3, 4])
plt.plot([-3, 4], [0, 0])
plt.plot([1.5, 3, 3.5, 2, 1.5], [0.5, 1, -0.5, -1, 0.5])
plt.plot([-2, -2.5, -1, -0.5, -2], [1, 2.5, 3, 1.5, 1])
plt.plot([-1, -2.5, -3, -1.5, -1], [-2, -2.5, -1, -0.5, -2])
plt.show()
"""
# 11
"""
#plt.plot([-4, 4], [0, 0])
#plt.plot([0, 0],[-3.5, 3])
plt.plot([-1,0,3, 4,1,-1],[0,2,2,0,-2,0])
plt.plot([-3.5,-2,0.5,1.5,-2,-3.5],[-1,2,1,-3,-4,-1])
plt.plot([-1, 3],[0, 2])
plt.plot([-3.5, 0.5],[-1, 1])
plt.plot([3,4], [2,0])
plt.plot([-2,-3.5], [-4,-1])
plt.show()
"""
# 12
"""
plt.plot([-2,4], [0,0])
plt.plot([-1,2], [0,0])
plt.plot([-1, -1, 1, 2, 0, -1], [-1, 0, 1, 0, -1, -1])
plt.plot([-3, -2, 3, 4, -1, -3], [-2, 0, 2, 0, -2, -2])
plt.show()
"""
# 13
"""
plt.plot([0,2,-3,3,-2,0],[3.5,-2,2,2,-2,3.5])
plt.plot([-3.5,-2,4,-8,6,-3.5],[-7,22,-31,23,-14,-7])
plt.show()
"""
# 14
"""
a=[[0,-0.5,-1.5,1.5,0.5,0,
          0, 1, 2, 3, 3.5, 3, 2, 1, 0,
          -1, -2, -3, -3.5, -3, -2, -1, 0],
         [1,2,3,3,2,1,
          0.5,1.5,1.5,1, 0, -2,-3,-3.5,-4.5,
          -3.5,-3,-2,0,1,1.5,1.5,0.5]]
ar1=[]
ar2=[]
for i in a[0]:
    ar1.append(4*i)
for i in a[1]:
    ar2.append(4*i)

plt.plot([0,-0.5,-1.5,1.5,0.5,0,
          0, 1, 2, 3, 3.5, 3, 2, 1, 0,
          -1, -2, -3, -3.5, -3, -2, -1, 0],
         [1,2,3,3,2,1,
          0.5,1.5,1.5,1, 0, -2,-3,-3.5,-4.5,
          -3.5,-3,-2,0,1,1.5,1.5,0.5])

plt.plot(ar1, ar2)

plt.show()
"""
"""
def rotate60(x, y):
    s = math.sqrt(3)/2
    m = [[0.5, -s],[s,0.5]]
    X = m[0][0]*x + m[0][1]*y
    Y = m[1][0]*x + m[1][1]*y
    return [X,Y]

def rotate30(x, y):
    s = math.sqrt(3)/2
    m = [[s, -0.5],[0.5,s]]
    X = m[0][0]*x + m[0][1]*y
    Y = m[1][0]*x + m[1][1]*y
    return [X,Y]

def rotate90(x, y):
    s = math.sqrt(3)/2
    m = [[0, -1],[1,0]]
    X = m[0][0]*x + m[0][1]*y
    Y = m[1][0]*x + m[1][1]*y
    return [X,Y]
"""
# 14-16
"""
def countPoint(m, x, y):
    X = m[0][0]*x + m[0][1]*y
    Y = m[1][0]*x + m[1][1]*y
    return [X,Y]

def getRes(frame, m):
    frameresX = []
    frameresY = [] 
    for i in range(len(frame[0])):
        tmp = countPoint(m, frame[0][i], frame[1][i])
        frameresX.append(tmp[0])
        frameresY.append(tmp[1])
    return [frameresX, frameresY]

# 15

frame=[[0,2,3,4,4,3,2,2,1,
          -1,-2,-2,-3,-4,-4,-3,-2,0],
         [5,4.5,3.5,2,1,-1,-2,-4.5,-5,
          -5,-4.5,-2,-1,1,2,3.5,4.5,5]
          ]
rightEye=[[0.5,0.5,1.5,2.5,2.5,1.5,0.5],
         [0.5,1.5,2,1.5,0.5,0,0.5]
]
leftEye=[[-0.5,-0.5,-1.5,-2.5,-2.5,-1.5,-0.5],
         [0.5,1.5,2,1.5,0.5,0,0.5]
]
rightNose=[[0.5, 1],[-2,-1]]
leftNose=[[-0.5, -1],[-2,-1]]
mouth=[[-2,-1,1,2],[-3,-3.5,-3.5,-3]]

skull = [frame, rightEye, leftEye, rightNose, leftNose, mouth]

tref=[
    [[0,1,2,3,3.5,3,2,1,0],[0,1,1.5,1,0,-1,-1.5,-1,0]],
    [[0,-1,-2,-3,-3.5,-3,-2,-1,0],[0,1,1.5,1,0,-1,-1.5,-1,0]],
    [[0, 0.5, 1.5, -1.5,-0.5,0],[0,-1.5,-2.5,-2.5,-1.5,0]],
    [[0, 1, 1.5, 1, 0, -1, -1.5, -1, 0],
     [0,1.5,2.5,3.5,4,3.5,2.5,1.5,0]]
    ]

m1 = [[0, -1],[1, 0]]
m2=[[0,1],[1,0]]
m3=[[-1,0],[0,1]]
m4=[[1,0],[0,-1]]
sqpi = math.sqrt(math.pi)
sq6 = math.sqrt(6)
#M = [[9/sqpi, 0],[0, sqpi]]
M = [[sq6, 0],[0,sq6]]
was = [[[0, 1/sqpi, 0, -1/sqpi,0],[1/sqpi, 0, -1/sqpi, 0,1/sqpi]]]

res = []
for i in was:
    plt.plot(i[0],i[1])
    res.append(getRes(i, M))

for i in res:
    plt.plot(i[0],i[1])

plt.show()
"""
# 6

def countPoint(m, x, y):
    X = m[0][0]*x + m[0][1]*y
    Y = m[1][0]*x + m[1][1]*y
    return [X,Y]

def getRes(frame, m):
    frameresX = []
    frameresY = [] 
    for i in range(len(frame[0])):
        tmp = countPoint(m, frame[0][i], frame[1][i])
        frameresX.append(tmp[0])
        frameresY.append(tmp[1])
    return [frameresX, frameresY]

#M = [[1, 1/3],[2,1]]
M=[[-1,5/6],[0,1]]
was = [[[0,0,-1,1,3,2,2,0],
       [-3,1,1,3,1,1,-3,-3]]]

res = []
for i in was:
    plt.plot(i[0],i[1])
    res.append(getRes(i, M))

for i in res:
    plt.plot(i[0],i[1])

plt.show()

