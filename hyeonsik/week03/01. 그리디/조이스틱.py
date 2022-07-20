def no_more_false(visited):
    for vi in visited:
        if not vi:
            return False
    return True


def solution(name):
    answer = 0
    name_length = len(name)

    now = 0
    v = [False for _ in range(name_length)]
    name = list(map(ord, list(name)))

    print(v)

    # A에서 원하는 알파벳까지 필요한 거리
    for i in range(name_length):
        name[i] = name[i] - 65
        if name[i] == 0:
            v[i] = True
            continue
        elif name[i] > 26 - name[i]:
            name[i] = 26 - name[i]
        answer += name[i]

    print(answer, name)

    # 처리 진행
    while not no_more_false(v):
        # 가까운 거리에 있는걸 처리한다.
        next = 0
        next_min = 99
        for j in range(name_length):
            if not v[j]:
                m = abs(now - j)
                mm = abs(j - name_length - now)
                if m > mm:
                    m = mm
                if next_min > m:
                    next_min = m
                    next = j

        # 완료 처리하고 비용 정산과 now 포인터를 정정한다.
        v[next] = True
        answer += next_min
        now = next
        print(next, answer, v)

    return answer
