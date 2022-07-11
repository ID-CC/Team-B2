def put(step):
    global N
    if step == N:
        return 1
    answer = 0
    for x in range(N):
        if not(left[x+step] or row[x] or right[step-x+N-1]):
            row[x] = True
            left[x+step] = True
            right[step-x+N-1] = True
            answer += put(step+1)
            row[x] = False
            left[x+step] = False
            right[step-x+N-1] = False
    return answer

def solution(num):
    global N,row, left,right
    N = num
    row = [False for _ in range(N)]
    left = [False for _ in range(N*2-1)]
    right = [False for _ in range(N*2-1)]

    return put(0)
