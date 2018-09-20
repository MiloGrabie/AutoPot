list =  [[[0,1],[2,4],[5,6],[7,8]],[[9,10],[11,12],[13,14],[15,16]]]

for a in list:
    for c, d in a:
        for g, h in c:
            print(g, h)