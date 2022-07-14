import java.util.*;

class Solution {
    int[] dx = {0, 1, 0, -1}; // 하/우/상/좌 검증을 위한 x 좌표
    int[] dy = {-1, 0, 1, 0}; // 하/우/상/좌 검증을 위한 y 좌표
    boolean[][] visited; // 방문기록을 저장할 배열
    int n, m; // n: x 최대길이, m: y 최대길이
    
    public int solution(int[][] maps) {
        n = maps.length; // 맵의 x 최대 길이 저장
        m = maps[0].length; // 맵의 y 최대 길이 저장
        
        visited = new boolean[n][m]; // 맵의 크기와 같은 방문기록 배열 생성
        
        return ROR(0, 0, maps); // 시작지점 부터 탐색 시작
    }
    
    public int ROR(int x, int y, int[][] maps) {
        Queue<Node> q = new LinkedList<>(); // 큐 생성
        q.offer(new Node(x, y, 1)); // 큐에 시작지점 좌표와 거리 저장(시작 칸도 1칸 이동한 것이므로 1로 설정)
        visited[x][y] = true; // 방문기록 배열에 시작지점 좌표 저장
        
        while(!q.isEmpty()) { // 큐가 비워질 때까지 반복
            Node node = q.poll(); // 큐의 가장 앞에 있는 객체 추출
            if(node.x == n - 1 && node.y == m - 1) { // 현재 객체의 x/y 좌표가 맵의 x/y 최대 길이-1과 같으면
                return node.distance; // 현재 거리 리턴
            }
            
            for(int i=0; i<4; i++) { // 하/우/상/좌 검증
                int nx = node.x + dx[i]; // 현재 x 좌표와 검증을 위한 x 좌표를 더함
                int ny = node.y + dy[i]; // 현재 y 좌표와 검증을 위한 y 좌표를 더함
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) { // 현재 좌표가 맵 밖으로 나갔는지 판별(0보다 작거나 맵의 크기보다 크면 거짓)
                    if(maps[nx][ny] == 1 && !visited[nx][ny]) { // 현재 좌표가 길이고 방문하지 않았는지 판별
                        visited[nx][ny] = true; // 방문기록 배열에 현재 좌표 저장
                        q.offer(new Node(nx, ny, node.distance + 1)); // 큐에 검증이 완료된 좌표와 거리 저장
                    }
                }
            }
        }
        return -1; // 모든 경우의 수 탐색 후, 상대팀 진영에 도달하지 못하면 -1 리턴
    }
    
    public class Node { // 큐에 삽입할 객체 생성
        int x;
        int y;
        int distance;
        
        public Node(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.distance = distance;
        }
    }
}